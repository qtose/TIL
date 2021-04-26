#include <iostream>
#include <vector>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12900

int solution(int n) {
	int answer = 0;

	vector<int> v;

	v.push_back(1);
	v.push_back(1);

	for (int i = 2; i <= n; ++i)
	{
		v.push_back((v[i - 1] + v[i - 2]) % 1000000007);
	}

	return v[n] % 1000000007;
}

int main()
{
	solution(4);

	return 0;
}