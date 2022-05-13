#include "base.h"
#include <iostream>
#include <algorithm>
using namespace std;
base::base(base* h, std::string n)
{
	status = 0;
	head = h;
	name = n;
	if (head != nullptr) {
		head->ar_p.emplace(head->ar_p.end(),this);
	}
}

void base::set_name(std::string n)
{
	name = n;
}

std::string base::get_name()
{
	return name;
}

void base::display()
{
	base* now = this;
	while (now->get_head_p() != nullptr) {
		now = now->get_head_p();
	}
	std::cout << now->get_name();
	if (now->ar_p.size() != 0) cout << endl;
	while (now->ar_p.size() != 0) {
		std::cout << now->name;
		for (int i = 0; i < now->ar_p.size(); i++) {
			std::cout<< "  " << now->ar_p[i]->get_name() ;
		}
		now = now->ar_p[now->ar_p.size() - 1];
		if(now->ar_p.size() != 0)
			std::cout << std::endl;
	}
}

void base::rebase(base* new_head)
{

	if (get_head_p() != nullptr && new_head!=nullptr) {
		get_head_p()->ar_p.erase(find(get_head_p()->ar_p.begin(), get_head_p()->ar_p.end(),this));
		new_head->ar_p.emplace_back(this);
		head = new_head;
	}
}


base* base::get_head_p()
{
	return head;
}

base::~base(){
	for(int i=0;i<ar_p.size();i++){
		delete ar_p[i];
	}
}

base* base::find_n(string n)
{
	if (this->name == n) return this;
	base* res = nullptr;
	for (int i = 0; i < ar_p.size(); i++)
	{
		res = ar_p[i]->find_n(n);
		if (res != nullptr) return res;
	}
	return res;
}

void base::print()
{
	if (this->get_head_p() == nullptr) cout << name;
	for (int i = 0; i < ar_p.size(); i++)
	{
		base* now = ar_p[i];
		string tab = "";
		while (now->get_head_p() != nullptr) {
			now = now->get_head_p();
			tab += "    ";
		}
		cout << endl << tab << ar_p[i]->get_name();
		ar_p[i]->print();
	}
}

void base::print_ready()
{
	if (this->get_head_p() == nullptr) {
		if (status != 0) cout << name << " is ready";
		else cout << name << " is not ready";
	}
	for (int i = 0; i < ar_p.size(); i++)
	{
		base* now = ar_p[i];
		string tab = "";
		while (now->get_head_p() != nullptr) {
			now = now->get_head_p();
			tab += "    ";
		}
		cout << endl << tab << ar_p[i]->get_name();
		if (ar_p[i]->status != 0) cout << " is ready";
		else cout << " is not ready";
		ar_p[i]->print_ready();
	}
}

void base::set_readiness(int s)
{
	if (head == nullptr || head->status != 0) {
		if (s != 0) status = s;
		else {
			for (int i = 0; i < ar_p.size(); i++){
				ar_p[i]->set_readiness(0);
			}
			status = 0;
		}
	}
}

base* base::find_cord(string p) {
	if (p.empty()) return nullptr;
	if (p[0] == '.') return this;
	base* root = this;
	if (p[0] == '/') {
		while (root->get_head_p() != nullptr) root = root->get_head_p();
		if (p.size() == 1) return root;
		if (p[1] == '/') {
		p.erase(0, 2);
		return root->find_n(p);
		}
		else p.erase(0, 1);
	}
	int id = p.find('/');
	string s = p;
	if (id!=-1)s = p.substr(0,id);
	for (int i = 0; i < root->ar_p.size(); i++) {
		base* o = root->ar_p[i];
		if (o->get_name() == s) {
			if (id == -1) {
				return o;
			}
			else {
				p.erase(0, id + 1);
				return o->find_cord(p);
			}
		}
	}
	return nullptr;
}

string base::get_abs_cord()
{
	string p = "";
	base* t = this;
	while (t->get_head_p() != nullptr) {
		p = "/" + t->get_name() + p;
		t = t->get_head_p();
	}
	if (p.size()!=0) return p;
	else return "/";
}

void base::set_connection(Tsignal s, base* b, Thandler h)
{
	connect c;
	for (int i = 0; i < con.size(); i++)
	{
		if (con[i].sg == s && con[i].hd == h && con[i].bas == b) {
			return;
		}
	}
	c.sg = s;
	c.bas = b;
	c.hd = h; 
	con.push_back(c);
}

void base::del_connection(Tsignal s, base* b, Thandler h)
{
	for (int i = 0; i < con.size(); i++)
	{
		if (con[i].sg == s && con[i].hd == h && con[i].bas == b) {
			con.erase(con.begin() + i);
			return;
		}
	}
}

void base::emit_signal(Tsignal s, string& com)
{
	if (status) {
		(this->*(s))(com);
		for (int i = 0; i < con.size(); i++)
		{
			if (con[i].sg == s && con[i].bas->status != 0) {
				(con[i].bas->*(con[i].hd))(com);
			}
		}
	}
}

void base::set_all_ready()
{
	set_readiness(1);
	for (int i = 0; i < ar_p.size(); i++)
	{
		ar_p[i]->set_readiness(1);
		ar_p[i]->set_all_ready();
	}
}

int base::get_n_class()
{
	return n_class;
}
