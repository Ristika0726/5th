#include<iostream>
using namespace std;

int total_steps = 0; // Total steps (comparisons and swaps) during sorting

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1; // left child
    int r = 2*i + 2; // right child

    if (l < n) {
        total_steps++; // Comparison step for left child
        if (arr[l] > arr[largest]) {
            largest = l;
        }
    }
    if (r < n) {
        total_steps++; // Comparison step for right child
        if (arr[r] > arr[largest]) {
            largest = r;
        }
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        total_steps++; // Swap step
        heapify(arr, n, largest); // Recursively heapify the affected subtree
    }
}

void heapSort(int arr[], int n){
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move the current root to the end
        total_steps++; // Swap step
        heapify(arr, i, 0);    // Heapify the reduced heap
    }
}

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapSort(arr, n);

    cout << "The elements after sorting: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nTotal steps (comparisons and swaps): " << total_steps << endl;

    return 0;
}


