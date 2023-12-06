#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
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

    int getMax(int x)
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

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    Trie trie;
    sort(arr.begin(), arr.end());
    vector<int> res(queries.size(), 0);
    vector<vector<int>> offline_queries;
    int index_no = 0;
    for (auto &it : queries)
        offline_queries.push_back({it[1], it[0], index_no++});
    int ind = 0;
    sort(offline_queries.begin(), offline_queries.end());
    for (auto &it : offline_queries)
    {
        int upto = it[0];
        int x = it[1];
        int index = it[2];
        if (upto < arr[0])
        {
            res[index] = -1;
            continue;
        }
        while (ind < arr.size() && arr[ind] <= upto)
        {
            trie.insert(arr[ind++]);
        }
        res[index] = trie.getMax(x);
    }
    return res;
}