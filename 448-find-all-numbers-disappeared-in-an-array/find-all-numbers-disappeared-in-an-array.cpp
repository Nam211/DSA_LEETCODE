#include <vector>
#include <cmath> // for std::abs

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++) {
            int index = std::abs(nums[i]) - 1; // Map value 1 to index 0, etc.
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        
        // Second Loop: Collect indices that have positive values
        std::vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};