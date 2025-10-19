class Solution {
public:
    // Function to find max occurring character
    char getMaxOccurringChar(string s) {
        // Map to store frequency of characters
        map<char, int> freq;

        // Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Variables to store result
        int maxFreq = 0;
        char maxChar = '\0';

        // Traverse map to find max occurring char
        for (auto it : freq) {
            if (it.second > maxFreq) {
                maxFreq = it.second;
                maxChar = it.first;
            }
        }

        // Return result
        return maxChar;
    }
};