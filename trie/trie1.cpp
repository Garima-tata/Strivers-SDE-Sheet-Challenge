#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool eow;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        eow = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* curr = root;

        for (int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';

            if (curr->children[ind] == nullptr) {
                curr->children[ind] = new TrieNode();
            }

            if (i == word.size() - 1) {
                curr->children[ind]->eow = true;
            }

            curr = curr->children[ind];
        }
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (int i = 0; i < prefix.size(); i++) {
            int ind = prefix[i] - 'a';

            if (curr->children[ind] == nullptr) {
                return false;
            }

            curr = curr->children[ind];
        }

        return true;
    }
};

