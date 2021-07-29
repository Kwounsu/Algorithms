#include <bits/stdc++.h>
using namespace std;

bool split[100010];

void print_split(long long* arr, int n) {
    int i;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (split[i]) {
            printf("/ ");
            split[i] = false;
        }
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void check_split(long long* arr, int n, long long s, int k) {
    int i, cnt = 1;
    long long sum = 0;
    for (i = n-1; i >= 0; i--) {
        sum += arr[i];
        if (sum > s) {
            sum = arr[i];
            split[i+1] = true;
            cnt++;
        }
    }
    i = 1;
    while (cnt < k && i < n) {
        if (!split[i]) {
            split[i] = true;
            cnt++;
        }
        i++;
    }
}

bool is_possible(long long* arr, int n, long long m, int k) {
    int i, cnt = 1;
    long long sum = 0;
    for (i = 0; i < n; i++) {
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
    // Input
    int n, k;
    long long s=0, e=0, m;
    scanf("%d%d", &n, &k);
    long long books[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &books[i]);
        s = max(s, books[i]);
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
    check_split(books, n, s, k);
    print_split(books, n);

    return 0;
}
