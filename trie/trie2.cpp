
#include <bits/stdc++.h> 
using namespace std;

struct Node{
    Node* link[26];
    int ew = 0;
    int cntpre = 0;

    bool containskey(char ch){
        return link[ch-'a']!=NULL;
    }
    Node *get(char ch){
        return link[ch-'a'];
    }
    
    void put(char ch, Node* node){
        link[ch-'a'] = node;
    }

    void increaseEnd(){
        ew++;
    }

    void increasePre(){
        cntpre++;
    }

    void deleteEnd(){
        ew--;
    }

    void reducePrefix(){
        cntpre--;
    }
    int getEnd(){
        return ew;
    }

    int getPrefix(){
        return cntpre;
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
            curr->increasePre();
        }
        curr->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(node->containskey(word[i])){
                node = node->get(word[i]);
            }else{
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(node->containskey(word[i])){
                node = node->get(word[i]);
            }else{
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string &word){
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(node->containskey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }else{
                return ;
            }
        }
        node->deleteEnd();
    }
};
