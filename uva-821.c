/**
 * Problem: UVa 821 - Page Hopping
 * Author: Maycon Maia Vitali ( mayconmaia at yahoo dot com dot br )
 * URL: http://uva.onlinejudge.org/external/8/821.html
 */

#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define LEN 101


int main(void)
{
	int M[LEN][LEN], p[LEN], d[LEN][LEN];	
	int a, b, n, t;
	
	int i, j, k;

	while (1)
	{
		n = 0;
		memset (M, 0x00, sizeof(M));
		
		scanf ("%d %d", &a, &b);
		
		if (!a && !b)
		{
			break;
		}
		
		M[a][b] = 1;
		n = MAX(n, MAX(a,b));
		
		while (scanf ("%d %d", &a, &b) && !a && !b)
		{
			M[a][b] = 1;
			n = MAX(n, MAX(a,b));
		}
			
		/* Floyd-Warshall                                 */
		/*------------------------------------------------*/
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (M[i][j]) p[j] = i;
		
		memset (d, 0x7f, sizeof(d));

		for (k = 1; k <= n; k++)
		{
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n; j++)
				{
					t = d[i][k] + d[k][j];
					
					if (d[i][j] > t) d[i][j] = t;
				}
			}
		}
	}
}