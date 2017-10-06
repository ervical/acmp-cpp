#include <cstdio>
#include <vector>

using namespace std;

void tick(int &h, int &m, int &s)
{
	if (s == 59)
	{
		s = 0;
		if (m == 59)
		{
			m = 0;
			if (h == 23)
			{
				h = 0;
			}
			else 
			{
				h++;
			}
		}
		else
		{
			m++;
		}
	}
	else
	{
		s++;
	}
}

void IncNum(vector<int> &v, int h, int m, int s)
{
	v[h / 10]++;
	v[h % 10]++;
	v[m / 10]++;
	v[m % 10]++;
	v[s / 10]++;
	v[s % 10]++;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	vector<int> digits(10, 0);
	int h1;
	int m1;
	int s1;
	scanf("%d:%d:%d", &h1, &m1, &s1);
	int h2;
	int m2;
	int s2;
	scanf("%d:%d:%d", &h2, &m2, &s2);
	while ((h1 != h2) || (m1 != m2) || (s1 != s2))
	{
		IncNum(digits, h1, m1, s1);
		tick(h1, m1, s1);
	}
	IncNum(digits, h1, m1, s1);
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d\n", digits[i]);
	}
	return 0;
}
