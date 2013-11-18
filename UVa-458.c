/**
 * 458 - The Decoder
 * URL: http://uva.onlinejudge.org/external/4/458.html
 * Author: Maycon Maia Vitali ( 0ut0fBound )
 */

#include <stdio.h>

int main(void)
{
	char c;
	
	while (scanf ("%c", &c) != EOF)
	{
		putc(((c == '\r') || (c == '\n')) ? c : c - 7, stdout);
	}
	
	return 0;
}
