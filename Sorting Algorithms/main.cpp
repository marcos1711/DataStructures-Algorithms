//
//  main.cpp
//  CSCI 115 Lab 3
//
//  Created by Marcos Martinez on 2/4/20.
//  Copyright © 2020 Marcos Martinez. All rights reserved.
//

#include <iostream>
using namespace std;
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void selectionSort(int arr[], int n){
    int min;
    int steps = 0;
    for(int i = 0; i < n-1; i++){
        min = i;
        for(int j = i+1; j < n; j++)
            if(arr[j] < arr[min])
                min = j;
            swap(&arr[min], &arr[i]);
        steps = steps +1;
        
    }
    cout << "Number of steps " << steps << endl;
}
void insertionSort(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j > 0; j--){
            if(arr[j-1] > arr[j]){
                swap(&arr[j], &arr[j-1]);
            }
               else break;
        }
    }
}

void printArray(int arr[], int s){
    for(int i = 0; i < s; i++)
        cout<< arr[i] << " ";
        cout << endl;
}
void bubbleSort(int arr[], int n){
    int i;
    int j;
        for (i = 0; i < n-1; i++)

        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}
int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);
        else
        return binarySearch(arr, mid + 1, high, x);
    }
    return -1;
}
int binarySearchF(int arr[], int n, int x){
    int low = arr[0];
    int high = n -1;
    //int mid = low +(high - low)/2;
    while (low <= high){
      int mid = low +(high - low)/2;
        if (arr[mid] == x) {
            return mid;
        }
        if(arr[mid] == x)
            low = mid + 1;
        else
            high = mid -1;
    }
    return -1;
}
int checkArray(int arr[], int n){
    if(n == 1 || n == 0){
        return 1;
    }
    if(arr[n-1] < arr[n -2])
        return 0;
    return checkArray(arr, n-1);
}
void isArraySorted(int arr[], int n){
    int marcos = checkArray(arr, n);
    if(marcos == 1)
        cout << "This array is sorted." << endl;
    if(marcos != 1)
        cout << "This array is not sorted, TRY AGAIN!!!!!" << endl;
}
int main(int argc, const char * argv[]) {
    int arr[1000];
    for(int i = 0; i < 1000; i++ ){
        arr[i] =  rand()%2000;
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    //bubbleSort(arr, n);
    //selectionSort(arr, n);
    //insertionSort(arr, n);
    printArray(arr, n);
    isArraySorted(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);
    isArraySorted(arr, n);
    int m = 1000;
    int result = binarySearch(arr, 0, n -1, m);
    if(result == -1){
        cout << " Element is not present" << endl;
    }
    if(result != -1){
        cout <<" Element is present " << result << endl;
    }
   cout << "Hello, World!\n";
    return 0;
}
