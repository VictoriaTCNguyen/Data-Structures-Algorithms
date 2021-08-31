template< class Item > 
class pq_zero {
private:
  vector<Item> heap; // The heap expands/shrinks to fit data
  typedef int indx;  // index with heap
  map<Item,indx> index;  // records each Item's place in heap
  map<Item,float> priority; // records each Item's priority
  void percolate_up( indx i ); 
  void percolate_down( indx i );
public: 
  // These use the min-heap functions above.
  int size( ) const;
  bool empty( ) const;
  const Item& top( ) const;
  void pop( );
  void push( const Item& w, float prio );
};