class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n= nums2.size();
        vector<int> nextGreater(n,-1);
        unordered_map<int,int> mp;
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()<nums2[i]){
                    s.pop();
            }
            if(!s.empty()){
                nextGreater[i]=s.top();
                mp[nums2[i]] = s.top();
                cout<<nums2[i]<<"-"<<s.top()<<endl;
            }
            
                s.push(nums2[i]);
            

        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i])==mp.end()){
                ans.push_back(-1);
            } else {
                ans.push_back(mp[nums1[i]]);
            }
            
        }
        return ans;
    }
};