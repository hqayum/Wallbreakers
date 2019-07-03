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
};

class Solution {
public:
    void dfs(TrieNode *node, vector<vector<char>>& board, int row, int col, string str, vector<string>& reVec) {
        if(row < 0 || row >= board.size()) return;
        if(col < 0 || col >= board[0].size()) return;
        if(board[row][col] == '0') return;
        
        char currChar = board[row][col];
        int index = currChar - 'a';
        str += currChar;
        if(node == NULL) return;
        node = node->alpha[index];
        if(node != NULL && node->wordEnd == true) {
            reVec.push_back(str);
            node->wordEnd = false;
        }
        
        board[row][col] = '0';
        dfs(node, board, row + 1, col, str, reVec);
        dfs(node, board, row - 1, col, str, reVec);
        dfs(node, board, row, col + 1, str, reVec);
        dfs(node, board, row, col - 1, str, reVec);
        board[row][col] = currChar;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.size() <= 0 || board[0].size() <= 0) return {};
        
        Trie *myTrie = new Trie();
        for(string a: words) myTrie->insert(a);
        
        TrieNode *root = myTrie->root;
        
        vector <string> reVec;
        string str = "";
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                dfs(root, board, i, j, str, reVec);
            }
        }
        return reVec;
    }
};
