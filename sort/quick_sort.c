#include <stdio.h>

void Swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int Partition(int arr[], int left, int right){
    int pivot = arr[left];
    int low = left + 1;
    int high = right;
 
    while (low <= high){
        // ASC order
        while (low <= right && pivot >= arr[low]){
            low++;
        }
        while (high >= (left+1)  && pivot <= arr[high]){
            high--;
        }
        
        /* 
        // DESC order
        while (low <= right && pivot <= arr[low]){
            low++;
        }
        while (high >= (left+1)  && pivot >= arr[high]){
            high--;
        }
        */
        
        if (low <= high){
            Swap(arr, low, high);
        }
    }
    Swap(arr, left, high);
    return high;
 
}
 
void QuickSort(int arr[], int left, int right)
{
    if (left <= right)
    {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot - 1);
        QuickSort(arr, pivot + 1, right);
    }
}

int main(){
    int N = 10
    int num[N];
  
    for(int i = 0; i < N; i++){
        scanf("%d", &num[i]);
    }
    
    QuickSort(num, 0, N - 1);
    
    for(int i = 0; i < N; i++){
        printf("%d ", num[i]);
    }
    
    return 0;
}


// Using Library
#include <stdio.h>
#include <stdlib.h>

int static compare (const void* a, const void* b)
{
    // ASC
    if (*(int*)a > *(int*)b)
        return 1;
    else if (*(int*)a < *(int*)b)
        return -1;
    /* DESC
    if (*(int*)a < *(int*)b)
        return 1;
    else if (*(int*)a > *(int*)b)
        return -1;
    */
    else
        return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    
    int arr[n];
    
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    qsort(arr, n, sizeof(int), compare);
    
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
