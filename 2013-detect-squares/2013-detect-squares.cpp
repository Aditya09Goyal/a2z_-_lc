class DetectSquares {
public:
    map<pair<int,int>,int>mp ; 
    DetectSquares(){}
    
    void add(vector<int> point) {
        mp[{point[0],point[1]}]++ ; 
    }
    
    int count(vector<int> point) {
        int cnt = 0 ; 
        int x = point[0];
        int y = point[1];
        for(auto t : mp)
        {
            auto it =t.first ; 
            int xc = it.first ;
            int yc = it.second ; 
            if(xc!=x and yc!=y and abs(xc-x)==abs(yc-y))
             {
                cnt += mp[{xc,yc}]*mp[{xc,y}]*mp[{x,yc}];
             }
        }
        return cnt ;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */