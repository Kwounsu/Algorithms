#include <stdio.h>

int N, SIZE = 6;
int NUM[14], COMB[6];

void combination(int, int);

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &NUM[i]);

    combination(0, 0);
    
    return 0;
}

// Using DFS
void combination(int s, int L) {
    if (L == SIZE) {
		for (int i = 0; i < SIZE; i++) {
			printf("%d ", COMB[i]);
		}
		printf("\n");
	} else {
		for (int i = s; i < N; i++) {
			COMB[L] = NUM[i];
			combination(i + 1, L + 1);
		}
	}
}
