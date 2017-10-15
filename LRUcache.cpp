#include <iostream>
#include <unordered_map>

using namespace std;

struct Entry {
  int value;
  Entry* next;
  Entry* prev;
 
  Entry(int val) {
    this->value = val;
    this->next = NULL;
    this->prev = NULL;
  }
};
 
struct Cache {
  Entry* LRU;
  Entry* tail;
	int capacity;
 
  unordered_map<int, Entry*> hashtable;	
 
  Cache(int n) {
    this->capacity = n;
		LRU = NULL;
    tail = NULL;
  }

  void update(int val) {
    // if new element
    if(hashtable.find(val) == hashtable.end()) {
      Entry* newEntry = new Entry(val);
			hashtable.insert(pair<int,Entry*>(val,newEntry));
      
      if(!tail) tail = newEntry;
      else if(!tail->prev) tail->prev = newEntry;

      // drop tail if oversized
      if(hashtable.size() > capacity) {
        Entry* oldTail = tail;

        tail = tail->prev;

        hashtable.erase(oldTail->value);

        delete(oldTail);
      }

      // attach new entry to head (LRU)
      newEntry->next = LRU;
      if(LRU)
        LRU->prev = newEntry;
			LRU = newEntry;
    } else { //if old element
      Entry* oldEntry = hashtable[val];

      if(oldEntry->prev)
        oldEntry->prev->next = oldEntry->next;
      else
        LRU = oldEntry->next;
      if(oldEntry->next)
        oldEntry->next->prev = oldEntry->prev;
      else
        tail = oldEntry->prev;

      oldEntry->next = LRU;
      oldEntry->prev = NULL;
      
      LRU = oldEntry;
    }
  }
 
  void printEntries() {
    Entry* currentEntry = LRU;
    cout << "Entries: ";
int count = 5;
    while(currentEntry && count) {
      cout << currentEntry->value << " ";
      currentEntry = currentEntry->next;
count--;
    }
    cout << endl;
  }
};


int main(int argv, char** argc) {
  cout << "Cache size? ";
  int size;
  cin >> size;
  Cache* cache = new Cache(size);

  int input;
  while(true) {
    cout << "value: ";
    cin >> input;
		if(!input) return 0;

    cache->update(input);
    cache->printEntries();
  }
}
