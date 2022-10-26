class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {

            int remain = target - nums[i];
            if (m.find(remain) != m.end() and m[remain] != i) {
                return {i, m[remain]};
            }

        }

        return {};
    }
};