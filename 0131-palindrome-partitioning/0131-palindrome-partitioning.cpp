class Solution {
public:
    bool checkPal(string &str) {
        string r = str; 
        reverse(r.begin(),r.end()) ; 
        return str==r; 
    }

    void solve(int idx , string &s ,vector<string>&temp , vector<vector<string>>&ans) {
        if(idx==s.length()) {
            ans.push_back(temp) ;
            return  ; 
        }

        for(int i=idx;i<s.length();i++) {
            string sub = s.substr(idx,i-idx+1) ; 
            if(checkPal(sub)) {
                temp.push_back(sub) ;
                solve(i+1,s,temp,ans) ; 
                temp.pop_back() ; 
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans; 
        vector<string>temp ; 
        solve(0,s,temp,ans) ; 
        return ans ;
    }
};