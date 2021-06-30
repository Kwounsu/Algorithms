#include <stdio.h>
 
int N, M, arr[10], check[10];

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
    
    switch (M) {
    case 1:
        for (int i = 1; i <= 6; i++) {
            arr[step] = i;
            dice(step + 1);
        }
        break;
    case 2:
        for (int i = arr[step - 1]; i <= 6; i++) {
            arr[step] = i;
            dice(step + 1);
        }
        break;
    case 3:
        for (int i = 1; i <= 6; i++) {
            if (check[i]) continue;
            check[i] = 1;
            arr[step] = i;
            dice(step + 1);
            check[i] = 0;
        }
        break;
    }
}
 
void print() {
    for (int i = 1; i <= N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
