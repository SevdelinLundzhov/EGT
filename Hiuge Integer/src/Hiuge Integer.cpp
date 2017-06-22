//============================================================================
// Name        : Hiuge.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

class HugeInteger
{
public:
HugeInteger();
void input();
void const output();
void add(const HugeInteger&);
void subtract(const HugeInteger&);
bool isEqualTo(const HugeInteger&);
bool isNotEqualTo(const HugeInteger&);
bool isLessThan(const HugeInteger&);
bool isLessThanOrEqualTo(const HugeInteger&);
bool isGreaterThan(const HugeInteger &);
bool isGreaterThanOrequalTo(const HugeInteger&);
bool isZero;
~HugeInteger();
private:
int const ArraySize;
int number [40];
int intConversion(char);
void CopyArray( int[], const int[]);
};

#include<iostream>
using namespace std;
HugeInteger::HugeInteger()
:ArraySize(40)
{
for (int i = 0; i < ArraySize; i++)
number[i] = 0;
}: <---- RIGHT HERE

void HugeInteger::input()

{
char line[50];
int temp[40]= {0};
cout << "Please enter 40 numbers to be implemented into the array \n";
cin.getline(line, 50);
if(stren(line))!= ArraySize)
cout >> "The values do not match in the array \n";
else
{
for (int i = ArraySize - 1, j= 0; i >=0; i--, j++}
{
if(intConversion(line[j]) != -1)
temp[i]= IntConversion(line[j])
else
{
temp[i] = 0;
cout << "Array incorrectly fielded, enter different integers \n";
break;
}
}

for(int i = 0; i<ArraySize; i++)
number[i] = temp[i];
}
};
void HugeInteger:utput()const
{
cout<<"The integers in the array are:"
for( int = ArraySize - 1; i >= 0;i++)
cout<<number[i];
cout<<end;
};
void HugeInteger::add(const HugeInteger & Num 2)
{
int carry = 0, temp;
for(int = i; i < ArraySize - 1; i++)
{
temp= number[i];
number[i] = temp + Num2.number[i] + carry %10;
carry = (temp + Num2.number[i] + carry %10;
}
number[ArraySize - 1]= number[ArraySize - 1] +
Num2.number[ArraySize - 1] + carry);
};
void HugeInteger::subtract(const HugeInteger & Num 2)
{
int copyNum[40];
if( isGreatThanOrEqualTo(Num2))
subtract_array((*this).number,Num2.number);
else
{
CopyArray{copyNum, Num2.number);
subtract_array(copyNum(*this).number);
for( int i = ArraySize - 1; i>=0; i++)
{
if (copyNum[i]! = 0)
{
copyNum[i]*= -1;
break;
}
}
CopyArray((*this).number, copyNum);
}
};
void HugeInteger::subtract_arrays(int array1[], const int array2[])
{
for(i = 0; i < ArraySize; i++)
{
if (array1[i]<array2[i] && (i+1)<= ArraySize - 1)
{
array1[i] = array[i] + 10;
array1[i + 1] = array1[i + 1] - 1;
}
array1[i] = array[i] - array2[i];
}
};
void HugeInteger::CopyArray( int array1[], const int array2[])
}
for (int = 0; i < ArraySize; i++);
array[i] = array2[i];
};
bool HugeInteger::isEqualTo (const HugeInteger & Num2)
{
for (int = 0; i < ArraySize; i++);
if number[i] != Num2.number) return false;
return true;
};
bool HugeInteger::isNotEqualTo (const HugeInteger & Num2)
{
if (!isEqualTo(Num2) return true;
return false;
};
bool HugeInteger::isGreaterThan (const HugeInteger & Num2)
{
if (isEqualTo(Num2) return false;
else
{
for(int = 0; i < ArraySize; i++);
if( number[i] <Num2.number[i]) return false;
}
return true;
};
bool HugeInteger::isLessThan (const HugeInteger & Num2)
{
if (isEqualTo(Num2)/isGreaterThan(Num2)) return true;
{
return false;
};
bool HugeInteger::isLessThanOrEqualTo (const HugeInteger & Num2)
{
if (isEqualTo(Num2)/isLessThan(Num2)) return true;
return false;
};
bool HugeInteger::isZero()
{
for (int i= 0; ; i < ArraySize; i++);
if(number[i]!= 0) return false;
return true;
}
HugeInteger::~HugeInteger()
{
cout<<"the array is being destroyed"<<endl;
int HugeInteger::IntConversion( char ToConvert)
{
switch (ToConvert)
{
case '1': return 1;
case '2': return 2;
case '3': return 3;
case '4': return 4;
case '5': return 5;
case '6': return 6;
case '7': return 7;
case '8': return 8;
case '9': return 9;
case '0': return 0;
default: return -1;
}
}
}


#include <iostream>
using namespace std:
int main()
{
HugeInteger Num1;
HugeInteger Num2;
Num1.input();
Num1.output();
Num2.input(0);
Num2.output();
Num1.add(Num2);
cout<<"Integer 1 after addition"<<Num1.output();
Num1.subtract(Num2);
cout<<"Integer 1 after subtraction"<<Num1.output();
if (Num1.isEqualTo(Num2))
cout<<"Integer 1 is equal to integer 2"<<endl;
if (Num1.isNotEqualTo(Num2))
cout<<"Integer 1 not equal to integer 2"<<endl;
if (Num1.isLessThan(Num2))
cout<< "Integer 1 is less than integer 2"<< endl;
if (Num1.isGreaterThanOrequalTo(Num2))
cout<<"Integer 1 is greater than or equal to integer 2"<< endl;
if (Num1.isLessThanOrEqualTo(Num2))
cout<<"Integer 1 is less than or equal to integer 2"<<endl;
if(Num1.isZero())
cout<<"Integer 1 is zero"<<endl;

return 0;
}
