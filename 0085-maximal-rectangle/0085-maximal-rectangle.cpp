class Solution {
public:
    vector<int> find_nse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] <= arr[st.top()])
                st.pop();
            if (st.empty()) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> find_pse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()])
                st.pop();

            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& arr) {
        vector<int> nse = find_nse(arr);
        vector<int> pse = find_pse(arr);
        int area = 0;
        for (int i = 0; i < arr.size(); i++) {
            area = max(area, arr[i] * (nse[i] - pse[i] - 1));
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> height(n, 0);
        int maxArea = 0  ; 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            int area = largestRectangleArea(height) ; 
            maxArea = max(area,maxArea) ; 
        }
        return maxArea ; 
    }
};