#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42747?language=cpp

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end(), [](int a, int b) { return a > b; });

	if (citations.front() == 0)
	{
		return 0;
	}

	for (auto num : citations)
	{
		if (answer < num)
		{
			++answer;
		}
		else
		{
			break;
		}

	}

	return answer;
}

int main() {

	vector<int> v = { 3, 0, 6, 1, 5 };

	solution(v);

	return 0;
}