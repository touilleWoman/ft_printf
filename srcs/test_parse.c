#include <stdio.h>
#include <stdlib.h>

#include "CuTest.h"
#include "../srcs/ft_printf.h"

void Test_deal_with_double_percentage(CuTest *tc)
{

	char	*new_format;
	int		real_p_nb;
	int		new_len;

	// real_p_nb = 0;
	// new_len = 0;
	new_format = deal_with_double_percentage("bonjour%%", &real_p_nb, &new_len);

	CuAssertStrEquals(tc, "bonjour%", new_format);
}
