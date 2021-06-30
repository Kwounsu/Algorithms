void insertion_sort(int arr[], int n){
    int i, j, key;
    for (i=1; i<n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        
        // print
        for (j=0; j<n; j++)
            printf("%d ", arr[j]);
        printf("\n");
    }
}
