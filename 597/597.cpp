#include <cstdio>

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int rfield;
	int r1;
	int r2;
	scanf("%d %d %d", &rfield, &r1, &r2);
	if(r1+r2 <= rfield) {
		printf("YES");
	} else {
		printf("NO");
	}
	return 0;
}