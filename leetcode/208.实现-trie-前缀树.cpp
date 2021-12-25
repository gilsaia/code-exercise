/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include<string>
using namespace std;
// @lc code=start
struct node {
    bool isEnd;
    int ind;
    node *next[26];
    node(){
        isEnd=false;
        ind=-1;
        for(int i=0;i<26;++i){
            next[i]=nullptr;
        }
    }
    node(int a){
        isEnd=false;
        ind=a;
        for(int i=0;i<26;++i){
            next[i]=nullptr;
        }
    }
};
class Trie {
public:
    node *root;
    Trie() {
        root=new node();
    }
    
    void insert(string word) {
        node *cur=root;
        for(char &item:word){
            if(cur->next[item-'a']==nullptr){
                cur->next[item-'a']=new node(item-'a');
            }
            cur=cur->next[item-'a'];
        }
        cur->isEnd=true;
    }
    
    bool search(string word) {
        node *cur=root;
        for(char &item:word){
            if(cur->next[item-'a']==nullptr){
                return false;
            }
            cur=cur->next[item-'a'];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        node *cur=root;
        for(char &item:prefix){
            if(cur->next[item-'a']==nullptr){
                return false;
            }
            cur=cur->next[item-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

