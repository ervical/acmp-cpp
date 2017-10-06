#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct point
{
    int x;
    int y;
    int count;
    
    point():
        x(0),
        y(0),
        count(0)
    {}
    
    point(int n, int m, int c):
        x(n),
        y(m),
        count(c)
    {}
};

const int FREE = -1;
const int WALL = -2;
const int PATH = -3;

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int size;
    scanf("%d\n", &size);
    point start;
    point finish;
    bool isStart = true;
    vector< vector<int> > field(size, vector<int>(size));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            char ch;
            scanf("%c", &ch);
            if (ch == '#')
			{
                field[i][j] = WALL;
			}
            else if (ch == '@')
			{
                if (isStart)
                {
                    start.x = i;
                    start.y = j;
                    start.count = 0;
                    isStart = false;
                }
                else
                {
                    finish.x = i;
                    finish.y = j;
                    field[i][j] = FREE;
                }
			}
            else if (ch == '.')
			{
                field[i][j] = FREE;
			}
			else
			{
				throw 1;
			}
        }
        scanf("\n");
    }
    queue<point> q;
    q.push(start);
    while (!q.empty())
    {
        point p = q.front();
		q.pop();
		for (int dx = -2; dx <= 2; dx++)
		{
			for (int dy = -2; dy <= 2; dy++)
			{
				if (dx * dx + dy * dy == 5)
				{
					if (0 <= p.x + dx && p.x + dx < size && 0 <= p.y + dy && p.y + dy < size)
					{
						if (field[p.x + dx][p.y + dy] == FREE)
						{
							field[p.x + dx][p.y + dy] = p.count + 1;
							q.push(point(p.x + dx, p.y + dy, p.count + 1));
						}
					}
				}
			}
		}
    }
    if (field[finish.x][finish.y] == FREE)
    {
        printf("Impossible");
        return 0;
    }
	while (finish.x != start.x || finish.y != start.y)
    {
		bool done = false;
		for (int dx = -2; dx <= 2 && !done; dx++)
		{
			for (int dy = -2; dy <= 2 && !done; dy++)
			{
				if (dx * dx + dy * dy == 5)
				{
					if (0 <= finish.x + dx && finish.x + dx < size && 0 <= finish.y + dy && finish.y + dy < size)
					{
						if (field[finish.x][finish.y] - field[finish.x + dx][finish.y + dy] == 1)
						{
							field[finish.x][finish.y] = PATH;
							finish.x += dx;
							finish.y += dy;
							done = true;
						}
					}
				}
			}
		}
    }
	field[start.x][start.y] = PATH;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (field[i][j] == PATH)
			{
                printf("@");
			}
            else if (field[i][j] == WALL)
			{
                printf("#");
			}
            else
			{
                printf(".");
			}
        }
        printf("\n");
    }

    return 0;
}
