class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = nums[n / 2];
        int answer = 0;
        for (int i = 0; i < n; i++) {
            answer += abs(nums[i] - median);
        }

        return answer;
    }
};