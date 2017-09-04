// The following header for the entity order
#include<iostream>
using std::string;
class Order{
	private:
		string order_id;		// Order id for an order
		string customer_name;		// Name of the customer, the order belongs too
		int days_passed=0;		// days since the order is received
		string status;			// Status of the order(could be 'Processing', 'Shipped', 'Delivered')
		string courier_assigned;	// Courier assigned, once the order is shipped
		bool delivered_on_time;		// boolean field to know if the order is delivered on time
		string shipping_speed;		// Shipping speed choosen
		int max_age;			// Max_age(max days within which the order should be delivered, else it will marked as delayed)
		int ship_priority;		// ship priority(0  for same day, 1 for one day, 2 for two day, 3 for three day & 4 for standard delivery)
	public:
				// Constructors
		Order();
		Order(string order_id, string customer_name, string shipping_speed, int ship_priority);
		void set_order_id(string order_id);
		string get_order_id() const;
		void set_customer_name(string name);
		string get_customer_name() const;
		void set_order_status(string status);
		string get_order_status() const;
		void set_courier_assigned(string courier);
		string get_courier_assigned();
		void set_shipping_speed(string speed);
		string get_shipping_speed() const;
		void set_max_age(int m_age);
		int get_max_age() const;
		int get_ship_priority() const;
		void set_ship_priority(int p);
		void set_delivered_on_time(bool t);
		bool get_delivered_on_time();
		bool needs_shipping();
                bool needs_delivery();
                void increment_age();
                int get_order_age() const;
                void print_order();
};
///////////////////	END OF SOURCE FILE	///////////////////////
