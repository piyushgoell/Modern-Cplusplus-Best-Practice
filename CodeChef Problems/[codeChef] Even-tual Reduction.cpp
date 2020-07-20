#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  size_t t, x;
  cin >> t;
  string str;
  while (t > 0)
  {
    cin >> x;
    cin >> str;
    if (x % 2 != 0)
    {
      cout << "NO\n";
      t--;
      continue;
    }
    else
    {
      sort(str.begin(), str.end());
      size_t i;
      for (i = 0; i < x; i += 2)
      {
        if (str[i] != str[i + 1])
        {
          cout << "No\n";
          break;
        }

        if (i == x - 2)
          cout << "YES\n";
      }
    }
    t--;
  }
}