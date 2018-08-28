#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int p;
		cin >> p;

		int menus = 0;
		for(int i = 11 ; i >= 0 ; i--)
		{
			int t = pow(2, i);
			if (t > p) continue;

			menus += p/t;
			p = p%t;
		}
		cout << menus << endl;;
	}
	return 0;
}