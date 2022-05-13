#ifndef BASE_C3_H
#define BASE_C3_H
#include "base.h"
#include<iostream>
class base_c3 :
	public base
{
public:
	base_c3(base* b, string n = "Def_name");
	void signal(string&);
	void handler(const string&);
};
#endif

