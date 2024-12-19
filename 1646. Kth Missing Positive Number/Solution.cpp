class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        vector<int> B;
        for(int i=0;i<arr.size();i++){
            B.push_back(arr[i]-i-1);
            cout<<B[i]<<endl;
        }
        int low =0,high=arr.size();
        while(low<high){
            int mid = low + (high-low)/2;
            if(B[mid]>=k){
                high = mid;
            } else {
                low = mid+1;
            }
        }
        //cout<<low<<"-"<<high<<endl;
        return high+k;
    }
};