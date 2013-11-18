#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

#define NMAX 3001

int main(void) {
	int n, m[NMAX][2];
	int dp[NMAX][NMAX];
	

	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++) {
			scanf ("%d %d", &m[i][0], &m[i][1]);
		}

		for (int i = 0; i < n; i++)
			for (int j = m[i][0]; j <= n; j++)
				dp[i][j] = 1;
	}

	return 0;
}

