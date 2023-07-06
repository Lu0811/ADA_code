#include <iostream>

unsigned long fibo(unsigned n)
{
    if (n < 2)
        return 1;

    unsigned long f1 = 0, f2 = 1;
    unsigned long output;

    do
    {
        output = f1 + f2;
        f1 = f2;
        f2 = output;
    } while (--n >= 2);

    return output;
}

int main()
{
    unsigned n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    unsigned long result = fibo(n);
    std::cout << "The " << n << "th Fibonacci number is: " << result << std::endl;

    return 0;
}
