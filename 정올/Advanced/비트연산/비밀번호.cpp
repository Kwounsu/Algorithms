#include <bits/stdc++.h>
using namespace std;

long long int bigger(long long int x){
    long long int smallest, ripple, ones;
    smallest = x&(-x);
    ripple   = x+smallest;
    ones     = x^ripple;
    ones     = (ones>>2)/smallest;
    return ripple|ones;
}

int main() {
    long long int n;
    scanf("%lld", &n);

    if (~bigger(~n) >= 0) printf("%lld ", ~bigger(~n));
    else printf("0 ");

    printf("%lld\n", bigger(n));
}
