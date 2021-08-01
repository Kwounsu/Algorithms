#include <bits/stdc++.h>
using namespace std;

priority_queue<int> Q;
int N;
long long cost, x;

int main(){
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%lld",&x);
        Q.push(-x);
    }

    while(--N){
        cost = cost -Q.top();
        x = - Q.top();
        Q.pop();
        cost = cost - Q.top();
        x = x- Q.top();
        Q.pop();
        Q.push(-x);
    }

    printf("%lld", cost);
    return 0;
}
