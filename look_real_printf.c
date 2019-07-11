#include <stdio.h>
// ** one capsule is [flags][width][.precision][modifier][conversion][literal],

int main()
{
// c takes:
	// + (warning)
	// -
	// width
	// modifier l (but not exiged in this project)


	//
		char c = 'a';
		printf("c:%c\n", c);
		printf("+c:%+c\n", c);
		printf("-c:%-c\n", c);
		printf("spacec:% c\n", c);
		printf("#c:%#c\n", c);
		printf("0c:%0c\n", c);./
		printf("10c:%10c\n", c);
		// printf("%.5c\n", c);
		// printf("%hc\n", c);
		printf("%lc\n", c);


	// char *s = "bonjour";
	// printf("%s|\n", s);
	// // printf("%+s|\n",s);
	// printf("%-s|\n",s);
	// printf("%10s|\n",s);
	// printf("%-10s|\n",s);
	// printf("%.5s|\n",s);
	// printf("%10.5s|\n",s);



	// printf("%10-s|\n",s);
	// printf("%0s|\n",s);
	// printf("%#s|\n",s);
	// printf("% s|\n",s);
	return 0;
}