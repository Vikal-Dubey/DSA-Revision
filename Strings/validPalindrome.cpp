class Solution {
public:
    bool isAlpha(char ch) {
        return ((tolower(ch) >= 'a' && tolower(ch) <= 'z') || (ch >= '0' && ch <= '9'));
    }
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start < end) {
            if(!isAlpha(s[start])) {
                start++;
                continue;
            }
            if(!isAlpha(s[end])) {
                end--;
                continue;
            }
            if(tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};