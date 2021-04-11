#include <iostream>
#include <stack>
#include "findRepeatNumber_3.h"
#include "findNUmberIn2DMatrix_4.h"

using namespace std;
string longestCommonPrefix(vector<string> strs){
    string res="";
    if(strs.size()==0){

        return "";

    }


    int MAXLENGTH = strs[0].length();
    for(int i=1;i<strs.size()-1;i++){
        if(strs[i].length() < MAXLENGTH)
            MAXLENGTH = strs[i].length();
    }
    for(int i=0;i<strs.size();i++){
        bool flag = true;
        char c = strs[0][i];
        for(int j =1;j<MAXLENGTH-1 ;j++){
            if(c != strs[j][i]){
                flag = false;
                break;
            }

        }
        if(!flag)
            break;
        res+=c;
    }

    return res;
}
string longestPalindrome(string s) {
    if(s.length()==0)
        return "";
    stack<char> pstack;
    bool beginflag = false;
    int begin=0;
    int count=0;
    pstack.push(s[0]);
    vector<vector<int>> resset;
    for(int i=1;i<s.length();i++){
        if(pstack.top()  == s[i]){
            if(!beginflag){
                begin = i;
                count ++;
            }
            beginflag = true;

            pstack.pop();
        }else{
            if(beginflag){
                vector<int> r;
                r.push_back(begin);
                r.push_back(count);
                begin=0;
                count = 0;
            }
            pstack.push(s[i]);
            beginflag = false;

        }

    }
    count=0;
    begin=0;
    for(vector<vector<int>>::iterator it = resset.begin();it!= resset.end();it++){
        vector<int> res = *it;
        if(res[1] > count){
            count = res[1];
            begin = res[0];

        }

    }


    string res = s.substr(begin,count);
    return res;

}

int max(int a,int b){
    if (a<b)
        return b;
    else
        return a;
}

int main() {
    string str = "qweew";
    string res = longestPalindrome(str);
    cout<<res<<endl;


    return 0;
}

