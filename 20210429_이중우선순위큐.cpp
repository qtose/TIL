#include <iostream>
#include <vector>
#include <string>
#include <list>


using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42628

vector<int> solution(vector<string> operations) {
	vector<int> answer;

	answer.push_back(0);
	answer.push_back(0);

	list<int> greater;
	list<int> less;

	int count = 0;

	for (size_t i = 0; i < operations.size(); ++i)
	{

		if (operations[i][0] == 'I')
		{
			string s = "";

			for (size_t j = 2; j < operations[i].size(); ++j)
			{
				s += operations[i][j];
			}

			int num = stoi(s);

			greater.push_back(num);
			less.push_back(num);

			greater.sort([](int a, int b) { return a > b; });
			less.sort([](int a, int b) { return a < b;});

			++count;
			continue;
		}
		
		if (count == 0)
		{
			continue;
		}

		if (operations[i] == "D 1")
		{
			greater.pop_front();
			--count;
		}

		else if (operations[i] == "D -1")
		{
			less.pop_front();
			--count;
		}
	}

	if (count == 0)
	{
		greater.clear();
		less.clear();
	}

	if (count != 0)
	{
		answer[0] = greater.front();
		answer[1] = less.front();
	}

	return answer;
}

int main()
{
	//solution({"I 7", "I 5", "I -5", "D -1"});
	solution({ "I 16","D 1" });

	return 0;
}