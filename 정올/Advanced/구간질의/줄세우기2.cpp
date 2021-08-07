#include <bits/stdc++.h>
using namespace std;

int max_tree[200000];
int min_tree[200000];
int N, Q, A[50050];

// query(트리노드번호, 구간시작, 구간끝, 쿼리시작, 쿼리끝, 쿼리종류)
int query(int cur, int s, int e, int qs, int qe, int q){
    if (e < qs || qe < s) {
        if (q) return 0;
        return 1000001;
    }
    if (qs <= s && e <= qe) {
        if (q) return max_tree[cur];
        return min_tree[cur];
    }
    int m = (s + e) / 2;
    int left = query(cur*2, s, m, qs, qe, q);
    int right = query(cur*2+1, m+1, e, qs, qe, q);
    if (q) return max(left, right);
    return min(left, right);
}

// update(트리노드번호, 구간시작, 구간끝, 목표 위치, 업데이트할 값)
void update(int cur, int s, int e, int target, int val){
    if (s == e) {
        max_tree[cur] = val;
        min_tree[cur] = val;
        return;
    }
    int m = (s + e) / 2;
    if (target <= m) update(cur*2, s, m, target, val);
    else update(cur*2+1, m+1, e, target, val);
    max_tree[cur] = max(max_tree[cur*2], max_tree[cur*2+1]);
    min_tree[cur] = min(min_tree[cur*2], min_tree[cur*2+1]);
}

void init(){
    for (int i = 1; i <= N; i++)
        update(1, 1, N, i, A[i]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>N>>Q;
    for (int i = 1; i <= N; i++)
        cin>>A[i];

    init();
    
    int a, b;
    for (int i = 1; i <= Q; i++) {
        cin>>a>>b;
        cout<<query(1, 1, N, a, b, 1) - query(1, 1, N, a, b, 0)<<'\n';
    }

    return 0;
}
