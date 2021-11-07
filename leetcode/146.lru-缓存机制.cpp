/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */
#include<unordered_map>
using namespace std;
// @lc code=start
struct LinkNode{
    int key,value;
    LinkNode *prev,*next;
    LinkNode():key(0),value(0),prev(nullptr),next(nullptr){}
    LinkNode(int _key,int _value):key(_key),value(_value),prev(nullptr),next(nullptr){}
};

class LRUCache {
private:
    unordered_map<int,LinkNode *>hash;
    LinkNode *head,*tail;
    int size,capacity;
    void moveToHead(LinkNode *cur){
        cur->prev->next=cur->next;
        cur->next->prev=cur->prev;
        cur->next=head->next;
        cur->prev=head;
        head->next->prev=cur;
        head->next=cur;
    }
    void addNode(LinkNode *cur){
        cur->next=head->next;
        cur->prev=head;
        head->next->prev=cur;
        head->next=cur;
    }
public:
    LRUCache(int _capacity) {
        size=0,capacity=_capacity;
        head=new LinkNode();
        tail=new LinkNode();
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(!hash.count(key)){
            return -1;
        }
        LinkNode *cur=hash[key];
        moveToHead(cur);
        return cur->value;
    }
    
    void put(int key, int value) {
        if(hash.count(key)){
            LinkNode *cur=hash[key];
            cur->value=value;
            moveToHead(cur);
            return;
        }
        if(size<capacity){
            LinkNode *cur=new LinkNode(key,value);
            addNode(cur);
            hash[key]=cur;
            ++size;
        }else{
            LinkNode *toera=tail->prev;
            hash.erase(toera->key);
            toera->key=key;
            toera->value=value;
            moveToHead(toera);
            hash[key]=toera;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

