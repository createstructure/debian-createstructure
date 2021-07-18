// Dependencies
#include <bits/stdc++.h>
#include "libraries/bin/createstructure_inputs.hpp"
#include "libraries/bin/createstructure_help.hpp"
#include "libraries/bin/createstructure_login.hpp"
#include "libraries/bin/createstructure_setting.hpp"
#include "libraries/bin/createstructure_debian.hpp"

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
#ifdef DEBUG
	cout << i.to_string() << endl;
#endif // DEBUG

	help h(i, "createstructure");
#ifdef DEBUG
	cout << h.to_string() << endl;
#endif // DEBUG

	login l(i);
#ifdef DEBUG
	cout << l.to_string() << endl;
#endif // DEBUG

	setting s;
#ifdef DEBUG
	cout << s.to_string() << endl;
#endif // DEBUG

	debian d(i, s);
#ifdef DEBUG
	cout << d.to_string() << endl;
#endif // DEBUG

	return 0;
}
