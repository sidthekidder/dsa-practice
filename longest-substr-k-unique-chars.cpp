//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring/0

#include <iostream>
#include <map>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--)
	{
		string s;
		int k;
		map<char, int> freq;
		int maxLen = -1;
		cin >> s;
		cin >> k;
		
		int j = 0, i = 0;
		// keep going while j < str.length and i < j
		while(j < s.length() && i <= j)
		{
			// increment freq of current character - j
			if (freq[s[j]])
				freq[s[j]] = freq[s[j]] + 1;
			else
				freq[s[j]] = 1;
			
			// check if condition satisfied - exactly k unique chars
			if (freq.size() == k)
			{
				maxLen = max(maxLen, j - i + 1);
			}
			else if (freq.size() == k + 1)
			{
				// we've just exceeded by 1 - increment i till size is back to k
				while (freq.size() > k && i <= j)
				{
					// remove ith element
					if (freq[s[i]] > 1)
						freq[s[i]] = freq[s[i]] - 1;
					else if (freq[s[i]] == 1)
						freq.erase(s[i]);
					i++;
				}
			}
			j++;
		}
		cout << maxLen << endl;
	}
	return 0;
}