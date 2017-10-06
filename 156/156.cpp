#include <cstdio>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int size;
    int rook;
    scanf("%d %d", &size, &rook);
    int numOfWays = 1;
    for (int i = size; i > size - rook; i--)
	{
        numOfWays *= i * i;
	}
	int numOfPlacements = 1;
    for (int i = rook; i >= 1; i--)
	{
        numOfPlacements *= i;
	}
    printf("%d", numOfWays / numOfPlacements);
    return 0;
}
