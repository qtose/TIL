#include <iostream>
#include <vector>
#include <list>
#include <string>


using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42587

int solution(vector<int> priorities, int location) {
	int answer = 0;

	list<pair<int, int>> q;

	for (size_t i = 0; i < priorities.size(); ++i)
	{
		q.push_back(pair<int, int>(i, priorities[i]));
	}

	int iNum = 0;
	while (q.size() != 0) {
		++iNum;
		for (size_t i = 0; i < q.size(); ++i) {
			for (auto iter = ++q.begin(); iter != q.end(); ++iter)
			{
				if ((*iter).second > q.front().second)
				{
					q.push_back(q.front());
					q.pop_front();
					break;
				}
			}
		}

		if (q.front().first != location)
		{
			q.pop_front();
		}

		else
		{
			answer = iNum;
			break;
		}
	}

	return answer;
}

int main() {
	vector<int> v = { 2, 1, 3, 2 };

	solution(v, 2);

	return 0;
}