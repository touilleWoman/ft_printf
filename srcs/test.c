#include "ft_printf.h"

int main()
{
	ft_printf("okone%-12coktwo%-lcokthree%-lc%lc", 'a', 'b', 'c');
	ft_printf("_unit0_%s%-s%---s%s%-----10.2s%10.2s\n", "bonjour1\n", "bonjour2\n", "bonjour3\n", "bonjour4\n", "bonjour5\n", "bonjour6\n");
	return 0;
}

//???  w_int_t

