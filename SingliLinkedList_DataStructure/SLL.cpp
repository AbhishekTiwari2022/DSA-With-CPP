#include<iostream>
#include<stdio.h>
using namespace std;

struct Node
{
   int item;
   Node *next;
};
class SLL
{
    Node *start;
    public:
        SLL()
        {
            start=NULL;
        }
        SLL(SLL&);
        void inserAtStart(int);
        void inserAtLast(int);
        Node* searchs(int);
        void insertAfter(Node*,int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(Node*);
        ~SLL();
};
SLL::SLL(SLL &l)
{
    Node *t;
    t=l.start;
    start=NULL;
    while(t)
    {
        inserAtLast(t->item);
        t=t->next;
    }
}
void SLL::inserAtStart(int data)
{
    Node *n=new Node;
    n->item=data;
    n->next=start;
    start=n;
}
void SLL::insertAtLast(int data)
{
    Node *t;
    Node *n=new Node;
    n->item=data;
    n->next=NULL;

    if(start==NULL)
        start=n;
    else
    {
        t=start;
        while(t->next!=NULL)
            t=t->next;
        t->next=n;
    }

}
Node* SLL::searchs(int data)
{
    Node *t;
    t=start;
    while(t)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return NULL;
}
void SLL::insertAfter(Node *t,int data)
{
    Node *n;
    if(t)
    {
        n=new Node;
        n->item=data;
        n->next=t->text;
        t->next=n;
    }
}
void SLL::deleteFirst()
{
    Node *t;
    if(start)
    {
        t=start;
        start=t->next;
        delete t;
    }
}
void SLL::deleteLast()
{
    Node *t;
    try{
            if(start==NULL)
                throw 1;
            if(start->next==NULL)
            {
                delete start;
                start=NULL;
            }
            else
            {
               t=start;
               while(t->next->next!=NULL)
               {
                   t=t->next;
               }
               delete t->next;
               t->next=NULL;
            }
        }
        catch(int e)
        {
            if(e==1)
                cout<<"List Is Empty";
        }
}
void SLL::deleteNode(Node *t)
{
    Node *r;
    try
    {
        if(start==NULL)
            throw 1;
        if(start==t)
            deleteFirst();
        else
        {
            r=start;
            while(r->next!=t)
                r=r->next;
            r->next=t->next;
            delete t;
        }
    }catch(int e)
    {
        if(e==1)
            cout<<"List Is Empty";
    }

}
void SLL::printSll()
{
        Node *temp=start;
        if(start==NULL)
        {
            cout<<"List is empty";
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
}
void SLL::~SLL()
{
    while(start)
        deleteFirst();
}
int main()
{
    SLL s1;
    s1.inserAtLast(2);
    s1.inserAtLast(4);
    s1.inserAtLast(5);
    s1.inserAtLast(6);
    s1.inserAtLast(7);
    s1.printSll();
    return 0;
}
