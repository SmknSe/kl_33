#include "base_c3.h"


base_c3::base_c3(base* b, std::string n) :base(b, n) { n_class = 3; }

void base_c3::signal(string& s)
{
	if (status) {
		cout << endl << "Signal from " << get_abs_cord();
		s += " (class: 3)";
	}
}

void base_c3::handler(const string& s)
{
	if (status) {
		cout << endl << "Signal to " << get_abs_cord() << " Text: " << s;
	}
}
