#include <bits/stdc++.h>
using namespace std;

int N, heap[1<<19], heap_size;

void heap_push(int num){
    heap[++heap_size] = num;
    int child = heap_size;
    while (child > 1 && heap[child] > heap[child / 2]) {
        swap(heap[child], heap[child / 2]);
        child /= 2;
    }
}

void heap_pop(){
    int parent = 1, child = 2;
    swap(heap[1], heap[heap_size--]);
    while (child <= heap_size) {
        if (child < heap_size && heap[child + 1] > heap[child])
            child++;
        if (heap[child] <= heap[parent])
            break;

        swap(heap[child], heap[parent]);
        parent = child, child *= 2;
    }
}

void output(){
    for (int i = 1; i <= N; ++i)
        printf("%d ", heap[i]);
    puts("");
}

void heapify(){
    int i, val;
    scanf("%d", &N);
    for (i = 0; i < N; ++i) {
        scanf("%d", &val);
        heap_push(val);
    }
    output();
}

void solve(){
    for (int i = 0; i < N; ++i)
        heap_pop();
    output();
}

int main(){
    heapify();
    solve();
}
