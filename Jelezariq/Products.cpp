/*
 * Products.cpp
 *
 *  Created on: 25.05.2017 ã.
 *      Author: Venci
 */

#include "Products.h"
#include <iostream>

using namespace std;

Products::Products() {
	// TODO Auto-generated constructor stub
	setRecords(0);
	setName(" ");
	setCount(0);
	setCost(0.0);
}

Products::~Products() {
	// TODO Auto-generated destructor stub
}

double Products::getCost() const {
	return cost;
}

void Products::setCost(double cost) {
	this->cost = cost;
}

int Products::getCount() const {
	return count;
}

void Products::setCount(int count) {
	this->count = count;
}

const string& Products::getName() const {
	return name;
}

void Products::setName(const string& name) {
	this->name = name;
}

int Products::getRecords() const {
	return records;
}

Products::Products(int records, string name, int count, double cost) {
	setRecords(records);
	setName(name);
	setCount(count);
	setCost(cost);
}

void Products::setRecords(int records) {
	this->records = records;
}

void Products::prin() {
	cout <<" "<< getRecords() <<"\n"<< getName() <<"\n"<< getCount() <<"\n"<< getCost() << endl;
}
