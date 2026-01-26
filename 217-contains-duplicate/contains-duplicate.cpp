#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        // Create a hash set to store unique elements
        std::unordered_set<int> seen;
        
        for (int num : nums) {
            // If the number is already in the set, we found a duplicate
            if (seen.count(num)) {
                return true;
            }
            // Otherwise, add it to the set
            seen.insert(num);
        }
        
        // If we finish the loop, no duplicates were found
        return false;
    }
};