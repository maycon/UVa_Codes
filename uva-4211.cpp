#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>

#define EXP_LEN 50
#define MAX_GRAU 20
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define C2D(c) ((c) - '0')
#define INF 0x3f3f3f3

using namespace std;

int max_number;

void imprimePolinomio(int *polinomio, int grau)
{
	int i;
	
	printf ("[%d] ", grau);
	for (i = 0; i <= grau; i++)
		printf ("%d ", polinomio[i]);
	
	printf ("\n");
}

int somaPolinomios (int *p1, int g1, int *p2, int g2, int *p3)
{
	int i;
	int grau_result = MAX(g1, g2);
	int min = MIN(g1, g2);

	memset (p3, 0, MAX_GRAU * sizeof(int));

	for (i = 0; i <= min; i++) p3[i] = p1[i] + p2[i];
	
	if (g1 > g2) for (; i <= g1; i++) p3[i] = p1[i];
	       else	 for (; i <= g2; i++) p3[i] = p2[i];

#ifdef DEBUG
	printf (">>> Somando polinomios\n");
	printf ("==========================================\n");
	imprimePolinomio(p1, g1);
	imprimePolinomio(p2, g2);
	printf ("------------------------------------------\n");
	imprimePolinomio(p3, grau_result);
	printf ("==========================================\n");
#endif

	return grau_result;
}

int subtraiPolinomios (int *p1, int g1, int *p2, int g2, int *p3)
{
	int i;
	int grau_result = MAX(g1, g2);
	int min = MIN(g1, g2);

	memset (p3, 0,  MAX_GRAU * sizeof(int));

	for (i = 0; i <= min; i++) p3[i] = p1[i] - p2[i];
	
	if (g1 > g2) for (; i <= g1; i++) p3[i] = p1[i];
	       else	 for (; i <= g2; i++) p3[i] = -p2[i];
	
	while ((p3[grau_result] == 0) && grau_result) grau_result--;

#ifdef DEBUG
	printf (">>> Subtraindo polinomios\n");
	printf ("==========================================\n");
	imprimePolinomio(p1, g1);
	imprimePolinomio(p2, g2);
	printf ("------------------------------------------\n");
	imprimePolinomio(p3, grau_result);
	printf ("==========================================\n");
#endif

	return grau_result;
}

int multiplicaPolinomios (int *p1, int g1, int *p2, int g2, int *p3)
{
	int i, j;
	int grau_result = g1 + g2;
	
	memset (p3, 0,  MAX_GRAU * sizeof(int));
	
	for (i = 0; i <= g1; i++)
		for (j = 0; j <= g2; j++)
			p3[i+j] += p1[i]*p2[j];

#ifdef DEBUG
	printf (">>> multiplicando polinomios\n");
	printf ("==========================================\n");
	imprimePolinomio(p1, g1);
	imprimePolinomio(p2, g2);
	printf ("------------------------------------------\n");
	imprimePolinomio(p3, grau_result);
	printf ("==========================================\n");
#endif

	return grau_result;
}

int adicionaPolinomioBase(int *polinomio, int n)
{
	char s[EXP_LEN];
	int i, grau = 0;
	
	memset (polinomio, 0,  MAX_GRAU * sizeof(int));
	
	sprintf (s, "%d", n);
	grau = strlen(s) - 1;
	
	for (i = 0; i <= grau; i++)
	{
		polinomio[grau - i] += C2D(s[i]);
		max_number = MAX(polinomio[grau - i], max_number);
	}

#ifdef DEBUG
	printf ("Adiciona [%d] ao polinomio em grau %d\n", n, grau);
	imprimePolinomio(polinomio, grau);
#endif

	return grau;
}

int reduzPolinomio(int *polinomio, int grau)
{
	int i, reducao = 0;
	
	for (i = 0; (i <= grau) && (polinomio[i] == 0); i++);
	
	if (i)
	{
		reducao = i;
		while (i <= grau)
		{
			polinomio[i - reducao] = polinomio[i];
			i++;
		}
	}
	
	return grau-reducao;
}

int criaPolinomio (char *expression, int *polinomio)
{
	int number, len;
	char oper, *ptr;
	int poli_tmp1[MAX_GRAU], poli_tmp2[MAX_GRAU], poli_tmp3[MAX_GRAU];
	int grau1, grau2, grau3;
			
	memset (poli_tmp1, 0,  MAX_GRAU * sizeof(int));
	memset (poli_tmp2, 0,  MAX_GRAU * sizeof(int));
	memset (polinomio, 0,  MAX_GRAU * sizeof(int));

#ifdef DEBUG
	printf ("Criando polinomio de [%s]\n", expression);
#endif

	ptr = expression;

	oper = '\0';
	if ((sscanf(ptr, "%d%c%n", &number, &oper, &len) != -1) && oper)
	{
#ifdef DEBUG
		printf ("%s -> [%d] [%c] \n", ptr, number, oper);
#endif
		grau1 = adicionaPolinomioBase(poli_tmp1, number);
		ptr += len;

nunca_pensei_que_fosse_utilizar_isso_1:

		if (oper == '+')
		{
#ifdef DEBUG
			printf ("\nSOMA\n");
#endif
			grau2 = criaPolinomio (ptr, poli_tmp2);
			grau3 = somaPolinomios(poli_tmp1, grau1, poli_tmp2, grau2, polinomio);

			return grau3;
		}
		else if (oper == '=')
		{
#ifdef DEBUG
			printf ("\nSUBTRACAO\n");
#endif
			grau2 = criaPolinomio (ptr, poli_tmp2);
			grau3 = subtraiPolinomios(poli_tmp1, grau1, poli_tmp2, grau2, polinomio);
			return grau3;
		}
		else if (oper == '*')
		{
#ifdef DEBUG
			printf ("\nMULTIPLICACAO\n");
#endif			
			do
			{
#ifdef DEBUG
				printf ("Expressao = [%s]\n", ptr);
#endif
				oper = '\0';
				sscanf(ptr, "%d%c%n", &number, &oper, &len);
				if (!oper)
				{
					sscanf(ptr, "%d%n", &number, &len);
					grau2 = adicionaPolinomioBase (poli_tmp2, number);
					return multiplicaPolinomios(poli_tmp1, grau1, poli_tmp2, grau2, polinomio);
				}		
#ifdef DEBUG
				printf ("*** %s -> [%d] [%d] \n", ptr, number, oper);
#endif

				grau2 = adicionaPolinomioBase(poli_tmp2, number);
				grau3 = multiplicaPolinomios(poli_tmp1, grau1, poli_tmp2, grau2, poli_tmp3);
				
				memcpy(poli_tmp1, poli_tmp3, sizeof(int)*(grau3+1));
				grau1 = grau3;
#ifdef DEBUG
				imprimePolinomio(poli_tmp1, grau1);
				imprimePolinomio(poli_tmp3, grau3);
#endif
				ptr += len;

			} while (oper == '*');
			
#ifdef DEBUG
			printf ("diferente de '*'\n");
#endif
			goto nunca_pensei_que_fosse_utilizar_isso_1;
		}
	}

nunca_pensei_que_fosse_utilizar_isso_2:

	if (sscanf(ptr, "%d%n", &number, &len) != -1)
	{
#ifdef DEBUG
		printf ("** so tem um numero [%d]\n", number);
#endif
		memset (polinomio, 0,  MAX_GRAU * sizeof(int));
		return adicionaPolinomioBase (polinomio, number);
	}

}



double resolvePolinomio(int *polinomio, int grau, double x)
{
	int i;
	double result = 0;
	
	for (i = 0; i <= grau; i++)
	{
		result += polinomio[i]*pow(x, i);
	}
	
	return result;
}

int main(void)
{
	char expression[EXP_LEN];
	int polinomio[MAX_GRAU], tmp, grau = 0;
	int i;

	while (1)
	{
		scanf ("%s", expression);
		if (!strcmp(expression, "=")) break;

		printf ("expression = [%s]\n", expression);
		memset(polinomio, 0, MAX_GRAU * sizeof(int));

		max_number = 0;
		grau = criaPolinomio (expression, polinomio);
		imprimePolinomio(polinomio, grau);
		
		if (grau == 0)
		{
			if (polinomio[0])
				printf ("*\n");
			else
				printf ("%d+\n", max_number ? max_number+1 : 2);
		}
		else
		{
		}
		
		for (i = 2; i <= 15; i++)
			printf ("%d -> %llf\n", i, resolvePolinomio(polinomio, grau, (double)i));
		
		printf ("\n\n\n");

	}
}

