#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42888

vector<string> solution(vector<string> record) {
	vector<string> answer;

	vector<vector<string>> v;

	for (size_t i = 0; i < record.size(); ++i)
	{
		string action = "";
		string id = "";
		string name = "";

		bool isAction = false;
		bool isId = false;

		string dummy = "";

		for (size_t j = 0; j < record[i].length(); ++j)
		{
			if (record[i][j] == ' ')
			{
				if (isAction == false)
				{
					action = dummy;
					isAction = true;

					if (action == "Leave")
					{
						id = "_";
						isId = true;
					}

					dummy = "";
					continue;
				}

				if (isId == false)
				{
					id = dummy;
					isId = true;

					dummy = "";
					continue;
				}
			}
			dummy += record[i][j];
		}

		name = dummy;

		if (action == "Leave")
		{
			for (size_t j = 0; j < v.size(); ++j)
			{
				if (name == v[j][1])
				{
					id = name;
					name = v[j][2];
					break;
				}
			}
		}

		vector<string> str = { action, id, name };
		v.push_back(str);
	}

	map<string, string> m;

	for (size_t i = 0; i < v.size(); ++i)
	{
		string action = v[i][0];
		string id = v[i][1];
		string name = v[i][2];

		if (action == "Leave")
		{
			auto iter = m.find(id);

			if (iter == m.end())
			{
				m.emplace(id, name);
			}
		}
		else if (action == "Enter")
		{
			auto iter = m.find(id);

			if (iter != m.end())
			{
				(*iter).second = name;
			}
		}
		else if (action == "Change")
		{
			auto iter = m.find(id);

			if (iter != m.end())
			{
				(*iter).second = name;
			}
			else
			{
				m.emplace(id, name);
			}
		}
	}

	for (size_t i = 0; i < v.size(); ++i)
	{
		string dummy = "";

		auto iter = m.find(v[i][1]);

		if (iter != m.end())
		{
			dummy += (*iter).second + "´ÔÀÌ ";
		}

		else
		{
			dummy += v[i][2] + "´ÔÀÌ ";
		}

		if (v[i][0] == "Enter")
		{
			dummy += "µé¾î¿Ô½À´Ï´Ù.";
		}
		else if (v[i][0] == "Leave")
		{
			dummy += "³ª°¬½À´Ï´Ù.";
		}
		else
		{
			continue;
		}

		answer.push_back(dummy);
	}

	return answer;
}

int main()
{
	vector<string> v = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };

	solution(v);

	return 0;
}