#include <iostream>
#include <string>

using namespace std;

int editDistance(string s1, string s2, int m, int n)
{
  if (m == 0)
    return n;
  if (n == 0)
    return m;
  if (s1[m - 1] == s2[n - 1])
    return editDistance(s1, s2, m - 1, n - 1);
  else
    return 1 + min(min(editDistance(s1, s2, m, n - 1), editDistance(s1, s2, m - 1, n)), editDistance(s1, s2, m - 1, n - 1));
}

int editDistanceDPIterative(string s1, string s2, int m, int n)
{
  int dp[m + 1][n + 1];
  for (int i = 0; i <= m; i++)
    dp[i][0] = i;
  for (int i = 0; i <= n; i++)
    dp[0][i] = i;
  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
    }
  }
  return dp[m][n];
}

int main()
{
  string s1 = "DISTANCE";
  string s2 = "EDITING";
  //cout << editDistance(s1, s2, s1.length(), s2.length());
  cout << editDistanceDPIterative(s1, s2, s1.length(), s2.length());
}