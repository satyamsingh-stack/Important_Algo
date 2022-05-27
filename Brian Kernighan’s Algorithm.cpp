// Used to find the number of set bits.


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n){
            n=n&(n-1);
            count++;
        }
        return count;
    }
};
