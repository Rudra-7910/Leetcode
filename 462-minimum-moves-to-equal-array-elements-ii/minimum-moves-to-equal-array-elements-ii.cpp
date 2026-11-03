class Solution {
public:


int findCost(vector<int> nums,int target)
{
    long long result=0;
    for(int i=0 ;i<nums.size();i++)
    {
        long long diff= abs(nums[i]-target);
        result +=diff;
    }
    return result;
}
    int minMoves2(vector<int>& nums) {
        int left= *min_element(nums.begin(),nums.end());
        int right= *max_element(nums.begin(),nums.end());

        int result= INT_MAX;
        while(right>=left)
        {
            int mid= (left+right)/2;
            int cost1= findCost(nums,mid);
            int cost2= findCost(nums,mid+1);
            result= min(cost1,cost2);

            if(cost2>cost1)
            {
                right= mid-1;
            }
            else
            {
                left= mid+1;
            }
        }
        return result==INT_MAX ?0:result;
    }
};