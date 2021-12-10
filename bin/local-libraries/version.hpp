/**
 * login.hpp
 * 
 * Library for handling the version of the program.
 * 
 * @author Castellani Davide (@DavideC03)
 */

#ifndef VERSION
// If not imported yet
#define VERSION

// Dependencies
#include <bits/stdc++.h>

// using ...
using namespace std;

// Definitions
// #define DEBUG

// Classes prototipe(s)
class Version
{
private:
public:
    static void getVersion();
};

// Function(s)
void Version::getVersion()
{
    /**
     * Get the version of the program.
     */
    system("dpkg --status createstructure | grep ^Version | sed 's/Version: //'"); 
}

#undef DEBUG
#endif
