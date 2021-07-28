#include <bits/stdc++.h>
using namespace std;

void print_split(int* arr, int n, int k) {
    int i, sum = 0;
    for (i = n-1; i >= 0; i--) {
        sum += arr[i];
        if (sum > k) {
            sum = arr[i];
            printf("/ ");
        }
        printf("%d ", arr[i]);
    }
}

bool is_possible(int* arr, int n, int m, int k) {
    int sum = 0, cnt = 1;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > m) {
            sum = arr[i];
            cnt++;
        }
    }
    if (cnt > k) return false;
    return true;
}

int main() {
    int TC;
    scanf("%d", &TC);

    while(TC--) {
        // Input
        int n, k, s=INT_MAX, e=0, m;
        scanf("%d%d", &n, &k);
        int books[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &books[i]);
            s = min(s, books[i]);
            e+=books[i];
        }
        // binary search
        while (s <= e) {
            m = (s+e)/2;
            // assign books(pages) to workers
            if (is_possible(books, n, m, k))
                e = m - 1;
            else
                s = m + 1;
        }

        // 책 나누기 프린트
        print_split(books, n, s);
    }

    return 0;
}
