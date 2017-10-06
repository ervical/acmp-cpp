#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct point
{
    int x;
    int y;
    int count;
    
    point(int n, int m, int c):
        x(n),
        y(m),
        count(c)
    {}
};

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int size;
    scanf("%d", &size);
    vector< vector<int> > field(size + 1, vector<int>(size + 1, -1));
    int sX;
    int sY;
    scanf("%d %d", &sX, &sY);
    int fX;
    int fY;
    scanf("%d %d", &fX, &fY);
    if (sX == fX && sY == fY)
    {
        printf("0");
        return 0;
    }
    field[sX][sY] = 0;
    queue<point> q;
    int steps = 0;
    while (sX != fX || sY != fY)
    {
		for (int dx = -2; dx <= 2; dx++)
		{
			for (int dy = -2; dy <= 2; dy++)
			{
				if (dx * dx + dy * dy == 5)
				{
					if (1 <= sX + dx && sX + dx <= size && 1 <= sY + dy && sY + dy <= size)
					{
						if (field[sX + dx][sY + dy] == -1)
						{
							field[sX + dx][sY + dy] = steps + 1;
							q.push(point(sX + dx, sY + dy, steps + 1));
						}
					}
				}
			}
		}
        sX = q.front().x;
        sY = q.front().y;
        steps = q.front().count;
        q.pop();
    }
    printf("%d", field[fX][fY]);
    return 0;
}
