#pragma once

struct complexo
{
	double real, imag;
};

typedef struct complexo cplx;

cplx cplx_init_cartesiano(double real, double imag);
cplx cplx_init_polar(double modulo, double fase);
double cplx_real(cplx arg);
double cplx_imag(cplx arg);
double cplx_modulo(cplx arg);
double cplx_fase(cplx arg);
cplx cplx_soma(cplx arg1, cplx arg2);
cplx cplx_subtracao(cplx arg1, cplx arg2);