#include <vector>
#include <iostream>
class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        int xorALL = 0;
        for(int x: nums) xorALL ^= x;

        int diffBit = xorALL & -xorALL;
        int a = 0; 
        int b = 0;
        for(int x: nums){
            if(x & diffBit) a ^= x;
            else b ^= x;
        }  
        return {a, b};
     }
};