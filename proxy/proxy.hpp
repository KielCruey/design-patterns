#include <string>
#include <iostream>
#include <iomanip> // setprecision
#include <chrono>


// ========== Helper Classes ==========
class CreditCardData
{
public:
	CreditCardData(bool isPaymentAuthenticated = NULL,
					int validMonth = NULL,
					int validYear = NULL,
					int securityCode = NULL,
					int cardNumber = NULL,
					std::string firstName = nullptr,
					std::string lastName = nullptr,
					std::string companyName = nullptr);
	~CreditCardData();

	bool GetisPaymentAuthenticated() const { return isPaymentAuthenticated; }
	int GetValidMonth() const { return validMonth; }
	int GetValidYear() const { return validYear; }
	int GetSecurityCode() const { return securityCode; }
	int GetCardNumber() const { return cardNumber; }
	std::string GetFirstName() const { return firstName; }
	std::string GetLastName() const { return lastName; }
	std::string GetCompany() const { return companyName; }

	void SetisPaymentAuthenticated(bool isPaymentAuthenticated) { this->isPaymentAuthenticated = isPaymentAuthenticated; }
	void SetValidMonth(int validMonth) { this->validMonth = validMonth; }
	void SetValidYear(int validYear) { this->validYear = validYear; }
	void SetSecurityCode(int securityCode) { this->securityCode = securityCode; }
	void SetCardNumber(int cardNumber) { this->cardNumber = cardNumber; }
	void SetFirstName(std::string firstName) { this->firstName = firstName; }
	void SetLastName(std::string lastName) { this->lastName = lastName; }
	void SetCompany(std::string companyName) { this->companyName = companyName; }

private:
	bool isPaymentAuthenticated;
	int validMonth;
	int validYear;
	int securityCode;
	int cardNumber;
	std::string firstName;
	std::string lastName;
	std::string companyName;
};

// ======= Subject =======
class PaymentType
{
public:
	virtual ~PaymentType() {};
	virtual double CheckBalance() = 0;
	virtual double PayAmount(double payment) = 0;
};

// ======= Real Subject =======
class Cash : public PaymentType
{
public:
	Cash(double paymentBalance = NULL, 
			double paymentTotal = NULL);
	~Cash() override;

	double CheckBalance() override;
	double PayAmount(double payment) override;

	double GetPaymentBalance() const;
	double GetPaymentTotal() const;
	void SetPaymentBalance(double paymentBalance);
	void SetPaymentTotal(double paymentTotal);

private:
	double paymentBalance;
	double paymentTotal;
};

// ======= Proxy =======
class CreditCard : public PaymentType
{
public:
	CreditCard(Cash * cash = nullptr, 
				CreditCardData * creditCardData = nullptr);
	~CreditCard() override;
	CreditCard(const CreditCard& creditCard); // copy constructor -- for deep copy
	CreditCard& operator= (const CreditCard& creditCard); // assignment operator -- for deep copy


	double CheckBalance() override;
	double PayAmount(double payment) override;

	bool CheckPaymentAuthentication(CreditCardData* creditCardData);

	bool CheckValidMonth(CreditCardData* creditCardData);
	bool CheckValidYear(CreditCardData* creditCardData);
	bool CheckSecurityCode(CreditCardData* creditCardData);
	bool CheckCardNumber(CreditCardData* creditCardData);
	bool CheckFirstName(CreditCardData* creditCardData);
	bool CheckLastName(CreditCardData* creditCardData);
	bool CheckCompanyName(CreditCardData* creditCardData);

	Cash * GetCash() const;
	CreditCardData* GetCreditCardData() const;
	void SetCash(Cash * cash);
	void SetCreditCardData(CreditCardData * creditCardData);

private:
	Cash * cash; // credit card is used to pay cash as payment
	CreditCardData * creditCardData;
};