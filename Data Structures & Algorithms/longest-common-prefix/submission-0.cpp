class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    
    // Loop through the characters of the first string
    for (int i = 0; i < strs[0].length(); i++) {
        char c = strs[0][i];
        
        // Compare with the rest of the strings in the array
        for (int j = 1; j < strs.size(); j++) {
            // If we reach the end of a string or find a character mismatch
            if (i == strs[j].length() || strs[j][i] != c) {
                // Return the substring of the first word up to index 'i'
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0]; // The entire first string is the common prefix
}
};