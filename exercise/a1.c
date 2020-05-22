//
// Created by Jiang Yinzuo on 2020/5/16.
//

#include <stdio.h>

int main() {
    int n, m;
    int row[8] = {0};
    int col[8] = {0};
    scanf("%d %d", &n, &m);

    int x, y;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        if (x != 0) col[x + 3]++;
        else if (y > 0) col[3]++;
        else col[7]++;
        if (y != 0) row[y + 3]++;
        else if (x > 0) row[3]++;
        else row[7]++;
    }

    int ans = 0;
    for (int i = 0; i <= 7; ++i) {
        ans += (row[i] == 3);
        ans += (col[i] == 3);
    }
    printf("%d\n", ans);
    for (int i = 0; i < m; ++i)
        scanf("%*d %*d");
    return 0;
}