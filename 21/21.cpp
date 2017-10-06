#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int wage1;
	int wage2;
	int wage3;
	scanf("%d %d %d", &wage1, &wage2, &wage3);
	printf("%d", max(max(wage1, wage2), wage3) - min(min(wage1, wage2), wage3));
	return 0;
}