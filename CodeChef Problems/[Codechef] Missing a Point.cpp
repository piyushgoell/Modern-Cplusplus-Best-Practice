#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
  int t;
  long long rectangles;
  cin >> t;
  while (t > 0)
  {
    cin >> rectangles;
    unordered_map<long long, long long> xpoints;
    unordered_map<long long, long long> ypoints;
    long long x, y;
    for (int i = 0; i < 4 * rectangles - 1; i++)
    {
      cin >> x >> y;
      xpoints[x]++;
      ypoints[y]++;
      if(xpoints[x] %2 == 0)
        xpoints.erase(x);
      if (ypoints[y] % 2 == 0)
        ypoints.erase(y);
    }
    cout << xpoints.begin()->first <<" "<<ypoints.begin()->first<<"\n";
    t--;
  }
  return 0;
}