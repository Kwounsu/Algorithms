#include<bits/stdc++.h>
using namespace std;
  
// dp[i][j]: i~j에서 같은 브랜드 최대 악수
int dp[1100][1100];
  
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, x;
    cin>>n;
    vector<int> brands;
    for (int i = 0; i < n; i++) {
        cin>>x;
        brands.push_back(x);
    }
  
    // dp 점화
    for (int j = 1; j < n; j+=2){      // j: size추가
        for (int i = 0; i+j < n; i++){   // i: 시작점
            dp[i][i+j] = dp[i+1][i+j-1];
            if (brands[i] == brands[i+j]){
                dp[i][i+j] += 1;
            }
            // 내부 탐색
            for (int k = i; k < i+j; k++){
                dp[i][i+j] = max(dp[i][i+j], dp[i][k]+dp[k+1][i+j]);
            }
        }
    }
  
    cout<<dp[0][n-1];
  
    return 0;
}
