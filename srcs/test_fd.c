#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int     ft_dprintf(int fd, const char * restrict format, ...);



#define ORACLE_DPRINTF dprintf
#define TEST_DPRINTF ft_dprintf
// #define TEST_DPRINTF dprintf


#define FAIL_AND_EXIT(msg) { fprintf(stderr, "%s\n", msg); exit(-1); }
#define FAIL(msg, ...) {                                                        \
fprintf(stderr, "Line %d: ", __LINE__);                                         \
fprintf(stderr, msg, __VA_ARGS__); current_test_result = -1;                    \
}


#define TESTCASE(fmt, ...) {                                                    \
    int current_test_result = 0;                                                \
    /* Avoid gcc to do static checks */                                         \
    char dyn_fmt[sizeof(fmt)];                                                  \
    strcpy(dyn_fmt, fmt);                                                       \
    /* Open a file for each */                                                  \
    int fd_oracle = fileno(tmpfile());                                          \
    int fd_test = fileno(tmpfile());                                            \
    if (fd_oracle == -1 || fd_test == -1) { FAIL_AND_EXIT("Cannot create temp file\n"); } \
    /* Run the implementations */                                               \
    int ret_oracle = ORACLE_DPRINTF(fd_oracle, dyn_fmt, __VA_ARGS__);           \
    int ret_test = TEST_DPRINTF(fd_test, dyn_fmt, __VA_ARGS__);                 \
    /* Compare the results */                                                   \
    if (ret_oracle != ret_test) {                                               \
        FAIL("Return values differ: %d != %d\n", ret_test, ret_oracle);         \
    }                                                                           \
    int out_size_oracle = lseek(fd_oracle, 0, SEEK_END);                        \
    int out_size_test = lseek(fd_test, 0, SEEK_END);                            \
    char out_oracle[out_size_oracle + 1];                                       \
    char out_test[out_size_test + 1];                                           \
    lseek(fd_oracle, 0, SEEK_SET);                                              \
    lseek(fd_test, 0, SEEK_SET);                                                \
    read(fd_oracle, out_oracle, out_size_oracle);                               \
    read(fd_test, out_test, out_size_test);                                     \
    out_oracle[out_size_oracle] = '\0';                                         \
    out_test[out_size_test] = '\0';                                             \
    if (strcmp(out_oracle, out_test)) {                                         \
        FAIL("Output differ: `%s` != `%s`\n", out_test, out_oracle);            \
    }                                                                           \
    /* Cleanup */                                                               \
    close(fd_oracle);                                                           \
    close(fd_test);                                                             \
    tests_total += 1;                                                           \
    if (current_test_result == 0) {                                             \
        printf(".");                                                            \
    } else {                                                                    \
        tests_failures += 1;                                                    \
    }                                                                           \
}


int main()
{
    int tests_total = 0;
    int tests_failures = 0;

    // TODO: add more tests !
    // TESTCASE("helloee", "");
    TESTCASE("hello%s\n", "world");
    TESTCASE("%s%s\n", "bonjour", "toi");
    // TESTCASE("_unit0_%s%-s%---s%s%s%10.2s\n", "bonjour1\n", "bonjour2\n", "bonjour3\n", "bonjour4\n", "bonjour5\n", (wchar_t*)"bonjour6\n");
    // TESTCASE("hello%s\n", "world");
    // TESTCASE("hello %s\t%d\n", "world", 42);

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

// int main()
// {
//     ft_dprintf(1, "hello%s\n", "world");
//     ft_dprintf(1, "%s%s\n", "bonjour", "toi");
// }