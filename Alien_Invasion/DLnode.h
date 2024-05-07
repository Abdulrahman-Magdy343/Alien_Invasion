
template<class T>
class DLnode {
	DLnode<T>* next;
	DLnode<T>* prev;
	T item;
public:
	DLnode()
	{
		next = prev = nullptr;
	}

	DLnode(const T& r_Item)
	{
		item = r_Item;
		next = nullptr;
		prev = nullptr;
	}

	void setItem(const T& r_Item)
	{
		item = r_Item;
	}

	void setNext(DLnode<T>* nextNodePtr)
	{
		next = nextNodePtr;
	}
	
	void setPrev(DLnode<T>* prevNodePtr)
	{
		prev = prevNodePtr;
	}

	T getItem() const
	{
		return item;
	}

	DLnode<T>* getNext() const
	{
		return next;
	}

	DLnode<T>* getPrev() const
	{
		return prev;
	}
};