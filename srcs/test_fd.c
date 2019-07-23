#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"




#define ORACLE_DPRINTF vdprintf
#define TEST_DPRINTF ft_vdprintf
// #define TEST_DPRINTF dprintf


#define FAIL_AND_EXIT(msg) { fprintf(stderr, "%s\n", msg); exit(-1); }
#define FAIL(msg, ...) {                                                        \
fprintf(stderr, "Line %d: ", __LINE__);                                         \
fprintf(stderr, msg, __VA_ARGS__); current_test_result = -1;                    \
}

static  int tests_total = 0;
static  int tests_failures = 0;

void     testcase(const char *fmt, ...)
{

    va_list args1, args2;
    va_start(args1, fmt);
    va_copy(args2, args1);

    int current_test_result = 0;
    /* Avoid gcc to do static checks */
    char dyn_fmt[ft_strlen(fmt) + 1];
    strcpy(dyn_fmt, fmt);
    /* Open a file for each */
    int fd_oracle = fileno(tmpfile());
    int fd_test = fileno(tmpfile());
    if (fd_oracle == -1 || fd_test == -1) { FAIL_AND_EXIT("Cannot create temp file\n"); }
    /* Run the implementations */
    int ret_oracle = ORACLE_DPRINTF(fd_oracle, dyn_fmt, args1);
    int ret_test = TEST_DPRINTF(fd_test, dyn_fmt, args2);
    /* Compare the results */
    if (ret_oracle != ret_test) {
        FAIL("Return values differ: %d != %d\n", ret_test, ret_oracle);
    }
    int out_size_oracle = lseek(fd_oracle, 0, SEEK_END);
    int out_size_test = lseek(fd_test, 0, SEEK_END);
    char out_oracle[out_size_oracle + 1];
    char out_test[out_size_test + 1];
    lseek(fd_oracle, 0, SEEK_SET);
    lseek(fd_test, 0, SEEK_SET);
    read(fd_oracle, out_oracle, out_size_oracle);
    read(fd_test, out_test, out_size_test);
    out_oracle[out_size_oracle] = '\0';
    out_test[out_size_test] = '\0';
    if (strcmp(out_oracle, out_test)) {
        FAIL("Output differ: `%s` != `%s`\n", out_test, out_oracle);
    }
    // else
    // {
    //     printf("%s\n",out_test);
    // }
    /* Cleanup */
    close(fd_oracle);
    close(fd_test);
    tests_total += 1;
    if (current_test_result == 0) {
        printf(".");
    } else {
        tests_failures += 1;
    }
    va_end(args1);
    va_end(args2);
}


int main()
{
// type c
    testcase("okone%-20coktwo%-lcokthree\n", 'a', 'b');
    testcase("okone%-20coktwo%-lcokthree\n", 'a', 'b');
    testcase("%c%12c%%%%oktwo%-lcokthree%-10c%50c\n",'a', 'b', 'c', 'd', 'e');

 //type s
    testcase("%10.2s_unit2_%-20.5s\n", "bonjour", "ca va");
    testcase("%2s%c\n", "bonjour", 'a');
    testcase("%-10.2s_unit2_%-1.50s\n", "bonjour", "ca va");
    testcase("helloee", "");
    testcase("hello%s\n", "world");
    testcase("%s%s\n", "bonjour", "toi");
    testcase("_unit0_%s%-s%---s%s%s%10.2s\n", "bonjour1\n", "bonjour2\n", "bonjour3\n", "bonjour4\n", "bonjour5\n", (wchar_t*)"bonjour6\n");
    testcase("hello%s\n", "world");
    testcase("hello %s\t%d\n", "world", 42);
    testcase("hello %s\t%d\n", "world", 42);
    //type p
    // char *ptr = "pointer test";
    // void *ptr2 = NULL;
    // void *ptr3 = ptr;
    // testcase("p1:%#-+ 0p P2:%+p P3:%p\n", ptr, ptr2, ptr3);

    if (tests_failures)
    {
        printf("\n%d/%d tests passed :'-(\n", tests_total - tests_failures, tests_total);
        return 1;
    }
    else
    {
        printf("\n%d/%d tests passed \\o/\n", tests_total, tests_total);
        return 0;
    }
}
// int main(void)
// {

//     ft_printf("%s%s\n", "bonjour", "toi");
//     return 0;
// }
