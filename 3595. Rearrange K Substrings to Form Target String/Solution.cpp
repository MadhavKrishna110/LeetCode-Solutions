class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int m=s.size();
        int n=t.size();

        if(m%k!=0 || n%k!=0){
            return false;
        }
        int len = m/k;
        unordered_map<string,int> mp1;
        unordered_map<string,int> mp2;
        for(int i=0;i<m;i+=len){
            string str = s.substr(i,len);
                mp1[str]++;
            
        }
        for(int j=0;j<n;j+=len){
            string str= t.substr(j,len);
            mp2[str]++;
        }

        for(auto itr:mp1){
            cout<<itr.first<<"-"<<itr.second<<"-"<<mp2[itr.first]<<endl;
            if(mp2[itr.first]!=itr.second){
                return false;
            }
        }
        return true;
    }
};