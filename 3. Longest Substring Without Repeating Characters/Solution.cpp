class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        set<char> st;
        int maxLength = 0;
        int i=0,j=0;
        while(j<s.size()){
            if(st.find(s[j])==st.end()){
                st.insert(s[j]);
                if(j-i+1>maxLength){
                    maxLength = j-i+1;
                }
            } else {
                while(s[i]!=s[j]){
                    st.erase(s[i]);
                    i++;
                }
                i++;
            }
            j++;
        }
        return maxLength;
    }
};