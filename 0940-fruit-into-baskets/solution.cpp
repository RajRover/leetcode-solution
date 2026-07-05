class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low=0;
        int res=-1;
        unordered_map<int,int>f;
        for(int high=0;high<fruits.size();high++){
            f[fruits[high]]++;
            while(f.size()>2){
                f[fruits[low]]--;
                if(f[fruits[low]]==0) f.erase(fruits[low]);
                low++;
            }
            if(f.size()<=2){
                int len=high-low+1;
                res=max(len,res);
            }
        }
        return res;
    }
};
