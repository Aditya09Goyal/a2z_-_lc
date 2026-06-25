class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0]) return a[1]>b[1]; 
        return a[0]<b[0] ; 
    }

    int maxEnvelopes(vector<vector<int>>& env) {
        // step 1 : sort env to make it increasing wrt w and decreasing wrt h  
        sort(env.begin(),env.end(),cmp); 
        // step 2 : perfrom  LIS using Binary search 
        vector<int>lis ;  
        for(auto &e : env) { 
            int h = e[1] ; 
            if(lis.empty() or h>lis.back())
            {
                lis.push_back(h);
            }
            else 
            {
                int idx= lower_bound(lis.begin(),lis.end(),h) - lis.begin();
                lis[idx] = h ; 
            }
        }
        return lis.size();
    }
};