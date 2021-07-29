#include <bits/stdc++.h>
using namespace std;
const int MAXN=100010;
const int MINELE=-1000000001;
 
int N, M;
int tree[MAXN*4];
 
// query(트리노드번호, 구간시작, 구간끝, 쿼리시작, 쿼리끝)
int query(int cur, int s, int e, int qs, int qe){
    if (e < qs || qe < s) return MINELE;
    if (qs <= s && e <= qe) return tree[cur];
    int m = (s + e) / 2;
    int left = query(cur*2, s, m, qs, qe);
    int right = query(cur*2+1, m+1, e, qs, qe);
    return max(left, right);
}
 
// update(트리노드번호, 구간시작, 구간끝, 목표 위치, 업데이트할 값)
void update(int cur, int s, int e, int target, int val){
    if (s == e) {
        tree[cur] = val;
        return;
    }
    int m = (s + e) / 2;
    if (target <= m) update(cur*2, s, m, target, val);
    else update(cur*2+1, m+1, e, target, val);
    tree[cur] = max(tree[cur*2], tree[cur*2+1]);
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    cin>>N>>M;
 
    for (int i = 1; i <= N*4; i++)
        tree[i] = MINELE;
 
    int a, b, c;
    for (int i = 1; i <= M; i++) {
        cin>>a>>b;
 
        if (a!=3) cin>>c;
        if (a==1) update(1, 1, N, b, c);
        else if (a==2) {
            int ans = query(1, 1, N, b, c);
            if (ans != MINELE)
                cout<<ans<<'\n';
        } else update(1, 1, N, b, MINELE);
    }
 
    return 0;
}
