#include<iostream>
#include<thread>
#include<chrono>
#include<vector>


void work_thread(int thread_id, int n)
{
    std::cout<<thread_id<<" begin run\n";
    while (n-- > 0)
    {
        std::cout<<"thread id:"<<thread_id<<", n="<<n<<"\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout<<thread_id<<" end run\n";
}

// 加法 addition
int add(int a, int b)
{
    int c = a + b;
    return c;
}

// 乘法 multiplication
int mul(int a, int b)
{
    int c = a * b;
    return c;
}

int mul(int a, int b, int c)
{
    return a * b * c;
}

struct SPoint
{
    int x;
    int y;
    int z;
};

struct SVec
{
    SPoint v1;
    SPoint v2;
};

// 求一个表达式: 直角三角形 斜边c的平方 = 直角边a的平方 + 直角边b的平方
int expression(int a, int b)
{
    int c2 = add(mul(a,a), mul(b,b));
    // for (int i=0; i<c2; ++i) {
    //     std::cout<<i<<"\n";
    // }
    char s1[] = "hello 加茯苓 bilibili\n";
    std::cout<<s1;
    SVec vec {{1,2,3}, {10,11,12}};
    SVec vs[2] = {vec, vec};
    return c2;
}

// 递归实现斐波那契数列Fib(n)
uint32_t Fib(uint32_t n)
{
    if(n==1 || n==2) {
        return 1;
    } else {
        return Fib(n-1)+Fib(n-2);
    }
}

int main()
{
    std::vector<std::thread> vt;
    for (int i=1; i<4; ++i) {
        vt.push_back(std::thread(work_thread, i, 60));
    }

`
    int n=100;
    while (n > 0)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<<"main thread n="<<n<<"\n";
        n -= 1;
        auto c2 = expression(3,4);
        //auto c2 =  Fib(50);
    }
    std::cout<<"app end\n";
    return 0;
}

