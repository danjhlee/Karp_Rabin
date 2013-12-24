#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PRIME_NUM   101
#define ROLLING_HASH    1

/*
 * calcuate hash value of a string
 */
int hash_function(char *str)
{
    int i, str_len;
    int hash_value = 0;

    str_len = strlen(str);
    while (*str)
        ++str;
    --str;

    for (i=0; i<str_len; i++)
    {
        hash_value = hash_value + *str * pow(PRIME_NUM, i);
        --str;
    }
    return hash_value;
}

/*
 * extract a substring from begin index to end index of a string
 */
char *split_str(char *s, int begin, int end)
{
    char *t;
    int size, i;

    if (begin < end)
        size = end - begin + 1;
    else
        return NULL;

    t = (char *)calloc(size+1, sizeof(char));
    for (i=0; i<size; i++)
    {
        *t++ = *(s + begin + i);
    }
    *t = '\0';
    return (t-size);
}

/*
 * Using Karp-Rabin method, print out all matched index(es) of substring
 * in a string
 */
int isSubStr(char *str, char *sub)
{
    int n, m;
    int i, j;
    int match, found;
    int hstr, hsub;
    char *split;

    found = match = 0;
    n = strlen(str);
    m = strlen(sub);

    hsub = hash_function(sub);
    split = split_str(str, 0, m-1);
    hstr = hash_function(split);
    for (i=0; i<n-m; i++)
    {
        if (hsub == hstr)
        {
            for (j=0; j<m; j++)
            {
                if (*(sub+j) == *(split+j))
                    ++match;
            }
            if (match == m)
            {
                printf("sub string %s found at %d\n", sub, i);
                found = 1;
            }
            match = 0;
        }
        if (ROLLING_HASH)
            hstr = (hstr - *(str+i) * pow(PRIME_NUM, m-1)) * PRIME_NUM + *(str+i+m);
        else
        {
            split = split_str(str, i+1, i+m);
            hstr = hash_function(split);
        }
    }
    if (found)
        return 1;
    else
        return -1;
}


int main()
{
    char *sub = "abr";
    char *str = "abracadabra";


    isSubStr(str, sub);

    return 0;
}
