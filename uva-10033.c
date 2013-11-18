/**
 * Problem: UVa 10033 - Interpreter
 * URL: http:/* uva.onlinejudge.org/external/100/10033.html
 * Author: Maycon Maia Vitali ( mayconmaia at yahoo dot com dot br )
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_REG 10
#define NUM_RAM 1000

#define C2I(c) (int)(c - '0')
int main(void)
{
	char ram[NUM_RAM][4]; /*  Ram memory */
	int reg[NUM_REG];     /*  Registers */
	int eip;              /*  Program Counter Register */

	int nins;             /*  Number of intructions */
	int tests;            /*  Number of tests */
	char c;               /*  Instruction code */

	int halted, cicles;

	char cmd;
	int arg1, arg2;

	scanf ("%d\n", &tests);
	
	while (tests--)
	{
		nins = 0;
		
		memset(reg, 0, sizeof(reg));
		memset(ram, 0, sizeof(ram));
		
		while ((c = getchar()) != '\n' && !feof(stdin))
		{
			ram[nins][0] = c;
			scanf("%s", ram[nins++] + 1);
			getchar();
		}
		
		eip = 0;
		halted = 0;
		cicles = 0;
		
		while (!halted)
		{
			
			cicles++;
			cmd  = ram[eip][0];
			arg1 = C2I(ram[eip][1]);
			arg2 = C2I(ram[eip][2]);
			
			switch (cmd)
			{
				case '1':
					halted = 1;
				break;
				case '2':
					reg[arg1] = arg2;
					reg[arg1] %= 1000;
				break;
				case '3':
					reg[arg1] += arg2;
					reg[arg1] %= 1000;
				break;
				case '4':
					reg[arg1] *= arg2;
					reg[arg1] %= 1000;
				break;
				case '5':
					reg[arg1] = reg[arg2];
					reg[arg1] %= 1000;
				break;
				case '6':
					reg[arg1] += reg[arg2];
					reg[arg1] %= 1000;
				break;
				case '7':
					reg[arg1] *= reg[arg2];
					reg[arg1] %= 1000;
				break;
				case '8':
					reg[arg1] = atoi(ram[reg[arg2]]);
					reg[arg1] %= 1000;
				break;
				case '9':
					sprintf(ram[reg[arg2]], "%03d", reg[arg1]);
				break;
				case '0':
					if (reg[arg2])
						eip = reg[arg1] - 1;
				break;
			}
			
			eip++;
			
		}
		
		printf ("%d\n", cicles);
		if (tests)
			printf ("\n");
		
	}

	return 0;
}
