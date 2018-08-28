#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--)
	{
		long long int n;
		cin >> n;
		
		string S;
		cin >> S;

		long long int count = 0, sum = 0, totalsum = 0;
		for(long long int i = 0 ; i < n ; i++)
		{
			if (S[i] == '1')
			{
				sum = count + 1;
				count += 1;
				totalsum += sum;
			}
		}
		cout << totalsum << endl;
	}
	return 0;
}