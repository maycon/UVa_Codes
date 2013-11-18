/**
 * UVa 10449 - Traffic
 * Url: http://uva.onlinejudge.org/external/104/10449.html
 * Author: Maycon Maia Vitali
 * Contact: maycon.ppgi.ufes at gmail dot com
 */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>

#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>


using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define INF 0x3f3f3f3f

typedef long long Weight;

struct Edge {
    int src, dst;
    Weight weight;
    Edge(int src, int dst, Weight weight) :
        src(src), dst(dst), weight(weight) { }
};

bool operator < (const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
        e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

bool shortestPath(const Graph g, int s,
        vector<Weight> &dist, vector<int> &prev)
{
    int n = g.size();
    dist.assign(n, INF+INF); dist[s] = 0;
    prev.assign(n, -2);
    bool negative_cycle = false;
    REP(k, n) REP(i, n) FOR(e,g[i])
    {
        if (dist[e->dst] > dist[e->src] + e->weight)
        {
            dist[e->dst] = dist[e->src] + e->weight;
            prev[e->dst] = e->src;
            if (k == n-1)
            {
                dist[e->dst] = -INF;
                negative_cycle = true;
            }
        }
    }
    return !negative_cycle;
}

vector<int> buildPath(const vector<int> &prev, int t)
{
  vector<int> path;

  for (int u = t; u >= 0; u = prev[u])
      path.push_back(u);
  reverse(path.begin(), path.end());

  return path;
}

long long cube (int v) { return v*v*v; }

int main()
{
	int n;
	int test = 1;

	while (scanf("%d", &n) == 1)
	{
		Graph graph(n);
		vector<Weight> dist;
		vector<int> prev;

		vector<int> busylist;
		int busyness, edges, src, dst;
		
		REP(i,n)
		{
			scanf ("%d", &busyness);
			busylist.push_back(busyness);
		}
		
		scanf ("%d", &edges);
		while (edges--)
		{
				scanf ("%d %d", &src, &dst);
				src--; dst--;
				graph[src].push_back(Edge(src, dst, cube(busylist[dst] - busylist[src])));
		}
		
		shortestPath(graph, 0, dist, prev);
		int querys;
		
		printf ("Set #%d\n", test++);
		scanf ("%d", &querys);
		while (querys--)
		{
			scanf ("%d", &dst);
			Weight distance = dist[dst-1];
			
			if ((distance < 3) || (distance == INF+INF))
				printf ("?\n");
			else
				printf ("%lld\n", distance);
		}
	}

    return 0;
}
