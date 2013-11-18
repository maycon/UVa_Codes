/**
 * Problem: UVa 706 - LCD Display
 * http:/*uva.onlinejudge.org/external/7/706.html
 * Author: Maycon Maia Vitali ( mayconmaia at yahoo dot com dot br )
 */

#include <stdio.h>
#include <string.h>

char seg[10][7] = {
    {1, 1, 1, 0, 1, 1, 1}, /* 0 */
    {0, 0, 1, 0, 0, 1, 0}, /* 1 */
    {1, 0, 1, 1, 1, 0, 1}, /* 2 */
    {1, 0, 1, 1, 0, 1, 1}, /* 3 */
    {0, 1, 1, 1, 0, 1, 0}, /* 4 */
    {1, 1, 0, 1, 0, 1, 1}, /* 5 */
    {1, 1, 0, 1, 1, 1, 1}, /* 6 */
    {1, 0, 1, 0, 0, 1, 0}, /* 7 */
    {1, 1, 1, 1, 1, 1, 1}, /* 8 */
    {1, 1, 1, 1, 0, 1, 1}  /* 9 */
};

char chars[] = "-||-||-";

void nputc(char c, int n)
{
    int i;
    for (i = 0; i < n; i++) putc(c, stdout);
}

int main(void)
{
    int s, l, i, j;
    char n[10];

    while (1)
    {
        scanf ("%d %s", &s, n);
		
        if (!s)
            break;
		
        l = strlen(n);
		
        /* 1o segmento */
        for (i = 0; i < l; i++)
        {
            putc(' ', stdout);
            nputc(seg[n[i] - '0'][0] ? '-' : ' ' , s);
            putc(' ', stdout);
            if (i != (l - 1)) putc(' ', stdout);
        }

        printf ("\n");

        /* 2o e 3o segmentos */
        for (j = 0; j < s; j++)
        {
            for (i = 0; i < l; i++)
            {
                putc(seg[n[i] - '0'][1] ? '|' : ' ' , stdout);
                nputc(' ' , s);
                putc(seg[n[i] - '0'][2] ? '|' : ' ' , stdout);
                if (i != (l - 1)) putc(' ', stdout);
            }
			
            printf ("\n");
        }

        /* 4o segmento */
        for (i = 0; i < l; i++)
        {
            putc(' ', stdout);
            nputc(seg[n[i] - '0'][3] ? '-' : ' ' , s);
            putc(' ', stdout);
            if (i != (l - 1)) putc(' ', stdout);
        }
		
        printf ("\n");
		
        /* 5o e 6o segmentos */
        for (j = 0; j < s; j++)
        {
            for (i = 0; i < l; i++)
            {
                putc(seg[n[i] - '0'][4] ? '|' : ' ' , stdout);
                nputc(' ' , s);
                putc(seg[n[i] - '0'][5] ? '|' : ' ' , stdout);
                if (i != (l - 1)) putc(' ', stdout);
            }
			
            printf ("\n");
        }
		
        /* 7o segmento */
        for (i = 0; i < l; i++)
        {
            putc(' ', stdout);
            nputc(seg[n[i] - '0'][6] ? '-' : ' ' , s);
            putc(' ', stdout);
            if (i != (l - 1)) putc(' ', stdout);
        }
		
        printf ("\n\n");
		
    }

    return 0;
}

