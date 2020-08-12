#include <cstdio>
#include <algorithm>
#include <ctime>

int arr[5001][5001] = {0};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int max_v[5001][5001] = {0};

inline int max(int a, long long b) {
    return a > b ? a : (int)b;
}

void get_max(int from, int to, int m) {
    for (int i = from; i <= to; ++i)
        max_v[from][m] = max(max_v[from][m], arr[i][m]);
}

long long get_max2(int n, int from, int to) {
    long long  answer = 0;
    for (int j = from; j <= to; ++j) {
        answer = max(max_v[n][j], answer);
    }
    return answer;
}

void solve(int n, int m, int k) {
    for (int i = 1; i + k - 1 <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            get_max(i, i + k - 1, j);
//            printf("%d ", max_v[i][j]);
        }
//        printf("\n");
    }

    long long result = 0;
    for (int i = 1; i + k - 1 <= n; ++i) {
        for (int j = 1; j + k - 1 <= m; ++j) {
            result += get_max2(i, j, j + k - 1);
        }
    }
    printf("%lld\n", result);

}

int main() {

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    clock_t start = clock();

//    long long temp_max = 0;
//    int min_n_m = n < m ? n : m;
//    for (int i = 1; i <= min_n_m; ++i)
//        arr[i][i] = i;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (arr[j][i]) arr[i][j] = arr[j][i];
            else arr[i][j] = lcm(i, j);
//            temp_max = max(temp_max, arr[i][j]);
        }
    }
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j < i; ++j) {
//            arr[i][j] = arr[j][i];
//        }
//    }
//    printf("%lld\n", temp_max);
    solve(n, m, k);
    printf("%d\n", clock() - start);

//    long long va = 0;
//    for (int i = 1; i <= n; ++i)
//        for(int j = 1; j <= m; ++j)
//            va += arr[i][j];
//        printf("%lld\n", va);
    return 0;
}
