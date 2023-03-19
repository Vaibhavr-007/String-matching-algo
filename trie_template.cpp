#include<bits/stdc++.h>
using namespace std;
class trie{
    public:
    map<int,trie*> children;
    int value;
    trie(){
        value=0;
    }
    void insert(string &s){
        trie * curr=this;
        for(auto c:s){
            if(!curr->children[c-'a']){
                curr->children[c-'a']=new trie();
            }
            curr->children[c-'a']->value++;
            curr=curr->children[c-'a'];
        }
    }
    int check(string &s){
        trie * curr=this;
        int ans=0;
        for(auto c:s){
            if(!curr->children[c-'a']){
                break;
            }
            ans+=curr->children[c-'a']->value;
            curr=curr->children[c-'a'];
        }
        return ans;
    }
};