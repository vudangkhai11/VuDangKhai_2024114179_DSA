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
    int a[] = {11, 10, 32, 106, 38, 78, 203, 16, 84, 17, 39, 15};
    //heap_sort(a, 12);
    for (int i = 5; i >= 0; i--){
        heapify(a, 12, i);
        cout << "lan " << i << ":";
        for(int i = 0; i < 12; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}