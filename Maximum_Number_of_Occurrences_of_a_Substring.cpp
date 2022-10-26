class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int>mp;
        for(int j = 0; j + minSize <= s.size(); j++) {
            string str = s.substr(j, minSize);
            unordered_map<char, int>uniqueChar;
            for(int k = 0; k < str.size(); k++) {
                uniqueChar[str[k]]++;
            }
            if(uniqueChar.size() <= maxLetters) {
                mp[str]++;
            }
        }
        int ans = 0;
        for(auto ele : mp) {
            ans = max(ans, ele.second);
        }
        return ans;
    }
};