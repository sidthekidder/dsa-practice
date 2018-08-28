#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Item
{
	int index;
	int val;
	int diff;
};

bool compareItem(const Item &a, const Item &b)
{
	return a.diff > b.diff;
}

int main()
{
	int N, X, Y;
	cin >> N >> X >> Y;

	vector<Item> A;
	vector<Item> B;
	for(int i = 0 ; i < N ; i++)
	{
		Item aa;
		aa.index = i;
		int temp;
		cin >> temp;
		aa.val = temp;
		aa.diff = 0;
		A.push_back(aa);
	}
	for(int i = 0 ; i < N ; i++)
	{
		Item bb;
		bb.index = i;
		int temp;
		cin >> temp;
		bb.val = temp;
		bb.diff = 0;
		B.push_back(bb);
	}

	vector<Item> diffA;
	vector<Item> diffB;
	for(int i = 0 ; i < N ; i++)
	{
		Item aa;
		aa.index = A[i].index;
		aa.val = A[i].val;
		aa.diff = A[i].val - B[i].val;
		diffA.push_back(aa);
	}
	for(int i = 0 ; i < N ; i++)
	{
		Item bb;
		bb.index = B[i].index;
		bb.val = B[i].val;
		bb.diff = B[i].val - A[i].val;
		diffB.push_back(bb);
	}

	sort(diffA.begin(), diffA.end(), compareItem);
	sort(diffB.begin(), diffB.end(), compareItem);

	int p = 0;
	int tips = 0, countA = 0, countB = 0;
	while (p < N)
	{
		// cout << "p is now " << p << endl;
		if (diffA[countA].diff >= diffB[countB].diff && countA <= X)
		{
			// cout << "adding A this time: ";
			tips += diffA[countA].val;
			p++;
			countA++;
		} else if (diffB[countB].diff >= diffA[countA].diff && countB <= Y)
		{
			// cout << "adding B this time: ";
			tips += diffB[countB].val;
			p++;
			countB++;
		}
	}
	cout << tips;

	return 0;
}