#include <stdio.h>
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
		// // printf("+c:%+c\n", c);
		// d = printf("-c:%-c\n", c);
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
	char *s = "bonjour";
	printf("s:%s|\n", s);
	// printf("+s:%+s|\n",s);
	printf("-s:%-s|\n",s);
	// printf("0s:%10s|\n",s);
	// printf("space s:% s|\n",s);
	// printf("#s:%#s|\n",s);
	printf("10s:%10s|\n",s);
	printf("-10s:%-10s|\n",s);
	printf(".5s:%.5s|\n",s);
	printf("10.5s:%10.5s|\n",s);
	printf("10.5ls:%10.5s|\n",s);
	return 0;
}