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


	printf("%+d\n%10.1d\n%.10d\n", 543, 543, 543);
	printf("%lld\n", (long long)53545135213513);
	printf("d:%--d\n", 5);


	return 0;
}