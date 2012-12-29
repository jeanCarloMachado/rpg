#ifndef __SYSRouterMgrAbstract__
#define __SYSRouterMgrAbstract__

#include "System/Language/Language.h"
#include "System/DesignPattern/ListenerInterface.h"
#include "System/Router/RouterControllerAbstract.h"


namespace System
{
	class RouterMgrAbstract : public System::ListenerInterface
	{
	public:
		virtual void listen() {};

	protected:
		RouterControllerAbstract *rController;
	};
}

#endif