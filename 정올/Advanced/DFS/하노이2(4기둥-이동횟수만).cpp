#include <bits/stdc++.h>
using namespace std;

#define ulli unsigned long long int

int N, input[101], max_n;
ulli h3[65], h4[1501];

void hanoi3(){
    h3[1]=1;
    for(int i = 2; i <= 64; i++)
        h3[i] = 2 * h3[i-1] + 1;
}

void hanoi4(int k){
    if(h4[k-1] == 0)
        hanoi4(k-1);

    h4[k] = 2 * h4[k-1] + h3[1];
    for(int i = 1; i < 64; i++){
        if(2 * (h4[k-i] - h4[k-i-1]) - h3[i] - 1 < 0)
            break;
        if(2 * h4[k-i] + h3[i] < h4[k])
            h4[k] = 2 * h4[k-i] + h3[i];
    }
}

int main(){
    scanf("%d",&N);

    for(int i = 0; i < N; i++){
        scanf("%d", &input[i]);
        max_n = max(max_n, input[i]);
    }

    hanoi3();
    h4[1] = 1;
    hanoi4(max_n);

    for(int i = 0; i < N; i++)
        printf("%llu\n",h4[input[i]]);

    return 0;
}
