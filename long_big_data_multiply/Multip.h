#pragma GCC diagnostic error "-std=c++11"	//void the warning of -std=C++11 under gcc compiler

#include <string.h>
#include <iostream>


class Multip {
	//overload operation of << and >>
	friend std::istream& operator >> (std::istream&, Multip&);
	friend std::ostream& operator << (std::ostream&, Multip&);
	
public:
	Multip() = default;
	~Multip();
private:
	void initMen();		//init the calc memory
	void bigMult();		//bit tired multiplicative
	void getRes();		//carry by every decimal
	void calc();		//calc process

	char* lastres;	//final result
	char data1[1000];	//data temp
	char data2[1000];	//data temp
	std::size_t lendata1;	//length of data1
	std::size_t lendata2;	//length of data2
	std::size_t* pres;	//point of result

};
