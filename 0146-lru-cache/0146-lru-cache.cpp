class LRUCache {
public:

    //doubly linked list  
    class Node{
   public: 
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key, int val){
            this->key=key;
            this->val=val;
        }

      };

      //unordered map to tell if the key and addres is present in the LRU Cache
      unordered_map<int, Node*> mpp;
      Node* head = new Node(-1,-1);
      Node* tail = new Node(-1,-1);


    int cap;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        
    }

    void addNode(Node* newNode){
        Node* temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
        
        
    }

    void deleteNode(Node* delNode){
        Node* delprev=delNode->prev;
        Node* delnext=delNode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
     
    }
    
    int get(int key) {
        // if the key is there
        if(mpp.find(key)!=mpp.end()){
            Node* res = mpp[key];
            mpp.erase(key);
            deleteNode(res);
            addNode(res);
            mpp[key]=head->next;

            return res->val;
        }
        return -1;
        
    }
    
    void put(int key, int val) {
        // if the node key value is already present in the cache
        if(mpp.find(key)!=mpp.end()){
            Node* putNode = mpp[key];
            mpp.erase(key);
            deleteNode(putNode);
           
        }
        if(mpp.size()==cap){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node* newNode = new Node(key,val);

        addNode(newNode);
        mpp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */