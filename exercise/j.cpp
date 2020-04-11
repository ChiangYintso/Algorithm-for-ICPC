//
// Created by Jiang Yinzuo on 2020/4/9.
//

#include <cstdio>

const int MAX = 70000;
int next[MAX];
char s[MAX];

void get_next(char *word, int len) {
    next[0] = -1;
    int i = 0, j = -1;
    while (i < len) {
        if (j != -1 && word[i] != word[j]) {
            j = next[j];
        } else {
            next[++i] = ++j;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    int ans = 0;
    int idx = 0;
    bool done = false;
    while (!done) {
        for (int i = 1; i <= n; ++i) {
            if (next[i] ==  next[i - 1] ) {
                ans++;
            }
        }
    }

    if (next[n] != 0) ans++;
    printf("%d\n", ans);
    return 0;
}

































//https://www.cnblogs.com/JHSeng/p/12185062.html