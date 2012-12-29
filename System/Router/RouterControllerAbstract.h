#ifndef __SYSROUTERCONTROLLER__
#define __SYSROUTERCONTROLLER__

#include <string>
#include <iostream>
#include <vector>

#include "System/Language/Language.h"
#include "System/Router/RouterInterface.h"
#include "System/Router/RouterViewAbstract.h"
#include "System/Object/Util.h"

#define CONTROLER_PARAM_POSITION 1

using namespace std;

namespace System
{
	class RouterControllerAbstract : public RouterInterface
	{	
	public:
		int route(std::string input)
		{
			// vector<string> resultParams = System::String::toVector(input);	
			
			
			// /** roteador de visoes */
			// this->rView = new RouterView();

			// /**
			//  * caso tenha sido passado somente um parametro
			//  * chama o controller default
			//  */
			// if(resultParams.size() <= 1) {
			// 	controller = new DefaultController();
			// 	return rView->route(input,controller);
			// }
			// /**
			//  * testa as possibilidade de acordo com 
			//  * o segundo parametro
			//  */

			// if(!resultParams[CONTROLER_PARAM_POSITION].compare(System::Language::translate("error"))) {
			// 	ErrorController *controller = new ErrorController;
			// 	return rView->route(input,controller);

			// }else if(!resultParams[CONTROLER_PARAM_POSITION].compare(System::Language::translate("message"))) {
			// 	MessageController *controller = new MessageController;
			// 	return rView->route(input,controller);

			// } else if(!resultParams[CONTROLER_PARAM_POSITION].compare(System::Language::translate("solution"))) {
			// 	ControllerSolution *controller = new ControllerSolution;
			// 	return rView->route(input,controller);

			// } else {
			// 	controller = new DefaultController();
			// 	return rView->route(input,controller);
			// }

			return 0;
		}

	protected:
		RouterViewAbstract *rView ;
		//BaseController *controller;
	};	


}

#endif