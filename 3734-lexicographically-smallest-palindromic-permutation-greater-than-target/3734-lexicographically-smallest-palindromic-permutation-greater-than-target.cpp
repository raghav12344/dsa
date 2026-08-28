class Solution {
public:
    int half_len;
    string target_str;
    string odd_char;
    string current_half;

    // Generates the lexicographically smallest suffix using remaining counts
    string fill_remaining_greedily(vector<int>& counts) {
        string rem = "";
        for (int i = 0; i < 26; ++i) {
            if (counts[i] > 0) {
                rem += string(counts[i], (char)('a' + i));
            }
        }
        return rem;
    }

    // Reconstructs the complete palindrome from the left half
    string build_palindrome(const string& left, const string& rem_greedy) {
        string full_left = left + rem_greedy;
        string right = full_left;
        reverse(right.begin(), right.end());
        return full_left + odd_char + right;
    }

    // DFS to find the first valid palindrome
    bool dfs(int idx, vector<int>& counts, bool is_greater, string& result) {
        // Base case: Entire left half is built
        if (idx == half_len) {
            string full_pal = current_half + odd_char;
            string right = current_half;
            reverse(right.begin(), right.end());
            full_pal += right;
            if (full_pal > target_str) {
                result = full_pal;
                return true;
            }
            return false;
        }

        // Case 1: We are already strictly greater than the target prefix.
        // We can immediately fill the rest greedily for the smallest configuration.
        if (is_greater) {
            string rem = fill_remaining_greedily(counts);
            result = build_palindrome(current_half, rem);
            return true;
        }

        // Case 2: We must maintain or exceed the target prefix.
        char target_char = target_str[idx];

        // Try the exact matching character to stay tight with the target prefix
        if (counts[target_char - 'a'] > 0) {
            counts[target_char - 'a']--;
            current_half.push_back(target_char);

            if (dfs(idx + 1, counts, false, result)) return true;

            // Backtrack
            current_half.pop_back();
            counts[target_char - 'a']++;
        }

        // Try to pick the next smallest available character that is strictly greater than target_char
        for (char c = target_char + 1; c <= 'z'; ++c) {
            if (counts[c - 'a'] > 0) {
                counts[c - 'a']--;
                current_half.push_back(c);

                // Since c > target_char, is_greater becomes true
                if (dfs(idx + 1, counts, true, result)) return true;

                // Backtrack
                current_half.pop_back();
                counts[c - 'a']++;
            }
        }

        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
       vector<int> total_counts(26, 0);
        for (char c : s) total_counts[c - 'a']++;

        int odd_count = 0;
        odd_char = "";
        vector<int> counts(26, 0);

        for (int i = 0; i < 26; ++i) {
            if (total_counts[i] % 2 != 0) {
                odd_count++;
                odd_char = string(1, (char)('a' + i));
            }
            counts[i] = total_counts[i] / 2;
        }

        // A valid palindrome cannot have more than 1 odd-frequency character
        if (odd_count > 1) return "";

        half_len = s.length() / 2;
        target_str = target;
        current_half = "";
        string result = "";

        if (dfs(0, counts, false, result)) {
            return result;
        }
        return "";
    }
};