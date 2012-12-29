#ifndef SYSBootstrap
#define SYSBootstrap

#include <string>
#include <iostream>

#include "System/Application/Bootstrap/BootstrapInterface.h"


using namespace std;

namespace SystemOgre {
	
	class Bootstrap : public System::BootstrapInterface
	{
	public:
		void init();
	protected:

	private:
	};
}

#endif
