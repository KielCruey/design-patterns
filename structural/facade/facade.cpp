#include <iostream>

#include "facade.hpp"

// ======== Waiter ========
Waiter::Waiter() {
    std::cout << "Waiter created" << std::endl;
}

Waiter::~Waiter() {
    std::cout << "Waiter destroyed" << std::endl;
}

void Waiter::CleansTable() {
    std::cout << "Waiter cleans tables" << std::endl;
}

void Waiter::PlacesUtensils() {
    std::cout << "Waiter places utensils down" << std::endl;
}

void Waiter::GivesMenu() {
    std::cout << "Waiter gives menus to guests" << std::endl;
}

void Waiter::ReceivesCustomerOrders() {
    std::cout << "Waiter receives food orders from guests" << std::endl;
}

void Waiter::WritesOrder() {
    std::cout << "Waiter writes down orders" << std::endl;
}

void Waiter::SendsOrderToKitchen() {
    std::cout << "Waiter sends ticket to kitchen" << std::endl;
}

void Waiter::ServesCustomers() {
    std::cout << "Waiter serves customer" << std::endl;
}

void Waiter::GivesBill() {
    std::cout << "Waiter gives bill to guests" << std::endl;
}

// ======== Chef ========
Chef::Chef() {
    std::cout << "Chef created" << std::endl;
}

Chef::~Chef() {
    std::cout << "Chef destroyed" << std::endl;
}

void Chef::PreparesFood() {
    std::cout << "Chef prepares food" << std::endl;
}

void Chef::CutsFood() {
    std::cout << "Chef cuts food" << std::endl;
}

void Chef::CooksFood() {
    std::cout << "Chef cooks food" << std::endl;
}

void Chef::PlatesFood() {
    std::cout << "Chef plates food" << std::endl;
}

void Chef::OrderReady() {
    std::cout << "'Order is Ready' the Chef yells" << std::endl;
}

void Chef::WashesDishes() {
    std::cout << "Chef washes dishes" << std::endl;
}

// ======== FrontOfHouse ========
FrontOfHouse::FrontOfHouse(Waiter* waiter) :
    waiter(waiter)
{
    std::cout << "FrontOfHouse created" << std::endl;
}

FrontOfHouse::~FrontOfHouse() {
    std::cout << "FrontOfHouse destroyed" << std::endl;
}

void FrontOfHouse::WritesReserveTime() {
    std::cout << "FrontOfHouse writes down guests reservation time" << std::endl;
}

void FrontOfHouse::SeatsGuests(int number) {
    for (int i = 0; i < number; i++) {
        std::cout << "Guest seated" << std::endl;
    }
}

void FrontOfHouse::ReceivesBill() {
    std::cout << "FrontOfHouse receives guests bill" << std::endl;
}

// ======== BackOfHouse ========
BackOfHouse::BackOfHouse(Chef * chef) :
    chef(chef)
{
    std::cout << "BackOfHouse created" << std::endl;
}

BackOfHouse::~BackOfHouse() {
    std::cout << "BackOfHouse destroyed" << std::endl;
}

void BackOfHouse::ReceivesOrder() {
    GetChef()->PreparesFood();
    GetChef()->CutsFood();
    GetChef()->CooksFood();
    GetChef()->PlatesFood();
}

void BackOfHouse::CallsWaiter() {
    GetChef()->OrderReady();
    GetChef()->WashesDishes();
}

// ======== Customer ========
Customer::Customer() {
    std::cout << "Customer created" << std::endl;
}

Customer::~Customer() {
    std::cout << "Customer destroyed" << std::endl;
}

void Customer::CallsForReservation() {
    std::cout << "Customer calls restaurant to make a reservation" << std::endl;
}

void Customer::EntersRestaurant() {
    std::cout << "Customer enters restaurant and wait for a table" << std::endl;
}

void Customer::GoesToTable() {
    std::cout << "Customer is seated" << std::endl;
}

void Customer::PlacesFoodOrder() {
    std::cout << "Customer places order" << std::endl;
}

void Customer::StartsEating() {
    std::cout << "Customer eats food" << std::endl;
}

void Customer::FinishesEating() {
    std::cout << "Customer finishes eating" << std::endl;
}

void Customer::PaysBill() {
    std::cout << "Customer pays bill" << std::endl;
}

void Customer::LeavesTable() {
    std::cout << "Customer leaves table" << std::endl;
}

void Customer::LeavesRestaurant() {
    std::cout << "Customer leaves restaurant" << std::endl;
}

void Customer::RatesRestaurantReview() {
    std::cout << "Customer reviews restaurant" << std::endl;
}

// ======== RestaurantFacade ========
RestaurantFacade::RestaurantFacade(FrontOfHouse* frontOfHouse,
                                    BackOfHouse* backOfHouse) :
    frontOfHouse(frontOfHouse),
    backOfHouse(backOfHouse)
{
    std::cout << "RestaurantFacade created" << std::endl;
}

RestaurantFacade::~RestaurantFacade() {
    std::cout << "RestaurantFacade destroyed" << std::endl;
}

void RestaurantFacade::ChecksForReservation(Customer* customer) {
    customer->CallsForReservation();
    GetFrontOfHouse()->WritesReserveTime();
    std::cout << "RestaurantFacade confirms reservation" << std::endl;
}

void RestaurantFacade::SeatsCustomers(int number) {
    // removes people from waiting queue
    for (int i = 0; i < number; i++) {
        customerQueue.front()->EntersRestaurant();
        customerQueue.front()->GoesToTable();
        RemoveCustomer();
    }

    GetFrontOfHouse()->SeatsGuests(number);
    GetFrontOfHouse()->GetWaiter()->PlacesUtensils();
    GetFrontOfHouse()->GetWaiter()->GivesMenu();
}

void RestaurantFacade::RequestsCustomersOrder(Customer * customer) {
    customer->PlacesFoodOrder();
    GetFrontOfHouse()->GetWaiter()->ReceivesCustomerOrders();
    GetFrontOfHouse()->GetWaiter()->WritesOrder();
}

void RestaurantFacade::CreateOrder() {
    GetBackOfHouse()->GetChef();
    GetFrontOfHouse()->GetWaiter()->SendsOrderToKitchen();
    GetBackOfHouse()->ReceivesOrder();
    GetBackOfHouse()->CallsWaiter();
}

void RestaurantFacade::CustomerConsumes(Customer* customer) {
    GetFrontOfHouse()->GetWaiter()->ServesCustomers();
    customer->StartsEating();
    customer->FinishesEating();
}

void RestaurantFacade::CustomerCheckout(Customer* customer) {
    GetFrontOfHouse()->GetWaiter()->GivesBill();
    customer->PaysBill();
    GetFrontOfHouse()->ReceivesBill();
}

void RestaurantFacade::ThankCustomers(Customer* customer) {
    customer->LeavesTable();
    std::cout << "Thank you! Come again." << std::endl;
    customer->LeavesRestaurant();
    GetFrontOfHouse()->GetWaiter()->CleansTable();
    customer->RatesRestaurantReview();
}

void RestaurantFacade::AddCustomer(Customer* customer) {
    GetCustomerQueue().push(customer);
}

void RestaurantFacade::RemoveCustomer() {
    GetCustomerQueue().pop();
}

// ========== Client Code ==========
Waiter * CreateWaiter() {
    return new Waiter();
}

Chef * CreateChef() {
    return new Chef();
}

Customer* CreateCustomer() {
    return new Customer();
}

void ServeCustomers(RestaurantFacade* restaurant, Customer * girlfriend, Customer* boyfriend) {
    restaurant->AddCustomer(girlfriend);
    restaurant->AddCustomer(boyfriend);

    restaurant->ChecksForReservation(girlfriend);
    restaurant->ChecksForReservation(boyfriend);

    restaurant->SeatsCustomers(2);

    restaurant->RequestsCustomersOrder(girlfriend);
    restaurant->RequestsCustomersOrder(boyfriend);

    restaurant->CreateOrder();

    restaurant->CustomerConsumes(girlfriend);
    restaurant->CustomerConsumes(boyfriend);

    restaurant->CustomerCheckout(girlfriend);
    restaurant->CustomerCheckout(boyfriend);

    restaurant->ThankCustomers(girlfriend);
    restaurant->ThankCustomers(boyfriend);
}

// ======== Main ========
int main()
{
    Waiter * waiter = CreateWaiter();
    Chef * chef = CreateChef();

    Customer * girlfriend = CreateCustomer();
    Customer * boyfriend = CreateCustomer();

    FrontOfHouse * frontOfHouse = new FrontOfHouse(waiter);
    BackOfHouse * backOfHouse = new BackOfHouse(chef);

    RestaurantFacade * restaurant = new RestaurantFacade(frontOfHouse, backOfHouse);
   
    ServeCustomers(restaurant, girlfriend, boyfriend);

    delete waiter;
    delete chef;
    delete girlfriend;
    delete boyfriend;
    delete frontOfHouse;
    delete backOfHouse;
    delete restaurant;

    return 0;
}