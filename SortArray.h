#ifndef SORTARRAY_H
#define SORTARRAY_H

using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>

class SortArray{
    public:
        SortArray();
        ~SortArray();

        void readFile(string& file);

        void BubbleSort();
        void InsertionSort();
        void MergeSort(double* myArray, int a, int c);
        void QuickSort(int low, int high);
        void SelectionSort();

        void swap(double& i, double& j);
        void merge(double* myArray, int a, int b, int c);
        int partition(int low, int high);

        int getSize();
        double* getArray();

    private:
        int size;
        double *myArray;
};


#endif