#include <cstdio>
#include <vector>

using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int maxI;
	int maxJ;
	scanf("%d %d\n", &maxI, &maxJ);
	vector< vector<char> > table (maxI, vector<char>(maxJ));
	for (int i = 0; i < maxI; i++) {
		for (int j = 0; j < maxJ; j++) {
			scanf("%c", &table[i][j]);
		}
		scanf("\n");
	}
	for (int i = 0; i < maxI; i++) {
		for (int j = 0; j < maxJ; j++) {
			int d;
			scanf("%d", &d);
			if (table[i][j] == 'B' && (d & 1) == 0) {
				printf("NO");
				return 0;
			}
			if (table[i][j] == 'G' && (d & 2) == 0) {
				printf("NO");
				return 0;
			}
			if (table[i][j] == 'R' && (d & 4) == 0) {
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES");
	return 0;
}
