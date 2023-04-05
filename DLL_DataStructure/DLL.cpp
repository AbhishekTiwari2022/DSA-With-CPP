#include<iostream>
#include<stdio.h>
using namespace std;

struct Node
{
    Node *prev;
    Node *next;
    int item;
};
class DLL
{
    private:
        Node *start;
    public:
        DLL();
        DLL(DLL&);
        DLL& operator=(DLL&);
        void insertAtFirst(int);
        void insertAtLast(int);
        Node* searchs(int);
        void insertAfter(Node*,int);
        void deletFirst();
        void deleteLast();
        void deleteSpecificNode(Node*);
        ~DLL();

};
DLL::DLL()
{
    start=NULL;
}
DLL::DLL(DLL &d)
{
    Node *t;
    if(d.start!=NULL)
    {
           t=d.start;
        while(t->next!=NULL)
            t=t->next;

        while(t)
        {
            insertAtFirst(t->item);
            t=t->prev;
        }
    }
    else
    {
        start=NULL;
    }

}
DLL& DLL::operator=(DLL &d)
{
    while(start)
        deletFirst();

    Node *t;
    if(d.start!=NULL)
    {
           t=d.start;
        while(t->next!=NULL)
            t=t->next;

        while(t)
        {
            insertAtFirst(t->item);
            t=t->prev;
        }
    }
    else
    {
        start=NULL;
    }
    return *this;
}
void DLL::insertAtFirst(int data)
{
    Node *n=new Node;
    n->item=data;
    n->prev=NULL;
    n->next=start;

    if(start!=NULL)
        start->prev=n;
    start=n;
}
void DLL::insertAtLast(int data)
{
    Node *n=new Node;
    Node *t;

    n->item=data;
    n->next==NULL;

    if(start==NULL)
    {
        n->prev=NULL;
        start=n;
    }
    else
    {
        t=start;
        while(t->next!=NULL)
            t=t->next;
        n->prev=t;
        t=n;
    }
}
Node* DLL::searchs(int data)
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
void DLL::insertAfter(Node *t,int data)
{
    Node *n=new Node;
    n->prev=t;
    n->item=data;
    n->next=t->next;

    if(t->next!=NULL)
        t->next->prev=n;
    t->next=n;
}
void DLL::deletFirst()
{
    Node *t;
    if(start!=NULL)
    {
        t=start;
        start=t->next;
        start->prev=NULL;
        delete t;
    }
}
void DLL::deleteLast()
{
    Node *t;
    if(start==NULL)
    {
        cout<<"List Is Empty";
    }
    else
    {
        if(start->next==NULL)
        {
            delete start;
            start=NULL;
        }
        else
        {
            while(t->next!=NULL)
                t=t->next;
            t->prev->next=NULL;
            delete t;
        }
    }
}
void DLL::deleteSpecificNode(Node *t)
{
        if(start==NULL)
            cout<<"List Is Empty";
        else if(start==t)
            deletFirst();
        else if(t->next==NULL)
            deleteLast();
        else
        {
            t->next->prev=t->prev;
            t->prev->next=t->next;
            delete t;
        }
}
DLL::~DLL()
{
    while(start)
        deletFirst();
}
