class Solution {
public:
    bool consecutiveSetBits(int n) {
        if(n==0) return false;
        string binary=bitset<32>(n).to_string();
        binary=binary.substr(binary.find('1'));
        int cnt=0;
        for(int i=0;i<(int)binary.size()-1;i++){
            if(binary[i]=='1' && binary[i+1]=='1') cnt++;
        }
        return (cnt==1);
    }
};
