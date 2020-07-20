#include <climits>
#include <cstring>
#include <iostream>
using namespace std;
int dp[100];
bool check[100];
void set()
{
  memset(dp, 0, sizeof(dp));
  memset(check, 0, sizeof(check));
  dp[2] = 1;
  dp[3] = 1;
  dp[4] = 2;
  dp[5] = 1;
  dp[6] = 3;
  dp[7] = 1;
  dp[8] = 4;
}

long long getCount(int n)
{
  if (dp[n] != 0)
  {
    check[n] = 1;
    return dp[n];
  }
  if (n <= 3)
    dp[n] = 1;

  for (int i = 1; i <= n / 2; i++)
  {
    for (int j = 1; j <= n && i * j <= n; j++)
    {
      std::cout << i << " " << j << "\n";
      if (i * j == n)
      {

        if (j == n)
        {
          cout << "common match ";
          dp[i * j] += 1;
        }

        else
        {
          cout << "match ";
          dp[i * j] += getCount(i) + getCount(j);
        }
        cout << " " << i * j << " " << dp[i * j] << "\n ";
      }
    }
  }
  check[n] = 1;
  return dp[n];
}

int main()
{
  int n;

  cin >> n;
  // long long count = 1;
  // for (int i = 1; i < n / 2; i++)
  // {
  //   for (int j = 1; j < n / 2; j++)
  //     if (i * (i + 1) == n)
  //       count++;
  // }
  set();
  cout << getCount(n);
}