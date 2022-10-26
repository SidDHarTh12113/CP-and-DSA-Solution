class Solution {
public:
    int maxVowels(string s, int k) {
        set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        int p1 = 0, p2 = 0, curr = 0, ans = INT_MIN;
        while(p2 < s.size() and p2 < k) {
            if(st.find(s[p2]) != st.end()) {
                curr++;
            }
            p2++;
        }
        p2--;
        ans = max(ans, curr);
        while(p2 < s.size()) {
            if(st.find(s[p1]) != st.end()) {
                curr--;
            }
            p1++;
            p2++;
            if(p2 < s.size() and st.find(s[p2]) != st.end()) {
                curr++;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};