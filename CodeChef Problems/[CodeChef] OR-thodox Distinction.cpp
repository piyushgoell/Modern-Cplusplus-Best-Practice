#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
  string result;
  long long t;
  cin >> t;
  while (t > 0)
  {
    long long a, x, res;
    cin >> x;
    map<long long, long long> arr;
    vector<long long> vec(x, 0);
    string str = "YES";
    cin >> a;
    vec[0] = a;
    arr[a]++;
    res = a;
    for (long long i = 1; i < x; i++)
    {
      cin >> a;
      vec[i] = a;
      arr[a]++;
      res = res | a;
      arr[res]++;
      if (arr[res] > 1)
        str = "NO";
      arr[res]++;
    
  }
  cout << str << "\n";
  t--;
}
}