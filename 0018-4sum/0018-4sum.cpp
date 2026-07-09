class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(begin(nums), end(nums));
        int n = nums.size();
        for (int st = 0; st < n; st++) {
            if(st>0 && nums[st]==nums[st-1]) continue; 
            for (int i = st+1; i < n; i++) {
                if (i > st+1 && nums[i] == nums[i - 1])
                    continue;
                int j = i + 1, k = n - 1;
                while (j < k) {
                    long long sum =(long long)nums[st] +  nums[i] + nums[j] + nums[k];
                    if (sum <target) {
                        j++;
                    } else if (sum >target) {
                        k--;
                    } else {
                        vector<int> temp = {nums[st], nums[i], nums[j],
                                            nums[k]};
                        ans.push_back(temp);
                        j++;
                        k--;
                        while (j < k && nums[j] == nums[j-1])
                            j++;
                        while (j < k && nums[k] == nums[k+1])
                            k--;
                    }
                }
            }
        }
        return ans;
    }
};