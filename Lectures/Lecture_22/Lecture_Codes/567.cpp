class Solution {
    private:
    bool checkEqual(int a[26], int b[26]) {
        for (int i=0; i<26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        // counting the occurence of each character in s2 string
        int count1[26] = {0};
        for (int i=0; i<s1.length(); i++) {
            int index = s1[i] - 'a';
            count1[index]++;
        }

        // traverse in array with first window
        int i=0;
        int windowSize = s1.length();
        int count2[26] = {0};

        while(i < windowSize && i<s2.length()) {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        // checking if two arrays matched or not
        if (checkEqual(count1, count2)) {
            return 1;
        }

        // traverse array with next windows
        while(i<s2.length()) {
            char newChar = s2[i];
            int index = newChar - 'a';
            count2[index]++;

            char oldChar = s2[i-windowSize];
            index = oldChar - 'a';
            count2[index]--;

            i++;

            if (checkEqual(count1, count2)) {
                return 1;
            }
        }
        return 0;
    }
};