// =========== Abstract Iterator ===========
class AbstractIterator
{
public:
	virtual ~AbstractIterator();

	virtual void first() = 0;
	virtual void next() = 0;
	virtual void hasNext() = 0;
	virtual void current() = 0;
};

class LinkedListIterator
{
public:
	virtual ~LinkedListIterator();
};

// =========== Abstract Collection ===========
class AbstractCollection
{
public:
	virtual ~AbstractCollection();

	virtual void addItem() = 0;
	virtual void removeItem() = 0;
	virtual bool isEmpty() = 0;
};

class LinkedList : AbstractCollection
{
public:
	virtual ~LinkedList();
};

