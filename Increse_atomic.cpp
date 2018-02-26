#include<iostream>
#include<thread>
#include<atomic>

using namespace std;    

void increse(atomic<int> &value)
{
    value += 1;
}
const int n_threads = 1<<14;
int main()
{
    atomic<int> sum;
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
