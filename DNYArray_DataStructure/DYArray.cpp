#include<stdio.h>
#include<iostream>
using namespace std;
class Array
{
    private:
        int capacity;
        int last_fill_index;
        int *ptr;
    public:
        Array();
        Array(Array &);
        Array& operator=(Array&);
        void createArray(int);
        void doubleArray();
        void halfArray();
        void append(int);
        bool isFull();
        bool isEmpty();
        void insert(int,int);
        int getItem(int);
        int getCapacity();
        int count();
        void edit(int ,int);
        void deleteItem(int);
        ~Array();
};
Array::Array()
{
    ptr=NULL;
}
Array::Array(Array &arr)
{
    int i;
    capacity=arr.capacity;
    last_fill_index=arr.last_fill_index;
    ptr=new int[capacity];
    for(i=0;i<last_fill_index;i++)
        ptr[i]=arr.ptr[i];
}
Array& Array::operator=(Array &arr)
{
    int i;
    capacity=arr.capacity;
    last_fill_index=arr.last_fill_index;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new int[capacity];
    for(i=0;i<last_fill_index;i++)
        ptr[i]=arr.ptr[i];
    return (*this);
}
void Array::createArray(int size)
{
    capacity=size;
    last_fill_index=-1;

    if(ptr!=NULL)
    {
        delete []ptr;
    }
    else
    {
        ptr=new int[capacity];
    }
}
void Array::doubleArray()
{
    int *temp;
    int i;
    temp=new int[capacity*2];
    for(i=0;i<=last_fill_index;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity*=2;
}
void Array::halfArray()
{
    int *temp;
    temp=new int[capacity/2];
    for(i=0;i<=last_fill_index;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity/=2;
}
void Array::append(int data)
{
    if(isFull())
    {
        doubleArray();
    }
    last_fill_index++;
    ptr[last_fill_index]=data;
}
bool Array::isFull()
{
    return last_fill_index==capacity-1;
}
bool Array::isEmpty()
{
    return last_fill_index==-1;
}
void Array::insert(int index,int data)
{
    int i;
    try{
         if(index<0 || index>last_fill_index+1)
            throw 1;
         if(isFull())
            doubleArray();
         for(i=last_fill_index;i>=index;i--)
            ptr[i+1]=ptr[i];
         ptr[index]=data;
         last_fill_index++;

    }catch(int e)
    {
        if(e==1)
            cout<<"\n Invalid Index";
    }

}
int Array::getItem(int index)
{
  try{
      if(index<0 || index>last_fill_index)
        throw 1;
      return ptr[index];
  }catch(int e){
      if(e==1)
        cout<<"\n Invalid Index Or Array Is Empty";
  }
  return -1;
}
int Array::getCapacity()
{
    return capacity;
}
int Array::count()
{
   return last_fill_index+1;
}
void Array::edit(int index,int newData)
{
    try{
        if(index<0 || index>last_fill_index)
            throw 1;
        ptr[index]=newData;

    }catch(int e)
    {
        if(e==1)
            cout<<"\n Invalid index or empty array";
    }
}
void Array::deleteItem(int index)
{
    int i;
    try{
        if(index<0 || index>last_fill_index)
            throw 1;
        for(i=0;i<last_fill_index;i++)
            ptr[i]=ptr[i+1];
        last_fill_index--;
        if(capacity>1 && last_fill_index+1<=capacity/2)
            halfArray();

    }catch(int e){
        if(e==1)
            cout<<"\n Invalid Index";
    }
}
Array::~Array()
{
    delete []ptr;
}
int main()
{
    Array a;
    a.createArray(10);
    a.append(10);
    a.getCapacity();
    return 0;
}

