#include <stdio.h>
 
int N, M, arr[8];

void dice(int);
void print();

int main() {
    arr[0] = 1;
    scanf("%d %d", &N, &M);
    dice(1);
    return 0;
}

void dice(int step) {
    if (step > N) {
        print();
        return;
    }
    
    for (int i = 1; i <= 6; i++) {
        arr[step] = i;
        dice(step + 1);
    }
}
 
void print() {
    int sum = 0;
    for (int i = 1; i <= N; i++)
        sum += arr[i];
    if (sum != M) return;
    
    for (int i = 1; i <= N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
