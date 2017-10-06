#include <cstdio>

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int year; 
	scanf("%d", &year);
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		printf("12/09/%04d", year);
	} else {
		printf("13/09/%04d", year);
	}
	return 0;
}
