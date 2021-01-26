#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42746

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> v;

	bool b = false;

	for (auto num : numbers)
	{
		if (num != 0)
		{
			b = true;
		}

		v.push_back(to_string(num));
	}

	if (b == false)
	{
		return "0";
	}

	sort(v.begin(), v.end(), [](string a, string b)
	{
		if (a == "0")
		{
			return false;
		}

		string c = a + b;
		string d = b + a;

		return c > d;
	});


	for (auto str : v)
	{
		answer += str;
	}

	return answer;
}

int main() {
	//303, 3001, 34
	//40, 403 ,44
	//0, 5, 10, 15, 20      52015100
	//1000, 0, 5, 99, 100   99510010000
	//111, 1112
	vector<int> v = { 111, 1112 };

	solution(v);

	return 0;
}
