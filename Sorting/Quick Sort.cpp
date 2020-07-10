#include <iostream>
#include <algorithm>
using namespace std;
// Time Complexity O(n);
int partitionLomuto(int* a, int start, int end) {
    // We took the last element as a pivot
    int pivot = a[end];
    int index = start;
    for (int i = start; i < end; i++) {
        if (a[i] <= a[pivot]) {
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
        while (a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i >= j)
            return i;
        swap(a[i], a[j]);
    }
}
int main()
{
    int* a = new int[10]{ 40,9,15,26,56,73,99,23,11,45 };
    cout<<partitionLomuto(a, 0, 9)<<"\n";
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    delete[] a;
    cout << endl;
    a = new int[10]{10,10,10,10,10,10,10,10,10,10 };
    cout << partitionHore(a, 0, 9)<<"\n";
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }

}

