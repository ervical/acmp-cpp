#include <cstdio>
#include <string>

using namespace std;

string NextElement(const string &f, size_t &i)
{
	if ((i < f.size()) && ('A' <= f[i] && f[i] <= 'Z'))
	{
		string s(1, f[i]);
		i++;
		if ((i < f.size()) && ('a' <= f[i] && f[i] <= 'z'))
		{
			s += f[i];
			i++;
		}
		string num;
		while ((i < f.size()) && ('0' <= f[i] && f[i] <= '9'))
		{
			num += f[i];
			i++;
		}
		if ((num.size() == 1 && num[0] == '1') || (num.size() > 0 && num[0] == '0'))
		{
			printf("NO");
			exit(0);
		}
		return s;
	}
	else
	{
		printf("NO");
		exit(0);
	}
}


int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	char buffer[1001];
	scanf("%s", buffer);
	string fo(buffer);
	size_t i = 0;
	string LE = NextElement(fo, i);
	while (i < fo.size())
	{
		string CE = NextElement(fo, i);
		if (LE == CE)
		{
			printf("NO");
			return 0;
		}
		else
		{
			LE = CE;
		}
	}
	printf("YES");
	return 0;
}
