class Solution {
public:

long long findCost(vector<int> & nums, vector<int> & cost, int target)
{
    long long result =0 ; 
    for(int i=0 ;i<nums.size();i++)
    {
        long long diff = abs(1LL * nums[i] - target);
    result = result + diff * cost[i];
    }
    return result;
}
    long long minCost(vector<int>& nums, vector<int>& cost) {
    long long answer = LLONG_MAX;
        int left= *min_element(nums.begin(),nums.end());
        int right = *max_element(nums.begin(),nums.end());
        while(left<=right)
        {
            long long mid = left+(right-left)/2;
            long long cost1= findCost(nums,cost,mid);
            long long cost2= findCost(nums,cost,mid+1);

            answer= min(cost1,cost2);

            if(cost2>cost1)
            {
                right=mid-1;
            } 

            if(cost1>=cost2)
            {
                left= mid+1;
            }
        }

        return answer==INT_MAX  ? 0:answer;
    }
};