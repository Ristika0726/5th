#include <iostream>

using namespace std;

int steps = 0;  // Counter for steps

// Iterative function to find nth Fibonacci number
int fibonacciIterative(int n) {
    if (n <= 1) return n;
    
    int a = 0, b = 1, c;
    steps++; // For the initial state of a and b
    
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
        steps++;  // Each loop iteration represents a step
    }
    
    return b;
}

int main() {
    int n;
    cout << "Enter the term (n) for Fibonacci sequence: ";
    cin >> n;

    int result = fibonacciIterative(n);
    
    cout << "The " << n << "th Fibonacci number is: " << result << endl;
    cout << "Total steps: " << steps << endl;
    
    return 0;
}

