// Dependencies
#include <bits/stdc++.h>
#include "global-libraries/bin/inputs.hpp"
#include "local-libraries/help.hpp"
#include "local-libraries/version.hpp"
#include "local-libraries/login.hpp"
#include "local-libraries/create.hpp"

// using ...
using namespace std;

// Definitions
#define DEBUG

int main(int argc, char *argv[])
{
	// Scan inputs
	Inputs inputs(argc, argv);

	if (inputs.exist("--help"))
	{
		Help::openMan();
		return 0;
	}

	if (inputs.exist("--version"))
	{
		Version::getVersion();
		return 0;
	}

	if (inputs.exist("--login"))
	{
		Login::login(inputs);
		return 0;
	}

	Create::elaborate(inputs);
	return 0;
}

#undef DEBUG
