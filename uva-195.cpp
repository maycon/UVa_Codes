/**
 * Problem: UVa 195 - Anagram
 * Author: Maycon Maia Vitali ( mayconmaia at yahoo dot com dot br )
 * URL: http://uva.onlinejudge.org/external/1/195.html
 */

#include <iostream>
#include <algorithm>
#include <strings>

#define LEN 100

using namespace std;

int main(void)
{
	char word[LEN];
	int n, l;

	scanf ("%d", &n);
	while (n--)
	{
		scanf ("%s", word);
		l = strlen(word);

		sort(word, word+l);

		do 
		{
			printf ("%s\n", word);
		} while (next_permutation(word, word+l));
	}

	return 0;
}

