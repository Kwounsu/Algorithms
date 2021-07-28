#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int n, one, two, three, four;
    scanf("%u", &n);
    
    one   = n>>24;
    two   = (n>>16) - (one<<8);
    three = (n>>8) - ((one<<16) + (two<<8));
    four  = n - ((one<<24) + (two<<16) + (three<<8));
    
    printf("%u", ((four<<24) + (three<<16) + (two<<8) + one));
    return 0;
}
