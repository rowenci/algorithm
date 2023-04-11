/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
struct DoubleLinkedNode
{
    int value;
    DoubleLinkedNode* pre;
    DoubleLinkedNode* next;
    DoubleLinkedNode() : key(0), value(0), pre(nullptr), next(nullptr) {}
    DoubleLinkedNode(int keyVal, int valueVal) : key(keyVal), value(valueVal), pre(nullptr), next(nullptr) {}
};


class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
        m_head = new DLinkedNode();
        m_tail = new DLinkedNode();
        m_head->next = m_tail;
        m_tail->pre = m_head;
    }
    
    int get(int key) {
        if(!m_cache.count(key))
            return -1;

        DoubleLinkedNode* node = m_cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {

    }

private:
    DoubleLinkedNode* m_head;
    DoubleLinkedNode* m_tail;
    int m_capacity;
    unordered_map<int key, DoubleLinkedNode*> m_cache;

    void addToHead(const DoubleLinkedNode* node){
        node->pre = m_head;
        node->next = m_head->next;
        m_head->next->pre = node;
        m_head->next = node;
    }

    void removeNode(DoubleLinkedNode* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void moveToHead(DoubleLinkedNode* node){
        removeNode(node);
        addToHead(node);
    }

    DoubleLinkedNode* removeTail(){
        DoubleLinkedNode* node = m_tail->pre;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

