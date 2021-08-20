#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define X first
#define Y second

set<pii> ans;
int b[10], bl;

void dfs(int N) {
    if (N <= 0) return;

    for (int i = 0; i < 10; i++){
        int a[10] = { i }, al = 1;
        int K = N, A = i;
        while (K >= 10) {
            K -= A;
            A = K % 10;
            K /= 10;
            a[al++] = A;
        }
        if (K > 0 && K == A) {
            pii p;
            for (int j = al - 1; j >= 0; j--)
                p.first = p.first * 10 + a[j];
            for (int j = bl - 1; j >= 0; j--)
                p.first = p.first * 10 + b[j];
            for (int j = al - 1; j > 0; j--)
                p.second = p.second * 10 + a[j];
            for (int j = bl - 1; j >= 0; j--)
                p.second = p.second * 10 + b[j];
            ans.insert(p);
        }
    }

    if (N % 2 == 0) {
        b[bl++] = N % 10 / 2;
        dfs(N / 10);
        b[bl - 1] += 5;
        dfs(N / 10 - 1);
        bl--;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    dfs(N);

    printf("%d\n", ans.size());
    for (auto const &i : ans)
        printf("%d + %0*d = %d\n", i.X, (int)log10(i.X), i.Y, N);

    return 0;
}
