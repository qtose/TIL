#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42885

int solution(vector<int> people, int limit) {
	int answer = 0;

	int begin = 0, end = people.size() - 1;

	sort(people.begin(), people.end());

	while (begin <= end)
	{
		if (people[begin] + people[end] <= limit)
		{
			begin++;
			end--;
		}
		else 
		{ 
			end--;
		}
		answer++;
	}
	return answer;
}

int main()
{
	vector<int> v = { 70, 50, 80, 50 };

	solution(v, 100);

	return 0;
}