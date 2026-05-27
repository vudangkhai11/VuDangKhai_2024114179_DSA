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

int main() {

    return 0;
}