/******************************************
This file contains helper function need for
simplified operations(receiving orders,
shipping, deliveries)
******************************************/
// System headers
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <climits>
// User headers

#include "Order.h"
#include "ReadFiles.h"
using std::string;
using std::vector;
int getRandom(int low, int high);
string genOrderID(int low, int high);
string forCustomer(const vector<string>& customers);
string getShippingSpeed(const vector<string>& shippingSpeeds);
string getRandomCourier(const vector<string>& couriers);
int getPriority(string speed, const vector<string>& shippingSpeeds);
void update_order_age(vector<Order>& vecOrders);
void print_stats(const int& day, const vector<Order> vecOrders, const int& new_orders, const int& orders_shipped, const int& orders_delivered);
void print_all_days_report(const int& days, const int& events, const vector<Order>& vecOrders,
	const int& total_orders_delivered, const int& total_orders_shipped);
///////////////		END OF SOURCE FILE	/////////////////////
