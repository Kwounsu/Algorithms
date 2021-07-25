#include <bits/stdc++.h>
using namespace std;
 
int gcd_(int a, int b){return b ? gcd_(b, a % b) : a;}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int gcd, lcm;
    cin>>gcd>>lcm;
 
    int ab= lcm / gcd;
    int a;
 
    for (int i = 1; i*i <= ab; i++)
        if (gcd_(i, ab/ i) == 1 && ab% i == 0)
            a= i;
 
    printf("%d %d", a* gcd, ab/ a* gcd);
 
    return 0;
}
