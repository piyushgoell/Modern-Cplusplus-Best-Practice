#include <iostream>
using namespace std;

void heapify(int *a, int n, int i)
{
  int parent = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && a[left] > a[parent])
    parent = left;
  if (right < n && a[right] > a[parent])
    parent = right;
  if (parent != i)
  {
    swap(a[parent], a[i]);
    heapify(a, n, parent);
  }
}
void buildHeap(int *a, int n)
{
  for (int i = (n - 2) / 2; i >= 0; i--)
    heapify(a, n, i);
}
void heapSort(int *a, int n)
{
  // We First build the Heap In our case it is Max Heap
  // time complexity is O(n)
  buildHeap(a, n);
  for (int i = n - 1; i >= 1; i--)
  {
    swap(a[0], a[i]);
    heapify(a, i, 0);
  }
}
int main()
{
  int *a = new int[20]{10, 50, 32, 85, 15, 20, 3, 99, 40, 48, 68, 8, 11, 15, 22, 25, 55, 100, 122, 139};
  heapSort(a, 20);
  for (int i = 0; i < 20; i++)
    cout << a[i] << " ";
}