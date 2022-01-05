/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution2 {
public:
    int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
    bool find(string &word,int index,vector<vector<char>>& board,vector<vector<int>> &used,int x,int y,int &m,int &n){
        if(index==word.size()){
            return true;
        }
        used[x][y]=1;
        bool res=false;
        for(int i=0;i<4;++i){
            int tx=x+dx[i],ty=y+dy[i];
            if(tx<0||tx>=m||ty<0||ty>=n||used[tx][ty]||board[tx][ty]!=word[index]){
                continue;
            }
            res|=find(word,index+1,board,used,tx,ty,m,n);
            if(res){
                break;
            }
        }
        used[x][y]=0;
        return res;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m=board.size(),n=board[0].size();
        vector<int> count[26];
        vector<vector<int>> used(m,vector<int>(n,0));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                count[board[i][j]-'a'].push_back(i*n+j);
            }
        }
        vector<string> res;
        for(string &item:words){
            int start=item[0]-'a';
            for(int pos:count[start]){
                int x=pos/n,y=pos%n;
                if(find(item,1,board,used,x,y,m,n)){
                    res.push_back(item);
                    break;
                }
            }
        }
        return res;
    }
};
struct node{
    node *next[26];
    bool isEnd;
    int children;
    node(){
        for(int i=0;i<26;++i){
            next[i]=nullptr;
        }
        isEnd=false;
        children=0;
    }
};
class Solution {
public:
    int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
    node *head;
    void insertWord(string &word){
        node *cur=head;
        for(char &item:word){
            if(!cur->next[item-'a']){
                cur->next[item-'a']=new node();
            }
            ++cur->children;
            cur=cur->next[item-'a'];
        }
        ++cur->children;
        cur->isEnd=true;
    }
    void eraseWord(string &word){
        node *cur=head;
        for(char &item:word){
            node *child=cur->next[item-'a'];
            --child->children;
            if(child->children){
                child->isEnd=false;
                cur=child;
            }else{
                cur->next[item-'a']=nullptr;
                cur=child;
            }
        }
    }
    void dfs(int x,int y,int &m,int &n,node *cur,vector<vector<char>> &board,string &find,vector<string> &res){
        if(board[x][y]=='#'||!cur->next[board[x][y]-'a']){
            return;
        }
        cur=cur->next[board[x][y]-'a'];
        find+=board[x][y];
        if(cur->isEnd){
            res.push_back(find);
            eraseWord(find);
        }
        char tmp=board[x][y];
        board[x][y]='#';
        for(int i=0;i<4;++i){
            int tx=x+dx[i],ty=y+dy[i];
            if(tx<0||tx>=m||ty<0||ty>=n){
                continue;
            }
            dfs(tx,ty,m,n,cur,board,find,res);
        }
        board[x][y]=tmp;
        find.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        head=new node();
        for(string &word:words){
            insertWord(word);
        }
        int m=board.size(),n=board[0].size();
        string find;
        vector<string> res;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                dfs(i,j,m,n,head,board,find,res);
            }
        }
        return res;
    }
};
// @lc code=end

