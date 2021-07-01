#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

void print();
void quick_sort(int, int);

int main() {
    int n, i, x;
    cin>>n;
    for(i = 0; i < n; i++) {
        cin>>x;
        arr.push_back(x);
    }
    
    quick_sort(0, n - 1);
    
    return 0;
}

void print() {
    for (int i = 0; i < arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void quick_sort(int low, int high){
    if (low >= high) 
        return;
    
    int i = low - 1;
    int pivot = arr[high];
    
    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    
    swap(arr[++i], arr[high]);
    print();
    quick_sort(low, i - 1);
    quick_sort(i + 1, high);
}
