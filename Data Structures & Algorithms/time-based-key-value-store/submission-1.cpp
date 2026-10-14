class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()){
            return "";
        }
        vector<pair<int,string>>& a=mp[key];
        string ans="";
        int i=0;
        int j=a.size()-1;
        int mid=0;
        while(i<=j){
            mid=i+(j-i)/2;
            if(a[mid].first==timestamp){
                return a[mid].second;
            }
            else if(a[mid].first<timestamp){
                ans=a[mid].second;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};
