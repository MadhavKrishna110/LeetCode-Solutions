class Solution {
public:
    bool isPalin(string str){
        int i=0,j=str.size()-1;
        while(i<=j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void fun(string str,vector<string> &res,vector<vector<string>> &ans){
        if(str.size()==0){
            ans.push_back(res);
            return;
        }

        for(int i=1;i<=str.size();i++){
            string s1 = str.substr(0,i);
            string s2= str.substr(i);
            
            if(isPalin(s1)){
                cout<<s1<<" "<<s2<<endl;
                res.push_back(s1);
                fun(s2,res,ans);
                res.pop_back();
            }   
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;
        fun(s,res,ans);
        return ans;
    }
};