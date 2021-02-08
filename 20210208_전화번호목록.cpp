#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42577

bool solution(vector<string> phone_book) {

	sort(phone_book.begin(), phone_book.end());

	for (size_t i = 0; i < phone_book.size() - 1; ++i)
	{
		if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].length()))
		{
			return false;
		}
	}

	return true;
}

int main() {

	vector<string> v = { "123", "456", "789" };

	solution(v);

	return 0;
}