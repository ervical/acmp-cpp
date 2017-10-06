#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

string::size_type findNumOfDifference(string &s)
{
	if (s.length() == 0) {
		return string::npos;
	}
	string::size_type i = 0;
	string::size_type j = s.length() - 1;
	while(true)
	{
		if(i >= j)
		{
			return string::npos;
		}
		else if (s[i] == s[j])
		{
			i++;
			j--;
		}
		else
		{
			return i;
		}
	}
}

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	stringstream ss;
	while (true)
	{
		int intC = getchar();
		if (intC == EOF)
		{
			break;
		}
		char ch = intC;
		if('A' <= ch && ch <= 'Z')
		{
			ss << (char)(ch - 'A' + 'a');
		}
		else if ('a' <= ch && ch <= 'z')
		{
			ss << ch;
		}
	}
	string str = ss.str();
	string::size_type i = findNumOfDifference(str);
	if (i == string::npos)
	{
		printf("YES\n");
		printf("%s", str.c_str());
		return 0;
	}
	{
		string buf = str;
		buf.erase(i, 1);
		if (findNumOfDifference(buf) == string::npos)
		{
			printf("YES\n");
			printf("%s", buf.c_str());
			return 0;
		}
	}
	string::size_type j = str.length() - 1 - i;
	{
		string buf = str;
		buf.erase(j, 1);
		if (findNumOfDifference(buf) == string::npos)
		{
			printf("YES\n");
			printf("%s", buf.c_str());
			return 0;
		}
	}
	{
		string buf = str;
		buf[i] = buf[j];
		if (findNumOfDifference(buf) == string::npos)
		{
			printf("YES\n");
			printf("%s", buf.c_str());
			return 0;
		}
	}
	printf("N0");
	return 0;
}
