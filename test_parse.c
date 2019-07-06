#include "ft_printf.h"


void		test_count_ture_percentage(char *s, int expected)
{
	int		result;

	result = count_true_percentage(s);
	if (result != expected)
		printf("error, s=%s, result=%d, expected =%d\n", s, result, expected);
}

int main()
{
	test_count_ture_percentage("%", 1);
	test_count_ture_percentage("asfsda%", 1);
	test_count_ture_percentage("%%", 0);
	test_count_ture_percentage("%%ok", 0);
	test_count_ture_percentage("%%%", 1);
	test_count_ture_percentage("%%%%%", 1);
	test_count_ture_percentage("%%%okjsks%", 2);
	return 0;
}