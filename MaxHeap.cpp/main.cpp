//
//  main.cpp
//  MarcosRamosMaxHeap.cpp
//
//  Created by Marcos Martinez on 3/31/20.
//  Copyright © 2020 Marcos Martinez. All rights reserved.
//
#include <iostream>
#include <cmath>
using namespace std;

void swap(int*& a, int*& b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

class MaxHeap {
private:
    int* a;
    int n;
    bool heap;

public:

    MaxHeap() {
        n = 0;
        a = nullptr;
        heap = true;
    }

    MaxHeap(int size) {
        n = size;
        a = new int[size];
        for (int i = 0; i < size; i++) {
            a[i] = rand() % 100;
        }
        cout << "Before Heapify" << endl;
        displayHeap();
        cout << "After Heapify" << endl;
        heapify(0, n);
        displayHeap();
        heap = true;
    };

    ~MaxHeap() { delete[] a; };

    void heapSort() {
        for (int i = n / 2 - 1; i >= 0; i--) { heapify(i, n); }
        for (int i = n - 1; i > 0; i--) {
            swap(a[0], a[i]);
            heapify(0, i);
        }
    }

    void displayHeap() { for (int i = 0; i < n; i++) { cout << a[i] << " "; } cout << endl; };


    void heapify(int root, int size) {
        int largest = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;

        if ((left < size) && (a[left] > a[largest])) { largest = left; }
        
        if ((right < size) && (a[right] > a[largest])) { largest = right; }
        
        if (largest != root) {
            swap(a[root], a[largest]);
            heapify(largest, size);
        }
    };

    void insertMaxHeap(int value) {
        n++;
        int* ac = new int[n];
        ac[0] = value;
        for (int i = 1; i < n; i++) {
            ac[i] = a[i - 1];
        }
        delete[] a;
        a = ac;
        heapify(0, n);
    };

    void deleteMaxHeap(int value) {
        int* ac = new int[n - 1];
        int i = 0; int target = 0;
        bool found = false;

        while ((i < n) && (!found)) {
            if (a[i] == value) { found = true; target = i; }
            i++;
        }
        a[target] = a[n-1];
        for (int i = 0; i < n - 1; i++) { ac[i] = a[i]; }
        delete[] a;
        a = ac;
        n--;
        heapify(0, n);
    };



};
int main() {
    MaxHeap v = MaxHeap(15);

    v.insertMaxHeap(7);
    
    cout << "Insertin 7 into heap" << endl;
    
    v.displayHeap();
    
    v.deleteMaxHeap(7);
    
    cout << "Deleting 7 from heap" << endl;
    
    v.heapSort();
    
    v.displayHeap();

    return 0;
}

