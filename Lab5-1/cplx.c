#include <math.h>
#include "cplx.h"

cplx cplx_init_cartesiano(double real, double imag)
{
	cplx res = { real, imag };

	return res;
}

cplx cplx_init_polar(double modulo, double fase)
{
	cplx res;
	
	res.real = modulo*cos(fase);
	res.imag = modulo*sin(fase);

	return res;
}

double cplx_real(cplx arg)
{
	return arg.real;
}

double cplx_imag(cplx arg)
{
	return arg.imag;
}

double cplx_modulo(cplx arg)
{
	return sqrt(arg.real*arg.real + arg.imag*arg.imag);
}

double cplx_fase(cplx arg)
{
	return atan2(arg.imag, arg.real);
}

cplx cplx_soma(cplx arg1, cplx arg2)
{
	cplx res;

	res.real = arg1.real + arg2.real;
	res.imag = arg1.imag + arg2.imag;

	return res;
}

cplx cplx_subtracao(cplx arg1, cplx arg2)
{
	cplx res;

	res.real = arg1.real - arg2.real;
	res.imag = arg1.imag - arg2.imag;

	return res;
}