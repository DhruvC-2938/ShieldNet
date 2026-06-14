#include <iostream>
#include <string>

using namespace std;

struct TrieNode
{
    TrieNode* children[26];

    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;

        for(int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class ThreatDictionary
{
private:
    TrieNode* root;

    void displayWords(
        TrieNode* node,
        string currentWord);

public:
    ThreatDictionary();

    void loadSampleData();

    void addSignature();

    void searchSignature();

    void checkTraffic();

    void displaySignatures();

    void menu();

    void insert(string word);

    bool search(string word);
};