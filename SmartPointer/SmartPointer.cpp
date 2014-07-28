#include<iostream>
using namespace std;

class RefBase{
    public:
        RefBase(int m):mRefCnt(m){cout<<"RefBase Constructor"<<mRefCnt<<endl;}
        RefBase():mRefCnt(0){cout<<"RefBase default Constructor"<<endl;}
        int incRef();
        int decRef();
    private:
        int mRefCnt;
};

int RefBase::incRef()
{
    mRefCnt++;
    cout<<"mRefCnt="<<mRefCnt<<endl;
    return mRefCnt;
}
int RefBase::decRef()
{
    mRefCnt--;
    cout<<"mRefCnt="<<mRefCnt<<endl;
    if(mRefCnt == 0)
        delete this;
    return mRefCnt;
}

class TestClass:public RefBase{
    public:
        TestClass(int m):RefBase(m){cout<<"TestClass Constructor"<<endl;};
        TestClass():RefBase(0){cout<<"TestClass Constructor (0)"<<endl;};
    private:
    int test;
};

template <typename T>
class SmartPointer{
    public:
        SmartPointer(T* p):mPointer(p){cout<<"SmartPointer Constructor"<<endl;p->incRef();}
        ~SmartPointer(){cout<<"SmartPointer Destructor"<<endl;mPointer->decRef();}
        T* operator->(){return mPointer;};
    private:
        T* mPointer;
};

int main()
{
    int a=1;
    TestClass *pTest=new(TestClass);
    SmartPointer<TestClass> SP(pTest);
}
