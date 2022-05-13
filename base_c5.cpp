#include "base_c5.h"

base_c5::base_c5(base* b, std::string n) :base(b, n) { n_class = 5; }

void base_c5::signal(string& s)
{
	if (status) {
		cout << endl << "Signal from " << get_abs_cord();
		s += " (class: 5)";
	}
}

void base_c5::handler(const string& s)
{
	if (status) {
		cout << endl << "Signal to " << get_abs_cord() << " Text: " << s;
	}
}
