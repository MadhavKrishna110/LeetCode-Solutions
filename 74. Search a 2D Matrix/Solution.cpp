class Solution {
public:
    bool binarySearch(vector<int> v,int target){
        int i=0,j=v.size()-1;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(v[mid]==target){
                return true;
            } else if(target<v[mid]){
                j=mid-1;
            } else {
                i = mid+1;
            }

        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size();
        int n = matrix[0].size();
        int i=0;
        bool ans = false;
        while(i<m ){
            if(target<=matrix[i][n-1]){
                ans = ans | binarySearch(matrix[i],target);
                if(ans) return true;
            } 
            i++;
        }
        return ans;
    }
};