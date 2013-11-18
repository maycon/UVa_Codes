/**
 * Ecological Premium
 * URL: http://uva.onlinejudge.org/external/103/10300.html
 * Author: Maycon Maia Vitali ( 0ut0fBound )
 */

#include <stdio.h>
 
int main(void)
{
	int t, f;
	int a, b, c;
	int s;
	
	scanf ("%d ", &t);
	while (t--)
	{
		scanf ("%d ", &f);
		s = 0;
		while (f--)
		{
			scanf ("%d %d %d ", &a, &b, &c);
			s += a*c;
		}
		printf ("%d\n");
	}

	return 0;
}

