#ifndef BASE_C5_H
#define BASE_C5_H
#include "base.h"
#include<iostream>
class base_c5 :
	public base
{
public:
	base_c5(base*, std::string = "Default_name");
	void signal(string&);
	void handler(const string&);
};
#endif