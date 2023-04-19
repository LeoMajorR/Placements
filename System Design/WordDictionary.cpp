#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    bool isWord;
    TrieNode *children[26];
    TrieNode() : isWord(false)
    {
        for (auto &a : children)
            a = NULL;
    }
};

class WordDictionary
{
public:
    TrieNode *root;
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *p = root;
        for (auto a : word)
        {
            int i = a - 'a';
            if (p->children[i] == NULL)
                p->children[i] = new TrieNode();
            p = p->children[i];
        }
        p->isWord = true;
    }

    /**
     * @Approach: DFS
     * 1. If the current character is not a letter, then we need to check all
     *   possible nodes at this level.
     * 2. If it is a letter, then just go to the only possible node at this level.
     * 3. As soon as we found a word in the trie which is the same as the given
     *  word, we return true.
     * 4. If we did not find a word which is the same as the given word, we
     * return false.
     */
    bool search(string word, TrieNode *p)
    {
        for (int i = 0; i < word.size(); i++)
        {
            // If the current character is a letter.
            if (word[i] == '.')
            {
                for (auto a : p->children)
                {
                    if (a != NULL && search(word.substr(i + 1), a))
                        return true;
                }
                return false;
            }
            // If the current character is not a letter.
            else
            {
                int j = word[i] - 'a';
                if (p->children[j] == NULL)
                    return false;
                p = p->children[j];
            }
        }
        return p->isWord;
    }

    bool search(string word)
    {
        return search(word, root);
    }
};