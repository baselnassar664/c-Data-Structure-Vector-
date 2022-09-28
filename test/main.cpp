#include <iostream>
#include <string>
#include <assert.h>
using namespace std;
template <class T>

class Vector{
private:
    T* arr;
    int length;
    int capacity;
    void increaseCapacity(){

        T* oldArr=arr;
        capacity*=2;
        arr=new T[capacity];
        for(int i=0;i<length;i++){
          arr[i]=oldArr[i];

        }
        delete oldArr;


    }
public:
    Vector(){
    length=0;
    capacity=1;
    arr=new T[capacity];
    }
   void push_back(T value){

    arr[length]=value;
     length++;
   if(length==capacity)
    increaseCapacity();

   }
   void pop_back(){
    if(length!=0)
     length--;
   }
   void insert(int index,T value){
    assert(index>=0 && index<length);
   for(int i=length;i>index;i--){
    arr[i]=arr[i-1];

   }
   arr[index]=value;
   length++;
    if(length==capacity)
    increaseCapacity();
   }
   void erase(int index){
   for(int i=index;i<length;i++){
    arr[i]=arr[i+1];
   }
   length--;
   }
   bool empty(){
   return length==0;
   }
   int size(){
   return length;
   }
   T front(){
       if(!empty())
    return arr[0];
   }
   T back(){
       if(!empty())
   return arr[length-1];
   }
   T& operator[](int index){
   if(index>=0 && index<length)
    return arr[index];
   }

   void print(Vector<int> v){
   for(int i=0;i<v.size();i++){

    cout<<v[i]<<" ";
    }
   }
};
int main(){
Vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
cout<<v.front()<<" "<<v.back()<<endl;
v.pop_back();

cout<<v.front()<<" "<<v.back()<<endl;
cout<<v[1]<<endl;
v[1]=1000;
cout<<v[1]<<endl;
v.print(v);
v.insert(1,500);
cout<<endl;
v.print(v);
v.erase(0);
cout<<endl;
v.print(v);
};












