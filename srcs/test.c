#include "ft_printf.h"

int main()
{

	ft_printf("okone%lc", 'a');
	ft_printf("%2s\n", "bonjour");
	printf("%2s\n", "bonjour");
	ft_printf("_unit0_%s%-s%---s%s%s%10.2s\n", "bonjour1\n", "bonjour2\n", "bonjour3\n", "bonjour4\n", "bonjour5\n", (wchar_t*)"bonjour6\n");
	ft_printf("okone%lld%d%d\n", 12147483647, 10, 33);
	ft_printf("okone%lld%d%d\n", 12147483647, 10, 33);
	return 0;
}


