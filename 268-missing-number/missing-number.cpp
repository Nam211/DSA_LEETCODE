#include <vector>
#include <numeric> // Required for std::accumulate

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        
        // Mathematical formula for sum of 0 to n: (n * (n + 1)) / 2
        // This is faster and uses less memory than looping/creating a range
        int expectedSum = n * (n + 1) / 2;
        
        // Calculate sum of elements in the vector
        int actualSum = std::accumulate(nums.begin(), nums.end(), 0);
        
        return expectedSum - actualSum;
    }
};