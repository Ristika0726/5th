#include <iostream>
using namespace std;

int main() {
    int max, hole;
    cout << "Enter the size of the array: ";
    cin >> max;

    int arr[max];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < max; i++) {
        cin >> arr[i];
    }

    cout << "The elements before sorting: " << endl;
    for (int i = 0; i < max; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Variables to track number of passes and steps
    int passes = 0, steps = 0;

    // Insertion Sort
    for (int i = 1; i < max; i++) {
        passes++; // Count each pass
        hole = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > hole) {
            steps++; // Count each comparison in the while loop
            arr[j + 1] = arr[j]; // Move element
            j = j - 1;
        }
        arr[j + 1] = hole;
        steps++; // Count the insertion step
    }

    cout << "The array after sorting: " << endl;
    for (int i = 0; i < max; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Output the number of passes and steps
    cout << "Number of passes: " << passes << endl;
    cout << "Number of steps: " << steps << endl;

    return 0;
}

