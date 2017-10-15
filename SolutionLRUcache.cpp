#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*class Cache {
	struct DoubleNode {
		int value;
		int key; //required for removal
		DoubleNode* prev;
		DoubleNode* next;

		DoubleNode(int key, int value) {
			this->key = key;
			this->value = value;
		}
	};

	DoubleNode* head;
	DoubleNode* tail; //LRU

public:
	int capacity;
	int count = 0;
	unordered_map<int, DoubleNode*> hashtable;

	Cache(int capacity) {
		this->capacity = capacity;
	}

	//For sorting LRU
	void moveToHead(DoubleNode* node) {
		//remove from old location
		if(node->next != NULL)
			node->next->prev = node->prev;
		if(node->prev != NULL)
			node->prev->next = node->next;

		//make node into head
		node->prev = NULL;
		node->next = this->head;
		this->head = node;
	}

	int get(int key) {
		if(hashtable.find(key) != hashtable.end()) {
			DoubleNode* node = hashtable.find(key)->second;
			moveToHead(node);
			return node->value;
		}

		return -1; //default error case
	}

	void put(int key, int value) {
		DoubleNode* node;

		//if key found, update
		if(hashtable.find(key) != hashtable.end()) {
			node = hashtable.find(key)->second;
			node->value = value; //update value
		} else { //if not found, insert & increment
			node = new DoubleNode(key, value);
			hashtable.insert(pair<int, DoubleNode*>(key, node));
			this->count++;

			if(count == 2 && tail == NULL) {
				tail = head; //first node becomes tail
			}
		}
		moveToHead(node);
		if(count > capacity) {
			tail->prev->next = NULL;
			tail->prev = NULL;
			hashtable.erase(tail->key);
			count--;
		}
	}
};
*/

class Cache {
    struct DoublyLinkedNode {
        DoublyLinkedNode* prev;
        DoublyLinkedNode* next;
        int key;
        int value;
        
        DoublyLinkedNode(int key, int value) {
            this->key = key;
            this->value = value;
        }
    };
    
    DoublyLinkedNode* head;
    DoublyLinkedNode* tail; //LRU
    int capacity;
    int count = 0;
    
    //<key, Node holding value>
    unordered_map<int, DoublyLinkedNode*> hashtable;
    
public:
    Cache(int capacity) {
        this->capacity = capacity;
    }
    
    void moveToHead(DoublyLinkedNode* node) {
        if(node->prev != NULL)
            node->prev->next = node->next;
        if(node->next != NULL)
            node->next->prev = node->prev;
        
        node->prev = NULL;
        node->next = this->head;
        
        if(this->head != NULL)
            this->head->prev = node;
    
        this->head = node;
    }
    
    int get(int key) {
        if(hashtable.find(key) != hashtable.end()) {
            DoublyLinkedNode* node = hashtable.find(key)->second;
            moveToHead(node);
            return node->value;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        DoublyLinkedNode* node;
        if(hashtable.find(key) == hashtable.end()) { //not in hashtable
            node = new DoublyLinkedNode(key, value);
            hashtable.insert(pair<int, DoublyLinkedNode*>(key, node));
        } else { //update if already in table
            node = hashtable.find(key)->second;
            node->value = value;
            
            //update tail
            if(this->tail == node) //if this node is current tail
                this->tail = node->prev; //prev node becomes new tail
            
            this->count++;
        }
        
        moveToHead(node);
        
        if(this->count == 2)
            this->tail = node->next;
            
        if(count > capacity) {
            hashtable.erase(tail->key);
            this->tail->prev->next = NULL;
            this->tail = tail->prev;
        }
    }
};

int main(int argv, char** argc) {
	Cache* cache = new Cache(2);

	cout << "cache.put(1,1)" << endl;
	cache->put(1, 1);
	cout << "cache.put(2,2)" << endl;
	cache->put(2, 2);
	cout << "cache.get(1): " << cache->get(1) << endl;
	cout << "cache.put(3,3)" << endl;
	cache->put(3, 3);
	cout << "cache.get(2): " << cache->get(2) << endl;	
	cout << "cache.put(4,4)" << endl;
	cache->put(4, 4);
	cout << "cache.get(1): " << cache->get(1) << endl;
	cout << "cache.get(3): " << cache->get(3) << endl;
	cout << "cache.get(4): " << cache->get(4) << endl;
}
