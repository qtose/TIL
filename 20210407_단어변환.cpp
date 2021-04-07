#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void find(string begin, string target, vector<string> words, vector<bool>* useCheck, int* answer, int cnt = 0)
{
	for (int i = 0; i < words.size(); i++)
	{
		int count = 0;
		for (int j = 0; j < words[i].length(); j++)
		{
			if (!(*useCheck)[i] && begin[j] != words[i][j])
			{
				count++;
			}
		}

		if (count == 1) 
		{
			if (target == words[i] && *answer > cnt + 1)
			{
				*answer = cnt + 1;
				return;
			}

			(*useCheck)[i] = true;

			find(words[i], target, words, useCheck, answer, cnt + 1);

			(*useCheck)[i] = false;
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	int answer = 50;

	vector<bool> check;
	check.resize(words.size());

	find(begin, target, words, &check, &answer);
	
	if (answer == 50)
	{
		answer = 0;
	}

	return answer;
}

int main()
{
	solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });

	return 0;
}