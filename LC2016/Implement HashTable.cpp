//
//  Implement HashTable.cpp
//  LC2016
//
//  Created by Fang Liu on 4/2/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Hash Table
 Hash Table is one implementtation of dictionary. It maps unique keys to associated values. It is an array based data structure, which uses hash function to convert the key into the index of an array element, where associated value could be found. 
 
 Collisions
 When hash function returns the same hash value for different keys, it cause collision. 
 
 Closed addressing (open hashing)
 Each slot of the hash table contains a link to another data structure(linked list), which stores key-value pairs with the same hash. When collision occures, this data struecture is searched for key-value pair, which matches the key.
 
 Open addressing (closed hashing)
 Each slot actually contains a key-value pair. When collision occurs, open addressing algorithm calculates another location (next one) to locate a free slot.
 */

#include <iostream>
using namespace std;

// hash table collisioin resolution by chaining
/*
 Each slot of the array contains a link to a single linked list containing key-value pairs with the same hash.
 New key-value pairs are added to the end of the list.
 Lookup algorithm searches through the list to find matching key.
 Initially table slots contain NULL.
 List is being created, when value with the certain hash is added for the first time.
 */

// 包含三个元素：int型key/value, 指针 *next
// get/set key/value/next
class HashNode{
private:
    int key;
    int value;
    HashNode* next;
public:
    HashNode(int _key, int _value):key(_key), value(_value), next(NULL){}
    int getKey(){
        return key;
    }
    int getValue(){
        return value;
    }
    HashNode* getNext(){
        return next;
    }
    void setValue(int v){
        value = v;
    }
    void setNext(HashNode* _next){
        next = _next;
    }
};

const int TABLE_SIZE = 128;

// 注意，这里hash table只包含一个table
class HashTable{
private:
    HashNode** table;
public:
    HashTable();
    ~HashTable();
    int get(int _key);
    void insert(int _key, int _value);
    void remove(int _key);
};

HashTable::HashTable(){
    table = new HashNode*[TABLE_SIZE];
    for(int i=0; i<TABLE_SIZE; ++i){
        table[i] = NULL;
    }
}

int HashTable::get(int _key){
    int hash = _key % TABLE_SIZE; // hash function
    if(table[hash] == NULL){
        return -1;
    }else{
        HashNode* entry = table[hash];
        while(entry != NULL && entry->getKey() != _key){
            entry = entry->getNext();
        }
        if(entry == NULL){
            return -1;
        }else{
            return entry->getValue();
        }
    }
}

/*
 之前的做法都是把冲突结点放在listlist最后，现在把它放入开头，节省时间
 1. 根据hash function找到hash entry
 2. 创建新的new LinkedHashEntry(_key, _value)
 3. 将新结点插入LinkedList开头
 
 
 2. 后移hash entry直到最后一个LinkedHashEntry
 3. 如果最后一个LinkedHashEntry的Key和_key相同，则替换之前的value为_value
 4. 如果不同，则在最后一个LinkedHashEntry的后面添加新的new LinkedHashEntry(_key, _value)
*/
void HashTable::insert(int _key, int _value){
    int hash = _key % TABLE_SIZE; // hash function
    if(table[hash] == NULL){
        table[hash] = new HashNode(_key, _value);
    }else{
        HashNode* entry = table[hash];
        while(entry->getNext() != NULL){
            entry = entry->getNext();
        }
        if(entry->getKey() == _key){
            entry->setValue(_value);
        }else{
            entry->setNext(new HashNode(_key, _value));
        }
        
    }
}

void HashTable::remove(int _key){
    int hash = _key % TABLE_SIZE;
    if(table[hash] != NULL){
        HashNode* preEntry = NULL;
        HashNode* entry = table[hash];
        while(entry->getKey() != _key && entry->getNext() != NULL){
            preEntry= entry;
            entry = entry->getNext();
        }
        if(entry->getKey() == _key){
            if(preEntry == NULL){
                table[hash] = entry->getNext();
            }else{
                preEntry->setNext(entry->getNext());
            }
            delete entry;
            entry = NULL;
        }
    }
}

HashTable::~HashTable(){
    
}