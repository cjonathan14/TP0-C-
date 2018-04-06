#ifndef COMPLEX__H
#define COMPLEX__H

#include <iostream>

using namespace std;

class Complex{
	double _real, _imag;
public:
	//Constructors
	Complex();
	Complex(double);
	Complex(double, double);
	Complex(const Complex &);

	//Destroyer
	~Complex();

	//Getters
	double real() const;
	double imag() const;

	//Setters
	void SetReal(double);
	void SetImag(double);

	//Operators
	const Complex & operator=(const Complex &);
	const Complex & operator=(const double &);
	const Complex & operator*=(const Complex  &);
	const Complex & operator*=(const double &);
	const Complex & operator+=(const Complex &);
	const Complex & operator+=(const double &);
	const Complex & operator-=(const Complex &);
	const Complex & operator-=(const double &);

	Complex operator*(const Complex &);
	Complex operator*(const double &);
	Complex operator+(const Complex &);
	Complex operator+(const double &);
	Complex operator-(const Complex &);
	Complex operator-(const double &);
	Complex operator/(const double &);
	Complex operator/(const unsigned int &);

	bool operator==(const Complex &);
	bool operator==(const double &);
	bool operator!=(const Complex &);
	bool operator!=(const double &);

	//Operations
	static Complex exp_imag(double);

};

//Operators
Complex operator*(const double, const Complex &);
Complex operator+(const double, const Complex &);
Complex operator-(const double, const Complex &);
bool operator==(const double, const Complex &);
bool operator!=(const double, const Complex &);

//Opearations
Complex exp_imag(double);

//Streams
ostream &operator<<(ostream &os, const Complex &);
istream &operator>>(istream &is, Complex &);

#endif
