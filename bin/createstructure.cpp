// Dependencies
#include <bits/stdc++.h>
#include "libraries/bin/json.hpp"
#include "libraries/bin/createstructure.hpp"
#include "createstructure_modules.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

// Definitions
//#define DEBUG

// Code
int main(int argc, char *argv[])
{
	/* Main: the start point of the code
	 *
	 * inputs:
	 * 	- argc: the number of command-line arguments
	 *	- argv: an array containing all command-line arguments
 	 *
	 * output:
	 *	- a run code: if it works in the correct way it will return 0
	 */

	inputs i(argc, argv);
	cout << i.to_string() << endl;

	help h(i);
	cout << h.to_string() << endl;

	login l(i);
	cout << l.to_string() << endl;

	setting s;
	cout << s.to_string() << endl;

	createstructure c(i, s);
	cout << c.to_string() << endl;

	return 0;
}
