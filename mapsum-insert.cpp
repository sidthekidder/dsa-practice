// https://leetcode.com/explore/learn/card/trie/148/practical-application-i/1058/
// time complexity - O(M), space complexity - O(M*N*26)

struct TrieNode {
    map<char, TrieNode*> children;
    int val;
};

class MapSum {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* cur = root;
        for(char ch : key)
        {
            if (cur->children.count(ch) == 0)
                cur->children[ch] = new TrieNode();
            cur = cur->children[ch];
        }
        cur->val = val;
    }
    
    int recur(TrieNode* root)
    {
        int cursum = root->val;
        for(auto itr = root->children.begin() ; itr != root->children.end() ; itr++)
        {
            cursum += recur(itr->second);
        }
        return cursum;
    }
    
    int sum(string prefix) {
        TrieNode* cur = root;
        for(char ch : prefix)
        {
            if (cur->children.count(ch) == 0)
                return 0;
            cur = cur->children[ch];
        }
        return recur(cur);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */