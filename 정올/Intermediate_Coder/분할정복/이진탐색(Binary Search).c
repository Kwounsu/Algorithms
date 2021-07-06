#include <stdio.h>
 
int bisect_recur(int [], int, int, int);
int bisect_loop(int [], int, int, int);
 
int main() {
    int i, n;
    scanf("%d", &n);
     
    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", arr + i);
     
    int target, q;
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &target);
        printf("%d ", bisect_loop(arr, 0, n - 1, target));
    }
     
    return 0;
}
 
int bisect_recur(int arr[], int low, int high, int target) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return bisect_recur(arr, mid + 1, high, target);
    else return bisect_recur(arr, low, mid - 1, target);
}
 
int bisect_loop(int arr[], int low, int high, int target) {
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
