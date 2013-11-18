/**
 * Problem .: Hashmat the brave warrior (UVa #10055)
 * Address .: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=94&page=show_problem&problem=996
 * Author ..:  Maycon Maia Vitali ( mayconmaia at yahoo dot com dot br )
 */

#include <stdio.h>

#define ull unsigned long long
#define ABS(x) ((ull)(x) < 0 ? -(x) : (x))

int main(void)
{
	ull a, b;

	while (scanf ("%lli %lli ", &a, &b) != EOF)
	{
        printf ("%lli\n", labs(b - a));
	}

	return 0;
}
