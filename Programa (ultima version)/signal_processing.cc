#include "signal_processing.h"

status_t dft( Array<Complex> & input_vector, Array<Complex> & output_vector)
{
status_t st=OK;
unsigned int i,j;
unsigned int size;
Complex acum,coef;

if(output_vector.getSize() != 0)
	st=ERROR_INVALID_OUTPUT_VECTOR;
if(input_vector.getSize()!=0){
	size = input_vector.getSize();
	for(i = 0 ; i < size ; i++)
	{
		acum.SetImag(0);
		acum.SetReal(0);
		for( j = 0; j < size ; j++)
		{
			acum+=input_vector[j]*exp_imag(-2*PI*i*j/size);
		}
		if(output_vector.load_vector(acum)!=OK)
			st = ERROR_OUT_OF_MEMORY;
	}	
}

return st;
}


status_t idft( Array<Complex> & input_vector, Array<Complex> & output_vector)
{
status_t st=OK;
unsigned int i,j;
unsigned int size;
Complex acum,coef;

if(output_vector.getSize() != 0)
	st = ERROR_INVALID_OUTPUT_VECTOR;
if(input_vector.getSize()!=0){
	size = input_vector.getSize();
	for(i = 0 ; i < size ; i++)
	{
		acum.SetImag(0);
		acum.SetReal(0);
		for(j = 0 ; j < size ; j++)
		{
			acum += input_vector[j]*exp_imag(2*PI*i*j/size);
		}
		if(output_vector.load_vector(acum/size)!=OK)
			st=ERROR_OUT_OF_MEMORY;
	}	
}


return st;
}




