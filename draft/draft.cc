#include <iostream>
#include <string>
#include <memory>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
// #include <cmath>
using namespace std;
using namespace std::chrono_literals;

void show_mem(char *start, int n){
    int i;
    for (i=0; i<n; i++){
        cout<<"#"<<i<<" ";
        printf("%.2x", start[i]);
        cout<<", ";
    }
    printf("\n");
}

int main() {
    int i = 0x123456;
    char *c = (char*)&i;
    if (*c) {
        cout<<"Little endian"<<endl;
    } else {
        cout<<"Big endian"<<endl;
    }
}