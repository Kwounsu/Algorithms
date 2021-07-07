#include <stdio.h>

int stack[80000], top = 0;

int main() {
    long long answer = 0;
    int N, num;
    scanf("%d", &N);
    
    while (N--) {
        scanf("%d", &num);
        while (top > 0 && stack[top - 1] <= num) top--;
        answer += top;
        stack[top++] = num;
    }
    
    printf("%lld\n", answer);
    return 0;
}
