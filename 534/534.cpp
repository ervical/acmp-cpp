#include <cstdio>
#include <vector>

using namespace std;

struct keys {

	int downs;

	int max;

	keys()
		: downs(0)
		, max(0)
	{}
};

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int nKeys;
	scanf("%d", &nKeys);
	vector<keys> a(nKeys);
	for (int i = 0; i < nKeys; i++) {
		scanf("%d", &a[i].max);
	}
	int nPresses;
	scanf("%d", &nPresses);
	for (int i = 0; i < nPresses; i++) {
		int key;
		scanf("%d", &key);
		a[key - 1].downs++;
	}
	for (int i = 0; i < nKeys; i++){
		if (a[i].downs <= a[i].max) {
			printf("no\n");
		} else {
			printf("yes\n");
		}
	}
	return 0;
}
