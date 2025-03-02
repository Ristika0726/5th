#include<iostream>
using namespace std;

void swap(int &a1, int &a2) {
    int temp = a1;
    a1 = a2;
    a2 = temp;
}

int main() {
    int max;
    cout << "Enter the size of the array: ";
    cin >> max;

    int array[max];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < max; i++) {
        cin >> array[i];
    }

    cout << "The elements before sorting: " << endl;
    for (int i = 0; i < max; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Variables to track the number of passes and steps
    int passes = 0, steps = 0;

    // Sorting using Selection Sort (with tracking of passes and steps)
    for (int i = 0; i < max - 1; i++) { // Outer loop (pass)
        passes++; // Increment pass count
        for (int j = i + 1; j < max; j++) { // Inner loop (comparison)
            steps++; // Count comparison
            if (array[i] > array[j]) {
                swap(array[i], array[j]); // Swap elements
                steps++; // Count swap as a step
            }
        }
    }

    cout << endl;
    cout << "The elements after sorting: " << endl;
    for (int i = 0; i < max; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Output the number of passes and steps
    cout << "Number of passes: " << passes << endl;
    cout << "Number of steps: " << steps << endl;

    return 0;
}

