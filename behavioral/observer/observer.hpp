// ====== publisher - the subject ======
class NewsPaperCompany
{
public:
	NewsPaperCompany();
	~NewsPaperCompany();

	SubscriptionManager* subManager;
};

// ====== interface subscriber - the dependent class ======
class SubscriptionManager
{
public:
	SubscriptionManager();
	virtual ~SubscriptionManager();
};

// ====== concrete subscriber ======
class PaperSubscriber : public SubscriptionManager
{
public:
	PaperSubscriber();
	virtual ~PaperSubscriber();
};

class OnlineSubscriber : public SubscriptionManager
{
public:
	OnlineSubscriber();
	virtual ~OnlineSubscriber();
};