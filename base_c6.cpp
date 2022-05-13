#include "base_c6.h"

base_c6::base_c6(base* b, std::string n) :base(b, n) { n_class = 6; }

void base_c6::signal(string& s)
{
	if (status) {
		cout << endl << "Signal from " << get_abs_cord();
		s += " (class: 6)";
	}
}

void base_c6::handler(const string& s)
{
	if (status) {
		cout << endl << "Signal to " << get_abs_cord() << " Text: " << s;
	}
}
