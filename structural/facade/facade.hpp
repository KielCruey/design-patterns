#include <queue>

// =========== Subsystem Helper Classes ===========
class Waiter
{
public:
    Waiter();
    ~Waiter();

    void CleansTable();
    void PlacesUtensils();
    void GivesMenu();
    void ReceivesCustomerOrders();
    void WritesOrder();
    void SendsOrderToKitchen();
    void ServesCustomers();
    void GivesBill();    
};

class Chef
{
public:
    Chef();
    ~Chef();

    void PreparesFood();
    void CutsFood();
    void CooksFood();
    void PlatesFood();
    void OrderReady();
    void WashesDishes();
};

// =========== Subsystem(s) ===========
class FrontOfHouse
{   
public:
    FrontOfHouse(Waiter * waiter = nullptr);
    ~FrontOfHouse();

    void WritesReserveTime();
    void SeatsGuests(int number);
    void ReceivesBill();

    // ------ getters/setters ------
    inline Waiter* GetWaiter() const;
    inline void SetWaiter(Waiter* waiter);

private:
    Waiter * waiter;
};

class BackOfHouse
{
public:
    BackOfHouse(Chef * chef = nullptr);
    ~BackOfHouse();

    void ReceivesOrder();
    void CallsWaiter();

    // ------ getters/setters ------
    inline Chef* GetChef() const;
    inline void SetChef(Chef* chef);

private:
    Chef * chef;
};

class Customer
{
public:
    Customer();
    ~Customer();

    void CallsForReservation();
    void EntersRestaurant();
    void GoesToTable();
    void PlacesFoodOrder();
    void StartsEating();
    void FinishesEating();
    void PaysBill();
    void LeavesTable();
    void LeavesRestaurant();
    void RatesRestaurantReview();
};

// =========== Facade ===========
// The facade class provides a simple interface for helping/supporting other subsystems.
// Think of the facade class to implements/orchestrates the subsystems functions together in a easy fashion.
class RestaurantFacade
{
public:
    RestaurantFacade(FrontOfHouse * frontOfHouse = nullptr,
                     BackOfHouse * backOfHouse = nullptr);
    ~RestaurantFacade();

    void ChecksForReservation(Customer* customer);
    void SeatsCustomers(int number);
    void RequestsCustomersOrder(Customer* customer);
    void CreateOrder();
    void CustomerConsumes(Customer* customer);
    void CustomerCheckout(Customer* customer);
    void ThankCustomers(Customer* customer);

    // ---- modifying customer queue ----
    void AddCustomer(Customer * customer);
    void RemoveCustomer();

    // ----- getters/setters -----
    inline FrontOfHouse* GetFrontOfHouse() const;
    inline BackOfHouse* GetBackOfHouse() const;
    inline std::queue<Customer*> GetCustomerQueue() const;

    inline void SetFrontOfHouse(FrontOfHouse* frontOfHouse);
    inline void SetBackOfHouse(BackOfHouse* backOfHouse);
    inline void SetCustomerQueue(std::queue<Customer*> customerQueue);

protected:
    FrontOfHouse * frontOfHouse;
    BackOfHouse * backOfHouse;

    std::queue<Customer*> customerQueue;
};

#include "facade.inl"