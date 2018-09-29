#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 */

/**
 * 比较次数太多，性能较低，可以进一步优化
 */
int lengthOfLongestSubstring(char *s) {
    if (!s) {
        return 0;
    }
    size_t len = strlen(s);
    if (len < 2) {
        return (int)len;
    }
    char *p1 = s;
    char *p2 = s;
    int max = 0;
    while ('\0' != *p2) {
        p2++;
        char *p = p1;
        while (p != p2) {
            if (*p != *p2) {
                max = (int)(max > (p2 - p) ? max : (p2 - p));
                p++;
            } else {
                p1 = ++p;
                break;
            }
        }
    }
    return max;
}

int main(int argc, const char *argv[]) {
    int i = 0;
    
    i = lengthOfLongestSubstring("abcabcbb");// 3
    printf("i = %d\n", i);

    i = lengthOfLongestSubstring("abcadbcbbbcadebb");// 5
    printf("i = %d\n", i);

    i = lengthOfLongestSubstring("www");// 1
    printf("i = %d\n", i);
    
    i = lengthOfLongestSubstring("pwwkew");// 3
    printf("i = %d\n", i);
    
    i = lengthOfLongestSubstring("pwwwkkeew");// 2
    printf("i = %d\n", i);
    
    return EXIT_SUCCESS;
}
