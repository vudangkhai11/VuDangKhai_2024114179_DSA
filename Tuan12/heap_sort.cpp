#include<iostream>
using namespace std;

void heapify(int a[], int n, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if(l < n && a[l] > a[largest]) {
        largest = l;
    }
    if(r < n && a[r] > a[largest]) {
        largest = r;
    }
    if(largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heap_sort(int a[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for(int i = n - 1; i >= 0; i--) {
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}


int main() {
    int a[] = {};
    return 0;
}