#include <iostream>
using namespace std;

// Function to compute GCD and count steps
int gcd(int a, int b, int &steps) {
    // Increment the step count
    steps++;

    // Base cases
    if (a == 0 || b == 0) {
        return 0; // GCD undefined for 0
    } else if (a == b) {
        return a; // GCD found
    }

    // Recursive cases
    if (a > b) {
        return gcd(a - b, b, steps);
    } else {
        return gcd(a, b - a, steps);
    }
}

int main() {
    int num1, num2, steps = 0;

    // Input numbers
    cout << "Enter any two numbers: ";
    cin >> num1 >> num2;

    // Compute GCD and track steps
    gcd(num1, num2, steps);
	cout<<"";
    // Output the number of steps
    cout << "Number of steps required to compute GCD: " << steps << endl;
	cout<<"The gcd of the numbers "<<num1<<" and "<<num2<<" is "<<gcd(num1, num2, steps);
    return 0;
}
