#include <iostream>
#include <string>
#include <memory>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;
using namespace std::chrono_literals;

struct Base {
    Base() {std::cout<<"Base::Base()\n";}
    ~Base() {std::cout<<"Base::~Base()\n";}
    void show() {
        cout<<"Base Class"<<endl;
    }
};

struct Derived : Base
{
    Derived() {cout<< "Derived::Derived\n";}
    ~Derived() {cout<< "Derived::~Derived\n";}
};

class Rectangle {
    private:
        int length;
        int breadth;
    public:
        Rectangle(){}
        Rectangle(int l, int b){
            length = l;
            breadth = b;
        }
    int area() {
        return length*breadth;
    }
};

void rec () {
    Rectangle *p = new Rectangle();
}


struct A {
    void show() {
        cout<<"This is A"<<endl;
    }
};

class SmartPtr{
    int *ptr;
    A* a;
    public:
    explicit SmartPtr(int *p=NULL) {ptr=p;}
    ~SmartPtr() {delete (ptr);}

    int& operator*() {
        return *ptr;
    }
    // int* operator->(){
    //     return ptr;
    // }
    A* operator->(){
        return a;
    }
    void print(){
        cout<<*ptr<<endl;
    }
};

class Some {
    public:
    SmartPtr p;
    Some(){}
    Some(int* k):p(k){}
    ~Some(){}
};

size_t& func

int main() {
    // unique_ptr<Rectangle> P1(new Rectangle(10, 5));
    // cout<<P1->area()<<endl;
    // unique_ptr<Rectangle> P2;
    // P2=move(P1);

    // cout<<P1->area()<<endl;
    // cout<<P2->area()<<endl;
    int a=60;
    int* b = new int(70);
    int *c = move(b);
    cout<<*b<<endl;
}