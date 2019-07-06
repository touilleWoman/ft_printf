#include "ft_printf.h"

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	char **ptr;

	ptr = ft_strsplit("%%ok%d%c", '%');
	printf("%s\n", ptr[0]);
	printf("%s\n", ptr[1]);
	printf("%s\n", ptr[2]);
	return 0;
}