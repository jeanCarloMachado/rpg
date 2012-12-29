noinst_HEADERS= Application.h  Bootstrap.h ControllerAbstract.h ControllerMain.h  Application/Modules/Main/ModelGround.h InputMgr.h Semaphore.h Application/Modules/Main/ModelPlayer.h

bin_PROGRAMS= game
 game_CPPFLAGS= -I$(top_srcdir)
 game_SOURCES= main.cpp Application.cpp Bootstrap.cpp  Application/Modules/Main/ModelGround.cpp ControllerAbstract.cpp ControllerMain.cpp InputMgr.cpp Semaphore.cpp Application/Modules/Main/ModelPlayer.cpp
game_CXXFLAGS= $(OGRE_CFLAGS) $(OIS_CFLAGS)
game_LDADD= $(OGRE_LIBS) $(OIS_LIBS) $(CEGUI_LIBS) $(CEGUI_OGRE_LIBS)

 
 EXTRA_DIST = bootstrap
 AUTOMAKE_OPTIONS = foreign