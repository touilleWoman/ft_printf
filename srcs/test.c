#include "ft_printf.h"

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	void	*a;

	a = NULL;
	printf("ok\n%f\n", *(float*)&a);
	return 0;
}