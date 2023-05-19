#include "SortArray.h"
#include <ctime>

int main(int argc, char* argv[]) {
    string filename = argv[1];

    SortArray sortArray;
    sortArray.readFile(filename);

    clock_t start_time, end_time;

    // Quick Sort
    start_time = clock();
    sortArray.QuickSort(0, sortArray.getSize() - 1);
    end_time = clock();

    cout << "Quick Sort: ";
    cout << "Start Time: " << start_time << " ";
    cout << "End Time: " << end_time << endl;

    //Merge Sort
    start_time = clock();
    sortArray.MergeSort(sortArray.getArray(), 0, sortArray.getSize() - 1);
    end_time = clock();

    cout << "Merge Sort: ";
    cout << "Start Time: " << start_time << " ";
    cout << "End Time: " << end_time << endl;

    // Selection Sort
    start_time = clock();
    sortArray.SelectionSort();
    end_time = clock();

    cout << "Selection Sort: ";
    cout << "Start Time: " << start_time << " ";
    cout << "End Time: " << end_time << endl;

    // Insertion Sort
    start_time = clock();
    sortArray.InsertionSort();
    end_time = clock();

    cout << "Insertion Sort: ";
    cout << "Start Time: " << start_time << " ";
    cout << "End Time: " << end_time << endl;

    // Bubble Sort
    start_time = clock();
    sortArray.BubbleSort();
    end_time = clock();

    cout << "Bubble Sort: ";
    cout << "Start Time: " << start_time << " ";
    cout << "End Time: " << end_time << endl;

    return 0;
}
