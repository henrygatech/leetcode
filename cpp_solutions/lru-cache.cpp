class LRUCache{
    struct node{
        int key, value;
        node *prev;
        node *next;
        node(){}
        node(int k, int v):key(k), value(v), prev(NULL), next(NULL){}
    };
    int capacity;
    map<int, node*> m;
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);

    void move_to_front(node *current){
        current->next=head->next;
        current->next->prev=current;
        head->next=current;
        current->prev=head;
    }

public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        node *current=m[key];
        current->prev->next=current->next;
        current->next->prev=current->prev;
        
        move_to_front(current);
        return m[key]->value;
    }
    
    void set(int key, int value) {
        if(get(key)!=-1){
            m[key]->value=value;
            return;
        }
        if(m.size()==capacity){
            node *temp=tail->prev;
            m.erase(temp->key);
            temp->prev->next=tail;
            tail->prev=temp->prev;
            delete temp;
        }
        node *newnode=new node(key,value);
        m[key]=newnode;
        move_to_front(newnode);
    }
};
