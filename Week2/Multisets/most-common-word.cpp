class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // Quick unordered map solution
        for(int i = 0; i < paragraph.size(); ++i) {
            if(isalpha(paragraph[i]) != 0) {
                paragraph[i] = tolower(paragraph[i]);
            } else {
                paragraph[i] = ' ';
            }
        }
        stringstream strStream(paragraph);
        string word;
        unordered_map<string, int> uMap;
        while(strStream >> word) {
            if(uMap.find(word) == uMap.end()) {
                uMap[word] = 1;
            } else {
                uMap[word]++;
            }
        }
        for(string a: banned) {
            if(uMap.find(a) != uMap.end()) {
                uMap.erase(a);
            }
        }
        int count = 0;
        for(auto it: uMap) {
            if(count < it.second) {
                count = it.second;
                word = it.first;
            }
        }
        return word;
        
        /*
        // Slow multiset solution
        string str;
        for(int i = 0; i < paragraph.size(); ++i) {
            if(isalpha(paragraph[i]) != 0) {
                str += tolower(paragraph[i]);
            } else {
                str += ' ';
            }
        }
        
        stringstream strStream(str);
        string word;
        multiset<string> mSet;
        while(strStream >> word) {
            mSet.insert(word);
        }
        //for(auto it: mSet) cout << it << endl;
        unordered_set<string> uSet;
        for(string a: banned) uSet.insert(a);
        
        string reStr;
        int max = 0;
        for(auto it: mSet) {
            if(uSet.find(it) != uSet.end()) continue;
            if(mSet.count(it) > max) {
                max = mSet.count(it);
                reStr = it;
            }
        }
        return reStr;
        */
    }
};