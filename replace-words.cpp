// https://leetcode.com/explore/learn/card/trie/148/practical-application-i/1053/
// time complexity - O(N), space complexity - O(M*N)

struct TrieNode {
    map<char, TrieNode*> children;
    bool finished;
};

class Trie {
    public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode();
    }
    
    void insert(string word)
    {
        TrieNode* cur = root;
        for(char ch : word)
        {
            if (cur->children.count(ch) == 0)
                cur->children[ch] = new TrieNode();
            cur = cur->children[ch];
        }
        cur->finished = true;
    }
    
    string traverse(string prefix)
    {
        // traverse word in trie like a prefix
        // if not reached, return original word
        // if word finished - return word till now
        TrieNode* cur = root;
        string newWord = "";
        for(char ch : prefix)
        {
            if (cur->children.count(ch) == 0)
                return prefix;
            cur = cur->children[ch];
            newWord += ch;
            if (cur->finished)
                return newWord;
        }
        return prefix;
    }    
};

class Solution 
{
public:
    string replaceWords(vector<string>& dict, string sentence) 
    {
        // form trie from dict
        Trie trie = Trie();
        for(string word : dict)
            trie.insert(word);
        
        string finalstr = "";
        
        // for each word, call a function
        int idx = sentence.find(" ");
        while (idx != -1)
        {
            string curword = sentence.substr(0, idx);
            if (finalstr.length() > 0) // don't add space before first word
                finalstr += " "; 
            
            finalstr += trie.traverse(curword);
            
            sentence = sentence.substr(idx+1);
            idx = sentence.find(" ");
        }
        finalstr += " " + trie.traverse(sentence);
        
        return finalstr;
    }
};