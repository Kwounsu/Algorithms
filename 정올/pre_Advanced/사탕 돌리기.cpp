#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll N, K, Q, x, cnt=0;
    bool first_finished = true;
    bool all_done = true;
    cin>>N>>K>>Q;
    for (int i=1; i<=N; i++)
        for (int j=0; j<K; j++){
            cin>>x;
            if (x < i) cnt++;
            if (i == 1 && x != i) first_finished = false;
            if (x != i) all_done = false;
        }
    if (all_done){
        cout<<1;
        return 0;
    }
    if (cnt && first_finished) cnt++;
    cout<<(cnt<=Q);
 
    return 0;
}
