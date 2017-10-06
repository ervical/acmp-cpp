#include <cstdio>
#include <vector>
#include <string>

using namespace std;

vector<size_t> getNumOfChars(const string &s)
{
	vector<size_t> buffer(26, 0);
	for (string::size_type i = 0; i < s.length(); i++)
	{
		buffer[s[i] - 'a']++;
	}
	return buffer;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int numOfWords;
	scanf("%d", &numOfWords);
	vector<string> words(numOfWords);
	for (int i = 0; i < numOfWords; i++)
	{
		char buffer[11];
		scanf("%s", buffer);
		words[i] = buffer;
	}
	char buffer[101];
	scanf("%s", buffer);
	vector<size_t> charsInSet = getNumOfChars(buffer);
	size_t count = 0;
	for (int i = 0; i < numOfWords; i++)
	{
		vector<size_t> charsInWord = getNumOfChars(words[i]);
		bool isContained = true;
		for (int j = 0; j < 26; j++)
		{
			if (charsInWord[j] > charsInSet[j]) 
			{
				isContained = false;
				break;
			}
		}
		if (isContained) 
		{
			count++;
		}
	}
	printf("%Iu", count);
	return 0;
}
