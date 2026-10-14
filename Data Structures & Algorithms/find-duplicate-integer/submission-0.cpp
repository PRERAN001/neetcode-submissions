class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(int x:nums){
            mp[x]++;
            if(mp[x]>1){
                return x;
            }
        }
        
    }
};
