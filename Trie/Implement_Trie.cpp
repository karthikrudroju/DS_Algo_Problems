class Node {
private:
    Node* links[26];
    bool flag=false;
public:
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag=true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    // O(length of word)
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i]) == false){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    // O(length of word)
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i]) == false){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    // O(length of prefix)
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(node->containsKey(prefix[i]) == false){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};


// Problem Link: https://leetcode.com/problems/implement-trie-prefix-tree/
// Input:
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output:
// [null, null, true, false, true, null, true]

// Explanation:
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True
