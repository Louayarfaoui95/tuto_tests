// test file for CallStackfile1
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include <stdio.h>

#include "cmocka.h"

#include "file1.h"
#include "file2.h"

void test_f1__1(void **state)
{
    (void) state; /* unused */
    int ret;

    ret = f1(1);
    assert_int_equal(0, ret);

}

int fa(int x)
{
  check_expected(x); // To ckeck the argument passed to Fa as input, which is an output of F2
  return mock();
}


/*
 * scenario ok with 2 call to fa with success
 */
/* Test1*/
void test_f2_1_1(void **state)
{
    (void) state; /* unused */
    int ret;
    expect_value(fa,x,1);
    will_return(fa, 0);
    expect_value(fa,x,2);
    will_return(fa, 15);
    ret = f2(1);
    assert_int_equal(0, ret);

}
/* Test2*/
void test_f2_1_2(void **state)
{
    (void) state; /* unused */
    int ret;
    expect_value(fa,x,10);
    will_return(fa, 0);
    expect_value(fa,x,11);
    will_return(fa, 10);
    ret = f2(10);
    assert_int_equal(0, ret);

}

/* Test3*/
void test_f2_1_3(void **state)
{
    (void) state; /* unused */
    int ret;
    expect_value(fa,x,10);
    will_return(fa, 0);
    expect_value(fa,x,11);
    will_return(fa, 19);
    ret = f2(10);
    assert_int_equal(0, ret);

}

/*Test 4*/
void test_f2_2_1(void **state)
{
    (void) state; /* unused */
    int ret;
    expect_value(fa,x,1);
    will_return(fa,-1);
    ret = f2(1);
    assert_int_equal(-1, ret);
}

/*Test 5*/
void test_f2_2_2(void **state)
{
    (void) state; /* unused */
    int ret;
    expect_value(fa,x,1);
    will_return(fa,1);
    ret = f2(1);
    assert_int_equal(-1, ret);
}

/*Test 6*/
void test_f2_3_1(void **state)
{
    (void) state; /* unused */
    int ret;
    expect_value(fa,x,8);
    will_return(fa,0);
    expect_value(fa,x,9);
    will_return(fa,9);
    ret = f2(8);
    assert_int_equal(-2, ret);
}

/*Test 7*/
void test_f2_3_2(void **state)
{
    (void) state; /* unused */
    int ret;
    expect_value(fa,x,19);
    will_return(fa,0);
    expect_value(fa,x,20);
    will_return(fa,20);
    ret = f2(19);
    assert_int_equal(-2, ret);
}

/*Test 8*/
void test_f2_3_3(void **state)
{
    (void) state; /* unused */
    int ret;
    expect_value(fa,x,1);
    will_return(fa,0);
    expect_value(fa,x,2);
    will_return(fa,1000);
    ret = f2(1);
    assert_int_equal(-2, ret);
}

/*Test 9*/
void test_f2_3_4(void **state)
{
    (void) state; /* unused */
    int ret;
    expect_value(fa,x,1);
    will_return(fa,0);
    expect_value(fa,x,2);
    will_return(fa,-1000);
    ret = f2(1);
    assert_int_equal(-2, ret);
}

/*Test 10*/
void test_f2_4_1(void **state)
{
    (void) state; /* unused */
    int ret;
    expect_value(fa,x,1000);
    will_return(fa,0);
    expect_value(fa,x,1001);
    will_return(fa,15);
    ret = f2(1000);
    assert_int_equal(0, ret);
}

/*Test 11*/
void test_f2_4_2(void **state)
{
    (void) state; /* unused */
    int ret;
    expect_value(fa,x,-10);
    will_return(fa,0);
    expect_value(fa,x,-9);
    will_return(fa,15);
    ret = f2(-10);
    assert_int_equal(0, ret);
}

const struct CMUnitTest do_something_tests[] = {
    cmocka_unit_test(test_f1__1),
    cmocka_unit_test(test_f2_1_1),
    cmocka_unit_test(test_f2_1_2),
    cmocka_unit_test(test_f2_1_3),
    cmocka_unit_test(test_f2_2_1),
    cmocka_unit_test(test_f2_2_2),
    cmocka_unit_test(test_f2_3_1),
    cmocka_unit_test(test_f2_3_2),
    cmocka_unit_test(test_f2_3_3),
    cmocka_unit_test(test_f2_3_4),
    cmocka_unit_test(test_f2_4_1),
    cmocka_unit_test(test_f2_4_2),
};


int main(void)
{
    return cmocka_run_group_tests(do_something_tests, NULL, NULL);
}
