#ifndef BASE_C4_H
#define BASE_C4_H
#include "base.h"
#include<iostream>
class base_c4 :
	public base
{
public:
	base_c4(base*, std::string = "Default_name");
	void signal(string&);
	void handler(const string&);
};
#endif