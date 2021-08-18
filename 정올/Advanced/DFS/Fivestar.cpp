#include <bits/stdc++.h>
using namespace std;

int N, M;
char arr[10][20];
int rcnt[6][11], ccnt[6][11], ans = 256;
int chk[11];

int calc(int cnt){
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (chk[j] || !ccnt[i][j]) continue;
            int k = j;
            while (k <= M && k < j + 5 && ccnt[i][k])
                k++;
            cnt++, j = k - 1;
            if (ccnt[i][j] < 5) return 256;
        }
    }
    return cnt;
}

void dfs(int step, int cnt){
    if (step > M) {
        ans = min(ans, calc(cnt));
        return;
    }

    if (rcnt[5][step] == 5) {
        chk[step] = 1;
        dfs(step + 1, cnt + 1);
        chk[step] = 0;
    }

    dfs(step + 1, cnt);
}

int main(){
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++){
            scanf(" %c", &arr[i][j]);
            if (arr[i][j] == '*') {
                rcnt[i][j] = rcnt[i - 1][j] + 1;
                ccnt[i][j] = ccnt[i][j - 1] + 1;
            }
        }

    if (N == 5) dfs(1, 0);
    else ans = calc(0);

    if (ans == 256) printf("-1\n");
    else printf("%d\n", ans);

    return 0;
}
