#include<bits/stdc++.h>
using namespace std;
 
int n, val, ans, j;
int a[10010], b[10010], lis[10010];
int path[10010], indices[10010];
 
int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
 
    cin>>n;
    for(int i = 1; i <= n; i++) {
        cin>>val;
        a[val] = i;
        indices[i] = val;
    }
    for(int i = 0; i < n; i++) {
        cin>>val;
        b[i] = a[val];
    }
 
    for(int i = 0; i < n; i++) {
        for(j = ans - 1; j >= 0; j--)
            if(lis[j] <= b[i])
                break;
        lis[j + 1] = b[i];
        if(j + 1 == ans) ans++;
        if(j != -1) path[b[i]] = lis[j];
        else path[b[i]] = 0;
    }
 
    cout<<ans<<'\n';
    val = lis[ans - 1], ans = 0;
    while(val != 0) {
        a[ans++] = indices[val];
        val = path[val];
    }
    sort(a, a + ans);
    for(int i = 0; i < ans; i++)
        cout<<a[i] <<' ';
 
    return 0;
}
