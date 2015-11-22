#include "Multip.h"
#include <stdlib.h>


std::istream& operator >> (std::istream& is, Multip& item)
{
	is >> item.data1 >> item.data2;
	return is;
}

std::ostream& operator << (std::ostream& os, Multip& item)
{
	item.calc();
	os << std::endl << item.data1 << " * " << item.data2 << " = " << item.lastres;
	return os;	
}

void Multip::calc()
{
	this->initMen();
	this->bigMult();
	this->getRes();
}

void Multip::initMen()
{
	lendata1 = strlen(this->data1);
	lendata2 = strlen(this->data2);
	pres = (std::size_t*)malloc(sizeof(std::size_t) * (lendata1 + lendata2));
	//init a block of memory
	memset(pres, 0, sizeof(std::size_t) * (lendata1 + lendata2));
}

void Multip::bigMult()
{	
	for (std::size_t i = 0; i < lendata1; ++i)
		for (std::size_t j = 0; j < lendata1; ++j)
			pres[i + j + 1] += (data1[i] - '0') * (data2[j] - '0');

	for (std::size_t k = lendata1 + lendata2 - 1; k != 0; --k)
	{
		if (pres[k] >= 10)
		{
			pres[k - 1] += pres[k] / 10;
			pres[k] %= 10;
		}
	}
}

void Multip::getRes()
{
	lastres = (char*)malloc(sizeof(char) * (lendata1 + lendata2));
	//std::size_t i = 0, k = 0;
	//for (i; pres[i] == 0; ++i)
	//	++k;

	for (std::size_t j = 0; j < lendata1 + lendata2; ++j)
		lastres[j] = pres[j] + '0';

	lastres[lendata1 + lendata2] = '\0';
}

Multip::~Multip()
{
	free(pres);
	free(lastres);
}
