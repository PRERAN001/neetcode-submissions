class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        int i=0;
        int j=n.size()-1;
        vector<int> ans;
        while(i<j){
            int a=n[i]+n[j];
            if(a==target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else{
                if(a>target){
                    j--;
                }else{
                    i++;
                }
            }           
        } 
        return ans;
    }
};
