// https://open.kattis.com/contests/naq19open/problems/stopcounting


#include <bits/stdc++.h>
using namespace std;

int main() 
{
	string str;
	cin >> str;
	int count = 0;
	
	int counter = 0;
	set<string> seen;
	
	vector<set<char>> prevRow;
	vector<set<char>> curRow;
	for(int i = str.length() ; i >= 0 ; i--)
	{
	    prevRow = curRow;
	    curRow = vector<set<char>>(str.length(), set<char>());
	    set<char> curSet;
		for(int j = i ; j < str.length() ; j++)
		{
		    curSet.insert(str[j]);
		    curRow[j] = curSet;
		}
		
		for(int j = i ; j < str.length() ; j++)
		{
			int start = i;
			int end = j;
			bool increment = true;
			if (j > 0 && str[j-1] == str[j])
			    continue;
// 			cout<<"Checking string "<<str.substr(i, j-i+1)<<endl;
			
			if (str[start] == str[end])
				continue;
			
			if (prevRow.size()>0 && (prevRow[j-1].count(str[start]) > 0 || prevRow[j-1].count(str[end]) > 0))
			    continue;
			
			string curstr = str.substr(i, j-i+1);
			if (seen.count(curstr) > 0)
			    continue;
			
			seen.insert(curstr);
// 			cout<<"good iterinary!\n";
		    counter++;
		}
	}
	
	cout<<counter;
}