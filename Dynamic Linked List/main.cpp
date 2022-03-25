//
//  main.cpp
//  Lab1CSCI115.cpp
//
//  Created by Marcos Martinez on 1/21/20.
//  Copyright © 2020 Marcos Martinez. All rights reserved.
//
#include <iostream>
#include<cstdlib>
#include <array>
#include <random>
using namespace std;
//destuctor
//remove front
//remove back
//add front
// add back
class arr
{
  public:
  int * arrName;
  int sizeOfArr;
  arr(){
      sizeOfArr = 15;
     arrName = new int[sizeOfArr];
     for(int i = 0; i < sizeOfArr; i++)
     {
         arrName[i] = rand()%100;
     }
  } // default
  arr(int n); // copy constructor
  ~arr(); // deconstructor
  //int * arrData; // integer array
  int getSize(){
      return sizeOfArr;
  } // function to access the size
  void remFront(); // function to remove from beggining;
  void remBack(); // function to remove from back;
  void addFront(int n); // function to add to front;
  void addBack(int x); // fucntion to add to the back;
  void reverseArr(); // Function to reverse the array;
  void print(); // prints elements in array;
  int returnSum(); // function that returns sum of elements in array;
  void checkOdd(); // function to return an array that contains odd numbers only;
  void writeToFile(char*); // function to dispay the content of the array ina file through fstream;
  int *operator+(const arr&) const;
  protected:
  private:
};

int arr::returnSum(){
    int sum =0;
    for(int i = 0; i < sizeOfArr;i++)
    {
        sum += arrName[i];
    }
    return sum;
}
void arr::print(){
    for(int i = 0; i < sizeOfArr;i++)
    {
        cout << arrName[i] << " ";
    }
}
void arr::reverseArr(){
    int* temp3;
    temp3 = new int[sizeOfArr];
    int counter = sizeOfArr;
    for(int i = 0; i < sizeOfArr; i++)
    {
        temp3[counter - 1] = arrName[i];
        counter--;
    }
    arrName = temp3;
}
void arr::checkOdd(){
    int* temp4;
    int counter = 0;
    temp4 = new int[sizeOfArr];
    for(int i = 0; i < sizeOfArr; i++)
    {
        if((arrName[i] %2) != 0)
        {
            temp4[counter] = arrName[i];
            counter++;
        }
    }
    arrName = temp4;
    sizeOfArr = counter;
}
void arr::remFront(){
    int *temp;
    sizeOfArr--;
    temp = new int[sizeOfArr];
    for(int i = 0; i < sizeOfArr; i++)
    {
        temp[i] = arrName[i+1];
    }
    arrName = temp;
    //10sizeOfArr--;
}

void arr::remBack(){
    int *temp;
    temp = new int[sizeOfArr-1];
    for(int i =0; i <sizeOfArr-1;i++)
    {
        temp[i] = arrName[i];
    }
    arrName = temp;
    sizeOfArr--;
}
void arr::addFront(int n){
    int* temp2;
    sizeOfArr++;
    temp2 = new int[sizeOfArr];
    temp2[0] = n;
    //sizeOfArr++;
    for(int i = 0; i < sizeOfArr; i++)
    {
        temp2[i+1] = arrName[i];
    }
    arrName = temp2;
}
void arr::addBack(int n){
int* temp;
temp = new int[sizeOfArr+1];
temp[sizeOfArr] = n; //
//sizeOfArr++;
for(int i = 0; i < sizeOfArr-1; i++)
{
    temp[i] = arrName[i];
}
arrName = temp;
    sizeOfArr++;
}
arr::~arr()
{
    delete [] arrName;
}
using namespace std;
int main()
{
    arr output;
    output.print();
    // first function
    output.remFront();
    cout << endl;
    output.print();
    //second function
    output.remBack();
    cout << endl;
    output.print();
    //pointer error for the size when you call the two functions
    cout << endl;
    int addF;
    cin >> addF;
    // third fucntion
    output.addFront(addF);
    output.print();
    int addB;
    cout << endl;
    cin >> addB;
    // 4th fucntion
    output.addBack(addB);
    output.print();
    //5th function
    output.reverseArr();
    cout << endl;
    //6th function
    output.print();
    output.checkOdd();
    cout << endl;
    output.print();
     cout << endl;
    cout << output.returnSum();
    cout << endl;

  return 0;
}
