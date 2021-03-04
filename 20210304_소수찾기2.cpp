#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42839

int solution(string numbers) {
	int answer = 0;

	vector<char> c;
	vector<int> v;

	for (size_t i = 0; i < numbers.length(); ++i)
	{
		c.push_back(numbers[i]);
	}

	sort(c.begin(), c.end());

	do {
		string temp = "";

		for (size_t i = 0; i < c.size(); i++) {
			temp += c[i];
			v.push_back(stoi(temp));
		}
	} while (next_permutation(c.begin(), c.end()));

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());


	for (size_t i = 0; i < v.size(); ++i)
	{
		if (v[i] < 2)
		{
			continue;
		}

		bool b = false;
		for (int j = 2; j <= sqrt(v[i]); ++j)
		{
			if (v[i] % j == 0)
			{
				b = true;
				break;
			}
		}
		
		if (b)
		{
			continue;
		}

		++answer;
	}

	return answer;
}

int main()
{

	solution("011");

	return 0;
}