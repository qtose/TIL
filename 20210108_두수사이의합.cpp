#include <iostream>
#include <vector>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/12912

long long solution(int a, int b) {
	long long answer = 0;

	int iMax = a < b ? b : a;
	int iMin = a < b ? a : b;

	
		for (int i = iMin; i <= iMax; ++i) 
			answer += i;
		
	return answer;
}

int main() {

	return 0;
}
