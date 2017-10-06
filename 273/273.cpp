#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	char buffer[102];
	scanf("%s", buffer);
	string digit(buffer);
	vector<bool> wasNum(1000, false);
	for (int i = 0; i < digit.length() - 2; i++) {
		for (int j = i + 1; j < digit.length() - 1; j++) {
			for (int k = j + 1; k < digit.length(); k++) {
				int n = (digit[i] - '0') * 100 + (digit[j] - '0') * 10 + (digit[k] - '0');
				wasNum[n] = true;
			}
		}
	}
	int count = 0;
	for (int i = 100; i <= 999; i++) {
		if (wasNum[i]) {
			count++;
		}
	}
	printf("%d", count);
	return 0;
}
