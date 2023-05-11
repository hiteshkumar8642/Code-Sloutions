class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0],currsum=0;
        for(int i=0;i<nums.size();i++)
        {
            currsum=max(currsum,0);
            currsum+=nums[i];
            maxsum=max(maxsum,currsum);
        }
        return maxsum;
        
        
    }
};