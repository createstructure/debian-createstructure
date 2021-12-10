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
public:
    static void login(Inputs i);
};

void Login::login(Inputs i)
{
    /**
     * Do the login.
     * 
     */
    // Variables
    string username, token;

    // Check if the user put the username and token in the command line
    if (i.exist("--username"))
    {
        username = i.getValue("--username");
    }
    else
    {
        cout << Emoji::getEmoji("red question mark") << "\t" << "GitHub username: ";
        cin >> username;
    }

    if (i.exist("--token"))
    {
        token = i.getValue("--token");
    }
    else
    {
        cout << Emoji::getEmoji("red question mark") << "\t" << "GitHub token: ";
        cin >> token;
    }

    // Login
    Settings(username, token);

    cout << "Login successful!" << endl;
}

#undef DEBUG
#endif
