#include<iostream>
using namespace std;

// TC of insertion is O(N) where n is length if word
// TC of search is O(N) where n is length if word


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
    private:
    bool isEmpty(TrieNode* root) {
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != nullptr) {
                return false;
            }
        }
        return true;
    }

    public:
    TrieNode* root;

    // initializing root with null
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
        int index = word[0] - 'A';
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

    void insertWord(string word) {
        insertUtil(root, word);
    }

    // search util function to find word in trie
    bool searchUtil(TrieNode* root, string word) {
        // base case
        if (word.size() == 0) {
            return root->isTerminal;
        }

        // assuming all letters in word will be in caps
        int index = word[0] - 'A';
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

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    // delete util function to delete word in trie
    bool deleteUtil(TrieNode* root, string word, int depth) {
        if (root == NULL)
            return false;

        if (depth == word.length()) {
            if (root->isTerminal) {
                root->isTerminal = false;

                // If current node is not prefix of any other word
                if (isEmpty(root)) {
                    return true;
                }
                return false;
            }
        }
        else {
            int index = word[depth] - 'A';
            if (deleteUtil(root->children[index], word, depth + 1)) {
                // last node marked, delete it
                delete root->children[index];
                root->children[index] = NULL;

                // recursively climb up, deleting nodes with no children
                return !root->isTerminal && isEmpty(root);
            }
        }
        return false;
    }

    void deleteWord(string word) {
        deleteUtil(root, word, 0);
    }

};

int main() {

    Trie *t = new Trie();

    t->insertWord("ABCD");
    t->insertWord("ARM");
    t->insertWord("TIME");

    cout<<"word (ABCD) is present or not : "<<t->searchWord("ABCD")<<endl;
    cout<<"word (TIME) is present or not : "<<t->searchWord("TIME")<<endl;
    cout<<"word (TIM) is present or not : "<<t->searchWord("TIM")<<endl;

    t->deleteWord("ABCD");
    cout << "word (ABCD) is present or not after deletion: " << t->searchWord("ABCD") << endl;

    t->deleteWord("TIME");
    cout << "word (TIME) is present or not after deletion: " << t->searchWord("TIME") << endl;

    return 0;
}