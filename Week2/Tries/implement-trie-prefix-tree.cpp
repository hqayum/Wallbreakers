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
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        int i, index;
        for(i = 0; i < word.size(); ++i) {
            index = word[i] - 'a';
            if(node->alpha[index] == NULL) {
                node->alpha[index] = new TrieNode;
            }
            node = node->alpha[index];
        }
        node->wordEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = root;
        int i, index;
        for(i = 0; i < word.size(); ++i) {
            index = word[i] - 'a';
            if(node->alpha[index] == NULL) {
                return false;
            }
            node = node->alpha[index];
        }
        return node->wordEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = root;
        int i, index;
        for(i = 0; i < prefix.size(); ++i) {
            index = prefix[i] - 'a';
            if(node->alpha[index] == NULL) {
                return false;
            }
            node = node->alpha[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */