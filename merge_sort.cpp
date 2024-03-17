// not working

#include <iostream>
using namespace std;

void merge(int arr[], int s, int m, int e) {
    int i = s;
    int j = m+1;
    int k = s;
    int* temp = new int[e - s + 1];

    while (i <= m && j <= e) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= m) {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= e) {
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (int i = s; i <= e; i++) {
        arr[i] = temp[i - s];
    }
    delete[] temp;
}

void mergeSort(int arr[], int s, int e) {
    int m;
    if (s < e) {
        m = (s + e) / 2;
        mergeSort(arr, s, m);
        mergeSort(arr, m+1, e);
        merge(arr, s, m, e);
    }
}

int main(){
    int size;
    cout << "Size of array: ";
    cin >> size;
    int* arr = new int[size];
    
    for (int i = 0; i < size;i++) {
        cout << "Index " << i << " :";
        cin >> arr[i];
    }

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;

}
