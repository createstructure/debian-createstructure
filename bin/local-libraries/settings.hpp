/**
 * settings.hpp
 *
 * Library for handling settings.
 *
 * @author Castellani Davide (@DavideC03)
 */

#ifndef SETTING
// If not imported yet
#define SETTING

// Dependencies
#include <bits/stdc++.h>
#include "../global-libraries/bin/json.hpp"
#include "../global-libraries/bin/emoji.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

// Definitions
// #define DEBUG

// Classes prototipe(s)
class Settings
{
    /* Setting: manage the settings
     */
private:
    inline static string filename =
#ifdef DEBUG
        string(".")
#else  // DEBUG
        string(getenv("HOME"))
#endif // DEBUG
        + "/createstructure.setting";
    string username;
    string token;

    void loginMissing();

public:
    Settings(string username = "", string token = "");
    bool load();
    bool save();
    string getUsername();
    string getToken();
};

Settings::Settings(string username, string token)
{
    /**
     * Constructor
     *
     * @param username: github username, default ""
     * @param token: github token, default ""
     */
    Settings::username = username;
    Settings::token = token;

    if (Settings::username == "" || Settings::username.empty() || Settings::token == "" || Settings::token.empty())
    {
        if (!Settings::load())
        {
            cout << Emoji::getEmoji("x") << "Please, do the login first" << endl;
            exit(EXIT_SUCCESS);
        }
#ifdef DEBUG
        cout << "Loaded settings" << endl;
#endif // DEBUG
    }
    else
    {
        Settings::save();
    }
}

void Settings::loginMissing()
{
    /**
     * Login missing
     */
    system("man createstructure.2");
    exit(EXIT_SUCCESS);
}

bool Settings::load()
{
    /**
     * Load settings from file
     *
     * @return: true if settings are loaded, false otherwise
     */
    try
    {
        ifstream file(Settings::filename);
        json j;
        file >> j;
        Settings::username = j["username"];
        Settings::token = j["token"];
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool Settings::save()
{
    /**
     * Save settings to file
     *
     * @return: true if settings are saved, false otherwise
     */
    try
    {
        ofstream file(Settings::filename);
        json j;
        j["username"] = Settings::username;
        j["token"] = Settings::token;
        file << j;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

string Settings::getUsername()
{
    /**
     * Get the username
     *
     * @return: username
     */
    if (Settings::username == "" || Settings::username.empty())
        Settings::loginMissing();
    return Settings::username;
}

string Settings::getToken()
{
    /**
     * Get the token
     *
     * @return: token
     */
    if (Settings::token == "" || Settings::token.empty())
        Settings::loginMissing();
    return Settings::token;
}

#undef DEBUG
#endif
