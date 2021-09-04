#include <bits/stdc++.h>
using namespace std;
 
int s, e, ans, val, x,y;
bool visit[2021][2021];
 
int gcd(int a, int b){return b ? gcd(b, a % b) : a;}
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL),cout.tie(NULL);
 
    cin>>s>>e;
 
    for (int i=s; i<=e; i++)
        for (int j=1; j<=i; j++){
            val = gcd(i,j);
            if (visit[i/val][j/val]) continue;
            visit[i/val][j/val] = true;
            ans++;
        }
 
    cout<<ans<<'\n';
 
    return 0;
}
