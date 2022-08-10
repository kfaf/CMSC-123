class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        // vector ind is for keeping track of indices in each array
        vector<int> ind(K,1);
        auto cmp = [](pair<int,int> a,pair<int,int> b){return a.first>b.first;};
        
        // i used priority_queue in c++ stl because it is almost similar to a heap,
        // (constant time for retrieving top element at a cost of logarithmic insertion)
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> q(cmp);
        
        // first is insert the first element of each array in the "heap"
        for(int i=0;i<K;i++)q.push({arr[i][0],i});
        
        // then, pop the top element in the "heap", insert the next element in the array
        // which the element came from, and repeat the process until all elements are inserted
        while(!q.empty()){
            auto next = q.top();
            ans.push_back(next.first);
            q.pop();
            int temp = next.second;
            if(ind[temp]<K){
                q.push({arr[temp][ind[temp]],temp});
                ind[temp]++;
            }
        }
        return ans;
    }
};
