#include <iostream>
using namespace std;

void merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int sizeLeft = m - l + 1;
    int sizeRight = r - m;

    /* create temp arrays */
    int *leftHalf = new int[sizeLeft]{0};
    int *rightHalf = new int[sizeRight]{0};

    /* Copy data to temp arrays leftHalf[] and rightHalf[] */
    for (int i = 0; i < sizeLeft; i++)
        leftHalf[i] = arr[l + i];
    for (j = 0; j < sizeRight; j++)
        rightHalf[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < sizeLeft && j < sizeRight)
    {
        if (leftHalf[i] <= rightHalf[j])
        {
            arr[k] = leftHalf[i];
            i++;
        }
        else
        {
            arr[k] = rightHalf[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of leftHalf[], if there
       are any */
    while (i < sizeLeft)
    {
        arr[k] = leftHalf[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of rightHalf[], if there
       are any */
    while (j < sizeRight)
    {
        arr[k] = rightHalf[j];
        j++;
        k++;
    }
    delete[] leftHalf;
    delete[] rightHalf;
}

void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
int main()
{
    int *a = new int[20]{10, 50, 32, 85, 15, 20, 3, 99, 40, 48, 68, 8, 11, 15, 22, 25, 55, 100, 122, 139};
    cout << "unsorted array := \n";
    for (int i = 0; i < 20; i++)
        cout << a[i] << " ";
    mergeSort(a, 0, 19);
    cout << "\nafter sorting array:=" << endl;
    for (int i = 0; i < 20; i++)
        cout << a[i] << " ";
}
