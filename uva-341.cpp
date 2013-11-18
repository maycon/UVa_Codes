/**
 * Problem UVa 341 - Non-Stop Travel
 * Url: http://online-judge.uva.es/p/v3/341.html
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

typedef int Weight;

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

void shortestPath(const Graph &g, int s,
        vector<Weight> &dist, vector<int> &prev) {

    int n = g.size();
    dist.assign(n, INF); dist[s] = 0;
    prev.assign(n, -1);
    priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"

    for (Q.push(Edge(-2, s, 0)); !Q.empty(); )
    {
        Edge e = Q.top(); Q.pop();
        if (prev[e.dst] != -1) continue;
        prev[e.dst] = e.src;

        FOR(f,g[e.dst]) {
            if (dist[f->dst] > e.weight+f->weight) {
                dist[f->dst] = e.weight+f->weight;
                Q.push(Edge(f->src, f->dst, e.weight+f->weight));
            }
        }
    }
}

vector<int> buildPath(const vector<int> &prev, int t) {
    vector<int> path;

    for (int u = t; u >= 0; u = prev[u])
        path.push_back(u);

    reverse(path.begin(), path.end());

    return path;
}

int main()
{
	int cases = 1;

	while (1)
	{
		int n, qt;
		int src, dst, weight;
		vector<Weight> dist;
		vector<int> prev, path;

		cin >> n;
		if (!n) break;
		
		Graph graph(n+1);
		
		for (src = 1; src <= n; src++)
		{
			cin >> qt;
			while (qt--)
			{
				cin >> dst >> weight;
				graph[src].push_back(Edge(src, dst, weight));
			}
		}
		
		cin >> src >> dst;
				
		shortestPath(graph, src, dist, prev);
		path = buildPath(prev, dst);
		
		cout << "Case " << cases++ << ": Path =";
		FOR (it,path) cout << " " << *it;
		cout << "; " << dist[dst] << " second delay" << endl;
	}
    return 0;
}
