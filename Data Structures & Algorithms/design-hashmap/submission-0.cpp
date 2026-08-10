class MyHashMap {
private:
    vector<int>keys;
    vector<int>values;
public:
    MyHashMap()
    {
        keys.resize(1000001,0);
        values.resize(1000001,-1);
    }
    
    void put(int key, int value)
    {
        if(keys[key])
        {
            values[key]=value;
        }
        else
        {
            keys[key]=1;
            values[key]=value;
        }
    }
    
    int get(int key)
    {
        return values[key];    
    }
    
    void remove(int key)
    {
        values[key]=-1;
        keys[key]=0;    
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */