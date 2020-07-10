#include <iostream>
#include <algorithm>
using namespace std;
// Time Complexity O(n);
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
//Time Complexity O(n)
int partitionHore(int* a, int start, int end) {
    // We took first element as a pivot
    int pivot = a[start];
    int i = start, j = end;
    while (true) {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (a[i] == pivot)
            i++;
        if (i >= j)
            return i;
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

        quickSortHore(a, start, partition-1);
        quickSortHore(a, partition + 1, end);
    }
}

void print(int* a, int start, int end) {
    for (int i = 0; i < end; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main()
{
    int* a = new int[10]{ 20,9,15,26,56,73,99,23,11,45 };
    //cout << partitionLomuto(a, 0, 9)<<"\n";
    quickSortLomuto(a, 0, 9);
    print(a, 0, 10);
    
    
    
    a = new int[10]{ 20,9,15,26,56,73,99,23,11,45 };
    //cout << partitionHore(a, 0, 9)<<"\n";
    quickSortHore(a, 0, 9);
    print(a, 0, 10);
    

}

