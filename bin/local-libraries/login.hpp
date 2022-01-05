/**
 * login.hpp
 *
 * Library for handling the login.
 *
 * @author Castellani Davide (@DavideC03)
 */

#ifndef LOGIN
// If not imported yet
#define LOGIN

// Dependencies
#include <bits/stdc++.h>
#include "../global-libraries/bin/json.hpp"
#include "../global-libraries/bin/inputs.hpp"
#include "../global-libraries/bin/rest.hpp"
#include "settings.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

// Definitions
// #define DEBUG

// Classes prototipe(s)
class Login
{
    /* Login: the class to handle login requestes
     */
private:
    inline static string CLIENT_ID = "4586020fd298fe1d5e8c";
    inline static string SCOPE = "repo workflow admin:org user write:org";
    inline static string GRANT_TYPE = "urn:ietf:params:oauth:grant-type:device_code";
    inline static string LINK_GET_CODE = "https://github.com/login/device/code";
    inline static string LINK_INSERT_CODE = "https://github.com/login/device";
    inline static string LINK_GET_TOKEN = "https://github.com/login/oauth/access_token";
    string deviceCode;
    string userCode;
    int expiresIn;
    string username;
    string token;

    void getCode();
    void insertCode();
    void getToken();

public:
    Login(Inputs i);

    static void login(Inputs i);
};

Login::Login(Inputs i)
{
    /**
     * Do the login.
     *
     */
    // Check if the user put the username and token in the command line
    if (i.exist("--username") && i.exist("--token"))
    {
        Login::username = i.getValue("--username");
        Login::token = i.getValue("--token");
    }
    else
    {
        // If not, create credentials for the user
#ifdef DEFAULT
        cout << "Auto-generate token" << endl;
#endif // DEFAULT
        try
        {

            Login::getCode();
            Login::insertCode();
            bool firstTime = true;
            while (Login::username == "" || Login::token == "" || Login::username.empty() || Login::token.empty())
            {
                if (!firstTime)
                {
                    cout << "Invalid credentials, try again. If the problem persists, please contact createstructure's team: https://github.com/createstructure/debian-createstructure/discussions" << endl;
                }
                cout << "Press enter to continue, I will get the username and token automatically...";
                cin.get();
                Login::getToken();
            }
        }
        catch (exception &e)
        {
            cout << Emoji::getEmoji("x") << "\tError: " << e.what() << endl;
            cout << Emoji::getEmoji("x") << "\tPlease, check your internet connection and try again." << endl;
            exit(EXIT_FAILURE);
        }
    }

    // Login
    Settings(Login::username, Login::token);

    cout << "Login successful!" << endl;
}

void Login::login(Inputs i)
{
    /**
     * Do directly the login.
     *
     */
    Login l(i);
}

void Login::getCode()
{
    /**
     * Get the code to be inserted in the GitHub.
     *
     */
    // Request the code to the server
#ifdef DEBUG
    cout << Rest::textRequest(Login::LINK_GET_CODE, "", {{"client_id", Login::CLIENT_ID}, {"scope", Login::SCOPE}}, true) << endl;
#else // DEBUG
    json response = Rest::jsonRequest(Login::LINK_GET_CODE, "", {{"client_id", Login::CLIENT_ID}, {"scope", Login::SCOPE}}, true);
    deviceCode = response["device_code"].get<string>();
    userCode = response["user_code"].get<string>();
    expiresIn = response["expires_in"].get<int>();
#endif // DEBUG

#ifdef DEBUG
    cout << "getCode: " << endl
         << response.dump(4) << endl;
#endif // DEBUG
}

void Login::insertCode()
{
    /**
     * Insert the code to the GitHub.
     *
     */
    // Ask the user to insert the code
    cout << "To create a new token, automatically, go to the following link: " << Login::LINK_INSERT_CODE << endl;
    cout << "... and insert this code: " << Login::userCode << endl;
}

void Login::getToken()
{
    /**
     * Get the token from the GitHub.
     *
     */
    // Request the token to the server
    json response = Rest::jsonRequest(Login::LINK_GET_TOKEN, "", {{"client_id", Login::CLIENT_ID}, {"device_code", Login::deviceCode}, {"grant_type", Login::GRANT_TYPE}}, true);
    if (response.find("error") != response.end())
        return;

    Login::token = response["access_token"].get<string>();
#ifdef DEBUG
    cout << "getToken: " << endl
         << response.dump(4) << endl;
#endif // DEBUG

    // Get the username
    json user = Rest::jsonRequest(Rest::GITHUB_REST_API + "user", Login::token);

    Login::username = user["login"].get<string>();

#ifdef DEBUG
    cout << "getToken: " << endl
         << user.dump(4) << endl;
#endif // DEBUG
}
#undef DEBUG
#endif
