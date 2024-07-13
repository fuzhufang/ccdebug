#include<iostream>
#include<thread>
#include<chrono>
#include<vector>
#include <mutex>

void test_dead_for()
{
    for (u_char i=0; i<255; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        std::cout<<(int)i<<"\n";
    }
}

static std::mutex _sg_ma;
static std::mutex _sg_mb;

void threadAB()
{
    while (1)
    {
        std::cout<<"in  "<<__FUNCTION__<<"\n";

        {std::lock_guard<std::mutex> lck_a(_sg_ma);}
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        {std::lock_guard<std::mutex> lck_b(_sg_mb);}

        std::cout<<"out "<<__FUNCTION__<<"\n";
    }
    
}

void threadBA()
{
    while (1)
    {
        std::cout<<"in  "<<__FUNCTION__<<"\n";

        {std::lock_guard<std::mutex> lck_b(_sg_mb);}
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        {std::lock_guard<std::mutex> lck_a(_sg_ma);}

        std::cout<<"out "<<__FUNCTION__<<"\n";
    }
    
}

void testCoreDump()
{
    //char* p = nullptr;
    //*p = 'A';

    int a[2];
    a[1] = 100;
}

int main()
{
    // test1
    // test_dead_for();
    
    // test2
    // auto th1 = std::thread(threadAB);
    // auto th2 = std::thread(threadBA);
    // th1.join();
    // th2.join();

    // test3
    testCoreDump();

    return 0;
}

