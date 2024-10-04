class Solution {
public:
    bool binarySearch(vector<int> arr,int target){

        int n = arr.size();
        int i=0,j=n-1;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(arr[mid] == target){
                return true;
            } else if(arr[mid]>target){
                j=mid-1;
            } else {
                i=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        for(int i=0;i<matrix.size();i++){
            if(target<=matrix[i][n-1]){
                return binarySearch(matrix[i],target);
            }
        }
        return false;
    }
};