class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {

        unordered_map <string, int> uMap;
        vector <string> reVec;
        
        char *tempA = (char *) A.c_str();
        char *tempB = (char *) B.c_str();
        char *tok;
        
        for(tok = strtok(tempA, " "); tok != NULL; tok = strtok(NULL, " ")) {
            if(uMap.find(tok) == uMap.end()) {
                uMap[tok] = 1;
            } else {
                uMap[tok] = uMap.at(tok) + 1;
            }
        }
        for(tok = strtok(tempB, " "); tok != NULL; tok = strtok(NULL, " ")) {
            if(uMap.find(tok) == uMap.end()) {
                uMap[tok] = 1;
            } else {
                uMap[tok] = uMap.at(tok) + 1;
            }
        }
        
        for(auto itor = uMap.begin(); itor != uMap.end(); ++itor) {
            if(itor->second == 1) reVec.push_back(itor->first);
        }
        
        return reVec;
    }
};
