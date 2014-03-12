#include<iostream>
using namespace std;
class Base {
    public:
       // Base* printThisPointer(){cout<<"*******"<<this<<"*********"<<endl;}  //sizeof=1
       virtual Base* printThisPointer(){cout<<"*******"<<this<<"*********"<<endl;} //sizeof=8
};
class A{
    public:
        A(Base* );
    private:
        Base* pB;
};

A::A(Base* p){
    pB=p;pB->printThisPointer();
    cout<<"*******"<<this<<"*********in Class A"<<endl;
}
int main()
{
    Base b;
    Base* pB=&b;
    cout<<"*******"<<pB<<"*********"<<sizeof(Base)<<endl; 
    Base* pB2=b.printThisPointer();

    A a(pB);
    cout<<"Class A:*******"<<&a<<"*********"<<endl;
    long long* longP=(long long*)&a;
    cout<<"********0x"<<hex<<*longP<<"********"<<endl;
    cout<<"********0x"<<hex<<*(longP+1)<<"********"<<endl;
    
}


add in experiment_branch
