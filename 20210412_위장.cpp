#include <iostream>
#include <vector>
#include <map>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42578

int solution(vector<vector<string>> clothes) {
	int answer = 0;

	map<string, vector<string>> m;

	for (int i = 0; i < clothes.size(); ++i)
	{
		auto iter = m.find(clothes[i][1]);

		if (iter == m.end())
		{
			vector<string> v;
			v.push_back(clothes[i][0]);

			m.emplace(clothes[i][1], v);
		}

		else
		{
			(*iter).second.push_back(clothes[i][0]);
		}
	}

	int num = 1;
	
	for (auto pair : m)
	{
		num *= pair.second.size() + 1;
	}

	answer = num - 1;


	return answer;
}

int main()
{
	solution({ { "yellowhat", "headgear"},{"bluesunglasses", "eyewear"},{"green_turban", "headgear" }});
	//solution({ {"crowmask", "face"},{"bluesunglasses", "face"},{"smoky_makeup", "face"} });


	return 0;
}