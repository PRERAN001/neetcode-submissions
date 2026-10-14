class KthLargest {
public:
    priority_queue<int> pq;
    int lala=0;
    KthLargest(int k, vector<int>& nums) {
        lala=k;
        for(int x:nums){
            pq.push(x);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(lala==1){
            return pq.top();
        }
        vector<int> temp;
        int o=lala;
        while(o!=1){
            temp.push_back(pq.top());
            pq.pop();
            o--;
        }
        int ans=pq.top();
        for(int x:temp){
            pq.push(x);
        }
        return ans;
    }
};
