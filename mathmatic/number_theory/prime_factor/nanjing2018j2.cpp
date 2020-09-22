#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define MAX 1000005//求MAX范围内的素数
using namespace std;
const int N = 1e6 + 5;
int su[MAX], cnt;
bool isprime[MAX];

void prime() {
    cnt = 1;
    memset(isprime, 1, sizeof(isprime));//初始化认为所有数都为素数
    isprime[0] = isprime[1] = 0;//0和1不是素数
    for (int i = 2; i < MAX; i++) {
        if (isprime[i])
            su[cnt++] = i;//保存素数i
        for (int j = 1; j < cnt && su[j] * i < MAX; j++) {
            isprime[su[j] * i] = 0;//筛掉小于等于i的素数和i的积构成的合数
        }
    }
}

vector<int> mp[MAX];

void init(int x, int pos) {
    for (int i = 1; su[i] * su[i] <= x; i++) {
        if (x % su[i] == 0) {
            mp[su[i]].push_back(pos);
            while (x % su[i] == 0)
                x /= su[i];
        }
    }
    if (x > 1) {
        mp[x].push_back(pos);
    }
}

int main() {
    prime();
    int a;
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i < cnt; i++)
            mp[su[i]].clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a);
            init(a, i);
        }
        long long ans = 0;
        for (int i = 1; i < cnt; i++) {
            if (mp[su[i]].size() == 0)
                continue;
            else {
                ans += mp[su[i]][0] * (n - mp[su[i]][0] + 1);
                for (int j = 1; j < mp[su[i]].size(); j++)
                    ans += (mp[su[i]][j] - mp[su[i]][j - 1]) * (n - mp[su[i]][j] + 1);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}