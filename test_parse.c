#include "ft_printf.h"


void		test_deal_with_double_percentage(char *s, char *expected)
{
	char	*new_format;

	new_format = deal_with_double_percentage(s, , &10 );
	if (ft_strcmp(s, expected) != 0)
		printf("error, s=%s, expected =%sn", s, expected);
}

int main()
{
	test_deal_with_double_percentage("%%%", "%");
	test_deal_with_double_percentage("bonjour%", "bonjour");
	test_deal_with_double_percentage("bonjour%%", "bonjour%");
	test_deal_with_double_percentage("ok%%%%%ok", "ok%%");
	return 0;
}