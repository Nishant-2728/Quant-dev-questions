//https://myntbit.com/training/ticker-symbol-trie
#include <vector>
#include <string>
#include <memory>
#include <array>
class TickerTrie {
private:
    // TODO: Define your Node structure here
    struct Node{
        Node* links[26]={nullptr};
        double value;
        double prefixsum=0.0;
        bool isEnd=false;
        bool containsKey(char ch){
            return (links[ch-'A']!=NULL);
        }
        void put(char ch,Node* node){
            links[ch-'A']=node;
        }
        Node* get(char ch){
            return links[ch-'A'];
        }
        void updateSum(double d){
            prefixsum+=d;
        }
        void setEnd(){
            isEnd=true;
        }
    };
    Node* root;
public:
    TickerTrie() {
        // TODO: Initialize your Trie
        root=new Node();
    }

    void insert(const std::string& key, double val) {
        // TODO: Insert or update the ticker with the given value
        Node* node=root;
        int sz=key.size();
        double prevval=0;
        for(int index=0;index<sz;index++){
            if(!node->containsKey(key[index])){
                break;
            }
            node=node->get(key[index]);
            if(index==sz-1){
                prevval=node->value;
            }
        }
        node=root;
        for(int index=0;index<sz;index++){
            if(!node->containsKey(key[index])){
                node->put(key[index],new Node());
            }
            node=node->get(key[index]);
            node->updateSum(val-prevval);
        }
        node->value=val;
        node->setEnd();
    }
    double search(const std::string& key) {
        // TODO: Return the value if exists, else -1.0
        Node* node=root;
        int sz=key.size();
        for(int index=0;index<sz;index++){
            if(!node->containsKey(key[index])){
                return -1.0;
            }
            node=node->get(key[index]);
        }
        if(node->isEnd){
            return node->value;
        }
        return -1.0;
    }
    double startsWith(const std::string& prefix) {
        // TODO: Return the sum of values of all tickers with this prefix
        Node* node=root;
        int sz=prefix.size();
        for(int index=0;index<sz;index++){
            if(!node->containsKey(prefix[index])){
                return 0.0;
            }
            node=node->get(prefix[index]);
            if(index==sz-1){
                return node->prefixsum;
            }
        }
        return 0.0;
    }
};
