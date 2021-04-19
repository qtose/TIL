#include <iostream>
#include <vector>
#include <string>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/76501

int solution(vector<int> absolutes, vector<bool> signs) {
	int answer = 0;
	
	for (int i = 0; i < absolutes.size(); ++i)
	{
		answer += signs[i] ? absolutes[i] : -absolutes[i];
	}

	return answer;
}

int main() 
{

}