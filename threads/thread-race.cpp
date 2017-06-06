#include <iostream>
#include <cmath>
#include <vector>
#include <thread>
using namespace std;

// GLOBAL VARIABLE
int accum = 0;

void addMoney(int x) {
    //this_thread::sleep_for(chrono::milliseconds(100*x));
    for (int m=0; m<x; ++m) {
        accum++;
    }
}

int spawnThreads() {
    vector<thread> ths;
    for (int i = 1; i <= 20; ++i) {
        ths.push_back(thread(&addMoney, 1000));
    }

    for (auto& th : ths) {
        th.join();
    }
    return accum;
}

int main() {

    int val=0;
    for (int c=0; c<200; ++c) {
        accum = 0;
        if ((val = spawnThreads()) != 20000) {
            cout << "Error at count=" << c << " value=" << val 
                 << " instead of 20000" << "\n";
        } 
        else {
            cout << "Correct at count=" << c << " value=" << val 
                 << " which is 20000" << "\n";
        }
    }

    return 0;
}


