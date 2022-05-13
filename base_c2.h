#ifndef BASE_C2_H
#define BASE_C2_H
#include <string>
#include<iostream>
#include "base.h"
using namespace std;
class base_c2 : public base
{
public:
	base_c2(base* b, string n = "Def_name");
	void signal(string&);
	void handler( const string&);
};

#endif