// ====== interface observer (subscriber) ======
class SubscriptionManager
{
public:
	SubscriptionManager();
	virtual ~SubscriptionManager();

	virtual void update() = 0;
};

// ====== interface publisher (subject) ======
class PublisherManager
{
public:
	PublisherManager();
	~PublisherManager();

	SubscriptionManager* subManager;

	virtual void attach(SubscriptionManager* observer) = 0; // adds to the list of items to update
	virtual void detach(SubscriptionManager* observer) = 0; // removes to the list of times to update
	virtual void notify() = 0;
};

// ===== concrete publisher (subject) ======
class NewPaperPublisher : public PublisherManager
{
public:
	NewPaperPublisher();
	~NewPaperPublisher();

	SubscriptionManager* subManager;

	virtual void attach(SubscriptionManager* observer) = 0; // adds to the list of items to update
	virtual void detach(SubscriptionManager* observer) = 0; // removes to the list of times to update
	virtual void notify() = 0;
};

class WebsitePublisher : public PublisherManager
{
public:
	WebsitePublisher();
	~WebsitePublisher();

	SubscriptionManager* subManager;

	virtual void attach(SubscriptionManager* observer) = 0; // adds to the list of items to update
	virtual void detach(SubscriptionManager* observer) = 0; // removes to the list of times to update
	virtual void notify() = 0;
};

// ===== concrete observer (subscriber) ======
class PaperObserver : public SubscriptionManager
{
public:
	PaperObserver();
	virtual ~PaperObserver();

	virtual void update() override;
};

class OnlineObserver : public SubscriptionManager
{
public:
	OnlineObserver();
	virtual ~OnlineObserver();

	virtual void update() override;
};

