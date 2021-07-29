#include <bits/stdc++.h>
using namespace std;

// 최대 배열의 크기인 50000에 4를 곱함
int tree[200000];
int N, Q, A[50050];

// query(트리노드번호, 구간시작, 구간끝, 쿼리시작, 쿼리끝)
int query(int cur, int s, int e, int qs, int qe){
    if (e < qs || qe < s) return 0;
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
        cout<<query(1, 1, N, a, b)<<'\n';
    }

    return 0;
}
