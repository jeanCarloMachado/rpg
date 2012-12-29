#ifndef SYSControllerMain
#define SYSControllerMain

using namespace std;

#include "ControllerAbstract.h"


	
class ControllerMain : public ControllerAbstract
{
public:
	ControllerMain(Application *app);
	void init();
	ControllerAbstract* indexAction();

private:
	void createGround(void);
};

#endif
