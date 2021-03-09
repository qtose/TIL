#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12913

int Max(int& idx, vector<int> v)
{
	int temp = 0;

	for (int i = 0; i < 4; i++)
	{
		if (i != idx)
		{
			temp = max(temp, v[i]);
		}
	}

	return temp;
}

int solution(vector<vector<int>> land)
{
	int answer = 0;
	
	for (size_t i = 1; i < land.size(); i++) 
	{
		for (int j = 0; j < 4; j++)
		{
			land[i][j] += Max(j, land[i - 1]);
			answer = max(answer, land[i][j]);
		}
	}
	
	return answer;
}

int main()
{
	vector<vector<int>> v = { { 4, 3, 2, 1 }, { 2, 2, 2, 1 }, { 6, 6, 6, 4 }, { 8, 7, 6, 5 } };

	solution(v);
	
	return 0;
}