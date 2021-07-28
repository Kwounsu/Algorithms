#include <bits/stdc++.h>
using namespace std;

class Line {
public:
    int swtch, light, idx;
    Line(){swtch=0; light=0;}
}lines[10010];

int N, dp[10010], path[10010];
int indices[10010], tracked_path[10010], res[10010];

int main() {
    cin >> N;

    int val;
    for(int i=1;i<=N;i++) {
        scanf("%d",&val);
        lines[i].swtch = val;
        lines[val].idx = i;
    }
    for(int i=1;i<=N;i++) {
        scanf("%d",&val);
        lines[i].light = val;
        indices[i] = lines[val].idx;
    }

    for(int i=1;i<=N;i++) printf("%d %d\n", lines[i].idx, indices[i]);

    int cnt=0, pos;
    for(int i = 1; i <= N; i++){
        for(pos = cnt-1; pos >= 0; pos--){
            if(dp[pos] < indices[i]) break;
        }
        dp[pos+1] = indices[i];
        if(pos >= 0)path[indices[i]] = dp[pos];
        if(pos+1 == cnt) cnt++;
    }

    int next = dp[cnt-1];
    int c=0;
    while(next){
        res[c++] = next;
        next = path[next];
    }

    for(int i = 0 ; i < c;i++)
        tracked_path[i] = lines[res[i]].swtch;

    sort(tracked_path,tracked_path+c);

    cout<<cnt<<'\n';
    for(int i = 0;i < c; i++)
        cout<<tracked_path[i]<<' ';

    return 0;
}
