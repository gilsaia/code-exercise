/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */
#include<string>
using namespace std;
// @lc code=start
struct node {
    bool isEnd;
    node *next[26];
    node(){
        isEnd=false;
        for(int i=0;i<26;++i){
            next[i]=nullptr;
        }
    }
    bool find(string &word,int index){
        if(index==word.size()){
            return isEnd;
        }
        if(word[index]!='.'){
            if(next[word[index]-'a']==nullptr){
                return false;
            }
            return next[word[index]-'a']->find(word,index+1);
        }else{
            bool ans=false;
            for(int i=0;i<26;++i){
                if(next[i]!=nullptr){
                    ans|=next[i]->find(word,index+1);
                    if(ans){
                        return true;
                    }
                }
            }
            return ans;
        }
    }
};
class WordDictionary {
public:
    node *root;
    WordDictionary() {
        root=new node();
    }
    
    void addWord(string word) {
        node *cur=root;
        for(char &item:word){
            if(cur->next[item-'a']==nullptr){
                cur->next[item-'a']=new node();
            }
            cur=cur->next[item-'a'];
        }
        cur->isEnd=true;
    }
    
    bool search(string word) {
        return root->find(word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

