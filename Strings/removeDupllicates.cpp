string removeDuplicates(string &s)
{
    // Create an integer array to store 
    // frequency for ASCII characters
    vector<int> ch(256, 0);

    // Create result string
    string ans = "";

    // Traverse the input string
    for (char c : s) {
      
        // Check if current character's frequency is 0
        if (ch[c] == 0) {
          
            // Add char if frequency is 0
            ans.push_back(c);

            // Increment frequency
            ch[c]++;
        }
    }
    return ans;
}