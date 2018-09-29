#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

static bool customCompare(pair<int, int> p1, pair<int, int> p2)
{
	return p1.first < p2.first;
}

int main() {
	int t;
	cin >> t;
	vector<pair<int, int>> times;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		times.push_back(pair<int, int>(a, b));
	}
	sort(times.begin(), times.end(), customCompare);
	
	int curEnd = times[0].second;
	int longestNoMilking = numeric_limits<int>::min();
	for(int i = 1 ; i < times.size() ; i++)
	{
		if (curEnd < times[i].first)
			longestNoMilking = max(longestNoMilking, times[i].first - curEnd);
		if (curEnd < times[i].second)
			curEnd = times[i].second;
	}
	
	curEnd = times[0].second;
	int curStart = times[0].first;
	int longestMilking = numeric_limits<int>::min();
	for(int i = 1 ; i < times.size() ; i++)
	{
		if (curEnd > times[i].first)
			longestMilking = max(longestMilking, times[i].second - curStart);
		else
			curStart = times[i].first;

		if (curEnd < times[i].second)
			curEnd = times[i].second;
	}
	cout << longestMilking << " " << longestNoMilking << endl;
	return 0;
}