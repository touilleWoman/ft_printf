#include <stdio.h>
#include "./srcs/ft_printf.h"
// ** one capsule is [flags][width][.precision][modifier][conversion][literal],

int main()
{


// c takes:
	// -
	// width
	//- and width
	// modifier l (but not exiged in this project)


		// int	d;
		// char c = 'a';
		// printf("lc:%lc\n", (wint_t)60);
		// // d = printf("------c:%-------10c|\n", c);
		// d = printf("-10cc:%-10lc|\n", c);
		// d = printf("10c:%10c|\n", c);
		// printf("ret:%d\n", d);
		// // printf("spacec:% c\n", c);
		// // printf("#c:%#c\n", c);
		// // printf("0c:%0c\n", c);
		// d =printf("10c:%-10c\n", c);
		// printf("ret:%d\n", d);

		// // d =printf("%.5c\n", c);
		// // d =printf("%hc\n", c);
		// d =printf("%lc\n", c);
		// printf("ret:%d\n", d);

		// // d =printf("%005c\n", c);
		// printf("ret:%d\n", d);
		// d =printf("%5c\n", c);
		// printf("ret:%d\n", d);

// s takes:
// 	-
// 	width
// 	- and width
	// precision
	// l
	// int	d;
	// char *s = "bonjour";
	// d = printf("s:%s|\n", s);
	// printf("%d\n", d);

	// // printf("+s:%+s|\n",s);
	// printf("-s:%-s|\n",s);
	// // printf("0s:%10s|\n",s);
	// // printf("space s:% s|\n",s);
	// // printf("#s:%#s|\n",s);
	// printf("10s:%10s|\n",s);
	// printf("-10s:%-10s|\n",s);
	// printf(".5s:%.5s|\n",s);
	// printf("10.5s:%10.5s|\n",s);
	// printf("10.5ls:%10.5s|\n",s);
	// s = NULL;
	// d = printf("%s\n", s);
	// printf("%d\n", d);


	// printf("%d\n",  2147483647);
	// printf("d:%hhd\n",  (signed char)20);

	// printf("d:%.2d\n", 22);
	// printf("d:%+.2d\n", 22);
	// printf("d:%2d\n",22);
	// printf("d:%+2d\n",22);
	// printf("d:%+3d\n",33);
	// printf("d:%+4d\n",33);
	// printf("d:% 10d\n",33);
	// printf("d:%+05d\n",55);
	// printf("d:%05d\n",55);
	// printf("d:%+5d\n",55);
	// printf("d:%-05d\n",66);
	// printf("d:%+10d\n",33);
	// printf("d:%.2d\n", +7);
	// printf("d:%+15.13d\n", +7777777);
	// printf("d:%2.10d\n", +7777777);
// type p
	// char *ptr = "ok";
	// void *ptr2 = ptr;
	// printf("%lp|%hp\n", ptr, ptr2);
	// printf("%.2x\n", -22);
	// printf("%.3x\n", -22);
	// printf("%.4x\n", -22);
	// printf("%#X\n",22);
	// printf("%#o\n", 22);
	// printf("%x\n", 0);
	// printf("%X\n", 0);
	// printf("%o\n", 0);
	// printf("%+3d\n", 22);
	// printf("%+4d\n", 22);
 //    printf("%#-10.6u|\n", 4444);
	printf("%.x\n", 0);
    printf("%.-4x|\n", 1);

    // printf("====================%+-5.3rc\n", 'n');

	return 0;
}