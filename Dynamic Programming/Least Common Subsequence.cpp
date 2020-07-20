#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dp[100][100]{-1};

long leastCommonSubsequenceRecursive(string s1, string s2, size_t m, size_t n)
{
  if (dp[m][n] != 0)
    return dp[m][n];
  else if (m == 0 || n == 0)
    return 0;
  else if (s1[m] == s2[n])
    dp[m][n] = 1 + leastCommonSubsequenceRecursive(s1, s2, m - 1, n - 1);
  else
    dp[m][n] = max(leastCommonSubsequenceRecursive(s1, s2, m - 1, n), leastCommonSubsequenceRecursive(s1, s2, m, n - 1));

  return dp[m][n];
}

int leastCommonSubsequenceIterative(string s1, string s2, size_t m, size_t n)
{

  for (size_t i = 1; i <= m; i++)
    for (size_t j = 1; j <= n; j++)
    {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }

  return dp[m][n];
}

int main()
{
  string s1 = "ABCDGH";
  string s2 = "AEDFHR";

  std::cout << leastCommonSubsequenceRecursive(s1, s2, s1.length(), s2.length());
  std::cout << leastCommonSubsequenceIterative(s1, s2, s1.length() + 1, s2.length() + 1);
  return 0;
}