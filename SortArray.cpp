#include "SortArray.h"

SortArray::SortArray(){
    myArray = nullptr;
    size = 0;
}

SortArray::~SortArray(){
    delete[] myArray;
}

void SortArray::readFile(string& fn){
    ifstream file(fn);
    if (!file.is_open()){
        cout << "Failed to open the file." << endl;
        return;
    }

    file >> size;
    myArray = new double[size];

    for (int i = 0; i < size; i++){
        file >> myArray[i];
    }

    file.close();
}



/*
Auxiliary methods to be used in the sorting methods
*/

void SortArray::swap(double& i, double& j){ //a swap method to be used in the BubbleSort, SelectionSort, and QuickSort methods
    double temp = i;
    i = j;
    j = temp;
}

void SortArray::merge(double *numbers, int a, int b, int c){ //merge method to be used for MergeSort
    int mergedSize = c - a + 1; //size of merged partition
    int mergePos = 0; //position to insert merged numbers
    int leftPos = a;
    int rightPos = b + 1;
    double *mergedNumbers = new double[mergedSize]; //temp array for merged numbers

    
    //Add smallest element from left or right partition to merged numbers
    while (leftPos <= b && rightPos <= c){
        if (numbers[leftPos] <= numbers[rightPos]){
        mergedNumbers[mergePos] = numbers[leftPos];
        ++leftPos;
        }
        else{
            mergedNumbers[mergePos] = numbers[rightPos];
        ++rightPos;
        }
        ++mergePos;
    }

    // If left partition is not empty, add remaining elements to merged numbers
    while (leftPos <= b){
        mergedNumbers[mergePos] = numbers[leftPos];
        ++leftPos;
        ++mergePos;
    }

    // If right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= c){
        mergedNumbers[mergePos] = numbers[rightPos];
        ++rightPos;
        ++mergePos;
    }

    // Copy merge number back to numbers
    for (mergePos = 0; mergePos < mergedSize; ++mergePos){
        numbers[a + mergePos] = mergedNumbers[mergePos];
    }
}

int SortArray::partition(int low, int high) { //partition method that returns to be used in QuickSort method
    double pivot = myArray[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (myArray[j] < pivot) {
            i++;
            swap(myArray[i], myArray[j]);
        }
    }
    swap(myArray[i + 1], myArray[high]);
    return (i + 1);
}



/*
Sorting methods in alphabetical order
*/

void SortArray::BubbleSort(){
    for (int i = 0; i < size - 1; i++){
        bool sorted = false;
        for (int j = 0; j < size - i - 1; j++){ //iterate through the unsorted part of the array
            if (myArray[j] > myArray[j + 1]){
                swap(myArray[j], myArray[j + 1]);
                sorted = true;
            }
        }
        if (!sorted) //if array is already sorted, terminate early
            break;
    }
}

void SortArray::InsertionSort(){
    for (int i = 1; i < size; i++){
        double curr = myArray[i];
        int j = i - 1;
        while (j >= 0 && myArray[j] > curr){ //move everything right to insert curr into correct position in sorted portion
            myArray[j + 1] = myArray[j];
            j--;
        }
        myArray[j + 1] = curr;
    }
}

void SortArray::MergeSort(double* myArray, int a, int c){
    int b = 0;

    if (a < b) {
        b = (a + c) / 2;  // Find the midpoint in the partition
        
        // Recursively sort left and right partitions
        MergeSort(myArray, a, b);
        MergeSort(myArray, b + 1, c);
        
        // Merge left and right partition in sorted order
        merge(myArray, a, b, c);
    }
}

void SortArray::QuickSort(int low, int high){
    if (low < high){
        int p = partition(low, high);
        QuickSort(low, p - 1);
        QuickSort(p + 1, high);
    }
}

void SortArray::SelectionSort(){
    for (int i = 0; i < size - 1; i++){
        int minIndex = i;
        for (int j = i + 1; j < size; j++){ //iterates through unsorted part and places minimum element at correct sorted position
            if (myArray[j] < myArray[minIndex])
                minIndex = j;
        }
        swap(myArray[minIndex], myArray[i]);
    }
}



/*
Accessors
*/

int SortArray::getSize(){
    return size;
}

double* SortArray::getArray(){
    return myArray;
}