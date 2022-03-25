//
//  main.cpp
//  RamosLab8.cpp
//
//  Created by Marcos Martinez on 12/7/19.
//  Copyright © 2019 Marcos Martinez. All rights reserved.
//
#include <iostream>
#include<vector>

using namespace std;
class priortyQU {  //unordered Class
public:
    void enqueue1(vector<int> &a, int temp);
    void dequeue1(vector<int>&a);
    void print1(vector<int> &a);
    bool isEmpty(vector<int> &a);
};
bool priortyQU::isEmpty(vector<int> &a){
    if(a.empty()){
        return true;
    }
    return false;
}
void priortyQU::enqueue1(vector<int> &a, int temp){
    a.push_back(temp);
}
void priortyQU::dequeue1(vector<int> &a){
    int max = a[0];
    for(int i = 0; i <a.size()-1; i ++){
        if(max > a[i])
            max = a[i];
    }
    swap(a[max],a[a.size()-1]);
}
void priortyQU::print1(vector<int> &a){
    for(int i =0; i <= a.size()-1; i++){
        cout << a[i] << " ";
    }
}
class priorityQ2{ // ordered vector/array
public:
    void enqueue2(vector<int>& v, int temp);
    void dequeue2(vector<int>&v);
    void print2(vector<int> &v);
    bool isEmpty2(vector<int> &v);
};
bool priorityQ2::isEmpty2(vector<int> &v){
    if(v.empty()){
        return true;
    }
    return false;
}
void priorityQ2::enqueue2(vector<int>&v, int temp){
    v.push_back(temp);
    int t = v.size()-1;
   for (int j = t; j>= 0; --j) {
       if (v[j-1] > v[j]) {
           swap(v[j-1], v[j]);
       }
   }
}
void priorityQ2::print2(vector<int> &v){
    for(int i =0; i <= v.size()-1; i++){
        cout << v[i] << " ";
    }
}

class heap1{
private:
    vector<int> heap;
public:
    void printHeap(vector<int> &heap){
        for(int i = 0; i<heap.size()-1; i++){
            cout<<heap[i] << " ";
        }
        cout << endl;
    }
    void swap(int x, int y){
        int temp = heap[x];
        heap[x] = heap[y];
        heap[y] = heap[temp];
    }
    bool isEmptyHeap(vector<int> & heap){
        if(heap.size() == 0){return true;}
        return false;
    }
    void swimHeap(int k){
        while(k >= 1 && heap[k/2] < heap[k]){
            swap(k,(k/2));
            k = k/2;
        }
    }
    void sinkHeap(int k){
        while(2*k <= heap.size()-1){
            int j = 2*k;
            if(j < heap.size()-1 && heap[j] < heap[j+1]){++j;}
            if(!(heap[k] < heap[j+1])){break;}
            swap(k, j);
            k=j;
        }
    }
    void insertHeap(int x){
        heap.push_back(x);
        swimHeap(heap[heap.size()-1]);
    }
    int deleteMax(){
        int max = heap[0];
        swap(heap[heap.size()-1], heap[0]);
        heap.pop_back();
        sinkHeap(0);
        return max;
        
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
