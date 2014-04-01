#include<iostream>
using namespace std;
#ifdef TEST1
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
#endif




class BaseA{
    public:
        BaseA(void *id){cout<<"BaseA::*******id="<<id<<"*********this="<<this<<endl;}
        virtual void BaseAprintThisPointer(void* id){cout<<"BaseA::*******id="<<id<<"*********this="<<this<<endl;} //sizeof=8
    private:
        char b[0x100];
        
};
class BaseB{
    public:
        BaseB(void *id){cout<<"BaseB::*******id="<<id<<"*********this="<<this<<endl;} 
        virtual void BaseBprintThisPointer(void* id){cout<<"BaseB::*******id="<<id<<"*********this="<<this<<endl;} //sizeof=8
    private:
        char b[100];
};

class Derive: public BaseA,public BaseB{
    public:
        Derive():BaseA(this),BaseB(this){cout<<"Derive::*******this="<<this<<"***********"<<endl;}
};
int main()
{
#ifdef TEST1
    Base b;
    Base* pB=&b;
    cout<<"*******"<<pB<<"*********"<<sizeof(Base)<<endl; 
    Base* pB2=b.printThisPointer();

    A a(pB);
    cout<<"Class A:*******"<<&a<<"*********"<<endl;
    long long* longP=(long long*)&a;
    cout<<"********0x"<<hex<<*longP<<"********"<<endl;
    cout<<"********0x"<<hex<<*(longP+1)<<"********"<<endl;
#else
    Derive d; 
    cout<<"sizeof(Derive)="<<sizeof(Derive)<<endl;
    d.BaseAprintThisPointer(&d);
    d.BaseBprintThisPointer(&d);
#endif
}


