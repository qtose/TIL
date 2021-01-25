#include <iostream>
#include <vector>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/68645

enum Dir 
{
	Down, Right, Up
};

vector<int> solution(int n) {
	vector<int> answer;

	vector<vector<int>> v;
	
	int Row = 0;
	int Column = 0;
	int Num = 1;

	Dir dir = Down;

	for (int i = 1; i <= n; ++i)
	{
		vector<int> vv;
		vv.resize(i);

		v.push_back(vv);
	}
	
	for (int i = 0; i < n; ++i)
	{
		if (dir == Down) 
		{
			for (int j = i; j < n; ++j)
			{
				v[Row++][Column] = Num++;
			}

			Row -= 1;
			Column += 1;
			dir = Right;
		}
		else if (dir == Right)
		{
			for (int j = i; j < n; ++j)
			{
				v[Row][Column++] = Num++;
			}
			Row -= 1;
			Column -= 2;
			dir = Up;
		}
		else if (dir == Up)
		{
			for (int j = i; j < n; ++j)
			{
				v[Row--][Column--] = Num++;
			}
			Row += 2;
			Column += 1;
			dir = Down;
		}
	}

	for (auto vv : v) 
	{
		for (auto num : vv)
		{
			answer.push_back(num);
		}
	}

	return answer;
}

int main() {

	solution(4);

	return 0;
}