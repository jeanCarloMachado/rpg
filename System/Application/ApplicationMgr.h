#ifndef __SYSAPPLICATIONMGR__
#define __SYSAPPLICATIONMGR__

#include <iostream>
#include <string>

#include "System/Language/Language.h"
#include "System/Error/Error.h"
#include "System/Modules/Ogre/Application.h"
//#include "System/Modules/Cmd/Application.h"


namespace System
{
	class ApplicationMgr
	{
	public:
		enum AppType {
			CMD,
			OGRE
		};

		static System::ApplicationAbstract* Factory(AppType type) 
 		{
 			System::ApplicationAbstract *obj;

 			switch(type)
 			{
 				case CMD:
					//obj = new SystemCmd::Application();
					break;

				case OGRE:
					obj = new SystemOgre::Application();
					break;

				default:

					std::string error = "não existe esse tipo de aplicação no framework";

					throw error;
 			}
			obj->init();
 			return obj;
 		}
		
	private:
		ApplicationMgr(){}
	};
}

#endif
