/**
 * Problem: UVa 706 - LCD Display
 * http:/*uva.onlinejudge.org/external/7/706.html
 * Author: Maycon Maia Vitali ( mayconmaia at yahoo dot com dot br )
 */

#include <stdio.h>
#include <string.h>

char seg[10][7] = {
	{1, 1, 1, 0, 1, 1, 1}, /* 0 */
	{0, 0, 1, 0, 0, 1, 0}, /* 1 */
	{1, 0, 1, 1, 1, 0, 1}, /* 2 */
	{1, 0, 1, 1, 0, 1, 1}, /* 3 */
	{0, 1, 1, 1, 0, 1, 0}, /* 4 */
	{1, 1, 0, 1, 0, 1, 1}, /* 5 */
	{1, 1, 0, 1, 1, 1, 1}, /* 6 */
	{1, 0, 1, 0, 0, 1, 0}, /* 7 */
	{1, 1, 1, 1, 1, 1, 1}, /* 8 */
	{1, 1, 1, 1, 0, 1, 1}  /* 9 */
};

void nputc(char c, int n)
{
	int i;
	for (i = 0; i < n; i++) putc(c, stdout);
}

int main(void)
{
	int s, l, i, j, k;
	char n[10];

	while (1)
	{
		scanf ("%d %s", &s, n);
		
		if (!s)
			break;
		
		l = strlen(n);
		i = 0;
		while (i < 7)
		{
			if ((i % 3) == 0)
			{
				for (j = 0; j < l; j++)
				{
					putc(' ', stdout);
					nputc(seg[n[j] - '0'][i] ? '-' : ' ' , s);
					putc(' ', stdout);
					if (j != (l - 1)) putc(' ', stdout);
				}
				printf ("\n");
				i++;
			}
			else
			{
				for (k = 0; k < s; k++)
				{
					for (j = 0; j < l; j++)
					{
						putc(seg[n[j] - '0'][i] ? '|' : ' ' , stdout);
						nputc(' ' , s);
						putc(seg[n[j] - '0'][i+1] ? '|' : ' ' , stdout);
						if (j != (l - 1)) putc(' ', stdout);
					}
					printf ("\n");
				}
				i += 2;
			}
		}
		
		printf ("\n");
		
	}

	return 0;
}

