void bubble_sort(int arr[], int n){
    int i, j, key, tmp;
    for (i=n-1; i>0; i--) {
        for (j=0; j<i; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
