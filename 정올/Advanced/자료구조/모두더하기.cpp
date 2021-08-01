#include <bits/stdc++.h>
using namespace std;

int N, i, num;;
long long ans;
multiset<int> s;

int main() {
    scanf("%d", &N);

    for (i = 0; i < N; ++i) {
        scanf("%d", &num);
        s.insert(num);
    }

    set<int, greater<int> >::iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++)
        cout<<*itr<<" ";
    cout<<'\n';


    for (i = 1; i < N; ++i) {
        num = *s.begin(), s.erase(s.begin());
        num += *s.begin(), s.erase(s.begin());
        s.insert(num);
        ans += num;
    }

    printf("%lld\n", ans);

    return 0;
}
