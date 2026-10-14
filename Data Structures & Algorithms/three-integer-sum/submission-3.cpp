class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ares;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int k=i+1;
            int r=nums.size()-1;
            while(k<r){
                int ans=nums[i]+nums[k]+nums[r];
                if(ans==0){
                    res.push_back(nums[i]);
                    res.push_back(nums[k]);
                    res.push_back(nums[r]);
                    ares.push_back(res);
                    res.clear();
                    k++;
                    r--;
                }
                else if(ans<0){
                    k++;
                }else{
                    r--;
                }
            }
        }
        sort(ares.begin(), ares.end());
        auto it=unique(ares.begin(),ares.end());
        ares.erase(it,ares.end());
        return ares;
    }
};
