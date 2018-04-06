#include <iostream>
#include "process_signal.h"

using namespace std;

status_t process_signal(istream &is, ostream &os)
{
	status_t st;
	Array<Complex> vi;
	Array<Complex> vo;

	while(!is.eof()) {
		vi.clean_vector();
		vo.clean_vector();
		st = read_line(vi, is);

		if(st != OK && st != ERROR_CORRUPT_LINE)
			return st;
		if(st ==  ERROR_CORRUPT_LINE) {
			handle_err(st);
		} else {
			switch(method){
				case DFT:
					st = dft(vi, vo);
					if(st != OK)
						return st;
					break;
				case IDFT:
					st = idft(vi, vo);
					if(st != OK)
						return st;
					break;
			}
			print_line(vo, os);
		}
	} /*WHILE*/

	return OK;
}


status_t read_line (Array<Complex> & v, istream & is)
{
	status_t st;
	Complex c;

	if (v.getSize() != 0)
		return ERROR_INVALID_INPUT_VECTOR;
	while (is.peek() != '\n' && !is.eof()) {
		if (!(is >> c)) {
			is.clear();
			is.ignore(MAX_INT,'\n');
			return ERROR_CORRUPT_LINE;
		}
		st = v.load_vector(c);
		if(st != OK)
			return st;
	}
	if (is.peek() == '\n')
		is.ignore();

	return OK;
}

void print_line (Array<Complex> & v, ostream & os)
{
	size_t size = v.getSize();
	for (size_t i = 0; i < size; i++)
		os << v[i] << ' ';
	os << '\n';
}