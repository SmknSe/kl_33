#include "app.h"

int main()
{
	app q(nullptr);
	q.build_tree_objects();
	return q.exec_app();
}
