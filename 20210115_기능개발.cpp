#include <iostream>
#include <vector>
#include <list>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42586

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	list<pair<int, int>> lists;

	for (size_t i = 0; i < progresses.size(); ++i)
	{
		lists.push_back(pair<int, int>(progresses[i], speeds[i]));
	}


	while (0 != lists.size())
	{
		int iNum = 0;

		for (auto& pair : lists)
		{
			pair.first += pair.second;
		}
		
		while (lists.size() != 0 && 100 <= lists.front().first)
		{
			lists.pop_front();
			++iNum;
		}

		if (0 < iNum)
		{
			answer.push_back(iNum);
		}
	}

	return answer;
}

int main() {

	vector<int> progress = { 93, 30, 55 };
	vector<int> speeds = { 1, 30, 5 };

	solution(progress, speeds);

	return 0;
}
