#include <iostream>

using namespace std;

int steps = 0;  // Counter for steps

// Recursive function to find nth Fibonacci number
int fibonacci(int n) {
    steps++;  // Count the step of calling fibonacci(n)
    if (n == 1||n==0)
        return n;  // Base case
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter the term (n) for Fibonacci sequence: ";
    cin >> n;

    int result = fibonacci(n);
    
    cout << "The " << n << "th Fibonacci number is: " << result << endl;
    cout << "Total steps: " << steps << endl;
    
    return 0;
}

