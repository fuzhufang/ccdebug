#include<iostream>
#include <thread>
#include <chrono>

int fun1(int a, int b)
{
    int c = a + b;

    return c*c;
}

int main()
{
    std::cout<<"hello world\n";

    int n=100;
    int s=0;
    while (n > 0)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<<"n="<<n<<"\n";
        n--;
        s = fun1(s, n);
    }
    std::cout<<"app end\n";
    return 0;
}

