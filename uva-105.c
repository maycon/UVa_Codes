/**
 * Problem: UVa 105 - The Skyline Problem
 * Author: Maycon Maia Vitali ( mayconmaia at yahoo dot com dot br )
 * URL: http://uva.onlinejudge.org/external/1/105.html
 */

#include <stdio.h>
#include <string.h>

#define LEN 10001

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main(void)
{
	int v[LEN];
	int l, h, r;
	int i;

	memset(v, 0, sizeof(v));

	while (scanf("%d %d %d\n", &l, &h, &r) != EOF)
	{
		for (i = l; i < r; i++)
			v[i] = MAX(v[i], h);
	}

	h = 0;
	for (i = 1; i < LEN; i++)
	{
		if (v[i] != h)
		{
			if (h) printf (" ");
			printf ("%d %d", i, v[i]);
			h = v[i];
		}
	}
	printf ("\n");

	return 0;

}

