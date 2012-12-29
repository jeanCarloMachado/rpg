#include "Bootstrap.h"


#include <iostream>

using namespace std;

void Bootstrap::init(Application* app)
{	
	cout << "user bootstrap " << endl;
}

 void Bootstrap::_init(Application* app)
 {
	cout << "SYSTEM bootstrap " << endl;
 }