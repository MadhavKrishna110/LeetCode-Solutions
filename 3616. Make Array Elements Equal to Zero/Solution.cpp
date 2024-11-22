class Solution {
public:
    // select a starting position
    // choose a direction be default
    // if nums[curr]>0 , nums[curr]-- , change direction
    bool isValid(int ind,int direcn,vector<int> nums){
        int j=ind;
            while(j>=0 && j<nums.size()){
                if(nums[j]>0){
                    nums[j]--;
                    direcn = !direcn;
                }
                if(direcn==1) j++;
                else j--;
            }

            bool check=  true;
            for(int j=0;j<nums.size();j++){
                if(nums[j]!=0){
                    check = false;
                }
            }
            if(check) return true;
            return false;
    }
    int countValidSelections(vector<int>& nums) {
        
        vector<int> zeroes;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeroes.push_back(i);
            }
        }
        int numSelections=0;

        for(int i=0;i<zeroes.size();i++){
            int direcn=1; // 1 for right and 0 for left
            if(isValid(zeroes[i],1,nums)) numSelections++; 
            if(isValid(zeroes[i],0,nums)) numSelections++; 
        }
        return numSelections;
    }
};