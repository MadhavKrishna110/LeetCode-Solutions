class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mp;
        mp[')']='(';
        mp[']'] ='[';
        mp['}']='{';
        stack<char> ch;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                ch.push(s[i]);
            } else {
                if(!ch.empty()&& ch.top()==mp[s[i]]){
                    ch.pop();
                }else {
                    return false;
                }
            }
            cout<<s[i]<<endl;

        }
        return ch.empty()?true:false;
    }
};