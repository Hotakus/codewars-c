#include "stdlib.h"
#include <math.h>
#include "include/utilities.h"

#if DEBUG == 1
#include <stdio.h>
#endif

/**
 * 统计十进制数字位数
 * @param num 待统计的数
 * @return 位数
 */
int digits_len(long long int num) {
    int digit = 0;
    do {
        num /= 10;
        digit++;
    } while ((num));
    return digit;
}


/**
 *
 * @param num
 * @return
 */
int get_digit(long long int num, unsigned char d) {
    num /= (int) pow(10, d);
    return (int) (num % 10);
}


/**
 * 实现
 * @param num
 * @return
 */
char *num_to_str(long long int num) {
    // TODO: 支持负数
    int len = digits_len(num);
    char *buf = (char *) calloc(len, sizeof(char));
    for (int i = len; i > 0; --i) {
        buf[i - 1] = (char) (num % 10 + 48);
        num /= 10;
    }
    buf[len] = '\0';
    return buf;
}


/**
 * 统计字符串中，特定字符出现的次数
 *
 * @param src 待查字符串
 * @param ch 指定字符
 * @return 指定字符出现次数
 */
int alpha_find_times(const char *src, const char ch) {
    int ascii[128] = {0};
    while (*src) ascii[*src++ - 'a'] += 1;
    return ascii[ch - 'a'];
}


int str_cmp(const char *s1, const char *s2) {
    while ((*s1 != '\0') && (*s1 == *s2)) {
        s1++;
        s2++;
    }

    int t;
    t = *s1 - *s2;

    if (t == 0) {
#if DEBUG == 1
        printf("%s: same string\n", __FUNCTION__);
#endif
        t = 0;
    } else if (t > 0) {
#if DEBUG == 1
        printf("%s: str1 is bigger\n", __FUNCTION__);
#endif
        t = 1;
    } else {
#if DEBUG == 1
        printf("%s: str2 is bigger\n", __FUNCTION__);
#endif
        t = -1;
    }

    return t;
}


void str_cpy(char *dest, const char *src) {
    if (dest == NULL || src == NULL) {
#if DEBUG == 1
        printf("%s: dest or src is null.\n", __FUNCTION__);
#endif
        return;
    }

    while (*src != '\0')
        *dest++ = *src++;

    *dest = '\0';
}


int str_len(const char *src) {
    int len = 0;
    while (*src++ != '\0') len++;
    return len;
}


/**
 * 将 s1 与 s2 进行连接，并返回新的字符串
 * @param s1 字符串1
 * @param s2 字符串2
 * @return 返回连接后的字符串，用完后需要free
 */
char *str_conn(char *s1, char *s2) {
    int s1_len = BA_STRLEN(s1);
    int s2_len = BA_STRLEN(s2);
    char *buf = calloc(s1_len + s2_len, sizeof(char));
    BA_STRCPY(buf, s1);
    BA_STRCPY(&buf[s1_len], s2);
    return buf;
}


/**
 * 通过sep，实现对字符串的分割，并返回分割后字符串列表
 *
 * @param src 源待处理字符串
 * @param sep 分隔符
 * @param wn 词数
 * @return 处理后的字符串列表
 */
char **str_split(const char *src, char sep, int *wn) {
    if (src == NULL) return NULL;

    char *src2 = (char *) calloc(BA_STRLEN(src) + 1, sizeof(char));
    BA_STRCPY(src2, src);

    int cnt = 0;
    while (*src) if (*src++ == sep) cnt++;
    cnt += 1;

    if (wn) *wn = cnt;

    char **tmp = (char **) calloc(cnt, sizeof(char *));
    char **pt = tmp;

    *pt = src2;
    do {
        if (*src2 == sep) {
            *++pt = (src2 + 1); // 将单词存入tmp
            *src2++ = '\0';
        }
    } while (*src2++);

    return tmp;
}

void str_split_free(char **buf) {
    free((void *) &buf[0][0]);
    free(buf);
}


char *str_chr(char ch, char *str) {
    for (int i = 0; i < BA_STRLEN(str); ++i)
        if (ch == str[i])
            return str;
    return NULL;
}