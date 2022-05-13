#include "base_c4.h"

base_c4::base_c4(base* b, std::string n) :base(b, n) { n_class = 4; }

void base_c4::signal(string& s)
{
	if (status) {
		cout << endl << "Signal from " << get_abs_cord();
		s += " (class: 4)";
	}
}

void base_c4::handler(const string& s)
{
	if (status) {
		cout << endl << "Signal to " << get_abs_cord() << " Text: " << s;
	}
}
