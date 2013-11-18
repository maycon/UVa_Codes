/**
 * Problem: UVa 10110 - Light, more light
 * Author: Maycon Maia Vitali ( mayconmaia at yahoo dot com dot br )
 * URL: http://uva.onlinejudge.org/external/101/10110.html
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
	long double n=0, sqr=0;

	while (1)
	{
		scanf("%Lf", &n);
		
		if (n == 0)
			return 0;

		sqr = ceil( sqrt( n ) );
		printf ("%s\n", ( sqr * sqr != n ) ? "no" : "yes");
	}

	return 0;
}

