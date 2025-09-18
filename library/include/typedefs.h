//
// Created by hania on 06.06.2024.
//

#ifndef APTEKA_TYPEDEFS_H
#define APTEKA_TYPEDEFS_H
#include <memory>
#include <functional>

class Client;
class Address;
class Order;
class Product;
class ClientType;
class ClientRepository;
class OrderRepository;
class ProductRepository;
class ClientManager;
class OrderManager;
class ProductManager;
class DefaultClient;
class RetiredClient;

typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<Order> OrderPtr;
typedef std::shared_ptr<Product> ProductPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;

typedef std::function<bool(const ClientPtr&)> ClientPredicate;
typedef std::function<bool(const OrderPtr&)> OrderPredicate;

typedef std::shared_ptr<DefaultClient> DefaultClientPtr;
typedef std::shared_ptr<RetiredClient> RetiredClientPtr;

typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;
typedef std::shared_ptr<OrderRepository> OrderRepositoryPtr;


typedef std::shared_ptr<ClientManager> ClientMenagerPtr;
typedef std::shared_ptr<OrderManager> OrderMenagerPtr;

#endif //APTEKA_TYPEDEFS_H
