class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int ,int>> arr;
        int size=nums.size();
        for(int i=0;i<size;i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        int l=0;
        vector<int> res;
        int r=size-1;
        while(l<r){
            if(arr[l].first+arr[r].first==target){
                res.push_back(arr[l].second);
                res.push_back(arr[r].second);
                break;
            }
            else if(arr[l].first+arr[r].first<target){
                l++;
            }
            else{
                r--;
            }
        }
        sort(res.begin(),res.end());
        return res;
        
    }
};