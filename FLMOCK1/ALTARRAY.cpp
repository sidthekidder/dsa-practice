#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--)
	{
		int N;
		 cin >> N;
		 vector<int> weights;

		 for(int i  = 0 ; i < N ; i++)
		 {
		 	int t;
		 	cin >> t;
		 	weights.push_back(t);
		 }
		 
		 int fin[N] = {1};
		 int cursign = 0, curLen = 0, maxLen = 0;
		 for(int i = N-1 ; i >= 0 ; i--)
		 {
		 	if (weights[i] > 0 && cursign <= 0)
		 	{
		 		curLen += 1;
		 		cursign = 1;
		 	}
		 	else if (weights[i] < 0 && cursign >= 0)
		 	{
		 		curLen += 1;
		 		cursign = -1;
		 	}
		 	else
		 	{
		 		curLen = 1;
		 	}
			fin[i] = curLen;
		 }
		 for(int i = 0 ; i < N ; i++)
			cout << fin[i] << " ";
		 cout << endl;
	}
	return 0;
}