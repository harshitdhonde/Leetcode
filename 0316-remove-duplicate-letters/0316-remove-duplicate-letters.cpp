
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        stack<char> st;
        vector<bool> seen(26, false);

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            // Skip if character is already in stack
            if (seen[ch - 'a']) {
                freq[ch - 'a']--;
                continue;
            }

            // Remove bigger characters if they appear again
            while (!st.empty() &&
                   st.top() > ch &&
                   freq[st.top() - 'a'] > 0) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            seen[ch - 'a'] = true;
            freq[ch - 'a']--;
        }

        string ans = "";

        // Build answer from stack
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
