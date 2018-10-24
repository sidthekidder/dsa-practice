/*
 * Complete the 'textQueries' function below.
 *
 * The function accepts following parameters:
 *  1. STRING_ARRAY sentences
 *  2. STRING_ARRAY queries
 */

vector<string> getWords(string s)
{
    vector<string> result;
    // split string on spaces
    int space_idx = s.find(" ");
    while (space_idx != -1)
    {
        string temp = s.substr(0, space_idx);
        result.push_back(temp);
        s = s.substr(space_idx + 1);
        space_idx = s.find(" ");
    }
    result.push_back(s);
    return result;
}

void textQueries(vector<string> sentences, vector<string> queries) 
{
    // first create a mapping from string->vector<sentence_index, freq> for all words of all sentences
    // then for each query
    // check all the words against the mapping - if all are present, 
    // eg for sentences ["a b c a b c a", "b c a", "a c b"] and queries ["a", "a b"]
    // the mapping will be a-> [(0,3), (1,1), (2,1)], b -> [(0,2), (1,1), (2,1)] etc
    // when we search for ["a","b"], iterate through each word of the query and search in the mapping and store min freq
    // a = [(0,3), (1,1), (2,1)], so store [0,1,2] as possible sentence indexes and possible freq indexes as [3,1,1] in a map
    // like tempMap1 = 0->3, 1->1, 2->1
    // b = [(0,2), (1,1), (2,1)] so store [0,1,2] as possible sentence indexes and possible freq indexes as [2,1,1]
    // tempMap2 = 0->2, 1->1, 2->1
    // now for iterate through the first tempMap and check for each key, whether the key exists in all other tempMaps
    // then take the min freq i.e. 0 exists as key in both tempMap1 and tempMap2, minfreq is 2
    // so push 0, 0 to result array (push key minfreq times)
    // then 1 exists in both tempMaps, minfreq is 1
    // push 1, 1 etc
    
    unordered_map<string, vector<pair<int, int>>> mapping;
    for(int i = 0 ; i < sentences.size() ; i++)
    {
        vector<string> words = getWords(sentences[i]);
        
        // create mapping
        for(string word : words)
        {
            if (mapping.find(word) == mapping.end())
            {
                vector<pair<int, int>> v;
                v.push_back(pair<int, int>(i, 1));
                mapping[word] = v;
            }
            else
            {
                // search in the vector for current sentence_idx
                bool found = false;
                for(int j = 0 ; j < mapping[word].size() ; j++)
                {
                    if (mapping[word][j].first == i)
                    {
                        mapping[word][j].second++;
                        found = true; // mark that we found the initial pair
                    }
                }
                if (!found) // this is the first word for sentence i
                {
                    mapping[word].push_back(pair<int, int>(i, 1));
                }
            }
        }
    }

    // now iterate through queries for query logic
    for(int q = 0 ; q < queries.size() ; q++)
    {
        vector<string> words = getWords(queries[q]);
        bool skipQuery = false;
        
        vector<unordered_map<int, int>> tempMaps(words.size());
        for(int i = 0 ; i < words.size() ; i++)
        {
            // cout << "Now searching for "<<words[i]<< " as part of query " << q << endl;
            if (mapping.find(words[i]) != mapping.end())
            {
                for(pair<int, int> ele : mapping[words[i]])
                {
                    tempMaps[i][ele.first] = ele.second;
                }
            }
            else    // if even 1 word of the query is not in the mapping, we can skip that query entirely
            {
                skipQuery = true;
                cout << "-1\n";
                break;
            }
        }
        if (skipQuery) continue;
        
        // now iterate through the first tempMap and check for each key, whether the key exists in all other tempMaps
        if (tempMaps.size() == 0) continue;
        vector<int> temp_result;
        bool atleastOneKey = false;
        for(auto itr = tempMaps[0].begin() ; itr != tempMaps[0].end() ; itr++)
        {
            int key = itr->first;
            int minFreq = itr->second;
            bool exists = true;
            for(int i = 1 ; i < tempMaps.size() ; i++)
            {
                if (tempMaps[i].find(key) != tempMaps[i].end())
                {
                    // then take the min freq i.e. 0 exists as key in both tempMap1 and tempMap2, minfreq is 2
                    minFreq = min(minFreq, tempMaps[i][key]);
                }
                else
                {
                    exists = false;
                    break;
                }
            }
            if (!exists) 
            {
                continue;
            }
            // print key minfreq times
            // (temporarily store in a vector for sorting later)
            for(int fi = 1 ; fi <= minFreq ; fi++)
                temp_result.push_back(key);
        }
        if (temp_result.size() == 0)
            cout << "-1\n";
        else
        {
            sort(temp_result.begin(), temp_result.end());
            for(int x : temp_result)
                cout << x << " ";
            cout << endl;
        }
    }
}

