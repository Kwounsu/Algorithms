#include <bits/stdc++.h>
using namespace std;

int arr[25], h3[25], h4[25];

// (1<<k)-1
void get_h3(int k){
    h3[1]=1;
    for(int i = 2; i <= k; i++)
        h3[i] = 2 * h3[i-1] + 1;
}

int get_h4(int k){
    if(h4[k] == 0){
        if(k == 1){
            arr[k] = 1;
            return 1;
        }

        int min_cnt = 99999;
        for(int i = 1; i < k; i++){
            int cnt = 2 * get_h4(i) + h3[k-i];
            if(cnt < min_cnt){
                min_cnt = cnt;
                arr[k] = k - i;
            }
        }

        h4[k] = min_cnt;
    }

    return h4[k];
}

void hanoi3(int n, int s, int o, int e, int k){
    if(n <= 0) return;
    hanoi3(n-1, s, e, o, k-1);
    printf("%d : %c->%c\n", k, s+'A'-1, e+'A'-1);
    hanoi3(n-1, o, s, e, k-1);
}

void hanoi4(int n, int s, int o1, int o2, int e){
    if(n <= 0) return;
    hanoi4(n-arr[n], s, o2, e, o1);
    hanoi3(arr[n], s, o2, e, n);
    hanoi4(n-arr[n], o1, s, o2, e);
}

int main(){
    int N;
    scanf("%d", &N);

    get_h3(N);
    printf("%d\n", get_h4(N));

    hanoi4(N, 1, 2, 3, 4);

    return 0;
}
