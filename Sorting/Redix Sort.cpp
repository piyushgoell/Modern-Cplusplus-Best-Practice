#include <iostream>
using namespace std;

void countingSort(int *a, int n, int exp)
{
  int *count = new int[10]{0};
  int *output = new int[10]{0};

  for (int i = 0; i < n; i++)
    count[(a[i] / exp) % 10]++;
    
  for (int i = 1; i < n; i++)
    count[i] += count[i - 1];

  for (int i = n - 1; i >= 0; i--)
  {
    output[count[(a[i] / exp) % 10]-1] = a[i];
    count[(a[i] / exp) % 10]--;
  }
  for (int i = 0; i < n; i++)
    a[i] = output[i];
}
void radixSort(int *a, int n)
{
  int max = a[0];
  for (int i = 0; i < n; i++)
    if (a[i] > max)
      max = a[i];
  for (int exp = 1; max / exp > 0; exp *= 10)
  {
    countingSort(a, n, exp);
  }
}

int main()
{
  int *a = new int[10]{5, 4, 5, 7, 8, 3, 5, 7, 6, 6};
  radixSort(a, 10);
  for (int i = 0; i < 10; i++)
  {
    cout << a[i] << " ";
  }
  
  return 0;
}