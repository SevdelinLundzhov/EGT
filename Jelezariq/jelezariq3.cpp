//============================================================================// Name        : jelezariq3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Products.h"
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

void createFile(fstream&);
Products* newProduct();
void addProducts(fstream&);
void updateProducts(fstream&);
void deleteRecord(fstream&);
void fillFile(fstream&);
void printFirst();
void printInfo(fstream&);

int main() {

	fstream tooldata("hardwear.dat", ios::in | ios::out | ios::binary);
	if(!tooldata)
	{
		cerr << "file could not be opened." << endl;
		tooldata.close();

		ofstream toolCreate("hardwear.dat", ios::binary);

		fillFile(tooldata);
		toolCreate.close();

		tooldata.open("hardwear.dat", ios::in | ios::out | ios::binary);

	}


	printInfo(tooldata);

	createFile(tooldata);
	tooldata.close();

	return 0;
}

void addProducts(fstream &add)
{
	Products* newProduct = new Products;
	Products oldProduct;
	add.seekg((newProduct->getRecords() - 1) * sizeof(Products));
	add.read(reinterpret_cast<char*> (&oldProduct), sizeof(Products));
	oldProduct.prin();

	if(oldProduct.getRecords() != 0)
	{
		return;
	}else{
		add.seekp((newProduct->getRecords() - 1) * sizeof(Products));
		add.write(reinterpret_cast<char*> (&oldProduct), sizeof(Products));
	}

}

void fillFile(fstream &addP)
{
	Products emptyProd;
	addP.seekp(0);

	for(int i = 0; i < 100; i++)
	{
		addP.write(reinterpret_cast<char*>(&emptyProd), sizeof(Products));
	}
}

void createFile(fstream &stream)
{
	ofstream outPrintFile("hardwear.txt");

	if(!outPrintFile)
	{
		cerr <<"file could not be created."<<endl;
		exit(1);
	}

	outPrintFile << left << setw(10) << "record: "<< setw(16) << "name "
			<< setw(11) << "count: " << right << setw(10) << "cost\n ";
	cout << "text file created." << endl;
	Products a;
	stream.seekg(0);
	stream.clear();
	while(!stream.eof())
	{
		stream.read(reinterpret_cast<char*>(&a),sizeof(Products));
		if(a.getRecords() != 0)
		{
			outPrintFile << a.getRecords() << setw(16) << a.getName() << setw(10) <<a.getCount()
					<<setw(10)<< a.getCost() << endl;
		}
	}
	outPrintFile.close();
}

void updateProducts(fstream &updateProduct)
{
	Products*  newProduct = new Products;
	updateProduct.seekg((newProduct->getRecords() - 1) * sizeof (Products));
	Products oldProd;
	updateProduct.read(reinterpret_cast<char*> (&oldProd), sizeof(Products));
	if(oldProd.getRecords() == 0)
	{
		return;
	}else{
		updateProduct.seekg((newProduct->getRecords() - 1) * sizeof(Products));
		updateProduct.write(reinterpret_cast<char*>(newProduct), sizeof(Products));
	}

}

Products* newProduct()
{
	int record;
	string name;
	int count;
	float cost;

	cout <<"enter records:"<< endl;
	cin>>record;

	cout <<"enter name:"<< endl;
	cin>> name;

	cout <<"enter count:"<< endl;
	cin>> count;

	cout <<"enter cost:"<< endl;
	cin>>cost;

	Products* rezult = new Products;
	return rezult;

 return 0;

}

void deleteRecord(fstream &deleteProd)
{
	int d;
	cin >> d;
	while(d > 1 || d > 100)
	{
		cout <<"enter  records from 1 to 100: "<< endl;
		cin >> d;
	}
	deleteProd.seekp((d - 1) * sizeof(Products));
	Products emptyProd;
	deleteProd.write(reinterpret_cast<char*> (&emptyProd), sizeof(Products));
}

void printFirst()
{
	cout << "record\tName\tCount\tCost\n";
}

void printInfo(fstream &info)
{
	info.seekg(0);
	info.clear();
	printFirst();
	Products one;
	for(int i = 0; i < 100; i++)
	{
		if(info.eof())
		{
			return;
		}else{
			info.read(reinterpret_cast<char*>(&one), sizeof(Products));
			if(one.getRecords() != 0)
			{
				one.prin();
			}
		}
	}
}
