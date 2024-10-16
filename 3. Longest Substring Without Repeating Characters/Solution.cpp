class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i=0,j=0,maxLength=0;
        set<char> st;

        while(j<n){
            if(!st.contains(s[j])){
                st.insert(s[j]);
            } else {
                while(i<j &&s[i]!=s[j]){
                    st.erase(s[i]);
                    i++;
                }
                i++;
            }
            maxLength = max(maxLength,j-i+1);
            j++;

        }
        return maxLength;
    }
};