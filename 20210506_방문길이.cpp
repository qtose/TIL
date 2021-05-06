#include <iostream>
#include <vector>
#include <string>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/49994

struct DIR
{
	bool u;
	bool d;
	bool r;
	bool l;
};

DIR space[11][11];

int solution(string dirs) {
	int answer = 0;

	int x = 5, y = 5;

	for (int i = 0;i<dirs.length();i++)
	{
		switch (dirs[i])
		{
		case 'U':
			if (x == 0)
			{
				break;
			}

			if (!space[x - 1][y].d)
			{
				space[x][y].u = true;
				space[x - 1][y].d = true;
				answer++;
			}

			x--;

			break;
		case 'D':
			if (x == 10) 
			{
				break;
			}

			if (!space[x + 1][y].u)
			{
				space[x][y].d = true;
				space[x + 1][y].u = true;
				answer++;
			}

			x++;

			break;
		case 'R':
			if (y == 10)
			{
				break;
			}

			if (!space[x][y + 1].l)
			{
				space[x][y].r = true;
				space[x][y + 1].l = true;
				answer++;
			}

			y++;

			break;
		case 'L':
			if (y == 0) 
			{
				break;
			}

			if (!space[x][y - 1].r)
			{
				space[x][y].l = true;
				space[x][y - 1].r = true;
				answer++;
			}

			y--;

			break;

		}

	}

	return answer;
}

int main()
{

	solution("ULURRDLLU");

	return 0;
}