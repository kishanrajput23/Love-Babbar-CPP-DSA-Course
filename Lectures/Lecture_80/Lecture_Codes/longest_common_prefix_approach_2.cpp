// TC = O(m*n);
// SC = O(m*n);

class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char ch) {
        data  = ch;
        for (int i=0; i<26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {

public:
    TrieNode* root;

    /** Initialize your data structure here. */
    Trie(char ch) { 
        root = new TrieNode(ch); 
    }

    // insert util function to insert word in trie
    void insertUtil(TrieNode* root, string word) {
        // base case
        if (word.size() == 0) {
            root->isTerminal = true;
            return ;
        }

        // assuming all letters in word will be in caps
        int index = word[0] - 'a';
        TrieNode* child;

        // if present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // for rest of the cases recursion will take care of it
        insertUtil(child, word.substr(1));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans) {
        for (int i=0; i<str.size(); i++) {
            char ch = str[i];

            if (root->childCount == 1) {
                ans.push_back(ch);

                // if child count is 1 move ahead;
                int index = ch - 'a';
                root = root->children[index];
            }
            else {
                break;
            }

            if (root->isTerminal) {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n) {
    // Write your code here
    Trie* t = new Trie('\0');

    // inserting all strings into trie
    for (int i=0; i<n; i++) {
        t->insert(arr[i]);
    }

    string ans = "";
    string first = arr[0];

    t->lcp(first, ans);

    return ans;

}
