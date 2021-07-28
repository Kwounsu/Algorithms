#include <bits/stdc++.h>
using namespace std;

char str[550];
int len;
int dp[550][550]; //dp[i][j]: i번째부터 j번째까지 최장 유전자 길이

void solution()
{
    for(int j=1; j<len; ++j){ //처음부터 차근차근
        for(int i=j-1; i>=0; --i){
            //양끝에 'at' 혹은 'gc'가 올 때
            if((str[i] == 'a' && str[j] == 't') || (str[i] == 'g' && str[j] == 'c')){
                dp[i][j] = dp[i+1][j-1] + 2;
            }
            int m = 0;
            // X와 Y가 KOI 유전자라면, 이 둘을 연결한 XY도 KOI 유전자다.
            for(int k=1; k<=j-i; ++k){
                m = max(m, dp[i][j-k] + dp[j-k+1][j]);
            }
            dp[i][j] = max(dp[i][j], m);
        }
    }
}

int main() {
    scanf("%s", str);
    len = strlen(str);

    solution();
    printf("%d", dp[0][len-1]);
    return 0;
}
