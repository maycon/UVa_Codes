/**
 * Problem: UVa 10189 - Minesweeper
 * Author: Maycon Maia Vitali ( mayconmaia at yahoo dot com dot br )
 * URL: http://uva.onlinejudge.org/external/101/10189.html
 */
#include <stdio.h>

#define MAX 102

int main(void)
{
	int campo[MAX][MAX];
	int i, j;
	int n, m;
	int t;
	char c;

	t = 0;
	while(1)
	{
		scanf ("%d %d ", &n, &m);
		if (!n || !m)
			break;

        if (t)
            printf ("\n");

		for (i = 0; i < n+1; i++)
			for (j = 0; j < m+1; j++)
				campo[i][j] = 0;

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				scanf("%c ", &c);

				if (c == '*')
				{
					/* Superior */
					if (campo[i-1][j-1] != -1) campo[i-1][j-1]++;
					if (campo[i-1][j] != -1) campo[i-1][j]++;
					if (campo[i-1][j+1] != -1) campo[i-1][j+1]++;

					/* Laterais */
					if (campo[i][j-1] != -1) campo[i][j-1]++;
					if (campo[i][j+1] != -1) campo[i][j+1]++;


					/* Inferior */
					if (campo[i+1][j-1] != -1) campo[i+1][j-1]++;
					if (campo[i+1][j] != -1) campo[i+1][j]++;
					if (campo[i+1][j+1] != -1) campo[i+1][j+1]++;

					/* Marco a posicao da mina */
					campo[i][j] = -1;
				}
			}
		}

		/* Imprimo o mapa do campo */
		printf ("Field #%d:\n", ++t);
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (campo[i][j] != -1)
				   printf ("%d", campo[i][j]);
				else
					putc('*', stdout);
			}
			printf ("\n");
		}
	}

	return 0;

}
