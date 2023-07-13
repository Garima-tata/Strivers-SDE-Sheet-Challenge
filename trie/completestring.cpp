#include <bits/stdc++.h> 
#include <string>
using namespace std;

struct Node{
    Node* link[26];
    bool ew = false;

    bool containskey(char ch){
        return link[ch-'a']!=NULL;
    }
    Node *get(char ch){
        return link[ch-'a'];
    }
    
    void put(char ch, Node* node){
        link[ch-'a'] = node;
    }

    void setEnd(){
        ew = true;
    }

    bool isEnd(){
        return ew;
    }
};

class Trie{

    private: 
        Node* root;
    public:

    Trie(){
        root = new Node();
    }
    void insert(string &word){
        Node * curr = root;
        for(int i=0;i<word.size();i++){
            if(curr->containskey(word[i])==false){
                curr->put(word[i], new Node());
            }
            curr = curr->get(word[i]);
        }
        curr->setEnd();
    }

    public:
    bool checkIfPreExists(string s){
        Node* node = root;
        bool flag = true;

        for(int i=0;i<s.size();i++){
            if(node->containskey(s[i])){
                node = node->get(s[i]);
                flag = flag&node->isEnd();
            }else{
                return false;
            }
        }
        return flag;
    }
};
string completeString(int n, vector<string> &a){
    Trie *trie = new Trie();
    for(auto &i: a){
        trie->insert(i);
    }

    string longest = "";
    for(auto &it: a){
        if(trie->checkIfPreExists(it)){
            if(it.length()>longest.length()){
                longest = it;
            }
            else if(it.length() == longest.length()&&it<longest){
                longest = it;
            }
        }
    }

    if(longest=="")return "None";
    return longest;
}