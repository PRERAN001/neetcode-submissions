class Solution {
public:
    int maxArea(vector<int>& nums) {
        int area=0;
        int l=0;
        int r=nums.size()-1;
        int res=0;
        while(l<r){
            res=(r-l)*min(nums[l],nums[r]);
            area=max(area,res);
            if(nums[l]>nums[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return area;
    }
};
