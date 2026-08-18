class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> occurence(26, 0);

        int left = 0;
        int ans = 0;
        int MaxOccurence = 0;

        
        for (int right = 0; right < s.length(); right++) {
            MaxOccurence = max(MaxOccurence, ++occurence[s[right] - 'A']);

            if ((right - left + 1) - MaxOccurence > k) {
                occurence[s[left] - 'A']--;
                left++;
            }
            
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};