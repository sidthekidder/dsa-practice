#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& adjMatrix, int color[], int idx, int curcolor)
{
	if (color[idx] == -1)
	{
		color[idx] = curcolor;
		int newcolor = (curcolor == 1)? 2 : 1;
		
		for(int i = 0 ; i < adjMatrix[idx].size() ; i++)
		{
			if (adjMatrix[idx][i] == 1)
			{
				bool ret = dfs(adjMatrix, color, i, newcolor);
				if (!ret) return false;
			}
		}
		return true;
	}
	else
	{
		if (curcolor != color[idx])
			return false;
		else
			return true;
	}
}

bool checkBicolorable(vector<vector<int>> adjMatrix)
{
	int n = adjMatrix.size();
	// start dfs on the graph and in each recursion color it
	// check if any colors mismatch
	int color[n];
	for(int i = 0 ; i < n ; i++) color[i] = -1;
	
	return dfs(adjMatrix, color, 0, 1);
}

int main() {

	while (true) {
	
	int n;
	cin >> n;
	if (n == 0) return 0;
	
	vector<vector<int>> adjMatrix;
	for(int i = 0 ; i < n ; i++)
	{
		vector<int> row(n, 0);
		adjMatrix.push_back(row);
	}
	
	int noOfEdges;
	cin >> noOfEdges;
	for(int i = 0 ; i < noOfEdges ; i++)
	{
		int a, b;
		cin >> a >> b;
		adjMatrix[a][b] = 1;
	}
	
	if (checkBicolorable(adjMatrix))
		cout << "BICOLORABLE.\n";
	else
		cout << "NOT BICOLORABLE\n";
	return 0;
	}
}