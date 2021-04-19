#include <iostream>
#include <vector>
#include <string>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12977



int solution(vector<int> nums) {
	int answer = 0;

	vector<int> v;

	int size = nums.size();

	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			for (int h = j + 1; h < size; ++h)
			{
				v.push_back(nums[i] + nums[j] + nums[h]);
			}
		}
	}

	int max = 3000;
	vector<int> sosu;
	sosu.resize(max);

	for (int i = 2; i < max; ++i)
	{
		sosu[i] = i;
	}

	for (int i = 2; i < 3000; ++i)
	{
		if (sosu[i] == 0)
		{
			continue;
		}

		for (int j = 2 * i; j < max; j += i)
		{
			sosu[j] = 0;
		}
	}

	for (auto num : v)
	{
		if (sosu[num] != 0)
		{
			++answer;
		}
	}

	return answer;
}

int main()
{
	vector<int> v = { 1, 2, 3, 4 };

	solution(v);

	return 0;
}