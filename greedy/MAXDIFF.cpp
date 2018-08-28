#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int main() 
{
	int T;
	cin >> T;

	while(T--)
	{
		int N, K;
		cin >> N >> K;

		vector<int> weights(N);
		for(int i = 0 ; i < N ; i++)
		{
			scanf("%d", &weights[i]);
		}

		sort(weights.begin(), weights.end());

		int minSize = min(K, N - K);

		int childSum = 0;
		for(int i = 0 ; i < minSize ; i++)
		{
			childSum += weights[i];
		}

		int chefSum = 0;
		for(int i = minSize ; i < N ; i++)
		{
			chefSum += weights[i];
		}

		cout << chefSum - childSum;
		cout << endl;
	}
	return 0;
}
