class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        unordered_map<int,int> visited;
        int maxStreak = 0;
        for(int i=0;i<nums.size();i++){
            if(!s.contains(nums[i]-1) && visited.find(nums[i])==visited.end()){
                int currentNum = nums[i];
                visited[currentNum]++;
                int currentStreak = 1;
                while(s.contains(currentNum+1)){
                    currentNum+=1;
                    visited[currentNum]++;
                    currentStreak+=1;
                }
                maxStreak = max(maxStreak,currentStreak);
            }
        }
        return maxStreak;
    }
};