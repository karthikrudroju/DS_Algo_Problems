class Node {
    Node* links[26];
    int ends_cnt = 0;
    int pref_cnt = 0;
public:
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        ends_cnt++;
    }
    
    void setPref(){
        pref_cnt++;
    }
    
    void unSetEnd(){
        ends_cnt--;
    }
    
    void unSetPref(){
        pref_cnt--;
    }
    
    int countEnd(){
        return ends_cnt;
    }
    
    int countPref(){
        return pref_cnt;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    
    void insert(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->setPref();
        }
        node->setEnd();
    }
    
    int countWordsEqualTo(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->countEnd();
    }
    
    int countWordsStartingWith(string prefix){
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])){
                return 0;
            }
            node = node->get(prefix[i]);
        }
        return node->countPref();
    }
    
    void erase(string word){
        int x = countWordsEqualTo(word);
        if(x==0)return;
        Node* node = root;
        for(int i=0;i<word.size();i++){
            node = node->get(word[i]);
            node->unSetPref();
        }
        node->unSetEnd();
    }
};

// Problem Link: https://leetcode.com/problems/counting-words-with-a-given-prefix/
