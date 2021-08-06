#include <bits/stdc++.h>
using namespace std;

int oneCount(long long int n){
	int i;
    for(i = 0; n != 0; i++) {
        n &= n-1;
    }
    return i;
}

long long int bigger(long long int n){
	long long int answer = n;
	while(1){
		answer++;
		if(oneCount(answer) == oneCount(n)) break;
	}
	return answer;
}

long long int smaller(long long int n){
	long long int answer = n;
	while(1){
		answer--;
		if(oneCount(answer) == oneCount(n)) break;
	}
	return answer;
}

int main(){
	long long int n;
    scanf("%lld", &n);

    long long int s = smaller(n);
    printf("%lld %lld\n", s>0?s:0, bigger(n));
}


//=====================================================


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
