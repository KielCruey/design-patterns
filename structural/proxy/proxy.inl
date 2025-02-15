// ======= Time =======
inline int Time::GetDay() const {
	return this->day;
}

inline int Time::GetMonth() const {
	return this->month;
}

inline int Time::GetYear() const {
	return this->year;
}

inline void Time::SetDay(int day) {
	this->day = day;
}

inline void Time::SetMonth(int month) {
	this->month = month;
}

inline void Time::SetYear(int year) {
	this->year = year;
}

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

inline void CreditCardOwnerData::SetSecurityCode(int securityCode) {
	this->securityCode = securityCode;
}

inline void CreditCardOwnerData::SetCardNumber(int cardNumber) {
	this->cardNumber = cardNumber;
}

inline void CreditCardOwnerData::SetFirstName(std::string firstName) {
	this->firstName = firstName;
}

inline void CreditCardOwnerData::SetLastName(std::string lastName) {
	this->lastName = lastName;
}

inline void CreditCardOwnerData::SetCompany(std::string companyName) {
	this->companyName = companyName;
}

// ======= CreditCardData =======
inline bool CreditCardData::GetisPaymentAuthenticated() const { 
	return this->isPaymentAuthenticated; 
}

inline int CreditCardData::GetValidMonth() const { 
	return this->validMonth;
}

inline int CreditCardData::GetValidYear() const { 
	return this->validYear;
}

inline int CreditCardData::GetSecurityCode() const { 
	return this->securityCode;
}

inline int CreditCardData::GetCardNumber() const { 
	return this->cardNumber;
}

inline std::string CreditCardData::GetFirstName() const { 
	return this->firstName;
}

inline std::string CreditCardData::GetLastName() const { 
	return this->lastName;
}

inline std::string CreditCardData::GetCompany() const { 
	return this->companyName;
}

inline void CreditCardData::SetisPaymentAuthenticated(bool isPaymentAuthenticated) { 
	this->isPaymentAuthenticated = isPaymentAuthenticated; 
}

inline void CreditCardData::SetValidMonth(int validMonth) { 
	this->validMonth = validMonth; 
}

inline void CreditCardData::SetValidYear(int validYear) { 
	this->validYear = validYear; 
}

inline void CreditCardData::SetSecurityCode(int securityCode) { 
	this->securityCode = securityCode; 
}

inline void CreditCardData::SetCardNumber(int cardNumber) { 
	this->cardNumber = cardNumber; 
}

inline void CreditCardData::SetFirstName(std::string firstName) { 
	this->firstName = firstName; 
}

inline void CreditCardData::SetLastName(std::string lastName) { 
	this->lastName = lastName; 
}

inline void CreditCardData::SetCompany(std::string companyName) {
	this->companyName = companyName; 
}

// ======= Cash =======
inline double Cash::GetPaymentBalance() const {
	return this->paymentBalance;
}

inline double Cash::GetPaymentTotal() const {
	return this->paymentTotal;
}

inline void Cash::SetPaymentBalance(double paymentBalance) {
	this->paymentBalance = paymentBalance;
}

inline void Cash::SetPaymentTotal(double paymentTotal) {
	this->paymentTotal = paymentTotal;
}

// ======= Credit Card =======
inline Cash* CreditCard::GetCash() const {
	return this->cash;
}

inline CreditCardData* CreditCard::GetCreditCardData() const {
	return this->creditCardData;
}

inline Time* CreditCard::GetTime() {
	return this->time;
}

inline void CreditCard::SetCash(Cash* cash) {
	this->cash = cash;
}

inline void CreditCard::SetCreditCardData(CreditCardData* creditCardData) {
	this->creditCardData = creditCardData;
}

inline void CreditCard::SetTime(Time* time) {
	this->time = time;
}