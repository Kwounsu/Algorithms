#include <stdio.h>

int visited[1000] = {0};
int COUNT = 1;

void mod(int, int, int);

int main() {
    int n, p;
    scanf("%d%d", &n, &p);
    mod(n, n, p);
    return 0;
}

void mod(int x, int n, int p) {
    if (visited[x]) {
        printf("%d\n", COUNT - visited[x]);
        return;
    }
    visited[x] = COUNT;
    COUNT++;
    mod((x * n) % p, n, p);
}
