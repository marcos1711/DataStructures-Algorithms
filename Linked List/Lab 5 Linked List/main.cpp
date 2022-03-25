//
//  main.cpp
//  Lab 5 Linked List
//
//  Created by Marcos Martinez on 2/18/20.
//  Copyright © 2020 Marcos Martinez. All rights reserved.
//

#include <iostream>
using namespace std;
template <typename T>
class tnode {
public:
 T data;
 tnode* next;
 tnode* prev;
 tnode(T d = T(), tnode* n = NULL, tnode* p = NULL){
   data = d;
   next = n;
   prev = p;
 }
};
/*
template <typename T>
struct node {
public:
    T data;
    node* next;
    node* prev;
};
*/
/*
• Create Double Chained Linked List
• Insert/remove an element at the beginning, at the end
• Display a list with a while loop, with a recursive function, with a for loop
(with the addition of a property number of elements in the list)
• Insert/remove an element in a sorted list with a while loop, with a recursive
function, with a for loop
 */
template <class T>
class dll {
private:
    tnode<T>* front;
    tnode<T>* tail;
    int n;
public:
    dll();
    ~dll();
    //struct node<T>* temp= (struct node<T>*) malloc(
    void insertFront(T val);
    void insertBack(T val);
    void displayF();
    void displayW();
    tnode<T>* returnFront();
    tnode<T>* displayR(tnode<T>* front);
    void insertInOrderWhile(T val);
    void insertInOrderRecursive(T val);
    void insertInOrderFor(T val);
    void removeInOrderWhile(T val);
    void removeInOrderFor(T val);
    void removeInOrderRecursive(T val);
    void defaulInsert(T val);
    int returnSize();

    };

template<typename T> dll<T>::dll(){
     front = NULL;
     tail = NULL;
     n = 0;
}
template<typename T> dll<T>::~dll(){
tnode<T>* current = front;
//template<typename T>
while(current)
{
  tnode<T>* temp = current -> next;
  delete current;
  current = temp;
}
}
template<typename T>
int dll<T>::returnSize(){
  return n;
}
template<typename T>
tnode<T>* dll<T>::returnFront(){
return front;
}
template<typename T>
void dll <T>::insertFront(T val){
     tnode<T>* temp = new tnode<T>(val, front, NULL);
     if(front == NULL)
     {
       front = tail;
       tail = temp;
     }
     else
     {
front -> prev = temp;
front = temp;
     }
     n++;
   }
   template<typename T>
   void dll<T>::defaulInsert(T val){
insertFront(val);
   }
template<typename T>
    void dll<T> ::displayF(){
        tnode<T>* temp = front;
        if(front == NULL){
            cout <<"Linked list is empty"<< endl;
            return;
        }
        int a;
        a = returnSize();
        for(int i =0; i < a; i++)
        {
          cout << temp -> data << " ";
          temp = temp -> next;
        }
        cout <<"Hey" << endl;
    }
    template<typename T>
    tnode<T>* dll<T>::displayR(tnode<T>* front)
    {
      tnode<T>* temp = front;
      if(temp == NULL){
        return 0;
      }
      cout<< temp -> data << " ";
      displayR(temp -> next);
    }

    template<typename T>
    void dll<T>::insertBack(T val){
      tnode<T>* temp = new tnode<T>(val);
      if(front == NULL)
      {
        front = temp;
        tail = temp;
      }
      else{
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
      }
      n++;
    }
    template<typename T>
    void dll<T>::displayW(){
      tnode<T>* temp = front;
      if(front == NULL){
        cout << "Linked list is empty please insert elements"<< endl;
      }
      while(temp != NULL){
        cout<< temp -> data << " ";
        temp = temp-> next;
      }
      cout << endl;
    }

    /*void insertInOrderWhile(T val);
    void insertInOrderRecursive(T val);
    void insertInOrderFor(T val);
    void removeInOrderWhile(T val);
    void removeInOrderFor(T val);
    void removeInOrderRecursive(T val);
*/
int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";
    dll<int> a;
    a.insertBack(8);
     a.insertBack(9);
      a.insertBack(10);
       a.insertBack(11);
        a.insertBack(12);
    a.displayR(a.returnFront());
    cout << a.returnSize() << endl;
    
    return 0;
}

