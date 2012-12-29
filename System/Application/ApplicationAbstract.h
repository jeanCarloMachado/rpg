
#ifndef SYSApplicationAbstract
#define SYSApplicationAbstract

using namespace std;

#include "System/Application/ApplicationInterface.h"

namespace System {
	
	class ApplicationAbstract : public ApplicationInterface
	{
	public:
		virtual void bootstrap(System::BootstrapInterface *bootstrap) {bootstrap->init();}
	};
}

#endif
