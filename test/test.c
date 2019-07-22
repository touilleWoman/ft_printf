// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int bad_fprintf(FILE *stream, const char *format, ...){
//     return 11;
// }

// #define ORACLE_FPRINTF fprintf
// #define TEST_FPRINTF bad_fprintf
// // #define TEST_FPRINTF fprintf


// #define FAIL_AND_EXIT(msg) { fprintf(stderr, "%s\n", msg); exit(-1); }
// #define FAIL(msg, ...) {                                                        \
// fprintf(stderr, "Line %d: ", __LINE__);                                         \
// fprintf(stderr, msg, __VA_ARGS__); current_test_result = -1;                    \
// }


// #define TESTCASE(fmt, ...) {                                                    \
//     int current_test_result = 0;                                                \
//     /* Avoid gcc to do static checks */                                         \
//     char dyn_fmt[sizeof(fmt)];                                                  \
//     strcpy(dyn_fmt, fmt);                                                       \
//     /* Open a file for each */                                                  \
//     FILE *fd_oracle = tmpfile();                                                \
//     FILE *fd_test = tmpfile();                                                  \
//     if (!fd_oracle || !fd_test) { FAIL_AND_EXIT("Cannot create temp file\n"); } \
//     /* Run the implementations */                                               \
//     int ret_oracle = ORACLE_FPRINTF(fd_oracle, dyn_fmt, __VA_ARGS__);           \
//     int ret_test = TEST_FPRINTF(fd_test, dyn_fmt, __VA_ARGS__);                 \
//     /* Compare the results */                                                   \
//     if (ret_oracle != ret_test) {                                               \
//         FAIL("Return values differ: %d != %d\n", ret_test, ret_oracle);         \
//     }                                                                           \
//     int out_size_oracle = ftell(fd_oracle);                                     \
//     int out_size_test = ftell(fd_test);                                         \
//     char out_oracle[out_size_oracle + 1];                                       \
//     char out_test[out_size_test + 1];                                           \
//     fseek(fd_oracle, 0, SEEK_SET);                                              \
//     fseek(fd_test, 0, SEEK_SET);                                                \
//     fread(out_oracle, sizeof(char), out_size_oracle, fd_oracle);                \
//     fread(out_test, sizeof(char), out_size_test, fd_test);                      \
//     out_oracle[out_size_oracle] = '\0';                                         \
//     out_test[out_size_test] = '\0';                                             \
//     if (strcmp(out_oracle, out_test)) {                                         \
//         FAIL("Output differ: `%s` != `%s`\n", out_test, out_oracle);            \
//     }                                                                           \
//     /* Cleanup */                                                               \
//     fclose(fd_oracle);                                                          \
//     fclose(fd_test);                                                            \
//     tests_total += 1;                                                           \
//     if (current_test_result == 0) {                                             \
//         printf(".");                                                            \
//     } else {                                                                    \
//         tests_failures += 1;                                                    \
//     }                                                                           \
// }


// int main(int argc, char const *argv[])
// {
//     int tests_total = 0;
//     int tests_failures = 0;

//     // TODO: add more tests !
//     TESTCASE("helloee", "");
//     TESTCASE("hello %d%s\n", "world", 'a');
//     TESTCASE("hello %s\t%d\n", "world", 42);

//     if (tests_failures) {
//         printf("\n%d/%d tests passed :'-(\n", tests_total - tests_failures, tests_total);
//         return 1;
//     } else {
//         printf("\n%d/%d tests passed \\o/\n", tests_total, tests_total);
//         return 0;
//     }
// }
