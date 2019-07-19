#include <stdio.h>
#include <stdlib.h>

#include "CuTest.h"
#include "../srcs/ft_printf.h"

// void Test_function_deal_with_double_percentage(CuTest *tc)
// {

// 	char	*new_format;
// 	int		real_p_nb;
// 	int		new_len;

// 	new_format = deal_with_double_percentage("bonjour%%", &real_p_nb, &new_len);
// 	CuAssertStrEquals(tc, "bonjour%", new_format);
// 	CuAssertIntEquals(tc, 0, real_p_nb);
// 	CuAssertIntEquals(tc, 8, new_len);
// 	new_format = deal_with_double_percentage("%%%%%%%", &real_p_nb, &new_len);
// 	CuAssertStrEquals(tc, "%%%", new_format);
// 	CuAssertIntEquals(tc, 1, real_p_nb);
// 	CuAssertIntEquals(tc, 4, new_len);
// 	new_format = deal_with_double_percentage("%%ok%this%%is%", &real_p_nb, &new_len);
// 	CuAssertStrEquals(tc, "%ok", new_format);
// 	CuAssertIntEquals(tc, 2, real_p_nb);
// 	CuAssertIntEquals(tc, 12, new_len);
// }


// // void Test_function_get_width(CuTest *tc)
// // {
// // 	CuAssertIntEquals(tc, 123, get_width("123l"));
// // 	CuAssertIntEquals(tc, FALSE , get_width("l"));
// // 	CuAssertIntEquals(tc, 1, get_width("1l"));
// // 	CuAssertIntEquals(tc, 1, get_width("01l"));
// //  }

// void Test_final_result_type_c(CuTest *tc)
//  {
// 	CuAssertIntEquals(tc, printf("okone%-20coktwo%-lcokthree\n", 'a', 'b'),
// 		ft_printf("okone%-20coktwo%-lcokthree\n", 'a', 'b'));
// 	CuAssertIntEquals(tc, printf("%12coktwo%-lcokthree%-10c\n", 'a', 'b', 'c'),
// 		ft_printf("%12coktwo%-lcokthree%-10c\n", 'a', 'b', 'c'));
// 	CuAssertIntEquals(tc, printf("%c%12c%%%%oktwo%-lcokthree%-10c%50c\n",'a', 'b', 'c', 'd', 'e'),
// 		ft_printf("%c%12c%%%%oktwo%-lcokthree%-10c%50c\n",'a', 'b', 'c', 'd', 'e'));
//  }


void Test_final_result_type_s(CuTest *tc)
{
	CuAssertIntEquals(tc, printf("%s\n", "bonjour"),
		ft_printf("%s\n", "bonjour"));
	// CuAssertIntEquals(tc, printf("%10.2s_unit2_%-20.5s\n", "bonjour", "ca va"),
	// 	ft_printf("%10.2s_unit2_%-20.5s\n", "bonjour", "ca va"));
	// CuAssertIntEquals(tc, printf("%2s%c\n", "bonjour", 'a'),
	// 	ft_printf("%2s%c\n", "bonjour", 'a'));
	// CuAssertIntEquals(tc, printf("%-10.2s_unit2_%-1.50s\n", "bonjour", "ca va"),
	// 	ft_printf("%-10.2s_unit2_%-1.50s\n", "bonjour", "ca va"));
}


// void Test_final_result_type_d(CuTest *tc)
// {
// 	CuAssertIntEquals(tc, printf("%d\n", 123212341),
// 		ft_printf("%d\n", 123212341));
// 	CuAssertIntEquals(tc, printf("%10.2d%%second%+015d\n", 22, 333),
// 		ft_printf("%10.2d%%second%+015d\n", 22, 333));
// 	CuAssertIntEquals(tc, printf("%-10.5d|\n", 4444),
// 		ft_printf("%-10.5d|\n", 4444));
// 	CuAssertIntEquals(tc, printf("%+-1.15d|\n", 4444),
// 		ft_printf("%+-1.15d|\n", 4444));
// 	CuAssertIntEquals(tc, printf("%+-1.15d|\n", 4444),
// 		ft_printf("%+-1.15d|\n", 4444));
// 	CuAssertIntEquals(tc, printf("%+-1.50ld|\n", (long)87120928344444),
// 		ft_printf("%+-1.50ld|\n", (long)87120928344444));
// 	CuAssertIntEquals(tc, printf("%+-ld|%0+lld|%+-0 hd|%hhd|\n", (long)255, (long long)99999999999999999, (short)333, (signed char)30),
// 		ft_printf("%+-ld|%0+lld|%+-0 hd|%hhd|\n", (long)255, (long long)99999999999999999, (short)333, (signed char)30));
// 	CuAssertIntEquals(tc, printf("%+-d%0d%-d% d\n", 1, 22, 333, 444),
// 		ft_printf("%+-d%0d%-d% d\n", 1, 22, 333, 444));
// }




