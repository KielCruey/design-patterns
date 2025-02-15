// Visitor is used when we have to perform an operation on a group of similar kind of objects
// With the help of visitor pattern, we can move the operational logic from the objects to another class.

// The visitor pattern consists of two parts :
// 1) a method called Visit() which is implemented by the visitor and is called for every element in the data structure
// 2) visitable classes providing Accept() methods that accept a visitor

// https://www.modernescpp.com/index.php/the-visitor-pattern/

class Visitor;

// ========== Abstract Element ==========
class Stock {
public: 
	virtual ~Stock() = default;

	virtual void accept(StockVisitor * stockVisitor) = 0;
};


// class should only consist of the AbstractElement's implementation
// ========== Concrete Element ==========
class Nvidia : public Stock
{
public:
	void accept(StockVisitor * stockVisitor) override;
};

class Intel : public Stock
{
public:
	void accept(StockVisitor * stockVisitor) override;
};

// ========== Abstract Visitor ==========
class StockVisitor
{
public:
	virtual ~StockVisitor() = default;

	virtual void visit(Nvidia * nvidia) = 0;
	virtual void visit(Intel * intel) = 0;
};

// ========== Abstract Visitor ==========
class BuyVisitor : public StockVisitor
{
public:
	void visit(Nvidia * nvidia) override;
	void visit(Intel * intel) override;
};

class SellVisitor : public StockVisitor
{
public:
	void visit(Nvidia * nvidia) override;
	void visit(Intel * intel) override;
};