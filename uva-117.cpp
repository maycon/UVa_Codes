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

#define TAM 27

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

void visit(const Graph &g, vector< vector<int> > &adj, int s, vector<int> &path) {
  FOR(e, g[s]) if (adj[e->src][e->dst]) {
    --adj[e->src][e->dst];
    --adj[e->dst][e->src];
    visit(g, adj, e->dst, path);
  }
  path.push_back(s);
}

bool eulerPath(const Graph &g, int s, vector<int> &path) {
    int n = g.size();
    int odd = 0, m = 0;
    REP(i, n) {
        if (g[i].size() % 2 == 1) ++odd;
		m += g[i].size();
	}
	m /= 2;
	if (odd == 0 || (odd == 2 && g[s].size() % 2 == 0)) {
		vector< vector<int> > adj(n, vector<int>(n));
		REP(u, n) FOR(e, g[u]) ++adj[e->src][e->dst];
		path.clear();
		visit(g, adj, s, path);
		reverse(ALL(path));
		return path.size() == m + 1;
	}
	return false;
}

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
	string street;
	int src, dst, weight;

	while (!feof(stdin))
	{
		Graph graph(TAM);
		int G[TAM][TAM];

		vector<int> path;
		int result = 0;
		
		memset(G, 0, sizeof(G));
		
		result = 0;
		while (1)
		{
			cin >> street;
			if (!street.compare("deadend")) break;
			
			weight = street.size();
			src = street[0] - 'a';
			dst = street[weight-1] - 'a';
			
			graph[src].push_back(Edge(src, dst, weight));
			graph[dst].push_back(Edge(dst, src, weight));
			G[src][dst] = G[dst][src] = weight;
			
			result += weight;			
		}
		
		int src = -1, dst = -1;
		FOR(it, graph)
		{
			int grau = it->size();
			
			if (grau % 2)
				if (src == -1) src = (*it)[0].src;
				          else dst = (*it)[0].src;
		}
		
		cout << "src = " << src << " / dst = " << dst << endl;
		
		if (src == -1)
		{
			cout << result << endl;
			continue;
		}

		result = 0;
		eulerPath(graph, src, path);
		for (int i = 1; i < path.size(); i++)
		{
			cout << char('a' + path[i-1]) << " " << char('a' + path[i]) << " " << G[path[i-1]][path[i]] << endl;
			result += G[path[i-1]][path[i]];
		}
		cout << "Euler: " << result << endl;
		
		vector<Weight> dist;
		vector<int> prev;
		
		shortestPath(graph, src, dist, prev);
		result = 0;
		for (int i = 0; i < dist.size(); i++)
		{
			if (dist[i] != INF)
			{
				cout << dist[i] << " " << prev[i] << endl;
				result += dist[i];
			}
		}
		cout << "Dijkstra: " << result << endl;

		cout << "-----------------------" << endl;
	}
	
    return 0;
}
