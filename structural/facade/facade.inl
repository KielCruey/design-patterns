// ======== FrontOfHouse ========
inline Waiter* FrontOfHouse::GetWaiter() const {
    return this->waiter;
}

inline void FrontOfHouse::SetWaiter(Waiter* waiter) {
    this->waiter = waiter;
}

// ======== BackOfHouse ========
inline Chef* BackOfHouse::GetChef() const {
    return this->chef;
}

inline void BackOfHouse::SetChef(Chef* chef) {
    this->chef = chef;
}

// ======== RestaurantFacade ========
inline FrontOfHouse* RestaurantFacade::GetFrontOfHouse() const {
    return this->frontOfHouse;
}

inline BackOfHouse* RestaurantFacade::GetBackOfHouse() const {
    return this->backOfHouse;
}

inline std::queue<Customer*> RestaurantFacade::GetCustomerQueue() const {
    return this->customerQueue;
}

inline void RestaurantFacade::SetFrontOfHouse(FrontOfHouse* frontOfHouse) {
    this->frontOfHouse = frontOfHouse;
}

inline void RestaurantFacade::SetBackOfHouse(BackOfHouse* backOfHouse) {
    this->backOfHouse = backOfHouse;
}

inline void RestaurantFacade::SetCustomerQueue(std::queue<Customer*> customerQueue) {
    this->customerQueue = customerQueue;
}
