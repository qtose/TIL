#include <iostream>
#include <vector>
#include <list>
//#include <unordered_map>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42583

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	//unordered_map<int, int> mapTruck;

	list<pair<int, int>> listTruck;

	while (true)
	{
		if (listTruck.size() == 0 && truck_weights.size() == 0)
		{
			break;
		}

		int iTotalweight = 0;
		++answer;

		for (auto iter = listTruck.begin(); iter != listTruck.end(); )
		{
			++(*iter).second;

			if ((*iter).second == bridge_length)
			{
				iter = listTruck.erase(iter);
			}
			else
			{
				++iter;
			}
		}

		for (auto& Pair : listTruck)
		{
			iTotalweight += Pair.first;
		}

		if (iTotalweight < weight && truck_weights.size() != 0)
		{
			if (iTotalweight + truck_weights.front() <= weight)
			{
				iTotalweight += truck_weights.front();
				listTruck.push_back(pair<int,int>(truck_weights.front(), 0));

				auto iter = truck_weights.begin();
				truck_weights.erase(iter);
			}
		}
	}

	return answer;
}

int main() {

	int bridge_length = 100;
	int weight = 100;
	vector<int> truck_weights = { 10,10,10,10,10,10,10,10,10,10 };

	solution(bridge_length, weight, truck_weights);

	return 0;
}
