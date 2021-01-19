#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42584

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	for (size_t i = 0; i < prices.size(); ++i)
	{
		int icnt = 0;
		for (size_t j = i + 1; j < prices.size(); ++j)
		{
			if (prices[i] <= prices[j])
			{
				++icnt;
			}
			else 
			{
				++icnt;
				break;
			}
		}
		answer.push_back(icnt);
	}

	return answer;
}

int main() {

	vector<int> v = { 1, 2, 3, 2, 3 };

	solution(v);

	return 0;
}