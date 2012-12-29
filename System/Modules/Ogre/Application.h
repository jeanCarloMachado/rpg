#ifndef __SYSOgreApplication__
#define __SYSOgreApplication__

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "System/Language/Language.h"
#include "System/Application/ApplicationAbstract.h"
#include "System/Modules/Ogre/RouterMgr.h"

namespace SystemOgre
{
	class Application : public System::ApplicationAbstract
	{

	public:
		int init() 
		{
			return 1;
		}

		int run(System::RouterMgrAbstract *router)
		{
			router->listen();
			return 1;
		}

		int setParams(char ***params) 
		{
			this->params = &**params;
		}

	protected:
		SystemOgre::RouterMgr routerMgr;
	};
}

#endif