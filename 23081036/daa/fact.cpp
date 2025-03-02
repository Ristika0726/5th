#include <iostream>
using namespace std;

// Function to compute factorial and count steps
int fact(int num, int &steps) {
    // Increment the step count
    steps++;

    // Base case
    if (num == 1) {
        return 1;
    }

    // Recursive case
    return num * fact(num - 1, steps);
}

int main() {
    int n, steps = 0;

    // Input number
    cout << "Enter an integer: ";
    cin >> n;

    // Compute factorial and track steps
    int result = fact(n, steps);

    // Output results
    cout << "The factorial of " << n << " is " << result << endl;
    cout << "Number of steps required: " << steps << endl;

    return 0;
}

