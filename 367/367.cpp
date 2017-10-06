#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

void mult(vector<int> &left,const int right)
{
    vector<int> temp(left.size(), 0);
	int carry = 0;
    for(int i = 0; i < (int)left.size(); i++)
    {
		carry += left[i] * right;
		left[i] = carry % 100000000;
		carry /= 100000000;
    }
	if (carry != 0)
	{
		left.push_back(carry);
	}
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int base;
    int power;
    scanf("%d %d", &base, &power);
    vector<int> num(1, base);
    for (int i = 1; i < power; i++)
	{
        mult(num, base);
	}
    printf("%d", num[num.size() - 1]);
    for (int i = num.size() - 2; i >= 0 ; i--)
	{
		printf("%08d", num[i]);
	}
    return 0;
}