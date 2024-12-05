class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      sort(g.begin(),g.end());
      sort(s.begin(),s.end());
      int m=g.size();
      int n= s.size();
      int i=m-1,j=n-1;
      int cnt=0;
      while(i>=0 && j>=0){
        if(s[j]>=g[i]){
            cnt++;
            j--;
            
        }
        i--;
      }
      return cnt;  
    }
};