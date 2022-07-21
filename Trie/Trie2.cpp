/*sample input : 
insert samsung
insert samsung
insert vivo
erase vivo
countWordsEqualTo samsung
countWordsEqualTo vi
*/

/*
sample output:
2
0
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    int countEndWith = 0;
    int countprefix = 0;

    bool containsKey(char ch)
    {
        return (links[ch - 'a']);
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    int getEnd()
    {
        return countEndWith;
    }

    int getPrefix()
    {
        return countprefix;
    }

    void increaseEnd()
    {
        countEndWith++;
    }

    void increaseprefix()
    {
        countprefix++;
    }

    void deleteEnd()
    {
        countEndWith--;
    }

    void reduceprefix()
    {
        countprefix--;
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
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
                node->put(word[i], new Node());
            node = node->get(word[i]);
            node->increaseprefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
                node = node->get(word[i]);
            else
                return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
                node->get(word[i]);
            else
                return 0;
        }
        return node->getPrefix();
    }
    void erase(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->reduceprefix();
            }
            else
                return;
        }
        node->deleteEnd();
    }
};
