#ifndef PROCESS_SIGNAL__H
#define PROCESS_SIGNAL__H

#include <iostream>
#include <limits.h>
#include "signal_processing.h"
#include "TempArray.h"
#include "err.h"
#include "types.h"
#include "Complex.h"

using namespace std;

extern method_t method;

status_t process_signal(istream &is, ostream &os);
status_t read_line (Array<Complex> & v, istream & is);
void print_line (Array<Complex> & v, ostream & os);


#endif
