#include "base_c2.h"
base_c2::base_c2(base* b, string n) :base(b, n) { n_class = 2; }

void base_c2::signal(string& s)
{
	if (status) {
		cout << endl << "Signal from " << get_abs_cord();
		s += " (class: 2)";
	}
}

void base_c2::handler(const string& s)
{
	if (status) {
		cout << endl << "Signal to " << get_abs_cord() << " Text: " << s;
	}
}
