void selection_sort(int arr[], int n){
    int i, j, tmp;
    for (i=0; i<n-1; i++) {
        int minIndex = i;
        for (j=i + 1; j<n; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = tmp;
    }
}
