class Solution {
public:
    vector<int> partitionLabels(string S) {
        if(S[0] == S[S.length() - 1]) return {S.length()};
        int arr[26] = {0};
        for(int i = 0; i < S.length(); ++i) {
            arr[S[i] - 'a'] = i;
        }
        //char temp = 'a';
        //for(int a: arr) cout << temp++ << " " << a << endl;
        vector<int> partition;
        int start = 0, end = 0;
        for(int i = 0; i < S.length(); ++i) {
            start = max(start, arr[S[i] - 'a']);
            //cout << i << ' ' << S[i] << " " << start << endl;
            if(i == start) {
                partition.push_back(i - end + 1);
                end = i + 1;
            }
        }
        return partition;        
    }
};
