class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1)
            return 0;
        // step 1
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
        // step2
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(0);
        vis[0] = true;
        int jmps = 0;
        // step 3 : Bfs
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int idx = q.front();
                q.pop();
                if (idx == n - 1)
                    return jmps;
                if (idx + 1 < n and !vis[idx + 1]) {
                    vis[idx + 1] = true;
                    q.push(idx + 1);
                }
                if (idx - 1 >= 0 and !vis[idx - 1]) {
                    vis[idx - 1] = true;
                    q.push(idx - 1);
                }
                for (auto it : mp[arr[idx]]) {
                    if (!vis[it]) {
                        vis[it] = true;
                        q.push(it);
                    }
                }
                mp[arr[idx]].clear();
            }
            jmps++;
        }
        cout<<"size of array:"<<n<<endl;
        return jmps ;
    }
};