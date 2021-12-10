/**
 * create.hpp
 *
 * Library for send the creation request to the server.
 *
 * @author Castellani Davide (@DavideC03)
 */

#ifndef CREATE
// If not imported yet
#define CREATE

// Dependencies
#include <bits/stdc++.h>
#include "../global-libraries/bin/json.hpp"
#include "../global-libraries/bin/inputs.hpp"
#include "../global-libraries/bin/emoji.hpp"
#include "../global-libraries/bin/positive.hpp"
#include "../global-libraries/bin/rest.hpp"
#include "settings.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

// Definitions
// #define DEBUG

// Classes prototipe(s)
class Create
{
private:
    struct question
    {
        string id;                        // id of the question
        string question;                  // The question
        bool boolean;                     // If the answer is a boolean
        vector<Create::question> ifTrue;  // Questions if true
        vector<Create::question> ifFalse; // Questions if false
    };
    vector<Create::question> questions =
        {{"name", "Please, insert the repo name: ", false},
         {"template", "Please, insert the template name: ", false},
         {"descr", "Please, insert the repo description: ", false},
         {"prefix", "Please, insert the repo prefix (if you want once): ", false},
         {"isOrg", "Please, insert if you want to put the new repo into an Organization [y/N]: ", true, {{"org", "Please, insert the organization name: ", false}, {"team", "Please, insert the team name (if didn't exist yet, I want to create that for you): ", false}}},
         {"private", "Please, insert do you want that this repo is private [y/N]: ", true}};
    json data;

    void elaborateQuestion(question q, json &data);
    Inputs inputs;
    Settings settings;

public:
    Create(Inputs i);
    void elaborate();

    static void elaborate(Inputs i);
};

Create::Create(Inputs i)
{
    /**
     * Constructor
     *
     * @param i The inputs by
     */
    Create::inputs = i;
}

void Create::elaborate()
{
    /**
     * Elaborate the creation request
     */
    if (Create::inputs.exist("--repo-info"))
        data = json::parse(Create::inputs.getValue("--repo-info"));
    else
        for (auto &q : Create::questions)
            elaborateQuestion(q, data);

    json payload;
    payload["username"] = Create::settings.getUsername();
    payload["token"] = Create::settings.getToken();
    payload["answers"] = data;

    json response = Rest::jsonRequest(
        Rest::CREATESTRUCTURE_REST_API,
        "",
        {
            {"request", "create_repo"},
            {"payload", payload}
        },
        true);

    if (response["code"] == 200)
    {
        cout << Emoji::getEmoji("check") << "\tRepo created successfully!" << endl;
    }
    else
    {
        cout << Emoji::getEmoji("x") << "\tError: " << response["message"] << endl;
    }

#ifdef DEBUG
    cout << response.dump(4) << endl;
#endif
}

void Create::elaborateQuestion(question q, json &data)
{
    /**
     * Elaborate the question
     *
     * @param q The question
     * @param data The json data where the question will be stored
     */

    string tmp;
    cout << Emoji::getEmoji("red question mark") << "\t" << q.question;
    getline(cin, tmp);

    if (q.boolean)
    {
        bool tmpBool = Positive::isPositive(tmp);
        data[q.id] = tmpBool;

        if (tmpBool)
            for (auto &qTrue : q.ifTrue)
                elaborateQuestion(qTrue, data);
        else
            for (auto &qFalse : q.ifFalse)
                elaborateQuestion(qFalse, data);
    }
    else
    {
        data[q.id] = tmp;
    }
}

void Create::elaborate(Inputs i)
{
    /**
     * Elaborate the creation request
     *
     * @param i The inputs by
     */
    Create c(i);
    c.elaborate();
}

#undef DEBUG
#endif
