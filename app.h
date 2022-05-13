#ifndef APP_H
#define APP_H
#include<iostream>
#include "base.h"
#include "base_c2.h"
#include "base_c3.h"
#include "base_c4.h"
#include "base_c5.h"
#include "base_c6.h"
using namespace std;
class app : public base
{
public:
	app(base* p);
	void build_tree_objects();
	int exec_app();
	void signal(string&);
	void handler( const string&);
};
#endif