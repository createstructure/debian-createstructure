/* createstructure addictional librarias
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_MODULE
// If not imported yet
#define CREATESTUCTURE_MODULE

// Dependencies
#include <bits/stdc++.h>
#include "libraries/bin/createstructure.hpp"

// using ...
using namespace std;

// Definitions
// #define DEBUG

// Classes prototipe(s)
class inputs
{
/* Inputs: the class to store the CLI inputs
 */
private:
    map<string, string> m;

public:
    inputs(int argc, char *argv[]);
    string to_string();
    bool exist(string key);
    string getValue(string key);
};

class help
{
/* Help: the class to handle help requestes
 */
private:
    bool is_help;

public:
    help(inputs i);
    string to_string();
};

class setting
{
/* Setting: manage the settings
 */
private:
    string username;
    string token;
    string filename = string(getenv("HOME")) + "/createstructure.setting";

public:
    setting();
    setting(string username, string token);
    bool load();
    bool save();
    string get_username();
    string get_token();
    string to_string();
};

class login
{
/* Login: the class to handle login requestes
 */
private:
    bool is_login;

public:
    login(inputs i);
    string to_string();
};

class createstructure
{
/* Createstructure: the class to handle normal-use requestes
 */
private:
    struct question
    {
        string id;                                 // id of the question
        string question;                           // The question
        bool boolean;                              // If the answer is a boolean
        vector<createstructure::question> ifTrue;  // Questions if true
        vector<createstructure::question> ifFalse; // Questions if false
    };
    string data;
    vector<question> questions =
        {
            {"name", "Please, insert the repo name: ", false},
            {"template", "Please, insert the template name: ", false},
            {"descr", "Please, insert the repo description: ", false},
            {"prefix", "Please, insert the repo prefix (if you want once): ", false},
            {"isOrg", "Please, insert if you want to put the new repo into an Organization [y/N]: ", true, {{"org", "Please, insert the organization name: ", false}, {"team", "Please, insert the team name (if didn't exist yet, I want to create that for you): ", false}}},
            {"private", "Please, insert do you want that this repo is private [y/N]: ", true}};
    void elaborate_question(question q, json &data);

public:
    createstructure(inputs i, setting s);
    string to_string();
};

// Functions
inputs::inputs(int argc, char *argv[])
{
    /* Inputs Constructor: the constructor of the inputs class
	 *
	 * inputs:
	 * 	- argc: the number of command-line arguments
	 *	- argv: an array containing all command-line arguments
	 */
    for (size_t i = 1; i < argc; ++i)
    {
        string tmp(argv[i]);
        if (tmp.rfind("-", 0) == 0 && i + 1 < argc && string(argv[i + 1]).rfind("-", 0) != 0)
        {
            string tmp2(argv[++i]);
            m[tmp] = tmp2;
        }
        else
        {
            if (tmp.rfind("-", 0) == 0)
                m[tmp] = "1"; // true
        }
    }
}

string inputs::to_string()
{
    /* Inputs to String: the instance printer
     *
	 * output:
	 *	- the instance string
	 */
    string s("inputs{\n");

    for (auto &elem : m)
    {
        s += "\t\"" + elem.first + "\": \"" + elem.second + "\"," + "\n";
    }

    s += "}";

    return s;
}

bool inputs::exist(string key)
{
    /* Inputs Exist: check if exist the asked key
	 *
	 * inputs:
	 * 	- key: the asked key
 	 *
	 * output:
	 *	- if the key exist in the inputs or not
	 */
    return m.find(key) != m.end();
}

string inputs::getValue(string key)
{
    /* Inputs Get Value: get the value related to the selected key
	 *
	 * inputs:
	 * 	- key: the asked key
 	 *
	 * output:
	 *	- the key value
	 */
    assert(exist(key));
    return m[key];
}

help::help(inputs i)
{
    /* Help Constructor: the constructor of the help class
	 *
	 * inputs:
	 * 	- i: the CLI arguments
	 */
    if (i.exist("--help"))
    {
        is_help = true;
        system("man createstructure");
        exit(0);
    }
    else
    {
        is_help = false;
    }
}

string help::to_string()
{
    /* Help to String: the instance printer
     *
	 * output:
	 *	- the instance string
	 */
    return string("help {\n\t") + (is_help ? "true" : "false") + "\n}";
}

setting::setting()
{
    /* Setting Normal Constructor: the constructor of the settings class
	 */
    try
    {
        if (!load())
            throw runtime_error("Load setting failed");
    }
    catch (...)
    {
        cout << "Login configuration missing" << endl
             << "Run ... [--login | -l] [[--username | -u] YOUR_USERNAME [--token | -t] YOUR_TOKEN]" << endl
             << "More info: createstructure [--help | -h]" << endl;
        exit(0);
    }
}

setting::setting(string username, string token)
{
    /* Setting Save Constructor: the constructor to save new settings
	 *
	 * inputs:
	 * 	- username: the GitHub username
	 *	- token: the GitHub token
	 */
    this->username = username;
    this->token = token;
    save();
}

bool setting::load()
{
    /* Setting Load: try to load saved settings
     *
	 * output:
	 *	- true if it's loaded correctly, false overwise
	 */
    try
    {
        // Open the file
        ifstream settingFile(filename);

        if (!getline(settingFile, username))
            throw runtime_error("Username missing");
        if (!getline(settingFile, token))
            throw runtime_error("Token missing");

        // Close the file
        settingFile.close();

        // Check
        assert(username != "" && token != "");

        // Return
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool setting::save()
{
    /* Setting Save: save all settings
     *
	 * output:
	 *	- true if it's saved correctly, false overwise
	 */
    try
    {
        // Initial check
        assert(username != "" && token != "");

        // Open the file
        ofstream settingFile(filename.c_str());

        settingFile << username << endl;
        settingFile << token << endl;

        // Close the file
        settingFile.close();

        // Return true
        return true;
    }
    catch (...)
    {
        return false;
    }
}

string setting::get_username()
{
    /* Setting Get Username: get the username
     *
	 * output:
	 *	- the username
	 */
    return username;
}

string setting::get_token()
{
    /* Setting Get Token: get the token
     *
	 * output:
	 *	- the token
	 */
    return token;
}

string setting::to_string()
{
    /* Setting to String: the instance printer
     *
	 * output:
	 *	- the instance string
	 */
    return string("") +
           "setting{\n" +
           "\tusername: " + username + ",\n" +
           "\ttoken: " + token + "\n" +
           "}";
}

login::login(inputs i)
{
    /* Login Constructor: the constructor of the login class
	 *
	 * inputs:
	 * 	- i: the CLI arguments
	 */
    if (i.exist("--login"))
    {
        if (i.exist("--username") && i.exist("--token"))
        {
            setting(i.getValue("--username"), i.getValue("--token"));
        }
        else
        {
            string username, token;
            cout << "Please insert your GitHub username: ";
            cin >> username;
            cout << "Please insert your GitHub token: ";
            cin >> token;
            cout << username << "\t" << token << endl;
            setting(username, token);
        }

        is_login = true;
        exit(0);
    }
    else
    {
        is_login = false;
    }
}

string login::to_string()
{
    /* Login to String: the instance printer
     *
	 * output:
	 *	- the instance string
	 */
    return string("login {\n\t") + (is_login ? "true" : "false") + "\n}";
}

createstructure::createstructure(inputs i, setting s)
{
    /* Createstructure Constructor: the constructor of the createstructure class
	 *
	 * inputs:
	 * 	- i: the CLI arguments
	 * 	- s: the loaded settings
	 */
    // Get repo data
    json data;
    if (i.exist("--batch") && i.exist("--values"))
    {
        data = json::parse(i.getValue("--values"));
    }
    else
    {
        string tmp;
        bool c = true; // continue

        for (question &q : questions)
        {
            cout << q.id << "\t" << q.question << "\t" << (q.boolean ? "true" : "false") << "\t" << q.ifTrue.size() << "\t" << q.ifFalse.size() << endl;
        }

        for (question &q : questions)
            elaborate_question(q, data);
    }

    cout << data.dump() << endl;

    // Run the web-request
    json payload;
    payload["answers"] = data;
    payload["username"] = s.get_username();
    payload["token"] = s.get_token();
    cout << payload.dump() << endl;

    string response = textRequest(
        string("https:\u002F\u002Fwww.castellanidavide.it/other/rest/product/create.php"),
        "",
        payload,
        "POST");
    cout << response << endl;
}

void createstructure::elaborate_question(question q, json &data)
{
    /* Createstructure Elaborate Question: elaborates the given question
	 *
	 * inputs:
	 * 	- q: the question
	 * 	- data: the place where to save the answer
	 */
    string tmp;
    cout << getEmoji("info") << "\t" << q.question;
    getline(cin, tmp);

    if (q.boolean)
    {
        bool positive = isPositive(tmp);
        data[q.id] = positive;

        if (positive)
            for (question &q2 : q.ifTrue)
                elaborate_question(q2, data);
        else
            for (question &q2 : q.ifFalse)
                elaborate_question(q2, data);
    }
    else
    {
        data[q.id] = tmp;
    }
}

string createstructure::to_string()
{
    /* Createstructure to String: the instance printer
     *
	 * output:
	 *	- the instance string
	 */
    return string("createstructure {\n\tdata: ") + data + "\n}";
}

#endif
