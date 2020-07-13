#include <iostream>
using namespace std;

void countSort(int *a, int n)
{
  int *count = new int[n]{0};
  for (int i = 0; i < n; i++)
    count[a[i]]++;

  for (int i = 1; i < n; i++)
    count[i] += count[i - 1];

  int *output = new int[n]{0};

  for (int i = n - 1; i >= 0; i--)
  {
    output[count[a[i]] - 1] = a[i];
    count[a[i]]--;
  }
  for (int i = 0; i < n; i++)
    a[i] = output[i];
  delete[] output;
}
int main()
{
  int *a = new int[10]{5, 4, 5, 7, 8, 3, 5, 7, 6, 6};
  countSort(a, 10);
  for (int i = 0; i < 10; i++)
    cout << a[i] << " ";

  return 0;
}