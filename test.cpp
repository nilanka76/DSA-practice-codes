#include<iostream>

using namespace std;
class A{
protected:
    int a;
    int b;
public: 
    virtual void func(){
        cout<<"vitual"<<endl;
    };
};
class B: private A{
public:
    void func(int x, int y){
        a = x;
        b = y;
        cout<<a-b<<endl;
    } 
};
int main(){
    B b;
    A a;
    a.func();
    b.func(4,2);
}