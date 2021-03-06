#include "gtest/gtest.h"

#define M_PI 3.1415926535897932384626

extern "C" {
#include "cplx.h"
}

TEST(CplxInitCartesiano, InicializaReal)
{
	cplx x = cplx_init_cartesiano(1.0, 2.0);

	EXPECT_NEAR(1.0, x.real, 1e-10);
}

TEST(CplxInitCartesiano, InicializaImag)
{
	cplx x = cplx_init_cartesiano(1.0, 2.0);

	EXPECT_NEAR(2.0, x.imag, 1e-10);
}

TEST(CplxInitPolar, InicializaPuramenteReal)
{
	cplx x = cplx_init_polar(5.0, 0.0);

	EXPECT_NEAR(5.0, x.real, 1e-10);
	EXPECT_NEAR(0.0, x.imag, 1e-10);
}

TEST(CplxInitPolar, InicializaPuramenteImaginario)
{
	cplx x = cplx_init_polar(3.0, M_PI/2.0);

	EXPECT_NEAR(0.0, x.real, 1e-10);
	EXPECT_NEAR(3.0, x.imag, 1e-10);
}

TEST(CplxInitPolar, InicializaComplexo)
{
	cplx x = cplx_init_polar(sqrt(2.0), 5.0 * M_PI / 4.0);

	EXPECT_NEAR(-1.0, x.real, 1e-10);
	EXPECT_NEAR(-1.0, x.imag, 1e-10);
}

TEST(CplxReal, PuramenteReal)
{
	cplx x = cplx_init_cartesiano(2.0, 0.0);

	EXPECT_NEAR(2.0, cplx_real(x), 1e-10);
}

TEST(CplxReal, PuramenteImaginario)
{
	cplx x = cplx_init_cartesiano(0.0, 1.0);

	EXPECT_NEAR(0.0, cplx_real(x), 1e-10);
}

TEST(CplxReal, Complexo)
{
	cplx x = cplx_init_cartesiano(3.0, 4.0);

	EXPECT_NEAR(3.0, cplx_real(x), 1e-10);
}

TEST(CplxImag, PuramenteReal)
{
	cplx x = cplx_init_cartesiano(2.0, 0.0);

	EXPECT_NEAR(0.0, cplx_imag(x), 1e-10);
}

TEST(CplxImag, PuramenteImaginario)
{
	cplx x = cplx_init_cartesiano(0.0, 1.0);

	EXPECT_NEAR(1.0, cplx_imag(x), 1e-10);
}

TEST(CplxImag, Complexo)
{
	cplx x = cplx_init_cartesiano(3.0, 4.0);

	EXPECT_NEAR(4.0, cplx_imag(x), 1e-10);
}

TEST(CplxModulo, PuramenteReal)
{
	cplx x = cplx_init_polar(5.0, 0.0);

	EXPECT_NEAR(5.0, cplx_modulo(x), 1e-10);
}

TEST(CplxModulo, PuramenteImaginario)
{
	cplx x = cplx_init_polar(3.0, M_PI / 2.0);

	EXPECT_NEAR(3.0, cplx_modulo(x), 1e-10);
}

TEST(CplxModulo, Complexo)
{
	cplx x = cplx_init_polar(sqrt(2.0), 5.0 * M_PI / 4.0);

	EXPECT_NEAR(sqrt(2.0), cplx_modulo(x), 1e-10);
}

TEST(CplxFase, PuramenteReal)
{
	cplx x = cplx_init_polar(5.0, 0.0);

	EXPECT_NEAR(0.0, cplx_fase(x), 1e-10);
}

TEST(CplxFase, PuramenteImaginario)
{
	cplx x = cplx_init_polar(3.0, M_PI / 2.0);

	EXPECT_NEAR(M_PI / 2.0, cplx_fase(x), 1e-10);
}

TEST(CplxFase, Complexo)
{
	cplx x = cplx_init_polar(sqrt(2.0), 5.0 * M_PI / 4.0);
	double y = cplx_fase(x);

	while (y < 0.0)
	{
		y += 2.0 * M_PI;
	}

	EXPECT_NEAR(5.0 * M_PI / 4.0, y, 1e-10);
}

TEST(CplxSoma, PuramenteReal)
{
	cplx x = cplx_init_cartesiano(2.0, 0.0);
	cplx y = cplx_init_cartesiano(3.0, 0.0);
	
	cplx z = cplx_soma(x, y);

	EXPECT_NEAR(5.0, cplx_real(z), 1e-10);
	EXPECT_NEAR(0.0, cplx_imag(z), 1e-10);
}

TEST(CplxSoma, PuramenteImaginario)
{
	cplx x = cplx_init_cartesiano(0.0, -5.0);
	cplx y = cplx_init_cartesiano(0.0, 2.0);

	cplx z = cplx_soma(x, y);

	EXPECT_NEAR(0.0, cplx_real(z), 1e-10);
	EXPECT_NEAR(-3.0, cplx_imag(z), 1e-10);
}

TEST(CplxSoma, Complexo)
{
	cplx x = cplx_init_cartesiano(1.0, 2.0);
	cplx y = cplx_init_cartesiano(3.0, 4.0);

	cplx z = cplx_soma(x, y);

	EXPECT_NEAR(4.0, cplx_real(z), 1e-10);
	EXPECT_NEAR(6.0, cplx_imag(z), 1e-10);
}

TEST(CplxSubtracao, PuramenteReal)
{
	cplx x = cplx_init_cartesiano(2.0, 0.0);
	cplx y = cplx_init_cartesiano(3.0, 0.0);

	cplx z = cplx_subtracao(x, y);

	EXPECT_NEAR(-1.0, cplx_real(z), 1e-10);
	EXPECT_NEAR(0.0, cplx_imag(z), 1e-10);
}

TEST(CplxSubtracao, PuramenteImaginario)
{
	cplx x = cplx_init_cartesiano(0.0, -5.0);
	cplx y = cplx_init_cartesiano(0.0, 2.0);

	cplx z = cplx_subtracao(x, y);

	EXPECT_NEAR(0.0, cplx_real(z), 1e-10);
	EXPECT_NEAR(-7.0, cplx_imag(z), 1e-10);
}

TEST(CplxSubtracao, Complexo)
{
	cplx x = cplx_init_cartesiano(1.0, 2.0);
	cplx y = cplx_init_cartesiano(3.0, 5.0);

	cplx z = cplx_subtracao(x, y);

	EXPECT_NEAR(-2.0, cplx_real(z), 1e-10);
	EXPECT_NEAR(-3.0, cplx_imag(z), 1e-10);
}