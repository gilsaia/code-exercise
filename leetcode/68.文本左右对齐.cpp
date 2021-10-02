/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int start=0;
        int curlength=words[0].length();
        int cur=1;
        vector<string> res;
        while(cur<words.size()){
            if((curlength+words[cur].length())<maxWidth){
                curlength+=(words[cur].length()+1);
                ++cur;
                continue;
            }
            curlength=curlength-(cur-start-1);
            string tmp;
            if((cur-start)==1){
                tmp+=words[start];
                if(tmp.length()<maxWidth){
                    tmp+=string(maxWidth-tmp.length(),' ');
                }
            }else{
                int spacelength=maxWidth-curlength;
                int wordspace=spacelength/(cur-start-1);
                int remainspace=spacelength%(cur-start-1);
                string space(wordspace,' ');
                for(int i=start;i<cur;++i){
                    tmp+=words[i];
                    if((i+1)<cur){
                        tmp+=space;
                        if(remainspace){
                            tmp+=' ';
                            --remainspace;
                        }
                    }
                }
            }
            res.push_back(tmp);
            start=cur;
            curlength=words[cur].length();
            ++cur;
        }
        string tmp;
        for(int i=start;i<cur;++i){
            tmp+=words[i];
            if((i+1)<cur){
                tmp+=' ';
            }
        }
        if(tmp.length()<maxWidth){
            tmp+=string(maxWidth-tmp.length(),' ');
        }
        res.push_back(tmp);
        return res;
    }
};
// @lc code=end

