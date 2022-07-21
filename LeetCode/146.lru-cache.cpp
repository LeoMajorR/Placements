/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache
{
public:
    class Node
    {
    public:
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node *> m;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node *newNode)
    {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node *delNode)
    {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key_)
    {
        if (m.find(key_) != m.end())
        {
            Node *resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deleteNode(resnode);
            addNode(resnode);
            m[key_] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key_, int value)
    {
        if (m.find(key_) != m.end())
        {
            Node *existingNode = m[key_];
            m.erase(key_);
            deleteNode(existingNode);
        }
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key_, value));
        m[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
