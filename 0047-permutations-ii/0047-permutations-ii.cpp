class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& temp, unordered_map<int, int>& mp, int n) {
        // base case 
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }
        // code for bactracking 
        for (auto& [num, count] : mp) {
            if (count == 0)
                continue;
            temp.push_back(num);    
            mp[num]--;
            solve(temp, mp, n);
            temp.pop_back();
            mp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }

        solve(temp, mp, n);
        return ans;
    }
};