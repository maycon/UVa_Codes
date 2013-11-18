/**
 * Problem: 10082 - WERTYU
 * URL: http://uva.onlinejudge.org/external/100/10082.html
 * Author: Maycon Maia Vitali ( mayconmaia at yahoo dot com dot br )
 */

#include <stdio.h>

char keytable[] = {
	';', '@', '@', '@', '@', 'M', '0', ',', '.', '9', '`', '1', '2', '3',
	'4', '5', '6', '7', '8', '@', 'L', '@', '-', '@', '@', '@', '@', 'V',
	'X', 'S', 'W', 'D', 'F', 'G', 'U', 'H', 'J', 'K', 'N', 'B', 'I', 'O',
	'@', 'E', 'A', 'R', 'Y', 'C', 'Q', 'Z', 'T', '@', 'P', ']', '['
};

int main(void)
{
	char c;

	while(scanf("%c", &c) != EOF)
		putc(((c == ' ') || (c == '\n')) ? c : keytable[c-'\''], stdout);
	printf ("\n");
	
	return 0;
}
