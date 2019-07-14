#include "ft_printf.h"

int main()
{
	// ft_printf("okone%12coktwo%-lcokthree%-lc", 'a', 'b');
	ft_printf("_unit0_%s%-s%-10s%10.2s", "bonjour1", "bonjour2", "bonjour3", "bonjour4", "bonjour5");
	return 0;
}
