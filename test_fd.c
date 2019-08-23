#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"
#include <limits.h>




#define ORACLE_DPRINTF vdprintf
#define TEST_DPRINTF ft_vdprintf


#define FAIL_AND_EXIT(msg) { fprintf(stderr, "%s\n", msg); exit(-1); }
#define FAIL(msg, ...) {                                                        \
fprintf(stderr, msg, __VA_ARGS__); current_test_result = -1;                    \
}

static  int tests_total = 0;
static  int tests_failures = 0;


FILE *fd_oracle_p = NULL;
FILE *fd_test_p = NULL;


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
    if (fd_oracle_p == NULL)
    {
        fd_oracle_p = tmpfile();
        if (fd_oracle_p == NULL)
            FAIL_AND_EXIT("Cannot create temp file\n");
    }
    else
    {
        ftruncate(fileno(fd_oracle_p), 0);
        fseek(fd_oracle_p, 0, SEEK_SET);
    }
    int fd_oracle = fileno(fd_oracle_p);

    if (fd_test_p == NULL)
    {
        fd_test_p = tmpfile();
        if (fd_test_p == NULL)
        {
            FAIL_AND_EXIT("Cannot create temp file\n");
        }
    }
    else
    {
        ftruncate(fileno(fd_test_p), 0);
        fseek(fd_test_p, 0, SEEK_SET);
    }
    int fd_test = fileno(fd_test_p);
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
    if (out_size_test != out_size_oracle) {
        FAIL("`%s` printed nb differ: `%s` != `%s`\n", fmt, out_test, out_oracle);
    }
    else
    {
        for (int i = 0; i < out_size_test; ++i)
            if (out_test[i] != out_oracle[i]) {
                FAIL("`%s` output differ: `%s` != `%s`\n", fmt, out_test, out_oracle);
                break;
            }
    }

    tests_total += 1;
    if (current_test_result == 0)
    {
        printf(".");
        /* show printed content */
        // printf("%s\n",out_test);
    }
    else
        tests_failures += 1;
    va_end(args1);
    va_end(args2);
}


int main()
{
#if 0
    ft_printf("%b\n", 1);
    ft_printf("%b\n", 2);
    ft_printf("%b\n", 3);
    ft_printf("%b\n", 4);
    ft_printf("%b\n", 16);
    ft_printf("%#b", 0);
    ft_printf("%b", 0);
    ft_printf("%#-.b", 0);
    ft_printf("%.0b", 0);
    ft_printf("%.5b", 0);
    ft_printf("%b", 0);
    ft_printf("%#08b", 42);
    ft_printf("%#10.7b|\n", 4444);
    ft_printf("%#10.7llb|\n", (long long)9287539484444);
    ft_printf("%#20.7llb|\n", (long long)9287539484444);
    ft_printf("%#10.7lb|\n", (long)9287539484444);
    ft_printf("%#10.7hb|\n", (short)9287539484444);
    ft_printf("%#10.7hhb|\n", 9287539484444);
#endif


#if 1
// flag *

	testcase("%*.*d", 8, 7, 1000);
	testcase("%*.*d", 0, 3, 0);
	testcase("%*d", 5, 42);

#endif

#if 1
    // // type p

    testcase("%.0p", 0);
    testcase("%10.0p", 0);
    testcase("%.5p", 0);
    testcase("%10.5p", 0);
    testcase("%+-10.5p", 0);
    testcase("%#10.5p", 0);
    testcase("%*.5p", 0, 0);
    testcase("%*.*p", 10, 4, 0);
    testcase("%010p", 0);
    testcase("%10p", 0);
    char *ptr = "pointer test";
    void *ptr2 = NULL;
    void *ptr3 = ptr;
    testcase("p1:%#-+ 0p P2:%+p P3:%p\n", ptr, ptr2, ptr3);
	testcase("%.0p, %.p", 0, 0);
	testcase("%.p, %.0p", 0, 0);

    int     nb;
    char    c;
    nb = 0;
    c = 'W';
    testcase("%15.2p\n", &nb);
    testcase("%15.2p\n", &nb);
    testcase("%-15p\n", &nb);
    testcase("%20.0p", &nb);
    testcase("%20.0p", 0);
    testcase("%-5p\n", &nb);
    testcase("%42p\n", &nb);
    testcase("%.0p", &nb);
    testcase("%10.0p", &nb);
    testcase("%.5p", &nb);
    testcase("%10.5p", &nb);
    testcase("%+-10.5p", &nb);
    testcase("%#10.5p", &nb);
    testcase("%-18p\n", &nb);
    testcase("%42p\n", &nb);
    testcase("%5p\n", &c);
    testcase("%-15p\n", &c);
    testcase("%-5p\n", &c);
    testcase("%42p\n", &c);
    testcase("%-18p\n", &c);
    testcase("%42p\n", &c);
#endif

    // testcase("-------------------%lc", (wint_t)-1);
    // testcase("====================%+-5.3rc\n", 'n');

//type f

#if 1
    testcase("{%Lf}",1.419999999l);
    testcase("{%Lf}",1.420000000000);
    testcase("{%f}", 0.1111111111111111);
    testcase("{%f}", 0.999999999999999999);
    testcase("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42L);
    float      fl2;
    fl2 = -0.000;

    testcase("%f\n",fl2);
    testcase("space:% f\n",0.123);
    testcase("space:% f\n",fl2);
    testcase("plus:%+f\n",fl2);
    testcase("hash:%#f\n",fl2);
    testcase("precision:%.2f\n",fl2);
    testcase("big prec:%.14f\n",fl2);

    testcase("precision + hash:%#.0f\n",fl2);
    testcase("space + prec:% .5f\n",fl2);
    testcase("space + prec + hash:%# .0f\n",fl2);
    testcase("space + prec + hash:% #.0f\n",fl2);
    testcase("Plus + prec / grande:%+.5f\n",fl2);
    testcase("Plus + prec / petite:%+.0f\n",fl2);
    testcase("Plus + prec + hash:%#+.0f\n",fl2);
    testcase("Prec + 0:%0.5f\n",fl2);
    testcase("Prec + minus:%-.5f\n",fl2);
    testcase("size:%5f\n",fl2);
    testcase("size + space:% 5f\n",fl2);
    testcase("size + plus:%+5f\n",fl2);
    testcase("size + space:%# 5f\n",fl2);
    testcase("size + plus:%#+5f\n",fl2);
    testcase("size + minus:%-5f\n",fl2);
    testcase("size + 0:%05f\n",fl2);
    testcase("size + 0 + plus:%+05f\n",fl2);
    testcase("size + 0 + plus:%0+5f\n",fl2);
    testcase("size + 0 + prec:%05.3f\n",fl2);
    testcase("size + 0 + prec + hash:%0#5.0f\n",fl2);
    testcase("size + minus + prec:%-5.3f\n",fl2);
    testcase("size + minus + prec + hash:%-#5.0f\n",fl2);
    testcase("size + plus + 0 + prec:%+05.3f\n",fl2);
    testcase("size + plus + 0 + prec + hash:%0+#5.0f\n",fl2);
    testcase("size + espace + zero + prec:%0 5.3f\n",fl2);
    testcase("size + espace + zero + prec:% 05.3f\n",fl2);
    testcase("size + espace + zero + prec + hash:%#0 5.0f\n",fl2);
    testcase("size + minus + plus + prec:%-+5.3f\n",fl2);
    testcase("size + minus + plus + prec + hash:%-#+5.0f\n",fl2);

    // testcase("%.20f\n", 1.0 / 3.0);
    // testcase("%.20Lf\n", 1.0L / 3.0L);

        double      db4;

        db4 = 1.0/0.0;
        testcase("%f\n", db4);
        testcase("%12f\n", db4);
        testcase("%-12f\n", db4);
        testcase("%5.9f\n", db4);


        db4 = -1.0/0.0;
        testcase("%f\n", db4);
        testcase("%12f\n", db4);
        testcase("%-12f\n", db4);
        testcase("%5.9f\n", db4);


        db4 = 0.0/0.0;
        testcase("%f\n", db4);
        testcase("%12f\n", db4);
        testcase("%-12f\n", db4);
        testcase("%5.9f\n", db4);

    float       fl;
    fl = 0;
    testcase("null prec : %+.0f\n", fl);
    fl = 12.5;
    testcase("null prec : %+.0f\n", fl);
    fl = 12.6;
    testcase("null prec : %+.0f\n", fl);
    fl = -25632.2541;
    testcase("null prec : %+.0f\n", fl);
    fl = -1.0123;
    testcase("null prec : %+.0f\n", fl);
    fl = 12354;
    testcase("null prec : %+.0f\n", fl);


    double      db3;
    db3 = 12389123798;

    testcase("space:%lf\n", db3);
    testcase("space:% f\n", db3);
    testcase("plus:%+f\n", db3);
    testcase("hash:%#f\n", db3);
    testcase("precision:%.2f\n", db3);
    testcase("big prec:%.14f\n", db3);
    testcase("precision + hash:%#.0f\n", db3);
    testcase("space + prec:% .5f\n", db3);
    testcase("space + prec + hash:%# .0f\n", db3);
    testcase("space + prec + hash:% #.0f\n", db3);
    testcase("Plus + prec / grande:%+.5f\n", db3);
    testcase("Plus + prec / petite:%+.0f\n", db3);
    testcase("Plus + prec + hash:%#+.0f\n", db3);
    testcase("Prec + 0:%0.5f\n", db3);
    testcase("Prec + minus:%-.5f\n", db3);
    testcase("size:%5f\n", db3);
    testcase("size + space:% 5f\n", db3);
    testcase("size + plus:%+5f\n", db3);
    testcase("size + space:%# 5f\n", db3);
    testcase("size + plus:%#+5f\n", db3);
    testcase("size + minus:%-5f\n", db3);
    testcase("size + 0:%05f\n", db3);
    testcase("size + 0 + plus:%+05f\n", db3);
    testcase("size + 0 + plus:%0+5f\n", db3);
    testcase("size + 0 + prec:%05.3f\n", db3);
    testcase("size + 0 + prec + hash:%0#5.0f\n", db3);
    testcase("size + minus + prec:%-5.3f\n", db3);
    testcase("size + minus + prec + hash:%-#5.0f\n", db3);
    testcase("size + plus + 0 + prec:%+05.3f\n", db3);
    testcase("size + plus + 0 + prec + hash:%0+#5.0f\n", db3);
    testcase("size + espace + zero + prec:%0 5.3f\n", db3);
    testcase("size + espace + zero + prec:% 05.3f\n", db3);
    testcase("size + espace + zero + prec + hash:%#0 5.0f\n", db3);
    testcase("size + minus + plus + prec:%-+5.3f\n", db3);
    testcase("size + minus + plus + prec + hash:%-#+5.0f\n", db3);


    long double ld;

    ld = 2.1l;
    testcase("space:%lf\n", ld);
    testcase("space:%Lf\n", ld);
    testcase("space:% f\n", ld);
    testcase("plus:%+f\n", ld);
    testcase("hash:%#f\n", ld);

#endif
#if 1
    testcase("big prec13:%.13f\n", 12547.58);
    testcase( "big prec14:%.14f\n", 12547.58);
    testcase("big prec15:%.15f\n",12547.58);
    testcase("big prec16:%.16f\n",12547.58);
    testcase("big prec17:%.17f\n",12547.58);
    testcase("big prec18:%.18f\n",12547.58);
    testcase("big prec18:%.18f\n",12547.58);
    testcase( "big prec14L:%.14Lf\n", 12547.58l);
    testcase( "big prec:%.13f\n", -12547.58);

    testcase("%p", NULL);
    ft_printf(NULL);
    testcase("six%f|\n", 6.0);
    testcase("six%#6.10f|\n", 6.0);
    // testcase("%lld", -9223372036854775808);
    testcase("%d%5ttttttt", 42);
    // testcase("%d%5kkkkkkk", 42);
    testcase( "space:% f\n", -12547.58);
    testcase( "plus:%+f\n", -12547.58);
    testcase( "hash:%#f\n", -12547.58);
    testcase( "precision:%.2f\n", -12547.58);
    testcase( "precision = 0:%.0f\n", -12547.58);
    testcase( "precision + hash:%#.0f\n", -12547.58);
    testcase( "space + prec:% .5f\n", -12547.58);
    testcase( "space + prec + hash:%# .0f\n", -12547.58);
    testcase( "space + prec + hash:% #.0f\n", -12547.58);
    testcase( "Plus + prec / grande:%+.5f\n", -12547.58);
    testcase( "Plus + prec / petite:%+.0f\n", -12547.58);
    testcase( "Plus + prec + hash:%#+.0f\n", -12547.58);
    testcase( "Prec + 0:%0.5f\n", -12547.58);
    testcase( "Prec + minus:%-.5f\n", -12547.58);
    testcase( "size:%5f\n", -12547.58);
    testcase( "size + space:% 5f\n", -12547.58);
    testcase( "size + plus:%+5f\n", -12547.58);
    testcase( "size + space:%# 5f\n", -12547.58);
    testcase( "size + plus:%#+5f\n", -12547.58);
    testcase( "size + minus:%-5f\n", -12547.58);
    testcase( "size + 0:%05f\n", -12547.58);
    testcase( "size + 0 + plus:%+05f\n", -12547.58);
    testcase( "size + 0 + plus:%0+5f\n", -12547.58);
    testcase( "size + 0 + prec:%05.3f\n", -12547.58);
    testcase( "size + 0 + prec + hash:%0#5.0f\n", -12547.58);
    testcase( "size + minus + prec:%-5.3f\n", -12547.58);
    testcase( "size + minus + prec + hash:%-#5.0f\n", -12547.58);
    testcase( "size + plus + 0 + prec:%+05.3f\n", -12547.58);
    testcase( "size + plus + 0 + prec + hash:%0+#5.0f\n", -12547.58);
    testcase( "size + espace + zero + prec:%0 5.3f\n", -12547.58);
    testcase( "size + espace + zero + prec:% 05.3f\n", -12547.58);
    testcase( "size + espace + zero + prec + hash:%#0 5.0f\n", -12547.58);
    testcase( "size + minus + plus + prec:%-+5.3f\n", -12547.58);
    testcase( "size + minus + plus + prec + hash:%-#+5.0f\n", -12547.58);
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
	double db = 0;
	testcase("size + espace + zero + prec + hash:%#0 5.0f\n", db);
	testcase("test basique:");
	testcase("space:% f\n", db);
	testcase("plus:%+f\n", db);
	testcase("hash:%#f\n", db);
	testcase("precision:%.2f\n", db);
	testcase("big prec:%.14f\n", db);
	testcase("precision + hash:%#.0f\n", db);
	testcase("space + prec:% .5f\n", db);
	testcase("space + prec + hash:%# .0f\n", db);
	testcase("space + prec + hash:% #.0f\n", db);
	testcase("Plus + prec / grande:%+.5f\n", db);
	testcase("Plus + prec / petite:%+.0f\n", db);
	testcase("Plus + prec + hash:%#+.0f\n", db);
	testcase("Prec + 0:%0.5f\n", db);
	testcase("Prec + minus:%-.5f\n", db);
	testcase("size:%5f\n", db);
	testcase("size + space:% 5f\n", db);
	testcase("size + plus:%+5f\n", db);
	testcase("size + space:%# 5f\n", db);
	testcase("size + plus:%#+5f\n", db);
	testcase("size + minus:%-5f\n", db);
	testcase("size + 0:%05f\n", db);
	testcase("size + 0 + plus:%+05f\n", db);
	testcase("size + 0 + plus:%0+5f\n", db);
	testcase("size + 0 + prec:%05.3f\n", db);
	testcase("size + 0 + prec + hash:%0#5.0f\n", db);
	testcase("size + minus + prec:%-5.3f\n", db);
	testcase("size + minus + prec + hash:%-#5.0f\n", db);
	testcase("size + plus + 0 + prec:%+05.3f\n", db);
	testcase("size + plus + 0 + prec + hash:%0+#5.0f\n", db);
	testcase("size + espace + zero + prec:%0 5.3f\n", db);
	testcase("size + espace + zero + prec:% 05.3f\n", db);
	testcase("size + minus + plus + prec:%-+5.3f\n", db);

#endif

#if 1
	double db2 = 45.123456789;
	testcase("size + espace + zero + prec:%010.0f\n", db2);
	testcase("size + espace + zero + prec:%0 10.2f\n", db2);
	testcase("size + espace + zero + prec:%010.2f\n", db2);
	testcase("size + espace + zero + prec:%0 5.0f\n", db2);
	testcase("size + espace + zero + prec + hash:%#0 5.0f\n", db2);

	testcase("space:% f\n", db2);
	testcase("plus:%+f\n", db2);
	testcase("hash:%#f\n", db2);
	testcase("precision:%.2f\n", db2);
	testcase("big prec:%.14f\n", db2);
	testcase("precision + hash:%#.0f\n", db2);
	testcase("space + prec:% .5f\n", db2);
	testcase("space + prec + hash:%# .0f\n", db2);
	testcase("space + prec + hash:% #.0f\n", db2);
	testcase("Plus + prec / grande:%+.5f\n", db2);
	testcase("Plus + prec / petite:%+.0f\n", db2);
	testcase("Plus + prec + hash:%#+.0f\n", db2);
	testcase("Prec + 0:%0.5f\n", db2);
	testcase("Prec + minus:%-.5f\n", db2);
	testcase("size:%5f\n", db2);
	testcase("size + space:% 5f\n", db2);
	testcase("size + plus:%+5f\n", db2);
	testcase("size + space:%# 5f\n", db2);
	testcase("size + plus:%#+5f\n", db2);
	testcase("size + minus:%-5f\n", db2);
	testcase("size + 0:%05f\n", db2);
	testcase("size + 0 + plus:%+05f\n", db2);
	testcase("size + 0 + plus:%0+5f\n", db2);
	testcase("size + 0 + prec:%05.3f\n", db2);
	testcase("size + 0 + prec + hash:%0#5.0f\n", db2);
	testcase("size + minus + prec:%-5.3f\n", db2);
	testcase("size + minus + prec + hash:%-#5.0f\n", db2);
	testcase("size + plus + 0 + prec:%+05.3f\n", db2);
	testcase("size + plus + 0 + prec + hash:%0+#5.0f\n", db2);
	testcase("size + espace + zero + prec:%0 5.3f\n", db2);
	testcase("size + espace + zero + prec:% 05.3f\n", db2);
	testcase("size + minus + plus + prec:%-+5.3f\n", db2);
	testcase("size + minus + plus + prec + hash:%-#+5.0f\n", db2);




#endif

#if 1
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
#if 1

// type c
    testcase("{%3c}\n", 0);
    testcase("%c\n", 0);
	testcase("okone%-20coktwo%-lcokthree\n", 'a', (wchar_t)'b');
	testcase("okone%-20coktwo%-lcokthree\n", 'a', 'b');
	testcase("%c%12c%%%%oktwo%-lcokthree%-10c%50c\n",'a', 'b', 'c', 'd', 'e');
	testcase("========%lc\n", (wchar_t)'&');
	testcase("%.2c", 5);
	testcase("%.2c", 0);
	testcase("%.2c", NULL);
	testcase("%2c", 0);
	testcase("% c", 0);
#endif

#if 1
 // type s
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

	testcase("%4.s", "42");
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

	char    *str;
	str = "Okalm";
	testcase("precision / zero:%.0s", str);
	testcase("precision / zero:%.s", str);
	testcase("precision / petite:%.5s", str);
	testcase("precision / grande:%.15s", str);
	testcase("prec + minus:%-.5s", str);
	testcase("size / petite:%5s", str);
	testcase("size / grande:%15s", str);
	testcase("Minus + size / petite:%-5s", str);
	testcase("Minus + size / grande:%-15s", str);
	testcase("Minus + size + prec:%-15.5s", str);
	testcase("NULL:%12s", NULL);
	testcase("NULL:%1s", NULL);
	testcase("NULL:%-5.6s", NULL);
	testcase("NULL:%-.8s", NULL);
	testcase("NULL:%.12s", NULL);
	testcase("empty:%-.5s", "");
	testcase("empty:%-1.32s", "");
	testcase("empty:%1.4s", "");
	testcase("empty:%23s", "");

#endif
#if 1

//type d
    testcase("{% 03d}", 0);
	testcase("max int :  %d", INT16_MAX);
	testcase("min int :  %d", INT16_MIN);
	testcase("max int :  %d", INT32_MAX);
	testcase("min int :  %d", INT32_MIN);
	testcase("max long :  %ld", LONG_MAX);
	testcase("max long long :  %lld", __LONG_LONG_MAX__);
	testcase("min long long :  %lld",LLONG_MIN);
	testcase("min long :  %ld", LONG_MIN);
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
#endif

#if 1
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
#endif

#if 1
// type u
    unsigned int        un_int;
    un_int = 0;
    testcase("null prec : %.0u\n", un_int);
    un_int = 8;
    testcase("null prec : %.0u\n", un_int);
    un_int = -1234212;
    testcase("null prec : %.0u\n", un_int);
    un_int = -1;
    testcase("null prec : %.0u\n", un_int);
    un_int = 12354;
    testcase("null prec : %.0u\n", un_int);
    un_int = 45;
    testcase("precision:%.5u\n", un_int);
    testcase("Prec + 0:%0.5u\n", un_int);
    testcase("Prec + minus:%-.5u\n", un_int);
    testcase("size:%5u\n", un_int);
    testcase("size + minus:%-5u\n", un_int);
    testcase("size + 0:%05u\n", un_int);
    testcase("size + 0 + prec:%05.3u\n", un_int);
    testcase("size + minus + prec:%-5.3u\n", un_int);
    testcase("%-5.3u\n", un_int);
    testcase("%050.5u\n", un_int);
    testcase("%050u\n", un_int);
    testcase("%050.u\n", un_int);
    testcase("%-1.45u\n", un_int);
    testcase("%-55.35u\n", un_int);
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




    // ft_printf("one%#sf|\n", 1);
    // testcase("one%#sf|\n", 1);   //printf seg fault in this case


    fclose(fd_oracle_p);
    fclose(fd_test_p);
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

