#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() 
{
	int N;
	scanf("%d", &N);
	vector<int> B(N);
	vector<int> L(N);
	for(int i = 0 ; i < N ; i++)
	{
		scanf("%d %d", &B[i], &L[i]);
	}

	sort(L.begin(), L.end());
	int count = 0;
	for(int i = 0 ; i < L.size() - 1 ; i++)
	{
		if (L[i+1] - L[i] <= D)
		{
			count++;
			i += 1;
		}
	}

	cout << count << endl;
	return 0;
}