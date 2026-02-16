class Solution {
public:
    int reverseBits(int n) {
        bitset<32> bits(n);
        string bitString = bits.to_string();
        reverse(bitString.begin(),bitString.end());
        bitset<32> reversedBits(bitString);
        return reversedBits.to_ulong();
    }
};
