#include<iostream>
#include<thread>
#include<mutex>

using namespace std;    

static mutex m;
void greet(int id)
{
    m.lock();
    // cout << "Hello World! from thread " << this_thread::get_id() << endl;
    cout << "Hello World! from thread " << id << endl;
    m.unlock();
}
const int n_threads = 10;
int main()
{
    thread t[n_threads];
    for(int i=0; i<n_threads; i+=1)
    {
        t[i] = thread(greet, i);
    }
    cout << "Hello World! from main thread" << endl;
    for(int i=0; i<n_threads; i+=1)
        t[i].join();
    return 0;
}
