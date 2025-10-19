string removeNonAlphabets(string s) {
        string result = "";
        for (char c : s) {
            // Check if character is alphabet
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                result += c;
            }
        }
        return result;
    }