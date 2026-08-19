class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.empty()) {
            return 0;
        }

        if (s.length() == 1) {
            return 1;
        }

        int left = 0;
        int right = 0;
        int ans = 0;

        unordered_set<char> set;

        while (right < s.length()) {

            char c = s[right];

            while (set.find(c) != set.end()) {
                set.erase(s[left]);
                left++;
            }

            set.insert(c);

            ans = max(ans, right - left + 1);

            right++;
        }

        return ans;
    }
};