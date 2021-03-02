#include <iostream>
#include <vector>
#include <string>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/17681

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	for (int i = 0; i < n; ++i)
	{
		vector<bool> v, vv;
		v.resize(n);
		vv.resize(n);

		int a = arr1[i];
		int b = arr2[i];

		int num = n - 1;

		while (a >= 1)
		{
			v[num--] = bool(a % 2);
			a = a / 2;
		}

		num = n - 1; 

		while (b >= 1)
		{
			vv[num--] = bool(b % 2);
			b = b / 2;
		}

		string str = "";

		for (int i = 0; i < n; ++i)
		{
			if (v[i] | vv[i])
			{
				str += "#";
			}
			else
			{
				str += " ";
			}
		}

		answer.push_back(str);
	}


	return answer;
}

int main()
{
	vector<int> arr1 = { 9, 20, 28, 18, 11 };
	vector<int> arr2 = { 30, 1, 21, 17, 28 };

	solution(5, arr1, arr2);

	return 0;
}