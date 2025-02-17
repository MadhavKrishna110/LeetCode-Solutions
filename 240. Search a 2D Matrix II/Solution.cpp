class Solution {
public:
    bool binarySearch(vector<int> v,int target){
        int i=0,j=v.size()-1;

        while(i<=j){
            int mid = i+(j-i)/2;
            if(v[mid]==target){
                return true;
            } else if(v[mid]>target){
                j=mid-1;
            } else {
                i=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size();
        int n = matrix[0].size();

        int i=0,j=n-1;
        while(i<m && j>=0){
            if(target>matrix[i][j]){
                i++;
            } else if(target<matrix[i][j]) {
                j--;
            } else {
                return true;
            }
        }
        return false;
    }
};