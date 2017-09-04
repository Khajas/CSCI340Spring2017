// This header is to read data(customers, couriers, shipping speeds)
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// To read customer from customer.txt file
void readCustomerNames(std::string fileName, std::vector<std::string>& vecNames);
// To read couriers from couriers.txt
void readCourierNames(std::string fileName, std::vector<std::string>& couriers);
// To read shipping speeds from shipping_speeds.txt
void readShippingSpeeds(std::string fileName, std::vector<std::string>& shippingSpeeds);
///////////////	END OF SOURCE FILE	/////////////////////////
