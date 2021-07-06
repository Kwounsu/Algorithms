#include <stdio.h>

#define LM 500005

int arr[LM], tmp[LM];
int n;

void print();
void merge_sort(int, int);

int main() {
    int i, x;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    
    merge_sort(0, n - 1);
    
    return 0;
}

void print() {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge_sort(int start, int end) {
    // 0. base condition
    if (start >= end) return;
    
    // 1. divide
    int mid = (start + end) / 2;
    
    // 2. conquer
    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    
    // 3. merge
    int i = start, j = mid + 1, k = start;
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }
    
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= end) tmp[k++] = arr[j++];
    
    // 4. copy
    for (i = start; i <= end; ++i)
        arr[i] = tmp[i];
    
    print();
}
