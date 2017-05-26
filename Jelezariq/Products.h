/*
 * Products.h
 *
 *  Created on: 25.05.2017 ã.
 *      Author: Venci
 */

#ifndef PRODUCTS_H_
#define PRODUCTS_H_
#include <string>

using namespace std;

class Products {
public:
	Products();
	Products(int records, string name, int count, double cost);

	virtual ~Products();
	double getCost() const;
	void setCost(double cost);
	int getCount() const;
	void setCount(int count);
	const string& getName() const;
	void setName(const string& name);
	int getRecords() const;
	void setRecords(int records);

	void prin();

private:
	int records;
	string name;
	int count;
	double cost;
};

#endif /* PRODUCTS_H_ */
