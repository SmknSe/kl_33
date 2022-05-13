#include "app.h"
#include <iostream>
#include <string>

app::app(base* p):base(p, "root")
{
	n_class = 1;
}

void app::build_tree_objects()
{
	base* temp = nullptr;
	string n_a, n_b;
	int class_n;
	cin >> n_a;
	if (n_a != "endtree") {
		set_name(n_a);
		do {
			cin >> n_a;
			if (n_a != "endtree") {
				cin >> n_b >> class_n;
				base* t = find_cord(n_a);
				if (t == nullptr) {
					cout << "Object tree\n";
					print();
					cout << "\nThe head object " << n_a << " is not found";
					exit(0);
				}
				switch (class_n)
				{
				case 2:
					temp = new base_c2(t, n_b);
					break;
				case 3:
					temp = new base_c3(t, n_b);
					break;
				case 4:
					temp = new base_c4(t, n_b);
					break;
				case 5:
					temp = new base_c5(t, n_b);
					break;
				case 6:
					temp = new base_c6(t, n_b);
					break;
				default:
					break;
				}
			}
		} while (n_a != "endtree");
	}
	cin >> n_a;
	Tsignal signals[] = { SIGNALL(app::signal),SIGNALL(base_c2::signal),SIGNALL(base_c3::signal) ,SIGNALL(base_c4::signal) ,SIGNALL(base_c5::signal) ,SIGNALL(base_c6::signal) };
	Thandler handlers[] = { HANDLERR(app::handler),HANDLERR(base_c2::handler),HANDLERR(base_c3::handler) ,HANDLERR(base_c4::handler) ,HANDLERR(base_c5::handler) ,HANDLERR(base_c6::handler) };
	while (n_a != "end_of_connections") {
		cin >> n_b;
		base* from = find_cord(n_a);
		base* to = find_cord(n_b);
		from->set_connection(signals[from->get_n_class() - 1], to, handlers[to->get_n_class() - 1]);
		cin >> n_a;
	}
}

int app::exec_app()
{
	Tsignal signals[] = { SIGNALL(app::signal),SIGNALL(base_c2::signal),SIGNALL(base_c3::signal) ,SIGNALL(base_c4::signal) ,SIGNALL(base_c5::signal) ,SIGNALL(base_c6::signal) };
	Thandler handlers[] = { HANDLERR(app::handler),HANDLERR(base_c2::handler),HANDLERR(base_c3::handler) ,HANDLERR(base_c4::handler) ,HANDLERR(base_c5::handler) ,HANDLERR(base_c6::handler) };
	cout << "Object tree" << endl;
	if (name != "") {
		print();
		string cmd, pt, txt;
		base* now = this;
		base* tmp = nullptr;
		int r;
		set_all_ready();
		do {
			cin >> cmd;
			if (cmd != "END") {
				cin >> pt;
				if (cmd == "EMIT") {
					getline(cin, txt);
					tmp = find_cord(pt);
					if (tmp == nullptr) {
						cout << "\nObject " << pt << " not found";
					}
					else {
						tmp->emit_signal(signals[tmp->get_n_class() - 1], txt);
					}
				}
				else if (cmd == "SET_CONNECT") {
					cin >> txt;
					now = find_cord(pt);
					tmp = find_cord(txt);
					if (now == nullptr) {
						cout << "\nObject " << pt << " not found";
					}
					if (tmp == nullptr) {
						cout << "\nHandler object " << txt << " not found";
					}
					if (tmp!=nullptr && now!=nullptr) {
						now->set_connection(signals[now->get_n_class() - 1], tmp, handlers[tmp->get_n_class() - 1]);
					}
				}
				else if (cmd == "DELETE_CONNECT") {
					cin >> txt;
					now = find_cord(pt);
					tmp = find_cord(txt);
					if (now == nullptr) {
						cout << "\nObject " << pt << " not found";
					}
					if (tmp == nullptr) {
						cout << "\nHandler object " << txt << " not found";
					}
					if (tmp != nullptr && now != nullptr) {
						now->del_connection(signals[now->get_n_class() - 1], tmp, handlers[tmp->get_n_class() - 1]);
					}
				}
				else if (cmd == "SET_CONDITION") {
					cin >> r;
					now = find_cord(pt);
					if (now != nullptr) {
						now->set_readiness(r);
					}
					else {
						cout << "\nObject " << pt << " not found";
					}
				}
			}
		} while (cmd != "END");
	}
	return 0;
}

void app::signal(string& s)
{
	if (status) {
		cout << endl << "Signal from " << get_abs_cord();
		s += " (class: 1)";
	}
}

void app::handler(const string& s)
{
	if (status) {
		cout << endl << "Signal to " << get_abs_cord() << " Text: " << s;
	}
}
