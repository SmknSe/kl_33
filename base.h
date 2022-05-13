#ifndef BASE_H
#define BASE_H
#include <string>
#include <vector>
using namespace std;

class base;
typedef void (base::*Tsignal)(string&);
typedef void (base::*Thandler)( const string& s);
#define SIGNALL(_signal) ((Tsignal)(&_signal))
#define HANDLERR(_handler) ((Thandler)(&_handler))

class base
{
protected:
	string name;
	base* head;
	int status;
	int n_class;
	vector<base*> ar_p;
	struct connect
	{
		base* bas;
		Tsignal sg;
		Thandler hd;
	};
	vector<connect> con;
public:
	
	base(base*, string="Def_name");
	void set_name(string);
	string get_name();
	void display();
	void rebase(base* new_per);
	base* get_head_p();
	~base();
	base* find_n(string);
	void print();
	void print_ready();
	void set_readiness(int);
	base* find_cord(string);
	string get_abs_cord();
	void set_connection(Tsignal, base*, Thandler);
	void del_connection(Tsignal, base*, Thandler);
	void emit_signal(Tsignal, string&);
	void set_all_ready();
	int get_n_class();
};
#endif