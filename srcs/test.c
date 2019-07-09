#include "ft_printf.h"

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;

	printf("check:\n");
	ft_printf("ok\n");
	ft_printf("bonjour%d");

	return 0;
}