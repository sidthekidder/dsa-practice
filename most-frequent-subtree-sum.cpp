// https://leetcode.com/problems/most-frequent-subtree-sum
// time complexity - O(N), space complexity - O(N)

class Solution {
public:
    int count_sums(TreeNode* root, unordered_map<int, int>& freq_count)
    {
        if (root == NULL)
            return 0;
        
        int sum = root->val + count_sums(root->left, freq_count) + count_sums(root->right, freq_count);
        freq_count[sum]++;

        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        unordered_map<int, int> freq_count;
        int ele = count_sums(root, freq_count);
        
        int max_count = 0;
        for(unordered_map<int, int>::iterator itr = freq_count.begin() ; itr != freq_count.end() ; itr++)
            if (itr->second > max_count)
                max_count = itr->second;

        vector<int> result;
        for(unordered_map<int, int>::iterator itr = freq_count.begin() ; itr != freq_count.end() ; itr++)
            if (itr->second == max_count)
                result.push_back(itr->first);
        
        return result;
    }
};