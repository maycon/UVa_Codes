/**
 * Problem: UVa 108 - Maximum Sum
 * Author: Maycon Maia Vitali ( mayconmaia at yahoo dot com dot br )
 * URL: http://uva.onlinejudge.org/external/1/108.html
 */

#include <stdio.h>
#include <string.h>

#define LEN 101
#define INF 0x7f7f7f7f

#define MAX(a,b) ((a) > (b) ? (a) : (b))


int max_sum_array(int *v, int n)
{
	int max = -INF, curr, i;

	for (i = 0, curr = 0; i < n; i++)
	{
		curr += v[i];
		max  = MAX(max, curr);
		curr = MAX(0, curr);
	}

	return max;
}

int max_sum_matrix(int v[LEN][LEN], int n)
{
	int max = -INF;
	int sum[LEN], curr;
	int i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			sum[j] = 0;

		for (j = i; j < n; j++)
		{
			for (k = 0; k < n; k++)
				sum[k] += v[j][k];

			curr = max_sum_array(sum, n);
			max = MAX(max, curr);
		}

	}

	return max;
}

int main(void)
{
	int M[LEN][LEN];
   	int n, i, j;

	scanf ("%d", &n);

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf ("%d", &M[i][j]);


	printf ("%d\n", max_sum_matrix(M, n));

	return 0;
}

