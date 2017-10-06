#include <cstdio>

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int nDigitNum;
	int radix;
	scanf("%d %d", &nDigitNum, &radix);
	int numsWithZero = 0;
	int numsWithoutZero = radix - 1;
	for (int i = 2; i <= nDigitNum; i++)
	{
		int buf = numsWithoutZero;
		numsWithoutZero = (numsWithoutZero + numsWithZero) * (radix - 1);
		numsWithZero = buf;
	}
	printf("%d", numsWithZero + numsWithoutZero);
	return 0;
}