class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> prevSmaller(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            if(!s.empty() && heights[i]<=heights[s.top()]){
                while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();    
            } 
            prevSmaller[i]=s.empty()?0:s.top()+1;
            s.push(i);
        }

        vector<int> nextSmaller(n);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            if(!st.empty() && heights[i]<=heights[st.top()] ){
                while(!st.empty() && heights[st.top()]>=heights[i]) st.pop(); 
            }
            nextSmaller[i] = st.empty()?n-1:st.top()-1;
            st.push(i);
        }
        int maxArea = 0;
        for(int i=0;i<n;i++){
            maxArea = max(maxArea,heights[i]*(nextSmaller[i]-prevSmaller[i]+1));
        }
        return maxArea;
    }
};