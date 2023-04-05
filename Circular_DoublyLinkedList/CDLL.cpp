#include<iostream>
#include<stdio.h>
using namespace std;
struct Node
{
    Node *prev;
    int item;
    Node *next;
};
class CDLL
{
    private:
        Node *start;
    public:
        CDLL();
        ~CDLL()
        void insertAtFirst(int);
        void insertAtLast(int);
        Node* searchs(int);
        void insertAfter(Node*,int);
        void deleteFirst();
        void deleteLast();
        void del(node*);
};
CDLL::CDLL()
{
    start=NULL;
}
CDLL::~CDLL()
{
    while(start)
        deleteFirst();
}
void CDLL::insertAtFirst(int data)
{
    Node *n=new Node;
    n->item=data;
    if(start==NULL)
    {
        n->prev=n;
        n->next=n;
        start=n;
    }
    else
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
        start=n;
    }
}
void CDLL::insertAtLast(int data)
{
    Node *n=new Node;
    n->item=data;
    if(start==NULL)
    {
        n->prev=n;
        n->next=n;
        start=n;
    }
    else
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
    }
}
Node* CDLL::searchs(int data)
{
    Node *t;
    if(start==NULL)
        return NULL;
    t=start;
    do
    {
        if(t->item==data)
            return t;
        t=t->next;
    }while(t!=start);

    return NULL;
}
void CDLL::insertAfter(Node *temp,int data);
{
    Node *n=new Node;
    if(start==NULL||temp==NULL)
        cout<<"Insertion cannot be performed";
    else
    {
        n->item=data;
        n->prev=temp;
        n->next=temp->next;
        temp->next->prev=n;
        temp->next=n;
    }
}
void CDLL::deleteFirst()
{
    Node *r;
    if(start!=NULL)
    {
        r=start;
        if(start->next==start)
        {
            delete start;
            start=NULL;
        }
        else
        {
            start->prev->next=r->next;
            start=start->next;
            start->prev=r->prev;
            delete r;
        }
    }
}
void CDLL::deleteLast()
{
    Node *r;
    if(start!=NULL)
    {

        if(start->next=start)
        {
            delete start;
            start=NULL;
        }
        else
        {
            r=start->prev;
            r->prev->next=start;
            r->prev=start->prev;
            delete r;
        }
    }
}
void CDLL::del(Node *temp)
{
    if(start==NULL||temp==NULL)
    {
        cout<<"Deletion can not be performed";
    }
    else
    {
        if(start==temp)
        {
            deleteFirst();
        }
        else
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
        }
    }
}
