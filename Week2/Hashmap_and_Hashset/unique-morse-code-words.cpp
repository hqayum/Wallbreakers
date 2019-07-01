class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {

        // This code is more efficent. I realized I didn't
        // need a map since the morse string array was 
        // sorted in alphabetic order anyways.
        string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set <string> uSet;
        for(int i = 0; i < words.size(); ++i) {
            string tempStr = "";
            for(char a: words[i]) {
                tempStr += morse[a - 'a'];
            }
            uSet.insert(tempStr);
        }
        return uSet.size();
        
        
        /*
        // Code passed all the tests but was
        // slow so I am going to try to improve it.
        string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_map <char, string> uMap;
        char tempChar = 'a';
        for(int i = 0; i < (sizeof(morse)/sizeof(morse[0])); ++i) {
            uMap[tempChar++] = morse[i];
        }
        
        unordered_set <string> uSet;
        for(int i = 0; i < words.size(); ++i) {
            string tempStr = "";
            for(char a: words[i]) {
                tempStr += uMap.at(a);
            }
            uSet.insert(tempStr);
        }
        return uSet.size();
        */
        
        /*
        // I started with doing things manual at first,
        // but I knew there had to be a quicker way.
        uMap['a'] = ".-";
        uMap['b'] = "-...";
        uMap['c'] = "-.-.";
        uMap['d'] = ".-";
        uMap['e'] = ".-";
        uMap['f'] = ".-";
        uMap['g'] = ".-";
        uMap['h'] = ".-";
        uMap['i'] = ".-";
        uMap['j'] = ".-";
        uMap['k'] = ".-";
        uMap['l'] = ".-";
        uMap['m'] = ".-";
        uMap['n'] = ".-";
        uMap['o'] = ".-";
        uMap['p'] = ".-";
        uMap['q'] = ".-";
        uMap['r'] = ".-";
        uMap['s'] = ".-";
        uMap['t'] = ".-";
        uMap['u'] = ".-";
        uMap['v'] = ".-";
        uMap['w'] = ".-";
        uMap['x'] = ".-";
        uMap['y'] = ".-";
        uMap['z'] = ".-";
        */
    }
};
