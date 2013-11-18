/**
 * 
 */
#include <iostream>

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

#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>

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
    return e.weight != f.weight ? e.weight < f.weight : // !!INVERSE!!
        e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

struct UndirectionalCompare {
    bool operator() (const Edge& e, const Edge& f) const {
        if (min(e.src,e.dst) != min(f.src,f.dst))
            return min(e.src,e.dst) < min(f.src,f.dst);
        return max(e.src,e.dst) < max(f.src,f.dst);
    }
};

typedef set<Edge, UndirectionalCompare> Edgeset;

void visit(const Graph &g, int v, int u,
        vector<int>& art, vector<Edgeset>& bcomp,
        stack<Edge>& S, vector<int>& num, vector<int>& low, int& time)
{
    low[v] = num[v] = ++time;
    FOR(e, g[v]) {
        int w = e->dst;
        if (num[w] < num[v]) S.push(*e);              // for bcomps

        if (num[w] == 0) {
            visit(g, w, v, art, bcomp, S, num, low, time);
            low[v] = min(low[v], low[w]);

            if ((num[v] == 1 && num[w] != 2) ||         // for arts
                (num[v] != 1 && low[w] >= num[v])) art.push_back(v);

            if (low[w] >= num[v]) {                     // for bcomps
                bcomp.push_back(Edgeset());
                while (1) {
                    Edge f = S.top(); S.pop();
                    bcomp.back().insert(f);
                    if (f.src == v && f.dst == w) break;
                }
            }
        } else low[v] = min(low[v], num[w]);
    }
}

void articulationPoint(const Graph& g,
        vector<int>& art, vector<Edgeset>& bcomp) {

    const int n = g.size();
    vector<int> low(n), num(n);
    stack<Edge> S;
    REP(u, n) if (num[u] == 0)
    {
        int time = 0;
        visit(g, u, -1, art, bcomp, S, num, low, time);
    }
}

int main() {
	int n, m, x, y, i, j;
	
	while (1)
	{
		cin >> n >> m;
		if (!n && !m) break;
		
		Graph g(n);
		vector<int> art;
		vector<Edgeset> bcomp;
		
		while (1)
		{
			cin >> x >> y;
			if ((x == -1) && (y == -1)) break;
			g[x].push_back(Edge(x, y, 1));
			//g[y].push_back(Edge(y, x, 1));
		}
		
		for (i = 0; i < g.size(); i++)
		{
			cout << i << " ->";
			FOR(e, g[i])
				cout << " " << e->dst;
			cout << endl;
		}
		cout << endl;

		articulationPoint(g, art, bcomp);

		FOR(it, art)
			cout << *it << " ";
		cout << endl << endl;

		vector<int> acum(n);
		
		cout << bcomp.size() << endl << "-------" << endl;
		FOR(it, bcomp)
		{
			FOR(it2, *it)
			{
				cout << "(" << (*it2).src << " " << (*it2).dst << ") ";
				acum[(*it2).src]++;
				acum[(*it2).dst]++;
			}
			cout << endl;				
		}
		cout << endl;				
		
		for (i = 0; i < acum.size(); i++)
			cout << acum[i] << " ";
		cout << endl << endl;

	}

}
