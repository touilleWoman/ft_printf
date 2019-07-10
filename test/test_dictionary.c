// #include <stdio.h>
// #include <stdlib.h>

// #include "CuTest.h"

// /* We need to directly insert the .c file in order to test the */
// /* static functions as well */
// // #include "dictionary.c"

// void Test_dictionary_hash(CuTest *tc)
// {
//     /* NULL test */
//     CuAssertIntEquals(tc, 0, dictionary_hash(NULL));
// }

// void Test_deal_with_double_percentage(CuTest *tc)
// {

//     char    *new_format;
//     int     real_p_nb;
//     int     new_len;

//     // real_p_nb = 0;
//     // new_len = 0;
//     new_format = deal_with_double_percentage("bonjour%%", real_p_nb, new_len);

//     CuAssertStrEquals(tc, "bonjour%", new_format);

// }

// void Test_dictionary_growing(CuTest *tc)
// {
//     int i, j;
//     char sec_name[32];
//     char key_name[64];
//     dictionary *dic;

//     dic = dictionary_new(DICTMINSZ);
//     CuAssertPtrNotNull(tc, dic);
//     CuAssertIntEquals(tc, 0, dic->n);

//     /* Makes the dictionary grow */
//     for (i = 1 ; i < 101; ++i) {
//         sprintf(sec_name, "sec%d", i);
//         CuAssertIntEquals(tc, 0, dictionary_set(dic, sec_name, ""));
//         for (j = 1 ; j < 11; ++j) {
//             sprintf(key_name, "%s:key%d", sec_name, j);
//             CuAssertIntEquals(tc, 0, dictionary_set(dic, key_name, "dummy_value"));
//             CuAssertIntEquals(tc, i + (i - 1) * 10 + j, dic->n);
//         }
//     }

//     /* Shrink the dictionary */
//     for (i = 100 ; i > 0; --i) {
//         sprintf(sec_name, "sec%d", i);
//         for (j = 10 ; j > 0; --j) {
//             sprintf(key_name, "%s:key%d", sec_name, j);
//             dictionary_unset(dic, key_name);
//         }
//         dictionary_unset(dic, sec_name);
//         CuAssertIntEquals(tc, (i - 1) * (11), dic->n);
//     }

//     dictionary_del(dic);
// }

// void Test_deal_with_double_percentage(CuTest *tc)
// {

//     char    *new_format;
//     int     real_p_nb;
//     int     new_len;

//     // real_p_nb = 0;
//     // new_len = 0;
//     new_format = deal_with_double_percentage("bonjour%%", real_p_nb, new_len);

//     CuAssertStrEquals(tc, "bonjour%", new_format);

// }

