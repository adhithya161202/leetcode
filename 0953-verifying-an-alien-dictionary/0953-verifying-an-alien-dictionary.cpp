class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for (int i = 0; i < order.length(); ++i) {
            mp[order[i]] = i;
        }
        
        for (int i = 0; i < words.size() - 1; ++i) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.length(), s2.length());

            bool isSorted = false;
            for (int j = 0; j < len; ++j) {
                if (mp[s1[j]] < mp[s2[j]]) {
                    isSorted = true;
                    break;
                }
                if (mp[s1[j]] > mp[s2[j]]) {
                    return false;
                }
            }

            // If words are identical up to the length of the shorter word, check their lengths
            if (!isSorted && s1.length() > s2.length()) {
                return false;
            }
        }
        
        return true;
    }
};
