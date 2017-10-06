#include <cstdio>
#include <vector>
#include <string>

using namespace std;

vector<int> getResultOfPrefixFunc(const string &s)
{
	vector<int> p(s.length());
	p[0] = 0;
	for (string::size_type i = 1; i < s.length(); i++)
	{
		int j = p[i - 1];
		while (j > 0 && s[j] != s[i])
		{
			j = p[j - 1];
		}
		if (s[j] == s[i])
		{
			j++;
		}
		p[i] = j;
	}
	return p;
}

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	char buffer1[50001];
	scanf("%s", buffer1);
	string str(buffer1);
	char buffer2[50001];
	scanf("%s", buffer2);
	string substr(buffer2);
	string sstr = substr + '#' + str;
	vector<int> p = getResultOfPrefixFunc(sstr);
	for (string::size_type i = substr.length() + 1; i < sstr.length(); i++)
	{
		if (p[i] == substr.length())
		{
			printf("%Iu ", i - 2 * substr.length());
		}
	}
	return 0;
}