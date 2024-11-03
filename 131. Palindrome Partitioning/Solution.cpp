class Solution {
public:
    bool isPalindrome(string str,int i,int j){
        while(i<=j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void fun(int ind,string s,vector<string> &v,vector<vector<string>> &ans){
        if(ind==s.size()){
            ans.push_back(v);
            return;
        }
        for(int i=ind;i<s.size();i++){
           if(isPalindrome(s,ind,i)){
                v.push_back(s.substr(ind,i-ind+1));
                fun(i+1,s,v,ans);
                v.pop_back();
           }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        fun(0,s,v,ans);
        return ans;
    }
};