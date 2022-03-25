//
//  main.cpp
//  Lab 4 CSCI 115 Ramos
//
//  Created by Marcos Martinez on 2/11/20.
//  Copyright © 2020 Marcos Martinez. All rights reserved.
//
// use random p ofr pivot
#include <iostream>
using namespace std;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low -1);
    for(int j = low; j <= high -1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i+1);
}
void quickSort(int arr[], int low, int high){
    if(low < high){
        int part = partition(arr, low, high);
        quickSort(arr, low, part -1);
        quickSort(arr, part +1, high);
    }
    
}
void merge(int arr[], int low, int middle, int high){
    int i;
    int j;
    int k;
    int m1 = middle - low +1;
    int m2 = high - middle;
    int L[m1];
    int R[m2];
    for(i = 0; i < m1; i++)
        L[i] = arr[low + i];
    for(j = 0; j < m2; j++)
        R[j] = arr[middle + 1 + j];
    i = 0;
    j = 0;
    k = low;
    while(i < m1 && j < m2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < m1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < m2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void meregeSort(int arr[], int low, int high){
    if(low < high){
        int middle = low+(high - low)/2;
        meregeSort(arr, low, middle);
        meregeSort(arr, middle + 1, high);
        merge(arr, low, middle, high);
    }
}
void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    int arr[10];
    for(int i = 0; i < 10; i++){
        arr[i] = rand()%100;
    }
    int m = sizeof(arr)/ sizeof(arr[0]);
    display(arr, m);
    cout<< "Now we will sort the array" << endl;
    meregeSort(arr, 0, m-1);
    //quickSort(arr, 0, m -1);
    display(arr, m);
    return 0;
}
