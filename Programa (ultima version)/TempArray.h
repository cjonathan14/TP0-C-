#include <cassert>
#include <iostream>
#include <stdio.h>
#include "err.h"


#define ARRAY_INIT_ALLOC 4
#define ARRAY_RESIZE_MULTIPLIER 2

#ifndef TempArray_h
#define TempArray_h


template <class T>
class Array
{
private:
unsigned int size;//cantidad elementos cargados
unsigned int alloc;//largo del array 
T *ptr;

void resize();
public:
Array();
Array( const Array<T> & ); 
~Array( ); 
unsigned int getSize( ) const; 
unsigned int getAlloc() const;
Array<T>&operator=( const Array<T> & ); 
bool operator==( const Array<T> & ) const; 
T &operator[ ](size_t);
//T &operator[ ]( int );
status_t load_vector(Array<T> &);
status_t load_vector(const T &);
void clean_vector();
};

template <class T>
Array<T>::Array()
{
ptr = new T[ARRAY_INIT_ALLOC];
size=0;
alloc=ARRAY_INIT_ALLOC;
}



template <class T>
Array<T>::Array( const Array<T> &init )
{
alloc=init.alloc ;
ptr = new T[ alloc ];
for ( unsigned int i = 0; i < init.size; i++ )
ptr[ i ] = init.ptr[ i ]; 
size=init.size;
}


template <class T>
Array<T>::~Array()
{
if (ptr)
delete [ ] ptr; 
}

template <class T>
unsigned int Array<T>::getAlloc() const { return alloc; }

template <class T>
unsigned int Array<T>::getSize() const { return size; }

template <class T>
Array<T>& Array<T>::operator=( const Array<T> &right )
{
if ( &right != this ) 
{ 
	if ( alloc != right.alloc )
	{
		T *aux; 
		aux=new T[ right.alloc ]; 
		delete [] ptr; 
		alloc =right.alloc ; 
		ptr=aux; 
		for ( unsigned int i = 0; i < right.size; i++ )
		ptr[ i ] = right.ptr[ i ]; 
	}	
	else 
	{
		for (unsigned int i = 0; i < right.size; i++ )
		ptr[ i ] = right.ptr[ i ]; 
	}
}
return *this;
}

template <class T>
bool Array<T>::operator==( const Array<T> &right ) const
{
if ( size != right.size )
return false; 
else
for ( unsigned int i = 0; i < size; i++ )
if ( ptr[ i ] != right.ptr[ i ] )
       return false; 

return true; 
}

template <class T>
T & Array<T>::operator [ ](size_t subscript )
{
size = size>(unsigned int)subscript+1? size:(unsigned int)subscript+1;
return ptr[ subscript ]; 
}




template <class T>
void Array<T>:: resize()
{
unsigned int newAlloc=alloc*ARRAY_RESIZE_MULTIPLIER;
T *NewArray =NULL ;

if((NewArray=new (std::nothrow) T[newAlloc]))
	{ 
	for(unsigned int i=0;i<alloc;i++)NewArray[i]=ptr[i];
	alloc=newAlloc;
	}
else
	{
	alloc=0;
	}
delete [] ptr;
ptr=NewArray;//si new falla ptr apunta a NULL
}


template <class T>
status_t Array<T>:: load_vector(const T &data)
{
status_t st=OK;

if(size<alloc)
	{
	ptr[size]=data;
	size++;
	}
else
{
	resize();
	if (ptr==NULL)	
		st=ERROR_OUT_OF_MEMORY;
	else
		{
		ptr[size]=data;
		size++;
		}
}

return st;
}

template <class T>
status_t Array<T>:: load_vector( Array<T> &data)
{
status_t st=OK;
unsigned int i;

if(size+data.getSize()<alloc)
	for(i=0;i<data.getSize() && st==OK ;i++)
		{st=load_vector(data[i]);}
else
{
	while(size+data.getSize()>alloc)
		{resize();}

	if (ptr==NULL)	
		st=ERROR_OUT_OF_MEMORY;
	else
		for(i=0;i<data.getSize() && st==OK;i++)
			{st=load_vector(data[i]);}
}
return st;
}


template <class T>
void Array<T>:: clean_vector()
{
	if (ptr)
		delete [ ] ptr;
	ptr = new T[ARRAY_INIT_ALLOC];
	size=0;
	alloc=ARRAY_INIT_ALLOC;
}

#endif