#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define X first
#define Y second

set<pii> ans;
int b[10], bl;

void dfs(int N) {
    if (N <= 0) return;

    for (int i = 0; i < 10; i++){
        int a[10] = { i }, al = 1;
        int K = N, A = i;
        while (K >= 10) {
            K -= A;
            A = K % 10;
            K /= 10;
            a[al++] = A;
        }
        if (K > 0 && K == A) {
            pii p;
            for (int j = al - 1; j >= 0; j--)
                p.first = p.first * 10 + a[j];
            for (int j = bl - 1; j >= 0; j--)
                p.first = p.first * 10 + b[j];
            for (int j = al - 1; j > 0; j--)
                p.second = p.second * 10 + a[j];
            for (int j = bl - 1; j >= 0; j--)
                p.second = p.second * 10 + b[j];
            ans.insert(p);
        }
    }

    if (N % 2 == 0) {
        b[bl++] = N % 10 / 2;
        dfs(N / 10);
        b[bl - 1] += 5;
        dfs(N / 10 - 1);
        bl--;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    dfs(N);

    printf("%d\n", ans.size());
    for (auto const &i : ans)
        printf("%d + %0*d = %d\n", i.X, (int)log10(i.X), i.Y, N);

    return 0;
}



///////////////////////////////////////////////



#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define endl '\n'
int n, H, S, L, big_num, small_num;
map<int,int> res, res_size;
 
int main(){
    cin>>n;
    // i: small_num 자릿수. res_size에 저장됨.
    // digit: 바뀌는 숫자(S) 자릿수.
    for(int i=0, digit=1; digit<=n; i++, digit*=10){
        if(n%digit%2) continue;
        H=n/digit/11;  // 앞부분
        S=n/digit%11;  // 중간 바뀌는 부분
        L=n%digit/2;   // 뒷부분
        if(S<=9 && H+S){
            big_num=(H*10+S)*digit+L;
            small_num = H*digit+L;
            res[big_num]=small_num;
            res_size[big_num]=i;
        }
        L=(n%digit+digit)/2;
        S=n/digit%11-1;
        if(S>=0 && L && H+S){
            big_num=(H*10+S)*digit+L;
            small_num = H*digit+L;
            res[big_num]=small_num;
            res_size[big_num]=i;
        }
    }
 
    cout<<res.size()<<endl;
    for(map<int,int>::iterator it=res.begin();it!=res.end();it++)
        cout<<it->X<<" + "<<setw(res_size[it->X])<<setfill('0')<<it->Y<<" = "<<n<<endl;
    return 0;
}
