/**
 * Problem: UVa 796 - Critical Links
 * Url: http://uva.onlinejudge.org/external/7/796.html
 * Author: Maycon Maia Vitali
 * Contact: 
 */

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <list>

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
    Edge(int src, int dst) :
        src(src), dst(dst) { weight = 1; }

};

bool operator < (const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight < f.weight : // !!INVERSE!!
        e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

void visit(const Graph & g, int v, int u,
        Edges& brdg, vector< vector<int> >& tecomp,
        stack<int>& roots, stack<int>& S, vector<bool>& inS,
        vector<int>& num, int& time)
{
    num[v] = ++time;
    S.push(v); inS[v] = true;
    roots.push(v);
    FOR(e, g[v])
    {
        int w = e->dst;
        if (num[w] == 0)
            visit(g, w, v, brdg, tecomp, roots, S, inS, num, time);
        else if (u != w && inS[w])
            while (num[roots.top()] > num[w]) roots.pop();
    }
    if (v == roots.top())
    {
		if (u < v)
			brdg.push_back(Edge(u, v));
		else
			brdg.push_back(Edge(v, u));
			
        tecomp.push_back(vector<int>());

        while (1)
        {
            int w = S.top(); S.pop(); inS[w] = false;
            tecomp.back().push_back(w);
            if (v == w) break;
        }
        roots.pop();
    }
}

void bridge(const Graph& g, Edges& brdg, vector< vector<int> >& tecomp)
{
    const int n = g.size();
    vector<int> num(n);
    vector<bool> inS(n);
    stack<int> roots, S;
    int time = 0;

    REP(u, n) if (num[u] == 0) {
        visit(g, u, n, brdg, tecomp, roots, S, inS, num, time);
        brdg.pop_back();
    }
}

int main()
{
}


