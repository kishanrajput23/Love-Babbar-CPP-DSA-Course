class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data  = ch;
        for (int i=0; i<26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {

public:
    TrieNode* root;

    /** Initialize your data structure here. */
    Trie() { 
        root = new TrieNode('\0'); 
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
            root->children[index] = child;
        }

        // for rest of the cases recursion will take care of it
        insertUtil(child, word.substr(1));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtil(root, word);
    }

    // function to find suggestion words
    void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }

        for (char ch='a'; ch<='z'; ch++) {
            TrieNode* next = curr->children[ch-'a'];

            if (next != NULL) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    // fucntion to find the words that matches every character as prefix in words
    vector<vector<string>> getSuggestions(string str) {
        TrieNode* prev = root;
        string prefix = "";
        vector<vector<string>> output;

        for (int i=0; i<str.size(); i++) {
            char lastChar = str[i];

            prefix.push_back(lastChar);

            // check for last char 
            TrieNode* curr = prev->children[lastChar - 'a'];

            // if last character not found
            if (curr == NULL) {
                break;
            }
            
            // if found 
            vector<string> temp;
            printSuggestions(curr, temp, prefix);
            
            output.push_back(temp);
            temp.clear();

            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr) {
    //    Write your code here.

    Trie *t = new Trie();

    for (int i = 0; i < contactList.size(); i++) {
        string temp = contactList[i];
        t->insert(temp);
    }

    return t->getSuggestions(queryStr);
}