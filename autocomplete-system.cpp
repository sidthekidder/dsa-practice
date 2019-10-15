// https://leetcode.com/problems/design-search-autocomplete-system

struct TrieNode {
    map<char, TrieNode*> children;
    int hotness;
    bool word;
};

class Trie {
    public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode();
        root->word = false;
    }
    
    void insert(string str, int val)
    {
        TrieNode* cur = root;
        for(char ch : str)
        {
            if (cur->children.count(ch) == 0)
                cur->children[ch] = new TrieNode();
            cur = cur->children[ch];
        }
        cur->word = true;
        cur->hotness += val;
    }
    
    void recur(TrieNode* cur, vector<pair<int, string>>& descendants, string curstr)
    {
        if (cur->word)
        {
            descendants.push_back({cur->hotness, curstr});
        }
        for(auto itr = cur->children.begin() ; itr != cur->children.end() ; itr++)
        {
            recur(itr->second, descendants, curstr + itr->first);
        }
    }
    
    vector<string> find_hot(string prefix)
    {
        // traverse till prefix in root
        TrieNode* cur = root;
        for(char ch : prefix)
        {
            if (cur->children.count(ch) == 0)
                return vector<string>();
            cur = cur->children[ch];
        }
        // now collect all descendants from cur pointer along with their hotness
        vector<pair<int, string>> descendants;
        recur(cur, descendants, prefix);
        
        // sort according to hotness
        auto customCmp = [](pair<int, string> p1, pair<int, string> p2)
        {
            if (p1.first == p2.first)
            {
                // cout<<"Compairng "<<p1.second << " with "<<p2.second<<endl;
                // cout<<"Anser is "<< p1.second < p2.second
                return strcmp(p1.second.c_str(), p2.second.c_str()) < 0;
            }
            return p1.first > p2.first;
        };
        sort(descendants.begin(), descendants.end(), customCmp);
        
        // only keep top 3 and return
        if (descendants.size() > 3)
            descendants.resize(3);
        
        vector<string> ans;
        for(auto ele : descendants)
            ans.push_back(ele.second);

        return ans;
    }
};

class AutocompleteSystem 
{
public:
    Trie trie;
    string cur_sentence;
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) 
    {
        trie = Trie();
        for(int i = 0 ; i < sentences.size() ; i++)
            trie.insert(sentences[i], times[i]);
        
        cur_sentence = "";
    }
    
    vector<string> input(char c) 
    {
        vector<string> ans;
        if (c == '#')
        {
            trie.insert(cur_sentence, 1);
            cur_sentence = "";
            return ans;
        }
        cur_sentence += c;
        
        return trie.find_hot(cur_sentence);
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */