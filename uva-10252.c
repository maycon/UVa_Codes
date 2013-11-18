/**
 * Problem: UVa 10252 - Common Permutation
 * Author: Maycon Maia Vitali ( mayconmaia at yahoo dot com dot br )
 * URL: http://uva.onlinejudge.org/external/102/10252.html
 */

#include <stdio.h>

#define LEN_ALFA 26

#define MIN(a,b) ((a) < (b) ? (a) : (b))

int main(void)
{
	short int letras[2][LEN_ALFA];
	char c;
	int w;

	memset (letras, 0, sizeof(letras));

	w = 0;

	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')
		{
			if (w)
			{
				int i, l;

				for (i = 0; i < LEN_ALFA; i++)
				{
					char ch = 'a' + i;
					l = MIN(letras[0][i], letras[1][i]);
					while (l--) putc(ch, stdout);
				}

				memset (letras, 0, sizeof(letras));
			}

			w = 1 - w;
			
		}
		else
		{
			letras[w][c - 'a']++;
		}
	}
}
