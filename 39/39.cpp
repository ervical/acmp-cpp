#include <cstdio>
#include <vector>

using namespace std;

int main() 
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int days;
	scanf("%d", &days);
	vector<int> priceOfDay(days);
	for (int i = 0; i < days; i++)
	{
		scanf("%d", &priceOfDay[i]);
	}
	vector<bool> isMax(days, false);
	int max = 0;
	for (int i = days - 1; i >= 0; i--)
	{
		if (priceOfDay[i] > max)
		{
			isMax[i] = true;
			max = priceOfDay[i];
		}
	}
	size_t money = 0;
	size_t lengthOfHair = 0;
	for (int i = 0; i < days; i++)
	{
		lengthOfHair++;
		if (isMax[i])
		{
			money += lengthOfHair * priceOfDay[i];
			lengthOfHair = 0;
		}
	}
	printf("%Iu", money);
	return 0;
}
