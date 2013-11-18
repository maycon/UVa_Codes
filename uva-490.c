/**
 * Problem: 490 - Rotating Sentences
 * Author: Maycon Maia Vitali ( maycon at yahoo dot com dot br )
 * URL: http://uva.onlinejudge.org/external/4/490.html
 */
 
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define LEN 100

int main(void)
{
	char c[LEN+1][LEN+1];
	int n = 0, m = 0;
	int i, j;
	
	memset(c, 0, sizeof(c));

	while(scanf("%[^\r\n]", c[n]) != EOF)
	{
		m = MAX(m, strlen(c[n]));
		n++;
		
		scanf("%*[\r\n]");
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%c", (isprint(c[i][j]) ? c[i][j] : ' '));
		}
		printf ("\n");
	}
	
	return 0;
}

