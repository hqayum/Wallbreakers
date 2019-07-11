// Both solutions are too slow and fail on 1 test, but pass all the rest.
// My unordered_map solution works and passes all the tests.

// My first solution.
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};
        if(p.size() == s.size()) {
            if(p.compare(s) == 0) return {0};
            return {};
        }
        
        sort(p.begin(), p.end());
        vector<int> vec;
        for(int i = 0; i < s.size() - p.size() + 1; ++i) {
            string temp = s.substr(i, p.size());
            sort(temp.begin(), temp.end());
            if(temp.compare(p) == 0) vec.push_back(i);
        }
        return vec;
    }
};


// Second solution. Modified to look like sliding window.
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};
        if(p.size() == s.size()) {
            if(p.compare(s) == 0) return {0};
            return {};
        }
        
        sort(p.begin(), p.end());
        vector<int> vec;
        string temp;
        for(int i = 0; i < p.size(); ++i) temp += s[i];
        string check = temp;
        sort(check.begin(), check.end());
        if(check.compare(p) == 0) vec.push_back(0);
        
        for(int i = p.size(); i < s.size(); ++i) {
            temp.erase(temp.begin());
            temp += s[i];
            check = temp;
            sort(check.begin(), check.end());
            if(check.compare(p) == 0) vec.push_back(i - p.size() + 1);
        }
        return vec;
    }
};
