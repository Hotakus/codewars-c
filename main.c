#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "main.h"


char *str1 = "pqmpgtzzfaqftdawjqiurwscy";
char *str2 = "fevbekrsaanbbsbrzwwbvfsdb";
char *ex = "2:bbbbbb/1:qqq/2:sss/1:pp/1:tt/1:zz/2:ee/2:rr/2:vv/=:aa/=:ff/=:ww";

void fun_test() {
    // sort test
    printf("------------------ Sort Test (Begin) ------------------\n");
    char *test_s1 = calloc(BA_STRLEN(str1), sizeof(char));
    BA_STRCPY(test_s1, str1);
    bubble_sort_char(test_s1, false);
    printf("%s\n", test_s1);
    free(test_s1);
    printf("------------------ Sort Test ( End ) ------------------\n\n");

    // chain test
    printf("------------------ Chain Test (Begin) ------------------\n");
    long long int cost_time = run_time(COUNT_TIME_US, chain_test);
    run_time_show(&cost_time);
    printf("%s\n", CW_KATA_VER);
    printf("------------------ Chain Test ( End ) ------------------\n\n");

    // string mix
    printf("------------------ String Mix (Begin) ------------------\n");
    char *res1 = string_mix(str1, str2);
    printf("%s\n", res1);
    free(res1);
    printf("------------------ String Mix ( End ) ------------------\n\n");
}
#include <math.h>
int main() {
    printf("%f\n", h_fast_sqrt(4));
    printf("%f\n", sqrt(4));
    fun_test();
    return 0;
}