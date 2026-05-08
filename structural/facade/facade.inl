// ======== FrontOfHouse ========
inline Waiter *FrontOfHouse::GetWaiter() const { return this->waiter; }

// ======== BackOfHouse ========
inline Chef *BackOfHouse::GetChef() const { return this->chef; }

// ======== RestaurantFacade ========
inline FrontOfHouse *RestaurantFacade::GetFrontOfHouse() const {
  return this->frontOfHouse;
}

inline BackOfHouse *RestaurantFacade::GetBackOfHouse() const {
  return this->backOfHouse;
}

inline std::queue<Customer *> RestaurantFacade::GetCustomerQueue() const {
  return this->customerQueue;
}