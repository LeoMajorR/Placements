/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start

struct Node
{
    int key, value, count;
    Node *next;
    Node *prev;
    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        count = 1;
    }
};

struct List
{
    int size;
    Node *head;
    Node *tail;
    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node *delNode)
    {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};

class LFUCache
{
    map<int, Node *> keyNode;     //store mapping of key and Node
    map<int, List *> freqListMap; //store mapping of frequency and correspoding key value pair in list
    int maxCacheSize;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity)
    {
        maxCacheSize = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node *node)
    {
        keyNode.erase(node->key);
        freqListMap[node->count]->removeNode(node);
        if (node->count == minFreq && freqListMap[node->count]->size == 0)
            minFreq++;
        List *nextHigherFreqList = new List();
        if (freqListMap.find(node->count + 1) != freqListMap.end())
            nextHigherFreqList = freqListMap[node->count + 1];

        node->count += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->count] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (maxCacheSize == 0)
            return;
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else
        {
            if (curSize == maxCacheSize)
            {
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;

            minFreq = 1;
            List *listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end())
                listFreq = freqListMap[minFreq];

            Node *node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
