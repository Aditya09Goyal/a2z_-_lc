class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
        vector<vector<string>>ans; 
        
        map<vector<int>,vector<string>>mp ; 
        
        for(int i=0;i<v.size();i++) {
            vector<int>f(26,0) ;
            for(char c: v[i]) f[c-'a']++;            
            mp[f].push_back(v[i]) ;
        }

        for(auto it : mp) ans.push_back(it.second);

        return ans ;
    }
};
// another method is use unordered_map and store string as key , freq vector as value 
// string as key is encrypted using # 