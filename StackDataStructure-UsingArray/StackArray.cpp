#include<iostream>
#include<stdio.h>
using namespace std;
class Stack
{
    private:
        int capacity;
        int top;
        int *ptr;
    public:
        Stack();
        Stack(int);
        Stack(Stack&);
        Stack& operator=(Stack&);
        void CreateStack(int);
        bool isFull();
        bool isEmpty();
        void push(int);
        int peek();
        void pop();
        ~Stack();
};
Stack::Stack()
{
    capacity=0;
    top=-1;
    ptr=NULL;
}
Stack::Stack(int cap)
{
    capacity=cap;
    top=-1;
    ptr=new int[cap];
}
Stack::Stack(Stack &s)
{
    capacity=s.capacity;
    top=s.top;
    ptr=new int[capacity];
    for(int i=0;i<=top;i++)
        ptr[i]=s.ptr[i];
}
Stack& Stack::operator=(Stack &s)
{
    if(ptr!=NULL)
        delete []ptr;
    capacity=s.capacity;
    top=s.top;
    ptr=new int[capacity];
    for(int i=0;i<=top;i++)
        ptr[i]=s.ptr[i];
    return *this;
}
void Stack::CreateStack(int cap)
{
    if(ptr==NULL)
        delete ptr;

    capacity=cap;
    top=-1;
    ptr=new int[cap];
}
bool Stack::isFull()
{
    return top==capacity-1;
}
bool Stack::isEmpty()
{
    return top==-1;
}
void Stack::push(int data)
{
    if(isFull())
        cout<<"\n Overflow";
    else
    {
        top++;
        ptr[top]=data;
    }
}
int Stack::peek()
{
    if(isEmpty())
        cout<<"\nStack Is Empty";
    return ptr[top];
}
void Stack::pop()
{
    if(isEmpty())
        cout<<"\n Stack Is Empty";
    else
        top--;
}
Stack::~Stack()
{
    if(ptr!=NULL)
        delete []ptr;
}
