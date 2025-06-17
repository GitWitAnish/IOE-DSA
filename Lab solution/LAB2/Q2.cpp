// Generate the Fibonacci sequence up to the nth term

#include <iostream>

using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;

    cout << "Enter the number of terms: ";

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << fib(i) << " ";
    }

    cout << endl;

    return 0;
}