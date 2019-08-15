#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"




#define ORACLE_DPRINTF vdprintf
#define TEST_DPRINTF ft_vdprintf


#define FAIL_AND_EXIT(msg) { fprintf(stderr, "%s\n", msg); exit(-1); }
#define FAIL(msg, ...) {                                                        \
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
    if (ret_oracle != ret_test)
        FAIL("`%s` return values differ: %d != %d\n", fmt, ret_test, ret_oracle);
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
        FAIL("`%s` output differ: `%s` != `%s`\n", fmt, out_test, out_oracle);
    }
    /* Cleanup */
    close(fd_oracle);
    close(fd_test);
    tests_total += 1;
    if (current_test_result == 0)
    {
        printf(".");
        /* show printed */
        printf("%s\n",out_test);
    }
    else
        tests_failures += 1;
    va_end(args1);
    va_end(args2);
}


int main()
{
    testcase("hello%s\n", "world");
    testcase("hello %s\t%d\n", "world", 42);
    testcase("hello %s\t%d\n", "world", 42);
    testcase("%.2d\n", -22);
    testcase("%.3d\n", -22);
    testcase("%+10.4d|\n", -22);
    testcase("%+ 10.4d\n", 22);
    testcase("%+010.4d\n", 22);
    // testcase("-------------------%lc", (wint_t)-1);
    // testcase("====================%+-5.3rc\n", 'n');

//type f
#if 1
    testcase("six%f|\n", 6.0);
    testcase("six%#6.10f|\n", 6.0);
    // testcase("%lld", -9223372036854775808);
    testcase("%d%5ttttttt", 42);
    // testcase("%d%5kkkkkkk", 42);
    double nb = -12547.58;
    testcase( "space:% f\n", nb);
    testcase( "plus:%+f\n", nb);
    testcase( "hash:%#f\n", nb);
    testcase( "precision:%.2f\n", nb);
    testcase( "big prec:%.14f\n", nb);
    testcase( "precision = 0:%.0f\n", nb);
    testcase( "precision + hash:%#.0f\n", nb);
    testcase( "space + prec:% .5f\n", nb);
    testcase( "space + prec + hash:%# .0f\n", nb);
    testcase( "space + prec + hash:% #.0f\n", nb);
    testcase( "Plus + prec / grande:%+.5f\n", nb);
    testcase( "Plus + prec / petite:%+.0f\n", nb);
    testcase( "Plus + prec + hash:%#+.0f\n", nb);
    testcase( "Prec + 0:%0.5f\n", nb);
    testcase( "Prec + minus:%-.5f\n", nb);
    testcase( "size:%5f\n", nb);
    testcase( "size + space:% 5f\n", nb);
    testcase( "size + plus:%+5f\n", nb);
    testcase( "size + space:%# 5f\n", nb);
    testcase( "size + plus:%#+5f\n", nb);
    testcase( "size + minus:%-5f\n", nb);
    testcase( "size + 0:%05f\n", nb);
    testcase( "size + 0 + plus:%+05f\n", nb);
    testcase( "size + 0 + plus:%0+5f\n", nb);
    testcase( "size + 0 + prec:%05.3f\n", nb);
    testcase( "size + 0 + prec + hash:%0#5.0f\n", nb);
    testcase( "size + minus + prec:%-5.3f\n", nb);
    testcase( "size + minus + prec + hash:%-#5.0f\n", nb);
    testcase( "size + plus + 0 + prec:%+05.3f\n", nb);
    testcase( "size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
    testcase( "size + espace + zero + prec:%0 5.3f\n", nb);
    testcase( "size + espace + zero + prec:% 05.3f\n", nb);
    testcase( "size + espace + zero + prec + hash:%#0 5.0f\n", nb);
    testcase( "size + minus + plus + prec:%-+5.3f\n", nb);
    testcase( "size + minus + plus + prec + hash:%-#+5.0f\n", nb);
    testcase("%f\n", 2.345);
    testcase("%4.5f\n", 2.345);
    testcase("%5.2f\n", 2.325);
    testcase("%5.2f\n", 2.395);
    testcase("%+5.5f\n", 2.345);
    testcase("%+05.5f\n", 2.345);
    testcase("% 05.5f\n", 2.345);
    testcase("%f\n", -2.345);
    testcase("%4.5f\n", -2.345);
    testcase("%5.2f\n", -2.345);
    testcase("%+5.5f\n", -2.345);
    testcase("%+05.5f\n", -2.345);
    testcase("% 05.5f\n", -2.345);
    testcase("zero%f|\n", 0.0);
    testcase("one%f|\n", 1);


#endif

#if 1
    testcase("%2c", 0);

    ft_printf("%hhld", 128);
    ft_printf("@main_ftprintf: %####0000 33..1..#00d\n", 256);
    testcase("%2c", 0);
    testcase("%.0%");
    testcase("");
    testcase("%d%5", 42);
    testcase("touille%5");
    testcase("%5");
    testcase("%5%");
    testcase("%5%%d", 4);
    testcase("%-5%");
    testcase("%5.11%");
    testcase("%.0%");
    testcase("%   %", "test");
    testcase("1@moulitest: %.o %.0o", 0, 0);
    testcase("2@moulitest: %5.o %5.0o", 0, 0);
    testcase("3@moulitest: %#.o %#.0o", 0, 0);
    testcase("4@moulitest: %.d %.0d", 0, 0);
    testcase("5@moulitest: %5.d %5.0d", 0, 0);
    testcase("6@moulitest: %#.x %#.0x", 0, 0);
    testcase("7@moulitest: %5.x %5.0x", 0, 0);
    testcase("8@moulitest: %5.x", 0);
    testcase("9@moulitest: %5.0x", 0);
    testcase("% u", 4294967295);
    testcase("%+u", 4294967295);
#endif

// random Strings
#if 1
    testcase("#nyancat inside");
    testcase("\x7f");
    testcase("The Game.");
    testcase("I know what you are doing.");
    testcase("You should better not go to sleep.");
    testcase("Drop the keyboard and RUN!");
    testcase("Any invalid command will remove a random file from your home.");
    testcase("You will die before this tests ends.");
    testcase("I love the smell of bugs in the morning.");
    testcase("What do you want to debug today?");
    testcase("rm: /: Permission denied.");
    testcase("Already up-to-date.");
    testcase(":(){ :|:& };:");
    testcase("Do you want to print 333.5K chars? (y/N)");
    testcase("Try with ASAN, and be amazed");
    testcase("Remember that word: C H A I R");
    testcase("Good morning, pal *<:-)");
    testcase("WASTED");
    testcase("Too old to crash");
    testcase("don’t feed the bugs! (except delicious stacktraces)!");
    testcase("Beer in mind.");
    testcase("3nl4r9e y0\\/r pr1ntf");
    testcase("Don't do this.");
    testcase("No fix, no sleep");
    testcase("/dev/brain: No such file or directory.");
    testcase("こんにちは、私はprintf単体テストです");
    testcase("中文测试");

// type c
    testcase("okone%-20coktwo%-lcokthree\n", 'a', (wchar_t)'b');
    testcase("okone%-20coktwo%-lcokthree\n", 'a', 'b');
    testcase("%c%12c%%%%oktwo%-lcokthree%-10c%50c\n",'a', 'b', 'c', 'd', 'e');
    testcase("========%lc\n", (wchar_t)'&');
    testcase("%.2c", 5);
    testcase("%.2c", 0);
    testcase("%.2c", NULL);
    testcase("%2c", 0);
    testcase("% c", 0);

 // type s
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
//type d
    testcase("%.2d\n", -22);
    testcase("%.3d\n", -22);
    testcase("%+10.4d|\n", -22);
    testcase("%+ 10.4d\n", 22);
    testcase("%+010.4d\n", 22);
    testcase("%+d\n", 123212341);
    testcase("%d\n", 123212341);
    testcase("%+d\n", -123212341);
    testcase("% d|\n", -123212341);
    testcase("% d|\n", 123212341);
    testcase("%+ d\n", -123212341);
    testcase("%10.2d%%second%+015d\n", 22, 333);
    testcase("%-10.5d|\n", 4444);
    testcase("%+-1.15d|\n", 4444);
    testcase("%+-1.15d|\n", 4444);
    testcase("%+-1.50ld|\n", (long)87120928344444);
    testcase("%+-ld|%0+lld|%+-0 hd|%hhd|\n", (long)255, (long long)99999999999999999, (short)333, (signed char)30);
    testcase("%+-d%0d%-d% d\n", 1, 22, 333, 444);

// type oxX


    testcase("%#X", 0);
    testcase("%X", 0);
    testcase("%#-.X", 0);
    testcase("%.0X", 0);
    testcase("%.5X", 0);
    testcase("%X", 0);
    testcase("%#08x", 42);



    testcase("%x|\n", 4444);
    testcase("%#o|\n", 4444);
    testcase("%#X|\n", 4444);
    testcase("%#-10.6x|\n", 4444);
    testcase("%-10.5o|\n", 4444);
    testcase("%-10.6o|\n", 4444);
    testcase("%#-10.6o|\n", 4444);
    testcase("%#10.6X|\n", 4444);
    testcase("%#-10.7x|\n", 4444);
    testcase("%#-010.7o|\n", 4444);
    testcase("%#010.7o|\n", 4444);
    testcase("%#-10.7o|\n", 4444);
    testcase("%#-2.7X|\n", 4444);
    testcase("%#-10.7X|\n", 4444);
    testcase("%#10.7X|\n", 4444);
    testcase("%#10.7X|\n", 4444);
    testcase("%#10.7X|\n", 4444);
    testcase("%#10.7llX|\n", (long long)9287539484444);
    testcase("%#20.7llX|\n", (long long)9287539484444);
    testcase("%#10.7lX|\n", (long)9287539484444);
    testcase("%#10.7hX|\n", (short)9287539484444);
    testcase("%#10.7hhX|\n", 9287539484444);

// type u
    testcase("%u|\n", 4444);
    testcase("%-10.6u|\n", 4444);
    testcase("%10.6u|\n", 4444);
    testcase("%-10.7u|\n", 4444);
    testcase("%-010.7u|\n", 4444);
    testcase("%010.7u|\n", 4444);
    testcase("%-5.7u|\n", 4444);
    testcase("%-2.7u|\n", 4444);
    testcase("%-1.7u|\n", 4444);
    testcase("%10.7u|\n", 4444);
    testcase("%10.7u|\n", 4444);
    testcase("%10.7llu|\n", (long long)9287539484444);
    testcase("%20.7llu|\n", (long long)9287539484444);
    testcase("%10.7lu|\n", (long)9287539484444);
    testcase("%10.7hu|\n", (short)9287539484444);
    testcase("%10.7hhu|\n", 9287539484444);
    testcase("%u|\n", 5);
//     // // type p
    char *ptr = "pointer test";
    void *ptr2 = NULL;
    void *ptr3 = ptr;
    testcase("p1:%#-+ 0p P2:%+p P3:%p\n", ptr, ptr2, ptr3);





    // testcase("one%#sf|\n", 1);   printf seg fault in this case



#endif
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

