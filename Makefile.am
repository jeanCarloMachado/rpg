noinst_HEADERS=
bin_PROGRAMS= App
 App_CPPFLAGS= -I$(top_srcdir) -lsqlite3
 App_SOURCES= main.cpp  				

 
 App_CXXFLAGS= $(OGRE_CFLAGS) $(OIS_CFLAGS) -lsqlite3
 App_LDADD= $(OGRE_LIBS) $(OIS_LIBS) -lsqlite3
 
 EXTRA_DIST = bootstrap
 AUTOMAKE_OPTIONS = foreign