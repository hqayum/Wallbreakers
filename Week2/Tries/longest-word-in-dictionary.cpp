#define LETTERS 26

class TrieNode {
public:
    TrieNode *alpha[LETTERS];
    bool wordEnd;
    
    TrieNode() {
        wordEnd = false;
        for(int i = 0; i < LETTERS; ++i) alpha[i] = NULL;
    }
};

class Trie {
public:
    TrieNode *root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string str) {
        TrieNode *cur = root;
        int i, index;
        for(i = 0; i < str.size(); ++i) {
            index = str[i] - 'a';
            if(cur->alpha[index] == NULL) {
                cur->alpha[index] = new TrieNode();
            }
            cur = cur->alpha[index];
        }
        cur->wordEnd = true;
    }
    
    string findLongestString(vector<string>& words) {
        TrieNode *cur = root;
        string maxStr;
        int index;
        bool check = false;
        for(int i = 0; i < words.size(); ++i) {
            for(int j = 0; j < words[i].size(); ++j) {
                index = words[i][j] - 'a';
                //cout << words[i][j];
                if(cur->alpha[index] == NULL || cur->alpha[index]->wordEnd == false) {
                    check = false;
                    break;
                }
                cur = cur->alpha[index];
                check = true;
            }
            cur = root;
            if(check == true) {
                if(maxStr.size() < words[i].size()) {
                    maxStr = words[i];
                } else if(maxStr.size() == words[i].size() && maxStr.compare(words[i]) >= 0)
                maxStr = words[i];
            }
            //cout << endl;
        }
        //cout << maxStr;
        return maxStr;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie *myTrie = new Trie();
        for(int i = 0; i < words.size(); ++i) {
            myTrie->insert(words[i]);
        }
        return myTrie->findLongestString(words);
    }
};
