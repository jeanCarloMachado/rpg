#ifndef __SYSAPPLICATIONINTERFACE__
#define __SYSAPPLICATIONINTERFACE__

#include <iostream>

#include "System/Application/Bootstrap/BootstrapInterface.h"
#include "System/Language/Language.h"
#include "System/Router/RouterMgrAbstract.h"

namespace System
{

/**
 * APPLICATION
 */
 	class ApplicationInterface
 	{
 	public:
 		virtual  int init()  = 0;
		virtual  int run(System::RouterMgrAbstract *router) =0;
		virtual int setParams(char*** params) = 0;

		virtual void bootstrap(System::BootstrapInterface *bootstrap) = 0;

	protected:
		char** params;
 	};
 }
 #endif