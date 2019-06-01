#include<stdio.h>

void generate_pre(int *pre, char *p, int length)
{
    pre[1] = 0;

    int matched = 0;
    for (int i = 2; i <= length; ++i) {
        while (matched > 0 && p[matched+1] != p[i]) {
            matched = pre[matched];
        }
        if (p[matched+1] == p[i]) {
            ++matched;
        }
        pre[i] = matched;
    }    
}

void kmp_matcher(int *pre, char *p, int m, char *t, int n, int pos[][2], int *len)
{
    int matched = 0;
    int pos_idx = 0;
    for (int i = 1; i <= n; ++i) {
        while (matched > 0 && p[matched+1] != t[i]) {
            matched = pre[matched];
        }
        if (p[matched+1] == t[i]) {
            ++matched;
        }

        if (matched == m) {
            printf("(%d, %d)\n", i-m+1, i);
            pos[pos_idx][0] = i - m + 1;
            pos[pos_idx][1] = i;
            pos_idx++;
        }
    }
    *len = pos_idx;
}

void replace(char *p, int m, char *t, int n, char *v, int pos[][2])
{
    int pos_idx = 0;
    int t_idx = 1;
    for (int i = 1; i <= n; ++i) {
        if (n <= pos_idx) {
            t[t_idx++] = t[i];
        }
        else if (pos[pos_idx][0] <= i && i <= pos[pos_idx][1]) {
            
        }
    }
}

void del_substring(char *t, int n, int len, int pos[][2])
{
    int pos_idx = 0;
    int t_idx = 1;
    for (int i = 1; i <= n; ++i) {
        if (len <= pos_idx) {
            t[t_idx++] = t[i];
        }
        else if (pos[pos_idx][0] <= i && i <= pos[pos_idx][1]) {
            continue;
        }
        else if (i > pos[pos_idx][1]) {
            pos_idx++;
            i--;
        }
        else {
            t[t_idx++] = t[i];
        }
    }
    t[t_idx] = '\0';
}

int main()
{
    int pre[1000];  // prefix function
    char p[1000];
    char t[100000];
    int m, n;
    int pos[1000][2];
    int len;

    scanf("%s%d%s%d", p+1, &m, t+1, &n);
    generate_pre(pre, p, m);

    kmp_matcher(pre, p, m, t, n, pos, &len);
    printf("%d\n", len);
    del_substring(t, n, len, pos);
    printf("%s\n", t+1);

    return 0;
}
