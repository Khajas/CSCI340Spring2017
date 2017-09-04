//		ASSIGNMENT ON HEAP, covers make_heap(), sort()
// User defined header for helper functions
#include "HelperFunctions.h"
/***
	The !dea is to use a heap to prioritize the orders for shipping & deliveries
***/

	/*********	TAKING A NEW ORDER	**************/
//	The following function takes a new order
// To radomize the ordering process, it uses various functions from HelperFunctions.h
//
int take_new_order(vector<Order>& vecOrders, const vector<string>& customers, const vector<string>& shippingSpeeds);
	/*********	SHIPPING ORDERS BASED ON SHIP PRIORITY & ORDER AGE	*******/
//	Comparator for shipping priority
// An order is prioritize for shipping if it needs_shipping() & based on its shipping speed & age
// priority function f = shipping priority + days since the order is placed
bool sortShip(const Order& a, const Order& b);
// We ship the order, mark it as shipped, dispay the details, increase the prioroty
// increment the count and sort the heap.
int ship_orders(vector<Order>& vecOrders, const vector<string>& couriers);
	/*********      DELIVERING ORDERS BASED ON SHIP PRIORITY & ORDER AGE      *******/
//      Comparator for deliveries priority
// An order is prioritize for delivery if needs_delivery() & based on its age
// priority function f = days since the order is shipped
// We may not use ship priority here since we're increasing the ship_priority after shipping it
bool sortDelivery(const Order& a, const Order& b);
// We deliver the order, mark it as delivered, dispay the details & duration(early, ontime, delayed),
// increase the max age, increment the count and sort the heap.
int deliver_orders(vector<Order>& vecOrders);
///////////////////	END OF SOURCE FILE	/////////////////////////////
