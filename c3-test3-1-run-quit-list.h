#include<iostream>
#include <thread>
#include <chrono>
#include <vector>
#include"c3-test3-2-run-quit-list.h"


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

char GSTR[] = "hello every body"; 
void *pvoid = GSTR;

int main()
{
    // std::cout<<"hello world\n";

    std::vector<std::thread> vt;
    for (int i=1; i<4; ++i) {
        vt.push_back(std::thread(work_thread, i, 60));
    }
    // for (auto& t : vt) {
    //     t.join();
    // }

    int n=100;
    int sum=0;
    while (n > 0)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout<<"main thread n="<<n<<"\n";
        n--;
        sum = fun_sum(sum, n);
    }
    std::cout<<"app end\n";
    return 0;
}

