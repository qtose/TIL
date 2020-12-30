#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42748?language=cpp

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	int iSize = commands.size();

	for (auto& vecCommand : commands) {
		vector<int> Buff;

		for (int i = vecCommand[0] - 1; i < vecCommand[1]; ++i) 
			Buff.push_back(array[i]);			
		
		sort(Buff.begin(), Buff.end());

		answer.push_back(Buff[vecCommand[2] - 1]);
	}

	return answer;
}

int main() {
	vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> commands = { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} };

	solution(array, commands);

	return 0;
}