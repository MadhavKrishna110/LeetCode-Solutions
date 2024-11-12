class Solution {
public:
    string reverseWords(string s) {

        stack<string> st;
        string str="";

        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                str+=s[i];
            } else {
                if(str.size()>0){
                    st.push(str);
                    str="";
                }
            }
        }
        if(str.size()>0){
            st.push(str);
        }

        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty()){
                ans+=' ';
            }
        }
        return ans;
    }
};