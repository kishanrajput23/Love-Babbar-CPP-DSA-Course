/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
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


// search util function to find word in trie
    bool searchUtil(TrieNode* root, string word) {
        // base case
        if (word.size() == 0) {
            return root->isTerminal;
        }

        // assuming all letters in word will be in caps
        int index = word[0] - 'a';
        TrieNode* child;

        // if present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            return false;
        }

        // rest case can take care of by recursion
        return searchUtil(child, word.substr(1));
    }


    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchUtil(root, word);
    }

    // startsWith util function to find prefix word in trie
    bool startsWithUtil(TrieNode* root, string word) {
        // base case
        if (word.size() == 0) {
            return true;
        }

        // assuming all letters in word will be in caps
        int index = word[0] - 'a';
        TrieNode* child;

        // if present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            return false;
        }

        // for rest of the cases recursion will take care of it
        return startsWithUtil(child, word.substr(1));
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);
    }
};