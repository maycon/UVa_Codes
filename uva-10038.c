/**
 * Problem: 10038 - Jolly Jumpers 
 * URL: http://uva.onlinejudge.org/external/100/10038.html
 * Author: Maycon Maia Vitali ( mayconmaia@yahoo.com.br )
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define MAX 3000

int main(void)
{
	int n, q;
	int i;
	int a, b, c;
	int v[MAX];

	while (scanf ("%d", &n) != EOF)
	{
		
		memset(v, 0, sizeof(v));
		
		q = 0;
		scanf ("%d", &a);
		for (i = 1; i < n; i++)
		{
			scanf ("%d", &b);
			
			c = abs(a - b);
			q += ((c < n) && (v[c] == 0));
			v[c] = 1;
			
			a = b;
		}
		
		printf ("%s\n", (q == (n - 1) ? "Jolly" : "Not jolly"));
	}

	return 0;
}
