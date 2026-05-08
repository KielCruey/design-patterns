#include <queue>

// =========== Subsystem Helper Classes ===========
class Waiter {
public:
  Waiter();
  ~Waiter();

  static void CleansTable();
  static void PlacesUtensils();
  static void GivesMenu();
  static void ReceivesCustomerOrders();
  static void WritesOrder();
  static void SendsOrderToKitchen();
  static void ServesCustomers();
  static void GivesBill();
};

class Chef {
public:
  Chef();
  ~Chef();

  static void PreparesFood();
  static void CutsFood();
  static void CooksFood();
  static void PlatesFood();
  static void OrderReady();
  static void WashesDishes();
};

// =========== Subsystem(s) ===========
class FrontOfHouse {
public:
  explicit FrontOfHouse(Waiter *waiter = nullptr);
  ~FrontOfHouse();

  static void WritesReserveTime();
  static void SeatsGuests(int number);
  static void ReceivesBill();

  // ------ getters/setters ------
  inline Waiter *GetWaiter() const;
  inline void SetWaiter(Waiter *waiter);

private:
  Waiter *waiter;
};

class BackOfHouse {
public:
  explicit BackOfHouse(Chef *chef = nullptr);
  ~BackOfHouse();

  void ReceivesOrder();
  void CallsWaiter();

  // ------ getters/setters ------
  inline Chef *GetChef() const;
  inline void SetChef(Chef *chef);

private:
  Chef *chef;
};

class Customer {
public:
  explicit Customer();
  ~Customer();

  static void CallsForReservation();
  static void EntersRestaurant();
  static void GoesToTable();
  static void PlacesFoodOrder();
  static void StartsEating();
  static void FinishesEating();
  static void PaysBill();
  static void LeavesTable();
  static void LeavesRestaurant();
  static void RatesRestaurantReview();
};

// =========== Facade ===========
// The facade class provides a simple interface for helping/supporting other
// subsystems. Think of the facade class to implements/orchestrates the
// subsystems functions together in a easy fashion.
class RestaurantFacade {
public:
  explicit RestaurantFacade(FrontOfHouse *frontOfHouse = nullptr,
                            BackOfHouse *backOfHouse = nullptr);
  ~RestaurantFacade();

  void ChecksForReservation(Customer *customer);
  void SeatsCustomers(int number);
  void RequestsCustomersOrder(Customer *customer);
  void CreateOrder();
  void CustomerConsumes(Customer *customer);
  void CustomerCheckout(Customer *customer);
  void ThankCustomers(Customer *customer);

  // ---- modifying customer queue ----
  void AddCustomer(Customer *customer);
  void RemoveCustomer();

  // ----- getters/setters -----
  inline FrontOfHouse *GetFrontOfHouse() const;
  inline BackOfHouse *GetBackOfHouse() const;
  inline std::queue<Customer *> GetCustomerQueue() const;

protected:
  FrontOfHouse *frontOfHouse;
  BackOfHouse *backOfHouse;

  std::queue<Customer *> customerQueue;
};

#include "facade.inl"