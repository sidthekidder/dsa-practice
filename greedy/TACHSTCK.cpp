#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() 
{
	int N, D;
	scanf("%d %d", &N, &D);
	vector<int> L(N);
	for(int i = 0 ; i < N ; i++)
	{
		scanf("%d", &L[i]);
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