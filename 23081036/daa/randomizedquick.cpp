#include<iostream>
#include<cstdlib>  // For rand() and srand()
using namespace std;

int passes = 0;  // Count of recursive passes (calls to QuickSort)
int steps = 0;   // Count of steps (comparisons and swaps)

void QuickSort(int arr[], int l, int r);
int partition(int arr[], int l, int r);
void swap_elements(int &a1, int &a2);
void randomize_pivot(int arr[], int l, int r);

void QuickSort(int arr[], int l, int r){
    passes++;  // Increment the pass count for each recursive call to QuickSort
    if (l < r){
        randomize_pivot(arr, l, r);  // Randomize pivot selection
        int p = partition(arr, l, r);  // Partition and get pivot index
        QuickSort(arr, l, p - 1);  // Recursively sort the left part
        QuickSort(arr, p + 1, r);  // Recursively sort the right part
    }
}

int partition(int arr[], int l, int r){
    int x = l + 1, y = r;
    int P = arr[l];  // Pivot element (arr[l])

    while (x <= y){
        // Move x right until arr[x] > pivot
        while (x <= y && arr[x] <= P){
            x++;
            steps++;  // Increment steps for comparison
        }

        // Move y left until arr[y] < pivot
        while (x <= y && arr[y] > P){
            y--;
            steps++;  // Increment steps for comparison
        }

        // If x and y haven't crossed, swap arr[x] and arr[y]
        if (x < y){
            swap_elements(arr[x], arr[y]);
            steps++;  // Increment steps for swap
        }
    }

    // Place pivot element at the correct position
    swap_elements(arr[l], arr[y]);
    steps++;  // Increment steps for final swap
    return y;  // Return pivot index
}

void swap_elements(int &a1, int &a2){
    int temp = a1;
    a1 = a2;
    a2 = temp;
}

// Function to randomize the pivot by selecting a random index and swapping
void randomize_pivot(int arr[], int l, int r){
    int random_index = l + rand() % (r - l + 1);  // Generate random index
    swap_elements(arr[l], arr[random_index]);  // Swap the random element with arr[l]
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "The elements before sorting: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    QuickSort(arr, 0, n - 1);

    cout << "\nThe elements after sorting: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "\nTotal passes: " << passes << endl;
    cout << "Total steps: " << steps << endl;

    return 0;
}
 
