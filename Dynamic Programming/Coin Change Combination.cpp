#include <iostream>

using namespace std;

int getCount(int coins[], int coinsLength, int amount)
{
  if (amount == 0)
    return 1;
  if (coinsLength < 0)
    return 0;
  int res = getCount(coins, coinsLength - 1, amount);
  if (coins[coinsLength - 1] <= amount)
    res = res + getCount(coins, coinsLength, amount - coins[coinsLength - 1]);

  return res;
}

int main()
{
  int coins[] = {2, 5, 3, 6};
  cout << getCount(coins, 4, 4);
}