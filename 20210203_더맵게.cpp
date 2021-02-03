#include <iostream>
#include <vector>
#include <map>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42626

int solution(vector<int> scoville, int K) {
	int answer = 0;

	map<int, int> m;
	
	for (auto& num : scoville)
	{
		auto iter = m.find(num);

		if (iter == m.end())
		{
			m.emplace(num, 1);
			continue;
		}
	
		++(*iter).second;
	}

	int count = -1;

	while (true)
	{	
		++count;

		auto iter_first = m.begin();

		if (iter_first == m.end())
		{
			return -1;
		}

		if (K <= (*m.begin()).first)
		{
			break;
		}

		if ((*iter_first).second <= 1 && m.size() == 1)
		{
			return -1;
		}
		if (2 <= (*iter_first).second)
		{
			int num = (*iter_first).first;
			num = num + num * 2;

			(*iter_first).second -= 2;

			if ((*iter_first).second <= 0)
			{
				m.erase(iter_first);
			}

			auto iter = m.find(num);

			if (iter == m.end())
			{
				m.emplace(num, 1);
			}
			else 
			{
				++(*iter).second;
			}

			continue;
		}

		auto iter_second = ++m.begin();
		int num = (*iter_first).first + (*iter_second).first * 2;

		--(*iter_second).second;
		iter_second = m.erase(iter_first);

		if ((*iter_second).second <= 0)
		{
			m.erase(iter_second);
		}

		auto iter = m.find(num);

		if (iter == m.end())
		{
			m.emplace(num, 1);
		}
		else
		{
			++(*iter).second;
		}
	}


	return answer = count;
}

int main() {

	vector<int> v = { 1, 2, 3, 9, 10, 12 };
	int i = 7;

	solution(v, i);

	return 0;
}