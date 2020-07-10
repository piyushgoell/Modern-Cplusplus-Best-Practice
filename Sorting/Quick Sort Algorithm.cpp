#include <iostream>
#include <algorithm>
using namespace std;

// Space Complexity O(n) & Time Complexity O(n)
void partitionNaive(int* a, int start, int end,int pivot) {
    int* temp_array = new int[(end - start) + 1];
    int index = 0;
    for (int i = start; i <= end; i++) {
        if (a[i] <= a[pivot])
            temp_array[index++] = a[i];
    }
    for (int i = start; i <= end; i++) {
        if (a[i] > a[pivot])
            temp_array[index++] = a[i];
    }
    for (int i = start; i <= end; i++) {
            a[i] = temp_array[i];
    }
}

// Space Complexity O(1) & Time Complexity O(n);
int partitionLomuto(int* a, int start, int end) {
    // We took the last element as a pivot
    int pivot = a[end];
    int index = start;
    for (int i = start; i < end; i++) {
        if (a[i] <= pivot) {
            swap(a[i], a[index]);
            index++;
        }
    }
    swap(a[index], a[end]);
    return index;
}
//Space Complexity O(1) & Time Complexity O(n)
int partitionHore(int* a, int start, int end) {
    // We took first element as a pivot
    int pivot = a[start]; 
    int i = start-1, j = end+1;
    while (true) {
        do {
            i++;
        } while (a[i] < pivot);
        do {
            j--;
        } while (a[j] > pivot);
           
        if (i >= j)
            return j;
        swap(a[i], a[j]);
    }
}

void quickSortLomuto(int* a, int start, int end) {
    if (start < end) {
        int partition = partitionLomuto(a, start, end);
        quickSortLomuto(a, start, partition - 1);
        quickSortLomuto(a, partition + 1, end);
    }
}

void quickSortHore(int* a, int start, int end) {
    if (start < end) {
        int partition = partitionHore(a, start, end);
        quickSortHore(a, start, partition);
        quickSortHore(a, partition + 1, end);

    }
}

void quickSortRandomHore(int* a, int start, int end) {
    int &pivot = a[start + rand() % (end - start)];
    //  we swap pviot element with starting element.
    //  So, quickSortHore is called;
    swap(a[start], pivot);
    quickSortHore(a, start, end);

}
void quickSortRandomLomuto(int* a, int start, int end) {
    int& pivot = a[start + rand() % (end - start)];
    //  we swap pviot element with last element.
    //  So, quickSortLomuto is called;
    swap(a[end], pivot);
    quickSortLomuto(a, start, end);

}
void print(int* a, int start, int end) {
    for (int i = 0; i < end; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main()
{

    int* a = new int[10]{ 10,9,15,26,56,73,99,23,11,10 };
    print(a, 0, 10);

    quickSortLomuto(a, 0, 9);
    print(a, 0, 10);
    
    delete[]a;

    a = new int[10]{ 20,9,15,26,56,73,99,23,11,45 };
    quickSortHore(a, 0, 9);
    print(a, 0, 10);

    delete[]a;
    a = new int[10]{ 20,9,15,26,56,73,99,23,11,45 };
    quickSortRandomHore(a, 0, 9);
    print(a, 0, 10);

    delete[]a;
    a = new int[10]{ 20,9,15,26,56,73,99,23,11,45 };
    quickSortRandomLomuto(a, 0, 9);
    print(a, 0, 10);

}

