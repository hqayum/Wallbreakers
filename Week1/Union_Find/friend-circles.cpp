class Solution {
public:
    int find(vector<int>& parent, int i) {
        while(parent[i] != i) i = parent[i];
        return i;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        if(N <= 0) return N;
        
        vector<int> root(N);
        int connections = N;
        for(int i = 0; i < N; ++i) root[i] = i;
        for(int i = 0; i < N; ++i) {
            for(int j = i + 1; j < N; ++j) {
                if(M[i][j] == 1) {
                    int rootI = find(root, i);
                    int rootJ = find(root, j);
                    if(rootI != rootJ) {
                        root[rootI] = rootJ;
                        --connections;
                    }
                }
            }
        }
        if(connections <= 0) return 1;
        return connections;
    }
};