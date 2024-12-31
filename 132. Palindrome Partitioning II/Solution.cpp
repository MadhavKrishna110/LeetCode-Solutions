class Solution {
public:
//     bool isPalin(string str){

//         int i=0,j=str.size()-1;
//         while(i<=j){
//             if(str[i]!=str[j]){
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }
//     int fun(int idx,string str,vector<int> &dp){
//         if(idx>=str.size() || isPalin(str.substr(idx))) return 0;
//         if(dp[idx]!=-1) return dp[idx];
//         string temp="";
//         int minCost = INT_MAX;
//         for(int j=idx;j<str.size();j++){
//             temp+=str[j];
//             if(isPalin(temp)){
//                 int cost = 1+fun(j+1,str,dp);
//                 minCost = min(minCost,cost);
//             }
//         }
//         return dp[idx]=minCost;
//     }
//     int minCut(string s) {
//         int n = s.size();
//         vector<int> dp(n,-1);
//         return fun(0,s,dp);
//     }
// };



    bool isPalindrome (string & s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    

    int solve (string & s, int i, int j, vector<int> & dp){    
        
        if(i>=j or isPalindrome(s, i, j)) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int ans = INT_MAX;
        
        for(int k=i; k<j; k++){
            
            /* 
                Instead of writing below standard line
                We will recurse for only right part
                Only when left part turns out to be palindrome
				
				Reason : If left substring becomes palindrome then there is no need to partition it further 
				(which in turn reduces the number of recursive calls)
                
                int temp =  solve (s, i, k, dp, palindrome) + solve (s, k+1, j, dp, palindrome) + 1;
                
            */
            
            if(isPalindrome(s, i, k)){                         
                int temp = solve (s, k+1, j, dp) + 1;
                ans = min (ans, temp);
            }
        }
        
        return dp[i] = ans;
    }
    
    int minCut(string s) {
        int n = s.length();
        
        /* I've used 1D DP here becoz only one parameter is changing i.e. `i` */
        
        vector<int> dp (n+1, -1);   
            
        return solve (s, 0, n-1, dp);
    }
};