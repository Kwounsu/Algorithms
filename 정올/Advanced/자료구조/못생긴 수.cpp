#include <cstdio>
#include <set>
#include <vector>
using namespace std;
 
using LL = long long;
const int LM = 1500;
vector<LL> ugly(1);
set<LL> tset = { 1 };
 
int main() {
    int i, tg;
    LL num;
    
    while (ugly.size() <= LM) {
        num = *tset.begin(), tset.erase(num) ;
        ugly.push_back(num);
        tset.insert(num * 2);
        tset.insert(num * 3);
        tset.insert(num * 5);
    }
    
    while (scanf("%d", &tg) && tg) {
        printf("%lld\n", ugly[tg]);
    }
    
    return 0;
}
