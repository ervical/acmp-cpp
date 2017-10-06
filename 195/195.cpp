#include <cstdio>

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int number;
	int width;
	int height;
	scanf("%d %d %d", &number, &width, &height);
	printf("%d", (width * height * number) * 2);
	return 0;
}