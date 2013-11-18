/**
 * Problem: 494 - Kindergarten Counting Game
 * Author: Maycon Maia Vitali ( mayconmaia at yahoo dot com dot br )
 * URL: http://uva.onlinejudge.org/external/4/494.html
 */
 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WORD_LEN 4096

int main(void)
{
	int n, a, l, i;
	char w[WORD_LEN];

	n = 0;
	while (scanf("%[A-Za-z]s", w) != EOF)
	{
		l = strlen(w);
		
		for (i = 0, a = 0; (i < l) && !a; i++)
		{
			a = (isalnum(w[i]) != 0);
		}
		n += a;
		
		if (scanf("%[^A-Za-z]s", w))
		{
			if (strchr(w, '\r') ||  strchr(w, '\n'))
			{
				printf ("%d\n", n);
				n = 0;
				a = 0;
			}
		}
	}
	
	printf ("%d\n", n);

	return 0;
}

