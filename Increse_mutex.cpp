#include<iostream>
#include<thread>
#include<mutex>

using namespace std;    

static mutex m;
void increse(int &value)
{
    m.lock();
    value += 1;
    m.unlock();
}
const int n_threads = 1<<14;
int main()
{
    int sum = 0;
    thread t[n_threads];
    for(int i=0; i<n_threads; i+=1)
    {
        t[i] = thread(increse, ref(sum));
    }
    for(int i=0; i<n_threads; i+=1)
        t[i].join();
    cout << "The number of threads: " << n_threads << "\n";
    cout << "Sum: " << sum << endl;
    return 0;
}
