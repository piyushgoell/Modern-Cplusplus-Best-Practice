//  Given a String. Print all the permutation
//  which contains "AB" as a substring

#include <iostream>
#include <string>

using namespace std;

bool isSafe(string str, int l, int r)
{
  string substring = str.substr(l, r);
  size_t found = substring.find("BA");
  if (found != string::npos)
    return false;
  else
    return true;
}
void permuteNaive(string str, int l, int r)
{
  if (l == r && str.find("AB") == string::npos)
  {
    cout << str << "\n";
    return;
  }
  else
  {
    for (int i = l; i <= r; i++)
    {
      if (isSafe(str, l, i))
      {
        swap(str[l], str[i]);
        permuteNaive(str, l + 1, r);
        swap(str[l], str[i]);
      }
    }
  }
}

int main()
{
  string str = "ABCD";
  permuteNaive(str, 0, 3);
}
