#ifndef __SYSOgreRouterMgr__
#define __SYSOgreRouterMgr__

#include <string>
#include <vector>
#include <stdlib.h>

#include "System/Router/RouterMgrAbstract.h"

using namespace std;

namespace SystemOgre
{
	/**
	 * implementação do roteador de chamadas para linha
	 * de comando
	 */
	class RouterMgr : public System::RouterMgrAbstract
	{

	public:
		void listen(){}
	};
}

 #endif