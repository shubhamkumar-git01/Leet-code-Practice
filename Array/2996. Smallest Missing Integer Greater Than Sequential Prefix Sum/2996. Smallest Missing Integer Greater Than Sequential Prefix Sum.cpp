// Problem: 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum
// Runtime: 0 ms (Beats 100.00%)
// Memory: 22.5 MB (Beats 90.34%)

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }

        while (find(nums.begin(), nums.end(), sum) != nums.end())
            sum++;

        return sum;
    }
};