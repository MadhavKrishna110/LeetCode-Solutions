class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int output=0;
        int i=1,j=n-2;
        int leftMax=height[0],rightMax=height[n-1];
        while(i<=j){
            
            if(leftMax<=rightMax){
                output += max(0,min(leftMax,rightMax) - height[i]);
                leftMax = max(leftMax,height[i]);
                i++;
            } else {
                output += max(0,min(leftMax,rightMax) - height[j]);
                rightMax = max(rightMax,height[j]);
                j--;
            }
        }
        return output;

    }
};