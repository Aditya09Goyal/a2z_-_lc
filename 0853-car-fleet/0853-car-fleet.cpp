class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& sp) {
        // step : 1
        int n = pos.size(); 
        vector<pair<int,int>>v; 
        for(int i=0;i<n;i++) {
            v.push_back({pos[i],sp[i]}) ; 
        }
        sort(v.begin(),v.end()) ; 
        // step : 2 
        int fleets=0 ; 
        float fleet_time = 0 ; 
        for(int i=n-1;i>=0;i--)
        {
            float curr_time = (float)(target-v[i].first)/v[i].second ; 
            if(curr_time > fleet_time) {
                fleets++ ;
                fleet_time = curr_time ;
            }
        }
        return fleets;
    }
};