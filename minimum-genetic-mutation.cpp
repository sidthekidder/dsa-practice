// https://leetcode.com/problems/minimum-genetic-mutation/
// time complexity - O(|V| + |E|), space complexity - O(|V|)

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        unordered_set<string> visited;
        unordered_set<string> all_genes(bank.begin(), bank.end());
        char choices[4] = {'A', 'C', 'G', 'T'};
        
        queue<pair<string, int>> bfs;
        bfs.push(pair<string, int>(start, 0));
        visited.insert(start);
        
        while (!bfs.empty())
        {
            pair<string, int> ele = bfs.front();
            bfs.pop();
            if (end.compare(ele.first) == 0)
                return ele.second;
            
            // put all neighbors of ele.first into queue
            for(int i = 0 ; i < ele.first.length() ; i++)
            {
                string word = ele.first;
                for(int j = 0 ; j < 4 ; j++)
                {
                    word[i] = choices[j];
                    if (all_genes.count(word) > 0 && visited.count(word) == 0)
                    {
                        visited.insert(word);
                        bfs.push(pair<string, int>(word, ele.second + 1));
                    }
                }
            }
        }
        return -1;
    }
};