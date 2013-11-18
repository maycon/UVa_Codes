/**
 * Problem: UVa 113 - Power of Cryptography
 * Author: Maycon Maia Vitali ( mayconmaia at yahoo dot com dot br )
 * URL: http://uva.onlinejudge.org/external/1/113.html
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

const long double EPS = 1e-6;
const long double INF = 0x7f7f7f7f;

int cmp(long double x, long double y, long double tol)
{
	return (x <= y+tol) ? (y > x+tol) ? -1 : 0 : 1;
}


long double logpq(long double p, long double q, long double i, long double f, long double tol)
{
	long double m, r;

	m = (i + f)/2;
	r = pow(p, m);

	printf ("(%.03Lf %.03Lf %.03Lf) %.03Lf^%.03Lf=%.03Lf\n", i, m, f, p, m, r);
	
	if ((f - i) <= 0)
		return 0;


	if (cmp(r, q, tol) == 0)
		return m;

	if (r > q)
		return logpq(p, q, i, m, tol);
	else
		return logpq(p, q, m, f, tol);
}


int main(void)
{
	long double p, n;
	long double base = 10;

	while (scanf("%Lf %Lf", &n, &p) != EOF)
	{
		printf ("%.Lf\n", log10(pow(p, 1/log10(n))));
		/*
		printf ("%.0Lf\n", pow(10, (log10(p) / n)));
		printf ("%.03Lf\n", pow(p, 1/n));
		printf ("%.0Lf\n", (long double)pow(p, 1/n));
		printf ("%.Lf\n", logpq(n, p, 0, pow(p, 1/n), 1e-1));
		*/
	}

	return 0;
}
