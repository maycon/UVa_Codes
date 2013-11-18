#define _GLIBCXX_DEBUG

#include <iostream>
#include <vector>
#include <queue>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define EXP_LEN 40
#define MAX_GRAU 20
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define C2D(c) ((c) - '0')
#define INF 0x3f3f3f3

using namespace std;

int max_number;

int somaPolinomios (int *p1, int g1, int *p2, int g2, int *p3)
{
	int i;
	int grau_result = MAX(g1, g2);
	int min = MIN(g1, g2);

	for (i = 0; i <= min; i++) p3[i] = p1[i] + p2[i];
	
	if (g1 > g2) for (; i <= g1; i++) p3[i] = p1[i];
	       else	 for (; i <= g2; i++) p3[i] = p2[i];

	return grau_result;
}

int subtraiPolinomios (int *p1, int g1, int *p2, int g2, int *p3)
{
	int i;
	int grau_result = MAX(g1, g2);
	int min = MIN(g1, g2);

	for (i = 0; i <= min; i++) p3[i] = p1[i] - p2[i];
	
	if (g1 > g2) for (; i <= g1; i++) p3[i] = p1[i];
	       else	 for (; i <= g2; i++) p3[i] = -p2[i];
	
	while ((p3[grau_result] == 0) && grau_result) grau_result--;

	return grau_result;
}

int multiplicaPolinomios (int *p1, int g1, int *p2, int g2, int *p3)
{
	int i, j;
	int grau_result = g1 + g2;

	for (i = 0; i <= grau_result; i++)
		p3[i] = 0;
	
	for (i = 0; i <= g1; i++)
		for (j = 0; j <= g2; j++)
			p3[i+j] += p1[i]*p2[j];

	return grau_result;
}

int adicionaPolinomioBase(int *polinomio, unsigned long long n)
{
	char s[EXP_LEN];
	int i, grau_result = 0, value;
	
	memset (polinomio, 0,  MAX_GRAU * sizeof(int));
	
	sprintf (s, "%lld%n", n, &grau_result);
	grau_result--;
	
	for (i = 0; i <= grau_result; i++)
	{
		value = C2D(s[i]);
		polinomio[grau_result - i] += value;
		max_number = MAX(value, max_number);
	}

	return grau_result;
}

int reduzPolinomio(int *polinomio, int grau)
{
	int i, reducao = 0;
	
	for (i = 0; (i <= grau) && (polinomio[i] == 0); i++);
	
	if (i)
	{
		reducao = i;
		while (i <= grau)
			polinomio[i - reducao] = polinomio[i++];
	}
	
	grau -= reducao;
	
	return (grau < 0 ? 0 : grau);
}

int criaPolinomio (char *expression, int *polinomio)
{
	unsigned long long number;
	char oper, *ptr;
	int poli_tmp1[MAX_GRAU], poli_tmp2[MAX_GRAU], poli_tmp3[MAX_GRAU];
	int grau1, grau2, grau3, len;
			
	ptr = expression;

	oper = '\0';
	if ((sscanf(ptr, "%lld%c%n", &number, &oper, &len) != -1) && oper)
	{
		grau1 = adicionaPolinomioBase(poli_tmp1, number);
		ptr += len;

nunca_pensei_que_fosse_utilizar_isso:

		if (oper == '+')
		{
			grau2 = criaPolinomio (ptr, poli_tmp2);
			return somaPolinomios(poli_tmp1, grau1, poli_tmp2, grau2, polinomio);
		}
		else if (oper == '=')
		{
			grau2 = criaPolinomio (ptr, poli_tmp2);
			return subtraiPolinomios(poli_tmp1, grau1, poli_tmp2, grau2, polinomio);
		}
		else if (oper == '*')
		{
			do
			{
				oper = '\0';
				sscanf(ptr, "%lld%c%n", &number, &oper, &len);
				if (!oper)
				{
					sscanf(ptr, "%lld%n", &number, &len);
					grau2 = adicionaPolinomioBase (poli_tmp2, number);
					return multiplicaPolinomios(poli_tmp1, grau1, poli_tmp2, grau2, polinomio);
				}

				grau2 = adicionaPolinomioBase(poli_tmp2, number);
				grau3 = multiplicaPolinomios(poli_tmp1, grau1, poli_tmp2, grau2, poli_tmp3);
				
				memcpy(poli_tmp1, poli_tmp3, sizeof(int)*(grau3+1));
				grau1 = grau3;

				ptr += len;

			} while (oper == '*');
			
			goto nunca_pensei_que_fosse_utilizar_isso;
		}
	}


	if (sscanf(ptr, "%lld%n", &number, &len) != -1)
	{
		return adicionaPolinomioBase (polinomio, number);
	}

	return 0;
}

bool raizValida (int *polinomio, int grau, int x)
{
	int i, div;
	
	for (i = 0, div = 0; i <= grau; i++)
	{
		div += polinomio[i];
		if (div % x != 0) return false;
		div /= x;
	}
	
	return (div == 0);
}

int main(void)
{
	char expression[EXP_LEN];
	int polinomio[MAX_GRAU], grau = 0;
	int i, j;

	while (1)
	{
		scanf ("%s", expression);
		if (!strcmp(expression, "=")) break;

		max_number = 0;
		grau = criaPolinomio (expression, polinomio);
		grau = reduzPolinomio (polinomio, grau);

		if (grau == 0)
		{
			if (polinomio[0])
				printf ("*\n");
			else
				printf ("%d+\n", max_number ? max_number+1 : 2);
		}
		else
		{
			vector<int> V;
			int a0, lim;

			a0 = polinomio[0];
			if (a0 < 0) a0 = -a0;
			lim = (int)sqrt(a0);

			for (i = 1; i <= lim; i++)
			{
				if (a0 % i == 0)
				{
					if (raizValida(polinomio, grau, (unsigned long long)i))
						V.push_back (i);
					
					if (raizValida(polinomio, grau, (unsigned long long)a0/i))
						V.push_back (a0/i);
				}
			}
			
			sort(V.begin(), V.end());

			int i = 0;
			while ((i < V.size()) && (V[i] <= max_number)) i++;
			
			if (i < V.size())
			{
				int raiz;
				while (i < V.size())
				{
					raiz = V[i];
					printf ("%d", raiz);
					while ((i < V.size()) && (V[i] == raiz))
						i++;
						
					if (i < V.size()) putc(' ', stdout);
				}
				printf ("\n");
			}
			else
				printf ("*\n");
/*		
			priority_queue<int, vector<int>, greater<int> > Q;
			int a0, lim;

			a0 = polinomio[0];
			if (a0 < 0) a0 = -a0;
			lim = (int)sqrt(a0);

			for (i = 1; i <= lim; i++)
			{
				if (a0 % i == 0)
				{
					if (raizValida(polinomio, grau, (unsigned long long)i))
						Q.push (i);
					
					if (raizValida(polinomio, grau, (unsigned long long)a0/i))
						Q.push (a0/i);
				}
			}
			
			while (Q.size() && (Q.top() <= max_number)) Q.pop();

			if (Q.size())
			{
				int raiz;
				while (Q.size())
				{
					raiz = Q.top();
					printf ("%d", raiz);
					while (Q.size() && (Q.top() == raiz))
						Q.pop();
						
					if (Q.size()) putc(' ', stdout);
				}
				printf ("\n");
			}
			else
				printf ("*\n");
*/
		}		

	}
	
	return 0;
}

