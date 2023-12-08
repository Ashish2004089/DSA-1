#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[2];
    int prefix;

    Node *getKey(int bit)
    {
        return links[bit];
    }

    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }

    void createTrie(int bit, Node *node)
    {
        links[bit] = node;
    }

    void inc(Node *node)
    {
        node->prefix++;
    }

    void dec(Node *node)
    {
        node->prefix--;
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
        for (int i = 20; i >= 0; i--)
        {
            int bit = ((n >> i) & 1);
            if (!node->containsKey(bit))
                node->createTrie(bit, new Node());
            node = node->getKey(bit);
            node->inc(node);
        }
    }

    void remove(int n)
    {
        Node *node = root;
        for (int i = 20; i >= 0; i--)
        {
            int bit = ((n >> i) & 1);
            node = node->getKey(bit);
            node->dec(node);
        }
    }

    int getMax(int x)
    {
        Node *node = root;
        int _xor = 0;
        for (int i = 20; i >= 0; i--)
        {
            int bit = ((x >> i) & 1);
            if (node->containsKey(1 - bit) && (node->getKey(1 - bit))->prefix)
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