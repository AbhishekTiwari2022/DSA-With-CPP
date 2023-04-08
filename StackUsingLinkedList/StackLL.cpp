#include<iostream>
#include<stdio.h>
using namespace std;

struct Node
{
    int item;
    Node *next;
};

class Stack
{
    private:
        Node *top;
    public:
        Stack();
        Stack(Stack &);
        Stack& operator=(Stack&);
        void push(int);
        int peek();
        void pop();
        void reversee();
        ~Stack();
};
Stack::Stack()
{
    top=NULL;
}
Stack::Stack(Stack &s)
{
    Node *t;
    s.reversee();
    t=s.top;
    while(t)
    {
        push(t->item);
        t=t->next;
    }
    s.reversee();
}
Stack& Stack::operator=(Stack &s)
{
    if(top!=NULL)
    {
        while(top)
            pop();
    }
    Node *t;
    s.reversee();
    t=s.top;
    while(t)
    {
        push(t->item);
        t=t->next;
    }
    s.reversee();
    return *this;
}
void Stack::push(int data)
{
    Node *n=new Node;
    n->item=data;
    n->next=top;
    top=n;
}
int Stack::peek()
{
    if(top==NULL)
        cout<<"Stack Empty";
    else
        return top->item;
}
void Stack::pop()
{
    Node *r;
    if(top!=NULL)
    {
        r=top;
        top=top->next;
        delete r;
    }
}
void Stack::reversee()
{
    Stack s;
    while(top)
    {
        s.push(peek());
        pop();
    }
    top=s.top;
    s.top=NULL;
}
Stack::~Stack()
{
    while(top)
        pop();
}
