class Solution {
public:

    vector<vector<int>> dp;

int sum (vector<int> & nums)
{
    int sumi =0 ; 
    for(int i=0 ;i<nums.size();i++)
    {
        sumi = sumi + nums[i];
    }

    return sumi;
}

bool solve ( int i , vector<int> & nums , int target )
{
    if(target==0)
    {
        return true;
    }

    if(i>=nums.size() || target <0)
    {
        return false;
    }

    if (dp[i][target] != -1) {
            return dp[i][target];
    }

    bool take= solve(i+1, nums, target- nums[i]);

    bool notTake= solve(i+1,nums,target);

        return dp[i][target] = take || notTake;
}



    bool canPartition(vector<int>& nums) {

        if(nums.size()==1)
        {
            return false;
        }

        int sumi = sum(nums);

        if(sumi%2!=0)
        {
            return false;
        }
        
        int required= sumi/2;

        dp = vector<vector<int>>(nums.size(), vector<int>(required + 1, -1));

        bool answer=  solve(0,nums,required);

        return answer;
    }
};