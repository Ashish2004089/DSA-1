#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    int endWith = 0, prefixCount = 0;

    void increasePrefix(Node *node)
    {
        node->prefixCount++;
    }

    void increaseEndWith(Node *node)
    {
        node->endWith++;
    }

    void decreasePrefix(Node *node)
    {
        node->prefixCount--;
    }

    void decreaseEndWith(Node *node)
    {
        node->endWith--;
    }

    Node *getKey(char ch)
    {
        return links[ch - 'a'];
    }

    void createTrie(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                node->createTrie(word[i], new Node());
            node = node->getKey(word[i]);
            node->increasePrefix(node);
        }
        node->increaseEndWith(node);
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return 0;
            node = node->getKey(word[i]);
        }
        return node->endWith;
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return 0;
            node = node->getKey(word[i]);
        }
        return node->prefixCount;
    }

    void erase(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            node = node->getKey(word[i]);
            node->decreasePrefix(node);
        }
        node->decreaseEndWith(node);
    }
};