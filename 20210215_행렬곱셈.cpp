#include <iostream>
#include <vector>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12949


//Row За, Column ї­

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;

	for (size_t col = 0; col < arr1.size(); ++col)
	{
		vector<int> row;
		row.resize(arr2[0].size());
		answer.push_back(row);
	}


	for (size_t col = 0; col < arr1.size(); ++col)
	{
		for (size_t i = 0; i < arr2[0].size(); ++i)
		{
			int num = 0;

			for (size_t row = 0; row < arr1[col].size(); ++row)
			{
				num += arr1[col][row] * arr2[row][i];
			}

			answer[col][i] = num;
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> arr1 = { {1,4}, {3,2}, {4,1} };
	vector<vector<int>> arr2 = { {3,3}, {3,3} };

	solution(arr1, arr2);

	return 0;
}