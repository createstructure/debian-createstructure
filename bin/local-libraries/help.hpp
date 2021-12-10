/**
 * help.hpp
 * 
 * Library for handling the help menu.
 * 
 * @author Castellani Davide (@DavideC03)
 */

#ifndef HELP
// If not imported yet
#define HELP

// Dependencies
#include <bits/stdc++.h>

// using ...
using namespace std;

// Definitions
// #define DEBUG

// Classes prototipe(s)
class Help
{
private:
public:
    static void openMan();
};

// Function(s)
void Help::openMan()
{
    /**
     * Open Manual
     */
    system("man createstructure");
}

#undef DEBUG
#endif
