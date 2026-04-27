#include "proxy.hpp"

// =======  =======
static void printToConsole(const std::string& toConsole) {
	std::cout << toConsole << std::endl;
}

// ======= Time =======
Time::Time() {
	std::time_t t = std::time(nullptr);
	std::tm local_tm;

	#if defined(_WIN32) || defined(_WIN64)
		localtime_s(&local_tm, &t);
	#else
		localtime_r(&t, &local_tm);
	#endif

	SetDay(local_tm.tm_mday);
	SetMonth(local_tm.tm_mon + 1); // tm_mon is 0-based
	SetYear(local_tm.tm_year + 1900); // tm_year is years since 1900

	printToConsole("Time created");
}

Time::~Time() {
	printToConsole("Time destroyed");
}

// ======= CreditCardOwnerData =======
CreditCardOwnerData::CreditCardOwnerData(int securityCode,
										 int cardNumber,
										 const std::string& firstName,
										 const std::string& lastName,
										 const std::string& companyName) :
	securityCode(securityCode),
	cardNumber(cardNumber),
	firstName(firstName),
	lastName(lastName),
	companyName(companyName)
{
	printToConsole("CreditCardOwnerData created");
}

CreditCardOwnerData::~CreditCardOwnerData() {
	printToConsole("CreditCardOwnerData destroyed");
}

// ======= CreditCardData =======
CreditCardData::CreditCardData(bool isPaymentAuthenticated,
								int validMonth,
								int validYear,
								int securityCode,
								int cardNumber,
								const std::string& firstName,
								const std::string& lastName,
								const std::string& companyName) :
	isPaymentAuthenticated(isPaymentAuthenticated),
	validMonth(validMonth),
	validYear(validYear),
	securityCode(securityCode),
	cardNumber(cardNumber),
	firstName(firstName),
	lastName(lastName),
	companyName(companyName)
{
	printToConsole("Credit Card Data created");
}

CreditCardData::~CreditCardData() {
	printToConsole("Credit Card Data destroyed");
}

// ======= Cash =======
Cash::Cash(double paymentBalance, double paymentTotal) :
	paymentBalance(paymentBalance),
	paymentTotal(paymentTotal)
{
	printToConsole("Cash created");
}

Cash::~Cash() {
	printToConsole("Cash destroyed");
}

double Cash::CheckBalance() {
	std::cout << "Balance: " << GetPaymentBalance() << std::endl;
	return this->paymentBalance;
}

double Cash::PayAmount(double payment, Time * time, CreditCardOwnerData * creditCardOwnerData) {
	double newBalance = GetPaymentBalance() - payment;

	// checks for overpayment, returns overplayment else return no overplayment value
	if (newBalance < 0) {
		newBalance = abs(newBalance);
		SetPaymentBalance(0);
		std::cout << "Over payment! Returning $" << std::setprecision(2) << newBalance << "!" << std::endl;
	}
	else {
		SetPaymentBalance(newBalance);
		printToConsole("Payment received");
	}

	return newBalance;
}

// ======= Credit Card =======
CreditCard::CreditCard(Cash const* cash, 
						CreditCardData* creditCardData, 
						Time* time) :
	cash(new Cash(*cash)),
	creditCardData(creditCardData),
	time(time)
{
	printToConsole("CreditCard created");
}

CreditCard::~CreditCard() {
	delete cash;

	printToConsole("CreditCard destroyed");
}

CreditCard::CreditCard(const CreditCard& creditCard) 
	: cash(creditCard.cash), 
	creditCardData(creditCard.creditCardData), 
	time(creditCard.time)
{ }

CreditCard& CreditCard::operator=(const CreditCard& creditCard) {
	this->cash = creditCard.cash;
	this->creditCardData = creditCard.creditCardData;
	this->time = creditCard.time;
	return *this;
}

double CreditCard::CheckBalance() {
	return GetCash()->CheckBalance();
}

double CreditCard::PayAmount(double payment, 
							 Time * time,
							 CreditCardOwnerData * creditCardOwnerData) {
	double results;

	if (CheckPaymentAuthentication(GetCreditCardData(), time, creditCardOwnerData)) {
		results = GetCash()->PayAmount(payment, time, creditCardOwnerData);
		GetCash()->SetPaymentBalance(results);
		std::cout << "Payment authenticated and processing..." << std::endl;
	}
	else {
		results = 0;
		printToConsole("Payment failed to autenticate!");
	}

	return results;
}

bool CreditCard::CheckPaymentAuthentication(CreditCardData const* creditCardData, 
											Time const* time,
											CreditCardOwnerData const* creditCardOwnerData) 
{
	if (CheckValidMonth(creditCardData, creditCardOwnerData) &&
		CheckValidYear(creditCardData, time, creditCardOwnerData) &&
		CheckSecurityCode(creditCardData, creditCardOwnerData) &&
		CheckCardNumber(creditCardData, creditCardOwnerData) &&
		CheckFirstName(creditCardData, creditCardOwnerData) &&
		CheckLastName(creditCardData, creditCardOwnerData) &&
		CheckCompanyName(creditCardData, creditCardOwnerData))
	{
		printToConsole("Success: Credit Card Payment Proccessed!");
		return true;
	}
	else {
		printToConsole("Failed: Credit Card Payment Denied!");
		return false;
	}
		
}

bool CreditCard::CheckValidMonth(CreditCardData const* creditCardData,
								 CreditCardOwnerData const* creditCardOwnerData) 
{
	if (1 <= creditCardData->GetValidMonth() &&
		creditCardData->GetValidMonth() <= 12)
	{
		return true;
	}
	else 
		return false;
}

bool CreditCard::CheckValidYear(CreditCardData const* creditCardData,
								Time const* time,
								CreditCardOwnerData const* creditCardOwnerData) 
{
	if (time->GetYear() <= creditCardData->GetValidYear()) 
		return true;
	else 
		return false;
}

bool CreditCard::CheckSecurityCode(CreditCardData const* creditCardData, 
								   CreditCardOwnerData const* creditCardOwnerData) {
	if (creditCardData->GetSecurityCode() >= 0 &&
		creditCardData->GetSecurityCode() <= 999 &&
		creditCardData->GetSecurityCode() == creditCardOwnerData->GetSecurityCode())
	{
		return true;
	}
	else 
		return false;
}

bool CreditCard::CheckCardNumber(CreditCardData const* creditCardData,
								 CreditCardOwnerData const* creditCardOwnerData) 
{
	if (creditCardData->GetCardNumber() == creditCardOwnerData->GetCardNumber())
		return true;
	else
		return false;
}

bool CreditCard::CheckFirstName(CreditCardData const* creditCardData,
								CreditCardOwnerData const* creditCardOwnerData) 
{
	if (creditCardData->GetFirstName() == creditCardOwnerData->GetFirstName())
		return true;
	else
		return false;
}

bool CreditCard::CheckLastName(CreditCardData const* creditCardData,
							   CreditCardOwnerData const* creditCardOwnerData) 
{
	if (creditCardData->GetLastName() == creditCardOwnerData->GetLastName())
		return true;
	else
		return false;
}

bool CreditCard::CheckCompanyName(CreditCardData const* creditCardData,
								  CreditCardOwnerData const* creditCardOwnerData) 
{
	if (creditCardData->GetCompany() == creditCardOwnerData->GetCompanyName())
		return true;
	else
		return false;
}

// ======= Client Code =======
static double RequestCheckBalance(PaymentType * paymentType) {
	return paymentType->CheckBalance();
}

static double PayBill(PaymentType * paymentType, double amount, Time * time, CreditCardOwnerData* creditCardOwnerData) {
	return paymentType->PayAmount(amount, time, creditCardOwnerData);
}

// overloading function to differentiate if cash is used for payment
static double PayBill(Cash * paymentType, double amount, Time * time, CreditCardOwnerData* creditCardOwnerData) {
	return paymentType->PayAmount(amount, time, creditCardOwnerData);
}

// ======= Main =======
int main() {
	Time * time = new Time();

	Cash * cash = new Cash(100.00, 500.00);
	CreditCardOwnerData * creditCardOwnerData = new CreditCardOwnerData(420, 123456, "John", "Doe", "Capital One");
	CreditCardData * creditCardData = new CreditCardData(false, 9, 2026, 420, 123456, "John", "Doe", "Capital One");
	CreditCard * creditCard = new CreditCard(cash, creditCardData, time);

	auto creditCardBalance_precheck = RequestCheckBalance(creditCard);
	auto paymentLeft = PayBill(creditCard, 30.00, time, creditCardOwnerData);
	auto creditCardBalance_check = RequestCheckBalance(creditCard);
	auto paymentRemainding = PayBill(creditCard, 60.00, time, creditCardOwnerData);
	auto creditCardBalance_postcheck = RequestCheckBalance(creditCard);

	printf("Credit Card Balance (Pre-check): %.2f\n", creditCardBalance_precheck);
	printf("Payment Left: %.2f\n", paymentLeft);
	printf("Credit Card Balance (Check): %.2f\n", creditCardBalance_check);
	printf("Payment Remaining: %.2f\n", paymentRemainding);
	printf("Credit Card Balance (Post-check): %.2f\n", creditCardBalance_postcheck);

	delete time;
	delete cash;
	delete creditCardOwnerData;
	delete creditCardData;
	delete creditCard;
	
	return 0;
}