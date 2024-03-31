#include <iostream>
using namespace std;

void max_heapify(int A[], int i, int heapsize) {
    int largest;
    int L = 2 * i + 1;
    int R = 2 * i + 2;

    if (L < heapsize && A[L] > A[i]) {
        largest = L;
    }
    else {
        largest = i;
    }

    if (R < heapsize && A[R] > A[largest]) {
        largest = R;
    }

    if (largest != i) {
        swap(A[i], A[largest]);
        max_heapify(A, largest, heapsize);
    }
}

void build_max_heap(int A[], int length) {
    for (int i = length / 2 - 1; i >= 0; i--) {
        max_heapify(A, i, length);
    }
}

void heap_sort(int A[], int length) {
    build_max_heap(A, length);
    for (int i = length - 1; i > 0; i--) {
        swap(A[0], A[i]);
        max_heapify(A, 0, i);
    }
}

int main() {
    cout << "Enter number of Elements in array : ";
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cout << "Element [" << i + 1 << "]: ";
        cin >> a[i];
    }

    cout << "Inputted Array : ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    heap_sort(a, n);

    cout << "Sorted Array : ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
