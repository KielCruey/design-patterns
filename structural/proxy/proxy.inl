// ======= Time =======
inline int Time::GetYear() const { return this->year; }

inline void Time::SetDay(int day) { this->day = day; }

inline void Time::SetMonth(int month) { this->month = month; }

inline void Time::SetYear(int year) { this->year = year; }

// ======= CreditCardOwnerData =======
inline int CreditCardOwnerData::GetSecurityCode() const {
  return this->securityCode;
}

inline int CreditCardOwnerData::GetCardNumber() const {
  return this->cardNumber;
}

inline std::string CreditCardOwnerData::GetFirstName() const {
  return this->firstName;
}

inline std::string CreditCardOwnerData::GetLastName() const {
  return this->lastName;
}

inline std::string CreditCardOwnerData::GetCompanyName() const {
  return this->companyName;
}

// ======= CreditCardData =======
inline int CreditCardData::GetValidMonth() const { return this->validMonth; }

inline int CreditCardData::GetValidYear() const { return this->validYear; }

inline int CreditCardData::GetSecurityCode() const {
  return this->securityCode;
}

inline int CreditCardData::GetCardNumber() const { return this->cardNumber; }

inline std::string CreditCardData::GetFirstName() const {
  return this->firstName;
}

inline std::string CreditCardData::GetLastName() const {
  return this->lastName;
}

inline std::string CreditCardData::GetCompany() const {
  return this->companyName;
}

// ======= Cash =======
inline double Cash::GetPaymentBalance() const { return this->paymentBalance; }

inline void Cash::SetPaymentBalance(double paymentBalance) {
  this->paymentBalance = paymentBalance;
}

// ======= Credit Card =======
inline Cash *CreditCard::GetCash() const { return this->cash; }

inline CreditCardData *CreditCard::GetCreditCardData() const {
  return this->creditCardData;
}