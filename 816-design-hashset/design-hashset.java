class MyHashSet {
    // Array size is max key + 1 (0 to 1,000,000 inclusive)
    private boolean[] set; 

    /** Initialize your data structure here. */
    public MyHashSet() {
        set = new boolean[1000001];
    }
    
    public void add(int key) {
        set[key] = true;
    }
    
    public void remove(int key) {
        set[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        return set[key];
    }
}