
#ifndef SYSModelGround
#define SYSModelGround

using namespace std;

#include "System/Db/TableRowAbstract.h"
#include "ControllerAbstract.h"

namespace Main {
	
	class ModelGround : public System::TableRowAbstract
	{
	public:
		void createSimpleStoneGround(ControllerAbstract *controller);
	};
}

#endif
