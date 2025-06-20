#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int _key, int _value) {
        key = _key;
        value = _value;
        prev = next = nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> mpp;
    int capacity;
    Node* head;
    Node* tail;

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        if (prevNode) prevNode->next = nextNode;
        if (nextNode) nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!mpp.count(key)) return -1;
        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mpp.count(key)) {
            Node* node = mpp[key];
            node->value = value;
            deleteNode(node);
            insertAfterHead(node);
        } else {
            if (mpp.size() == capacity) {
                Node* nodeToRemove = tail->prev;
                mpp.erase(nodeToRemove->key);
                deleteNode(nodeToRemove);
                delete nodeToRemove;
            }
            Node* newNode = new Node(key, value);
            mpp[key] = newNode;
            insertAfterHead(newNode);
        }
    }
};
