#include<iostream>
#include<stdio.h>
using namespace std;

struct Node
{
    int item;
    Node *next;
};
class CLL
{
    private:
        Node *last;
    public:
        CLL();
        CLL(CLL&);
        CLL& operator=(CLL&);
        void insertAtFirst(int);
        void insertAtLast(int);
        Node* searchs(int);
        void insertAfter(Node*,int);
        void deleteFirst();
        void deleteLast();
        void del(Node*);
        ~CLL();
};
CLL::CLL()
{
    last=NULL;
}
CLL::CLL(CLL &c)
{
    Node *t;
    if(c.last==NULL)
        last=NULL;
    else
    {
        t=c.last->next;
        while(t!=last)
        {
            insertAtLast(t->item);
            t=t->next;
        }
        insertAtLast(last->item);
    }
}
CLL& CLL::operator=(CLL &c)
{
    while(last)
        deleteFirst();

    Node *t;

    if(c.last==NULL)
        last=NULL;
    else
    {
        t=c.last->next;
        while(t!=last)
        {
            insertAtLast(t->item);
            t=t->next;
        }
        insertAtLast(last->item);
    }
    return *this;
}
void CLL::insertAtFirst(int data)
{
    Node *n=new Node;
    n->item=data;
    if(last==NULL)
    {
        n->next=n;
        last=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
    }
}
void CLL::insertAtLast(int data)
{
    Node *n=new Node;
    n->item=data;
    if(last==NULL)
    {
        n->next=n;
        last=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
        last=n;
    }
}
Node* CLL::searchs(int data)
{
    Node *t;
    t=last->next;
    if(last==NULL)
        return NULL;

    while(t!=last)
    {
        if(t-next==data)
            return t;
        t=t->next;
    }
    if(last->next==data)
        return last;
    return NULL;
}
void CLL::insertAfter(Node *t,int data)
{
    Node *n=new Node;
    if(t==last)
        insertAfter(data);
    else if(t)
    {
        n->item=data;
        n->next=t->next;
        t->next=n;
    }
}
void CLL::deleteFirst()
{
    Node *t;
    t=last->next;

    if(last==NULL)
        cout<<"List Is Empty";
    else
    {
        last->next=t->next;
        if(last==t)
            last=NULL;//so last is not become Dangling Pointer
        delete t;

    }
}
void CLL::deleteLast()
{
    Node *r,*t;
    if(last)
    {
        r=last;
        if(r->next=r)
            last=NULL;
        else
        {
            t=last->next;
            while(t->next!=NULL)
                t=t->next;
            t->next=last->next;
            last=t;
        }
        delete r;
    }

}
void CLL::del(Node *t)
{
    Node *r;
    if(t!=NULL)
    {
        if(t==last)
            deleteLast();
        else if(t==last->next)
            deleteFirst();
        else
        {
            r=last->next;
            while(r->next!=t)
                r=r->next;
            r->next=t->next;
            delete t;
        }
    }
}
CLL::~CLL()
{
    while(last)
        deleteFirst();
}
