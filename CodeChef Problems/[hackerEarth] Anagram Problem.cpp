#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

void subsequenceIndex(string s1, string s2)
{
  size_t len1 = s1.size();
  size_t len2 = s2.size();
  for (size_t i = 0; i <= len2 - len1; i++)
  {
    if (is_permutation(s2.begin() + i, s2.begin() + i + len1, s1.begin()))
    {
      cout << i << " ";
    }
  }
}

int main()
{
  int t;
  cin >> t;
  string str1, str2;
  while (t > 0)
  {
    cin >> str1 >> str2;
    subsequenceIndex(str1, str2);
    cout << "\n";
    t--;
  }
}