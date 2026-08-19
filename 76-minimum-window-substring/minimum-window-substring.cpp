class Solution {
public:
    string minWindow(string s, string t) {

        if (s.length() < t.length()) {
            return "";
        }

        vector<int> need(128, 0);
        vector<int> window(128, 0);

        // Count characters required from t
        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int right = 0;

        int have = 0;
        int required = t.length();

        int minLength = INT_MAX;
        int start = 0;

        while (right < s.length()) {

            char c = s[right];

            // Add current character to window
            window[c]++;

            // This occurrence is useful if we still needed it
            if (window[c] <= need[c]) {
                have++;
            }

            // If window contains everything required
            while (have == required) {

                // Update minimum answer
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                // Remove left character
                char leftChar = s[left];
                window[leftChar]--;

                // If we removed a required occurrence,
                // window is no longer valid
                if (window[leftChar] < need[leftChar]) {
                    have--;
                }

                left++;
            }

            right++;
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(start, minLength);
    }
};