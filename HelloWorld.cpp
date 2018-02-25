/*
Compiling command: g++ -std=c++11 -pthread HelloWorld.cpp
*/
#include <iostream>
#include <thread>
using namespace std;    

void greet()
{
    cout << "Hello World!" << endl;
}

int main(){
    thread t(greet);
    t.join();
    return 0;
}
