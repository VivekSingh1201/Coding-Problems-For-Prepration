// Stream of Characters
//Design an algorithm that accepts a stream of characters and checks if a suffix of these characters is a string of a given array of strings words.

//For example, if words = ["abc", "xyz"] and the stream added the four characters (one by one) 'a', 'x', 'y', and 'z', your algorithm should detect that the suffix "xyz" of the characters "axyz" matches "xyz" from words.

//Implement the StreamChecker class:

//StreamChecker(String[] words) Initializes the object with the strings array words.
//boolean query(char letter) Accepts a new character from the stream and returns true if any non-empty suffix from the stream forms a word that is in words.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class StreamChecker {
private:
    struct Trie{
        Trie *link[26]={};
        bool flag=false;
    };

    Trie *root;
    string stream;
    int maxLen;

public:
    StreamChecker(vector<string>& words) {
        root = new Trie();
        maxLen=0;

        for(auto &word:words){
            Trie *node = root;
            maxLen=max(maxLen, (int)word.size());
            for(int i=word.size()-1;i>=0;--i){
                int idx = word[i] - 'a';
                if(!node->link[idx]){
                    node->link[idx]=new Trie();
                }
                node=node->link[idx];
            }
            node->flag=true;
        }
    }
    
    bool query(char letter) {
        stream += letter;
        if(stream.size()>maxLen){
            stream.erase(stream.begin());
        }

        Trie *node = root;
        for(int i=stream.size()-1;i>=0;--i){
            int idx=stream[i]-'a';
            if(!node->link[idx]){
                return false;
            }
            node = node->link[idx];
            if(node->flag){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

int main() {
    vector<string> words = {"cd","f","kl"};
    StreamChecker* obj = new StreamChecker(words);
    cout << obj->query('a') << endl; // return false
    cout << obj->query('b') << endl; // return false
    cout << obj->query('c') << endl; // return false
    cout << obj->query('d') << endl; // return true, because 'cd' is in the wordlist
    cout << obj->query('e') << endl; // return false
    cout << obj->query('f') << endl; // return true, because 'f' is in the wordlist
    cout << obj->query('g') << endl; // return false
    cout << obj->query('h') << endl; // return false
    cout << obj->query('i') << endl; // return false
    cout << obj->query('j') << endl; // return false
    cout << obj->query('k') << endl; // return false
    cout << obj->query('l') << endl; // return true, because 'kl' is in the wordlist

    delete obj;
    return 0;
}


//Time Complexity: O(N) for the constructor, where N is the total number of characters in all the words. O(M) for each query, where M is the length of the longest word in the words array.
//Space Complexity: O(N) for the Trie data structure, where N is the total number of characters in all the words. O(M) for the stream string, where M is the length of the longest word in the words array.