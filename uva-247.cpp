/**
 * Problem: UVa 247 - Calling Circles
 * Url: http://uva.onlinejudge.org/external/2/247.html
 *
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

void visit(const Graph &g, int v, vector< vector<int> >& scc,
      stack<int> &S, vector<bool> &inS,
      vector<int> &low, vector<int> &num, int& time)
{
    low[v] = num[v] = ++time;
    S.push(v); inS[v] = true;

    FOR(e, g[v])
    {
        int w = e->dst;
        if (num[w] == 0)
        {
            visit(g, w, scc, S, inS, low, num, time);
            low[v] = min(low[v], low[w]);
        } else if (inS[w])
            low[v] = min(low[v], num[w]);
    }

    if (low[v] == num[v])
    {
        scc.push_back(vector<int>());
        while (1)
        {
            int w = S.top(); S.pop(); inS[w] = false;
            scc.back().push_back(w);
            if (v == w) break;
        }
    }
}

void stronglyConnectedComponents(const Graph& g, vector< vector<int> >& scc) {
    const int n = g.size();
    vector<int> num(n), low(n);
    stack<int> S;
    vector<bool> inS(n);
    int time = 0;

    REP(u, n) if (num[u] == 0)
        visit(g, u, scc, S, inS, low, num, time);
}

int getid(map<string, int> &m1, string &s)
{
	int &r = m1[s];
	if (r == 0)	r = m1.size();
	return r - 1;
}

bool OrdenaPeloPrimeiro(const vector<int> &a, const vector<int> &b)
{
	return a[0] < b[0];
}

int main()
{
	int n, m;
	int t = 0;
	int first = 1;
	

	while (1)
	{
		cin >> n >> m;
		if (!n && !m) break;
		
		if (!first) { cout << endl; first = 0; }

	
		map<string, int> nomes;
		
		string nome1, nome2;
		int id_src, id_dst;
		
		Graph graph(n);
		vector<string> nomes_id(n);
		vector< vector<int> > scc;
		
		while (m--)
		{
			cin >> nome1 >> nome2;	
			id_src = getid(nomes, nome1);
			id_dst = getid(nomes, nome2);
			graph[id_src].push_back(Edge(id_src, id_dst, 1));
		}

		FOR(it,nomes)
			nomes_id[it->second-1] = it->first;
			
		stronglyConnectedComponents (graph, scc);

		for (int i = 0; i < scc.size(); i++)
			sort(scc[i].begin(), scc[i].end());
		
		sort(scc.begin(), scc.end(), OrdenaPeloPrimeiro);
		
		cout << "Calling circles for data set " << ++t << ":" << endl;
		for (int i = 0; i < scc.size(); i++)
		{
			int size = scc[i].size();
			for (int j = 0; j < size; j++)
			{
				cout << nomes_id[scc[i][j]];
				if (j < (size-1)) cout << ", ";
			}
			cout << endl;
		}		
	}
	
	return 0;
}
