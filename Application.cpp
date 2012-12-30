
#include "Application.h"

#include <OgreException.h>
#include <OgreConfigFile.h>
#include <OgreRenderWindow.h>
#include <OgreWindowEventUtilities.h>

#include "Bootstrap.h"
#include "InputMgr.h"

#include "ControllerAbstract.h"
#include "ControllerMain.h"

#include "System/Object/Util.h"


Application::Application(void)
 : root(0),
    resourcesCfg(Ogre::StringUtil::BLANK),
    pluginsCfg(Ogre::StringUtil::BLANK),
    window(0),
    mouse(0),
    keyboard(0)
{
            this->semaphore = new Semaphore();

            /**
             * instancia o jogador princial (o que vai se manter entre as cenas)
             */
            this->player = new ModelPlayer;
           
	/**
	 * executa o bootstrap
	 */
	this->bootstrap();
}

Application::~Application(void)
{
	//Remove ourself as a Window listener
	    Ogre::WindowEventUtilities::removeWindowEventListener(window, this);
	    windowClosed(window);
	    delete root;
}

bool Application::bootstrap()
{
    std::cout << "bootstrap da  aplicação";

    Bootstrap boot;
    /**
     * boostrap do sistema
     */
    boot._init(this);
    /**
     * boostrap do usuário
     */
    boot.init(this);
/**
 * configurações iniciais do ogre
 */

#ifdef _DEBUG
    resourcesCfg = "resources_d.cfg";
    pluginsCfg = "plugins_d.cfg";
#else
    resourcesCfg = "resources.cfg";
    pluginsCfg = "plugins.cfg";
#endif
 
    // construct Ogre::Root
    root = new Ogre::Root(pluginsCfg);
 
/**
 * habilita os recursos
 */
    // Load resource paths from config file
    Ogre::ConfigFile cf;
    cf.load(resourcesCfg);
 
    // Go through all sections & settings in the file
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
 
    Ogre::String secName, typeName, archName;
    while (seci.hasMoreElements())
    {
        secName = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        Ogre::ConfigFile::SettingsMultiMap::iterator i;
        for (i = settings->begin(); i != settings->end(); ++i)
        {
            typeName = i->first;
            archName = i->second;
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
                archName, typeName, secName);
        }
    }

/**
 * termina de habilitar os recursos
 */
    // configure
    // Show the configuration dialog and initialise the system
    if(!(root->restoreConfig() || root->showConfigDialog()))
    {
        return false;
    }
 
    window = root->initialise(true, MAIN_WINDOW_NAME);
 
    // Set default mipmap level (NB some APIs ignore this)
    Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
  
     //Register as a Window listener
    Ogre::WindowEventUtilities::addWindowEventListener(window, this);

/**
 * inicializa OIS
 */
    OIS::ParamList pl;
    size_t windowHnd = 0;
    std::ostringstream windowHndStr;
 
    window->getCustomAttribute("WINDOW", &windowHnd);
    windowHndStr << windowHnd;
    pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
 
    mInputManager = OIS::InputManager::createInputSystem( pl );
    this->keyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject( OIS::OISKeyboard, true ));
    this->mouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject( OIS::OISMouse, true ));

    InputMgr* inputMgr = InputMgr::getInstance();
    this->mouse->setEventCallback(inputMgr);
    this->keyboard->setEventCallback(inputMgr);
    /**
     * registra a classe input mgr como 
     */
/**
 * FIM inicializa OIS
 */

    return true;
}

//Adjust mouse clipping area
void Application::windowResized(Ogre::RenderWindow* rw)
{
    unsigned int width, height, depth;
    int left, top;
    rw->getMetrics(width, height, depth, left, top);
 
    const OIS::MouseState &ms = this->mouse->getMouseState();
    ms.width = width;
    ms.height = height;
}
 
//Unattach OIS before window shutdown (very important under Linux)
void Application::windowClosed(Ogre::RenderWindow* rw)
{
    //Only close for window that created OIS (the main window in these demos)
    if( rw == window )
    {
        if( mInputManager )
        {
            mInputManager->destroyInputObject( this->mouse );
            mInputManager->destroyInputObject( this->keyboard );
 
            OIS::InputManager::destroyInputSystem(mInputManager);
            mInputManager = 0;
        }
    }
}
 


/**
 * setps to basic ogre cycles
1-Create the Root object.
2-Define the resources that Ogre will use.
3-Choose and set up the RenderSystem (that is, DirectX, OpenGL, etc).
4-Create the RenderWindow (the window which Ogre resides in).
5Initialise the resources that you are going to use.
6-Create a scene using those resources.
7-Set up any third party libraries and plugins.
8-Create any number of frame listeners.
9-Start the render loop.
 * @return  [description]
 */
bool Application::run(void)
{	 
        this->getSemaphore()->setCurrentStatus(Semaphore::PLAYING);

        ControllerAbstract* currentController = new ControllerMain(this);

        /** executa o laço com o próximo controllador até o resultado for null */
        while(currentController != NULL)
        {   
                /**
                 * passa apra o input mgr  o controlador atualmente usado
                 */
                InputMgr* inputMgr = InputMgr::getInstance();
                inputMgr->setSemaphore(this->semaphore);
                inputMgr->setControllerPtr(currentController);

               

                currentController = currentController->indexAction();
        }

        return false;
}