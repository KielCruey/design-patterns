#include <string>
#include <iostream>
#include <iomanip> // setprecision
#include <chrono>

class Time {
public:
	Time();
	~Time();

	inline int GetYear() const;
	inline void SetDay(int day);
	inline void SetMonth(int month);
	inline void SetYear(int year);

private:
	int day;
	int month;
	int year;
};

class CreditCardOwnerData
{
public:
	explicit CreditCardOwnerData(int securityCode = 0,
						int cardNumber = 0,
						const std::string& firstName = nullptr,
						const std::string& lastName = nullptr,
						const std::string& companyName = nullptr);
	~CreditCardOwnerData();

	inline int GetSecurityCode() const;
	inline int GetCardNumber() const;
	inline std::string GetFirstName() const;
	inline std::string GetLastName() const;
	inline std::string GetCompanyName() const;

	inline void SetSecurityCode(int securityCode);
	inline void SetCardNumber(int cardNumber);

private: 
	int securityCode;
	int cardNumber;
	std::string firstName;
	std::string lastName;
	std::string companyName; // what company the credit card was issued from
};

// ========== Helper Classes ==========
class CreditCardData
{
public:
	explicit  CreditCardData(bool isPaymentAuthenticated = false,
					int validMonth = 0,
					int validYear = 0,
					int securityCode = 0,
					int cardNumber = 0,
					const std::string& firstName = nullptr,
					const std::string& lastName = nullptr,
					const std::string& companyName = nullptr);
	~CreditCardData();

	inline int GetValidMonth() const;
	inline int GetValidYear() const;
	inline int GetSecurityCode() const;
	inline int GetCardNumber() const;
	inline std::string GetFirstName() const;
	inline std::string GetLastName() const;
	inline std::string GetCompany() const;

	inline void SetSecurityCode(int securityCode);
	inline void SetCardNumber(int cardNumber);

private:
	bool isPaymentAuthenticated;
	int validMonth;
	int validYear;
	int securityCode;
	int cardNumber;
	std::string firstName;
	std::string lastName;
	std::string companyName; // what company the credit card was issued from
};

// ======= Subject =======
class PaymentType
{
public:
	virtual ~PaymentType() {};
	virtual double CheckBalance() = 0;
	virtual double PayAmount(double payment, Time * time, CreditCardOwnerData * creditCardOwnerData) = 0;
};

// ======= Real Subject =======
class Cash : public PaymentType
{
public:
	explicit Cash(double paymentBalance = 0.0, 
			double paymentTotal = 0.0);
	~Cash() override;

	double CheckBalance() override;
	double PayAmount(double payment, Time * time, CreditCardOwnerData * creditCardOwnerData) override;

	inline double GetPaymentBalance() const;

	inline void SetPaymentBalance(double paymentBalance);

private:
	double paymentBalance;
	double paymentTotal;
};

// ======= Proxy =======
class CreditCard : public PaymentType
{
public:
	explicit CreditCard(Cash const* cash = nullptr,
				CreditCardData* creditCardData = nullptr,
				Time* time = nullptr);
	~CreditCard() override;

	CreditCard(const CreditCard& creditCard); // copy constructor
	CreditCard& operator= (const CreditCard& creditCard); // copy assignment

	double CheckBalance() override;
	double PayAmount(double payment, Time * time, CreditCardOwnerData * creditCardOwnerData) override;

protected:
	inline Cash * GetCash() const;
	inline CreditCardData * GetCreditCardData() const;

	Cash * cash; // credit card is used to pay cash as payment
	CreditCardData * creditCardData;
	Time * time; // 

private:
	bool CheckPaymentAuthentication(CreditCardData const* creditCardData, Time const* time, CreditCardOwnerData const* creditCardOwnerData);
	bool CheckValidMonth(CreditCardData const* creditCardData, CreditCardOwnerData const* creditCardOwnerData);
	bool CheckValidYear(CreditCardData const* creditCardData, Time const* time, CreditCardOwnerData const* creditCardOwnerData);
	bool CheckSecurityCode(CreditCardData const* creditCardData, CreditCardOwnerData const* creditCardOwnerData);
	bool CheckCardNumber(CreditCardData const* creditCardData, CreditCardOwnerData const* creditCardOwnerData);
	bool CheckFirstName(CreditCardData const* creditCardData, CreditCardOwnerData const* creditCardOwnerData);
	bool CheckLastName(CreditCardData const* creditCardData, CreditCardOwnerData const* creditCardOwnerData);
	bool CheckCompanyName(CreditCardData const* creditCardData, CreditCardOwnerData const* creditCardOwnerData);
};

#include "proxy.inl"