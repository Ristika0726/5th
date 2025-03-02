#include<iostream>
using namespace std;

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

    // Bubble sort with tracking passes and steps
    for (int i = 0; i < max - 1; i++) { // Outer loop (pass)
        passes++; // Increment pass count
        for (int j = 0; j < max - 1 - i; j++) { // Inner loop (comparison)
            steps++; // Increment step count for each comparison
            if (array[j] > array[j + 1]) {
                // Swap elements
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                steps++; // Increment step count for the swap
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

