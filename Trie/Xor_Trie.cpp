#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[2];

    Node *getKey(int bit)
    {
        return links[bit];
    }

    bool containsKey(int bit)
    {
        return links[bit] != NULL;
    }

    void createTrie(int bit, Node *node)
    {
        links[bit] = node;
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
    void insert(int n)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = ((n >> i) & 1);
            if (!node->containsKey(bit))
                node->createTrie(bit, new Node());
            node = node->getKey(bit);
        }
    }
    int getMaxXor(int x)
    {
        Node *node = root;
        int _xor = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = ((x >> i) & 1);
            if (node->containsKey(1 - bit))
            {
                _xor |= (1LL << i);
                node = node->getKey(1 - bit);
            }
            else
                node = node->getKey(bit);
        }
        return _xor;
    }
};