/**
 * Problem: UVa 414 - Machined Surfaces
 * Author: Maycon Maia Vitali ( maycon at yahoo dot com dot br )
 * URL: http://uva.onlinejudge.org/external/4/414.html
 */

#include <stdio.h>
#include <string.h>

#define MIN(x,y) ((x) < (y) ? (x) : (y))

#define LEN 25
#define MAXLN 13

int main(void)
{
	int n, i;
	char c[LEN+1];
	int d[MAXLN], r;
	int l1, l2;
	int m;
	
	while (1)
	{
		scanf ("%d", &n);
		if (!n) break;
		
		m = LEN+1;

		for (i = 0; i < n; i++)
		{
			scanf ("%s", c);
			l1 = strlen(c);
			
			if (l1 < LEN)
			{
				scanf ("%s", c);
				l2 = strlen(c);
			}
			else
				l2 = 0;
			
			d[i] = LEN - (l1 + l2);
			m = MIN(m, d[i]);
		}

		for (i = 0, r = 0; i < n; i++)
			r += (d[i] - m);
			
		printf ("%d\n", r);
		
	}
	
	return 0;
}

 
