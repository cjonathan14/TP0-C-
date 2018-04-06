#ifndef SIGNAL_PROCESSING__H
#define SIGNAL_PROCESSING__H

#include "err.h"
#include "Complex.h"
#include "TempArray.h"
#include "types.h"

status_t dft(Array<Complex> & , Array<Complex> &);
status_t idft(Array<Complex> &, Array<Complex> &);



#endif
