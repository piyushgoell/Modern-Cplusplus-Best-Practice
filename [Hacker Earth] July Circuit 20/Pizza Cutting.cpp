#include <cmath>
#include <iostream>

using namespace std;

int main()
{
  int t;
  long long x;
  cin >> t;
  while (t > 0)
  {
    cin >> x;
    cout << 1 + (x * (x + 1) / 2) << "\n";
    t--;
  }
}