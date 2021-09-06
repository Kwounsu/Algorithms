include<bits/stdc++.h>
using namespace std;
#define LL long long
int a, b, c, s, e;
 
// 낱개가 이득인 경우의 수
LL f(int x){
    if (x <= 0) return 0;
 
    LL i, n, sum = 0;
 
    for (i=1; (i-1)*b<x; i++){
        n = i*c/a - (i-1)*b;
        if (n<=0) break;
        sum += n;
    }
 
    if (sum > x) return x;
    return sum;
}
 
int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
 
    cin>>a>>b>>c>>s>>e;
 
    if (a*b <= c){
        cout<<e-s+1<<'\n'<<0;
    }else{
        int ans = f(e)-f(s-1);
        cout<<ans<<'\n'<<e-s+1-ans<<'\n';
    }
 
    return 0;
}
