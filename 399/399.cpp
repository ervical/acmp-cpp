#include <cstdio>
#include <vector>
#include <limits>

using namespace std;


const int MAX_STEPS = 5000000;
const int WALL = numeric_limits<int>::max();
const int DOWN_DI = 1;
const int DOWN_DJ = 0;
const int UP_DI = -1;
const int UP_DJ = 0;
const int RIGHT_DI = 0;
const int RIGHT_DJ = 1;
const int LEFT_DI = 0;
const int LEFT_DJ = -1;

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int maxI;
	int maxJ;
	scanf("%d %d\n", &maxI, &maxJ);
	vector< vector<int> > nVisits(maxI, vector<int>(maxJ)); 
	for (int i = 0; i < maxI; i++)
	{
		for (int j = 0; j < maxJ; j++)
		{
			char ch;
			scanf("%c", &ch);
			if (ch != '@') 
			{
				nVisits[i][j] = 0;
			} 
			else
			{
				nVisits[i][j] = WALL;
			}
		}
		scanf("\n");
	}
	nVisits[1][1] = 1;

	if (((nVisits[2][1] == WALL) && (nVisits[0][1] == WALL) && (nVisits[1][2] == WALL) && (nVisits[1][0] == WALL)))
	{
		printf("-1");
		return 0;
	}
	int steps = 0;
	int curI = 1;
	int curJ = 1;
	int di = DOWN_DI;
	int dj = DOWN_DJ;
	while (true)
	{
		int minVisits = numeric_limits<int>::max();
		int bestDI = 0;
		int bestDJ = 0;
		if (nVisits[curI + DOWN_DI][curJ + DOWN_DJ] < minVisits)
		{
			minVisits = nVisits[curI + DOWN_DI][curJ + DOWN_DJ];
			bestDI = DOWN_DI;
			bestDJ = DOWN_DJ;
		}
		if (nVisits[curI + RIGHT_DI][curJ + RIGHT_DJ] < minVisits)
		{
			minVisits = nVisits[curI + RIGHT_DI][curJ + RIGHT_DJ];
			bestDI = RIGHT_DI;
			bestDJ = RIGHT_DJ;
		}
		if (nVisits[curI + UP_DI][curJ + UP_DJ] < minVisits)
		{
			minVisits = nVisits[curI + UP_DI][curJ + UP_DJ];
			bestDI = UP_DI;
			bestDJ = UP_DJ;
		}
		if (nVisits[curI + LEFT_DI][curJ + LEFT_DJ] < minVisits)
		{
			minVisits = nVisits[curI + LEFT_DI][curJ + LEFT_DJ];
			bestDI = LEFT_DI;
			bestDJ = LEFT_DJ;
		}
		if (minVisits != nVisits[curI + di][curJ + dj])
		{
			di = bestDI;
			dj = bestDJ;
			
		}
		curI += di;
		curJ += dj;
		steps++;
		nVisits[curI][curJ]++;
		if ((curI == maxI - 2) && (curJ == maxJ - 2))
		{
			printf("%d", steps);
			return 0;
		}
		if (steps > MAX_STEPS)
		{
			printf("-1");
			return 0;
		}
	}
}
