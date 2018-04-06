#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "main.h"

using namespace std;


static void opt_input(string const &);
static void opt_output(string const &);
static void opt_method(string const &);
static void opt_help(string const &);


/**************** Elementos globales ******************/
static option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	{2, "m", "method", "-", opt_method, OPT_DEFAULT},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};

method_t method;
static istream *iss = 0;
static ostream *oss = 0;
static fstream ifs;
static fstream ofs;


/******************* **********************************/

static void
opt_input(string const &arg)
{
	if (arg == "-") {
		iss = &cin;
	}
	else {
		ifs.open(arg.c_str(), ios::in);
		iss = &ifs;
	}
	if (!iss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

static void
opt_output(string const &arg)
{
	if (arg == "-") {
		oss = &cout;
	} else {
		ofs.open(arg.c_str(), ios::out);
		oss = &ofs;
	}
	if (!oss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

static void
opt_method(string const &arg)
{
	if (arg == "-" || arg == CMD_ARG_METHOD_DFT) {
		method = DFT;
	} else if (arg == CMD_ARG_METHOD_IDFT) {
		method = IDFT;
	}
	else {
	cerr << "non-valid method: "
	     << arg
	     << "."
	     << endl;
	exit(1);
	}
}

static void
opt_help(string const &arg)
{
	cout << "cmdline [-m method] [-i file] [-o file]"
	     << endl;
	exit(0);
}



int main(int argc, char * const argv[])
{
	status_t st;

	cmdline cmdl(options);
	cmdl.parse(argc, argv);
	st = process_signal(*iss, *oss);
	if(st != OK)
		handle_err(st);

	return 0;
}
