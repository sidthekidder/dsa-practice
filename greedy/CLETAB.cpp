#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N, M;
		cin >> N >> M;

		vector<int> orders(M);
		for(int i = 0 ; i < M ; i++)
		{
			scanf("%d", &orders[i]);
		}

		int tables[N];
		for(int i = 0 ; i < N ; i++)
		{
			tables[i] = 0;
		}
		int tableNo = 0;
		int count = 0;

		for(int i = 0 ; i < M ; i++)
		{
			// search for this existing customer(orders[i]) already on a table
			bool seatedFlag = false;
			for(int j = 0 ; j < N ; j++)
			{
				if (tables[j] == orders[i])
				{
					// the customer is already seated
					seatedFlag = true;
					break;
				}
			}
			if (seatedFlag)
			{
				continue;
			}

			// else clean a table for him
			count++;
			tables[tableNo++] = orders[i];

			// if end of table roulette then start from 0
			if (tableNo == N - 1)
			{
				tableNo = 0;
			}
		}
		cout << count << endl;
	}
	return 0;
}