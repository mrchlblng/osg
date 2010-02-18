// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/StaticMethodInfo>
#include <osgIntrospection/Attributes>

#include <OpenThreads/Thread>
#include <osg/FrameStamp>
#include <osg/GraphicsContext>
#include <osg/Group>
#include <osg/Node>
#include <osg/PagedLOD>
#include <osg/Referenced>
#include <osg/State>
#include <osgDB/DatabasePager>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ENUM_REFLECTOR(osgDB::DatabasePager::DrawablePolicy)
	I_DeclaringFile("osgDB/DatabasePager");
	I_EnumLabel(osgDB::DatabasePager::DO_NOT_MODIFY_DRAWABLE_SETTINGS);
	I_EnumLabel(osgDB::DatabasePager::USE_DISPLAY_LISTS);
	I_EnumLabel(osgDB::DatabasePager::USE_VERTEX_BUFFER_OBJECTS);
	I_EnumLabel(osgDB::DatabasePager::USE_VERTEX_ARRAYS);
END_REFLECTOR

TYPE_NAME_ALIAS(OpenThreads::Thread::ThreadPriority, osgDB::DatabasePager::ThreadPriority)

TYPE_NAME_ALIAS(std::list< osg::ref_ptr< osg::PagedLOD > >, osgDB::DatabasePager::PagedLODList)

TYPE_NAME_ALIAS(std::set< osg::ref_ptr< osg::StateSet > >, osgDB::DatabasePager::StateSetList)

TYPE_NAME_ALIAS(std::vector< osg::ref_ptr< osg::Drawable > >, osgDB::DatabasePager::DrawableList)

TYPE_NAME_ALIAS(std::pair< osgDB::DatabasePager::StateSetList COMMA  osgDB::DatabasePager::DrawableList >, osgDB::DatabasePager::DataToCompile)

TYPE_NAME_ALIAS(std::map< unsigned int COMMA  osgDB::DatabasePager::DataToCompile >, osgDB::DatabasePager::DataToCompileMap)

TYPE_NAME_ALIAS(std::set< unsigned int >, osgDB::DatabasePager::ActiveGraphicsContexts)

TYPE_NAME_ALIAS(std::vector< osg::observer_ptr< osg::GraphicsContext > >, osgDB::DatabasePager::CompileGraphicsContexts)

BEGIN_OBJECT_REFLECTOR(osgDB::DatabasePager)
	I_DeclaringFile("osgDB/DatabasePager");
	I_BaseType(osg::NodeVisitor::DatabaseRequestHandler);
	I_Constructor0(____DatabasePager,
	               "",
	               "");
	I_Constructor1(IN, const osgDB::DatabasePager &, rhs,
	               Properties::NON_EXPLICIT,
	               ____DatabasePager__C5_DatabasePager_R1,
	               "",
	               "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "",
	          "");
	I_Method0(osgDB::DatabasePager *, clone,
	          Properties::VIRTUAL,
	          __DatabasePager_P1__clone,
	          "Create a shallow copy on the DatabasePager. ",
	          "");
	I_Method6(void, requestNodeFile, IN, const std::string &, fileName, IN, osg::Group *, group, IN, float, priority, IN, const osg::FrameStamp *, framestamp, IN, osg::ref_ptr< osg::Referenced > &, databaseRequest, IN, const osg::Referenced *, options,
	          Properties::VIRTUAL,
	          __void__requestNodeFile__C5_std_string_R1__osg_Group_P1__float__C5_osg_FrameStamp_P1__osg_ref_ptrT1_osg_Referenced__R1__C5_osg_Referenced_P1,
	          "Add a request to load a node file to end the the database request list. ",
	          "");
	I_Method1(int, setSchedulePriority, IN, OpenThreads::Thread::ThreadPriority, priority,
	          Properties::NON_VIRTUAL,
	          __int__setSchedulePriority__OpenThreads_Thread_ThreadPriority,
	          "Set the priority of the database pager thread(s). ",
	          "");
	I_Method0(int, cancel,
	          Properties::VIRTUAL,
	          __int__cancel,
	          "Cancel the database pager thread(s). ",
	          "");
	I_Method0(bool, isRunning,
	          Properties::VIRTUAL,
	          __bool__isRunning,
	          "",
	          "");
	I_Method0(void, clear,
	          Properties::VIRTUAL,
	          __void__clear,
	          "Clear all internally cached structures. ",
	          "");
	I_MethodWithDefaults2(void, setUpThreads, IN, unsigned int, totalNumThreads, 2, IN, unsigned int, numHttpThreads, 1,
	                      Properties::NON_VIRTUAL,
	                      __void__setUpThreads__unsigned_int__unsigned_int,
	                      "",
	                      "");
	I_Method2(unsigned int, addDatabaseThread, IN, osgDB::DatabasePager::DatabaseThread::Mode, mode, IN, const std::string &, name,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__addDatabaseThread__DatabaseThread_Mode__C5_std_string_R1,
	          "",
	          "");
	I_Method1(osgDB::DatabasePager::DatabaseThread *, getDatabaseThread, IN, unsigned int, i,
	          Properties::NON_VIRTUAL,
	          __DatabaseThread_P1__getDatabaseThread__unsigned_int,
	          "",
	          "");
	I_Method1(const osgDB::DatabasePager::DatabaseThread *, getDatabaseThread, IN, unsigned int, i,
	          Properties::NON_VIRTUAL,
	          __C5_DatabaseThread_P1__getDatabaseThread__unsigned_int,
	          "",
	          "");
	I_Method0(unsigned int, getNumDatabaseThreads,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getNumDatabaseThreads,
	          "",
	          "");
	I_Method1(void, setDatabasePagerThreadPause, IN, bool, pause,
	          Properties::NON_VIRTUAL,
	          __void__setDatabasePagerThreadPause__bool,
	          "Set whether the database pager thread should be paused or not. ",
	          "");
	I_Method0(bool, getDatabasePagerThreadPause,
	          Properties::NON_VIRTUAL,
	          __bool__getDatabasePagerThreadPause,
	          "Get whether the database pager thread should is paused or not. ",
	          "");
	I_Method1(void, setAcceptNewDatabaseRequests, IN, bool, acceptNewRequests,
	          Properties::NON_VIRTUAL,
	          __void__setAcceptNewDatabaseRequests__bool,
	          "Set whether new database request calls are accepted or ignored. ",
	          "");
	I_Method0(bool, getAcceptNewDatabaseRequests,
	          Properties::NON_VIRTUAL,
	          __bool__getAcceptNewDatabaseRequests,
	          "Get whether new database request calls are accepted or ignored. ",
	          "");
	I_Method0(int, getNumFramesActive,
	          Properties::NON_VIRTUAL,
	          __int__getNumFramesActive,
	          "Get the number of frames that are currently active. ",
	          "");
	I_Method1(void, signalBeginFrame, IN, const osg::FrameStamp *, framestamp,
	          Properties::VIRTUAL,
	          __void__signalBeginFrame__C5_osg_FrameStamp_P1,
	          "Signal the database thread that the update, cull and draw has begun for a new frame. ",
	          "Note, this is called by the application so that the database pager can go to sleep while the CPU is busy on the main rendering threads. ");
	I_Method0(void, signalEndFrame,
	          Properties::VIRTUAL,
	          __void__signalEndFrame,
	          "Signal the database thread that the update, cull and draw dispatch has completed. ",
	          "Note, this is called by the application so that the database pager can go to wake back up now the main rendering threads are iddle waiting for the next frame. ");
	I_MethodWithDefaults2(void, registerPagedLODs, IN, osg::Node *, subgraph, , IN, int, frameNumber, 0,
	                      Properties::VIRTUAL,
	                      __void__registerPagedLODs__osg_Node_P1__int,
	                      "Find all PagedLOD nodes in a subgraph and register them with the DatabasePager so it can keep track of expired nodes. ",
	                      "note, should be only be called from the update thread. ");
	I_Method1(void, setDoPreCompile, IN, bool, flag,
	          Properties::NON_VIRTUAL,
	          __void__setDoPreCompile__bool,
	          "Set whether the database pager should pre compile OpenGL objects before allowing them to be merged into the scene graph. ",
	          "Pre compilation helps reduce the chances of frame drops, but also slows the speed at which tiles are merged as they have to be compiled first. ");
	I_Method0(bool, getDoPreCompile,
	          Properties::NON_VIRTUAL,
	          __bool__getDoPreCompile,
	          "Get whether the database pager should pre compile OpenGL objects before allowing them to be merged into the scene graph. ",
	          "");
	I_Method1(void, setTargetFrameRate, IN, double, tfr,
	          Properties::NON_VIRTUAL,
	          __void__setTargetFrameRate__double,
	          "Set the target frame rate that the DatabasePager should assume. ",
	          "Typically one would set this to the value refresh rate of your display system i.e. 60Hz. Default value is 100. Usage notes. The TargetFrameRate and the MinimumTimeAvailableForGLCompileAndDeletePerFrame parameters are not directly used by DatabasePager, but are should be used as a guide for how long to set aside per frame for compiling and deleting OpenGL objects - ie. the value to use when calling DatabasePager::compileGLObjectgs(state,availableTime,). The longer amount of time to set aside cthe faster databases will be paged in but with increased chance of frame drops, the lower the amount of time the set aside the slower databases will paged it but with better chance of avoid any frame drops. The default values are chosen to achieve the later when running on a modern mid to high end PC. The way to compute the amount of available time use a scheme such as : availableTime = maximum(1.0/targetFrameRate - timeTakenDuringUpdateCullAndDraw, minimumTimeAvailableForGLCompileAndDeletePerFrame). ");
	I_Method0(double, getTargetFrameRate,
	          Properties::NON_VIRTUAL,
	          __double__getTargetFrameRate,
	          "Get the target frame rate that the DatabasePager should assume. ",
	          "");
	I_Method1(void, setMinimumTimeAvailableForGLCompileAndDeletePerFrame, IN, double, ta,
	          Properties::NON_VIRTUAL,
	          __void__setMinimumTimeAvailableForGLCompileAndDeletePerFrame__double,
	          "Set the minimum amount of time (in seconds) that should be made available for compiling and delete OpenGL objects per frame. ",
	          "Default value is 0.001 (1 millisecond). For usage see notes in setTargetFrameRate. ");
	I_Method0(double, getMinimumTimeAvailableForGLCompileAndDeletePerFrame,
	          Properties::NON_VIRTUAL,
	          __double__getMinimumTimeAvailableForGLCompileAndDeletePerFrame,
	          "Get the minimum amount of time that should be made available for compiling and delete OpenGL objects per frame. ",
	          "For usage see notes in setTargetFrameRate. ");
	I_Method1(void, setMaximumNumOfObjectsToCompilePerFrame, IN, unsigned int, num,
	          Properties::NON_VIRTUAL,
	          __void__setMaximumNumOfObjectsToCompilePerFrame__unsigned_int,
	          "Set the maximum number of OpenGL objects that the page should attempt to compile per frame. ",
	          "Note, Lower values reduces chances of a frame drop but lower the rate that database will be paged in at. Default value is 8. ");
	I_Method0(unsigned int, getMaximumNumOfObjectsToCompilePerFrame,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getMaximumNumOfObjectsToCompilePerFrame,
	          "Get the maximum number of OpenGL objects that the page should attempt to compile per frame. ",
	          "");
	I_Method1(void, setTargetMaximumNumberOfPageLOD, IN, unsigned int, target,
	          Properties::NON_VIRTUAL,
	          __void__setTargetMaximumNumberOfPageLOD__unsigned_int,
	          "Set the target maximum number of PagedLOD to maintain in memory. ",
	          "Note, if more than the target number are required for rendering of a frame then these active PagedLOD are excempt from being expiried. But once the number of active drops back below the target the inactive PagedLOD will be trimmed back to the target number. ");
	I_Method0(unsigned int, getTargetMaximumNumberOfPageLOD,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getTargetMaximumNumberOfPageLOD,
	          "Get the target maximum number of PagedLOD to maintain in memory. ",
	          "");
	I_Method1(void, setExpiryDelay, IN, double, expiryDelay,
	          Properties::NON_VIRTUAL,
	          __void__setExpiryDelay__double,
	          "Deprecated. ",
	          "");
	I_Method0(double, getExpiryDelay,
	          Properties::NON_VIRTUAL,
	          __double__getExpiryDelay,
	          "Deprecated. ",
	          "");
	I_Method1(void, setExpiryFrames, IN, int, expiryFrames,
	          Properties::NON_VIRTUAL,
	          __void__setExpiryFrames__int,
	          "Deprecated. ",
	          "");
	I_Method0(int, getExpiryFrames,
	          Properties::NON_VIRTUAL,
	          __int__getExpiryFrames,
	          "Deprecated. ",
	          "");
	I_Method1(void, setReleaseDelay, IN, double, releaseDelay,
	          Properties::NON_VIRTUAL,
	          __void__setReleaseDelay__double,
	          "Deprecated. ",
	          "");
	I_Method0(double, getReleaseDelay,
	          Properties::NON_VIRTUAL,
	          __double__getReleaseDelay,
	          "Deprecated. ",
	          "");
	I_Method1(void, setReleaseFrames, IN, int, releaseFrames,
	          Properties::NON_VIRTUAL,
	          __void__setReleaseFrames__int,
	          "Deprecated. ",
	          "");
	I_Method0(int, getReleaseFrames,
	          Properties::NON_VIRTUAL,
	          __int__getReleaseFrames,
	          "Deprecated. ",
	          "");
	I_Method1(void, setDeleteRemovedSubgraphsInDatabaseThread, IN, bool, flag,
	          Properties::NON_VIRTUAL,
	          __void__setDeleteRemovedSubgraphsInDatabaseThread__bool,
	          "Set whether the removed subgraphs should be deleted in the database thread or not. ",
	          "");
	I_Method0(bool, getDeleteRemovedSubgraphsInDatabaseThread,
	          Properties::NON_VIRTUAL,
	          __bool__getDeleteRemovedSubgraphsInDatabaseThread,
	          "Get whether the removed subgraphs should be deleted in the database thread or not. ",
	          "");
	I_Method1(void, setDrawablePolicy, IN, osgDB::DatabasePager::DrawablePolicy, policy,
	          Properties::NON_VIRTUAL,
	          __void__setDrawablePolicy__DrawablePolicy,
	          "Set how loaded drawables should be handled w.r.t their display list/vertex buffer object/vertex array settings. ",
	          "");
	I_Method0(osgDB::DatabasePager::DrawablePolicy, getDrawablePolicy,
	          Properties::NON_VIRTUAL,
	          __DrawablePolicy__getDrawablePolicy,
	          "Get how loaded drawables should be handled w.r.t their display list/vertex buffer object/vertex array settings. ",
	          "");
	I_Method2(void, setUnrefImageDataAfterApplyPolicy, IN, bool, changeAutoUnRef, IN, bool, valueAutoUnRef,
	          Properties::NON_VIRTUAL,
	          __void__setUnrefImageDataAfterApplyPolicy__bool__bool,
	          "Set whether newly loaded textures should have their UnrefImageDataAfterApply set to a specified value. ",
	          "");
	I_Method2(void, getUnrefImageDataAfterApplyPolicy, IN, bool &, changeAutoUnRef, IN, bool &, valueAutoUnRef,
	          Properties::NON_VIRTUAL,
	          __void__getUnrefImageDataAfterApplyPolicy__bool_R1__bool_R1,
	          "Get whether newly loaded textures should have their UnrefImageDataAfterApply set to a specified value. ",
	          "");
	I_Method2(void, setMaxAnisotropyPolicy, IN, bool, changeAnisotropy, IN, float, valueAnisotropy,
	          Properties::NON_VIRTUAL,
	          __void__setMaxAnisotropyPolicy__bool__float,
	          "Set whether newly loaded textures should have their MaxAnisotopy set to a specified value. ",
	          "");
	I_Method2(void, getMaxAnisotropyPolicy, IN, bool &, changeAnisotropy, IN, float &, valueAnisotropy,
	          Properties::NON_VIRTUAL,
	          __void__getMaxAnisotropyPolicy__bool_R1__float_R1,
	          "Set whether newly loaded textures should have their MaxAnisotopy set to a specified value. ",
	          "");
	I_Method0(bool, requiresUpdateSceneGraph,
	          Properties::NON_VIRTUAL,
	          __bool__requiresUpdateSceneGraph,
	          "Return true if there are pending updates to the scene graph that require a call to updateSceneGraph(double). ",
	          "");
	I_Method1(void, updateSceneGraph, IN, const osg::FrameStamp &, frameStamp,
	          Properties::VIRTUAL,
	          __void__updateSceneGraph__C5_osg_FrameStamp_R1,
	          "Merge the changes to the scene graph by calling calling removeExpiredSubgraphs then addLoadedDataToSceneGraph. ",
	          "Note, must only be called from single thread update phase. ");
	I_Method2(void, setCompileGLObjectsForContextID, IN, unsigned int, contextID, IN, bool, on,
	          Properties::NON_VIRTUAL,
	          __void__setCompileGLObjectsForContextID__unsigned_int__bool,
	          "Turn the compilation of rendering objects for specified graphics context on (true) or off(false). ",
	          "");
	I_Method1(bool, getCompileGLObjectsForContextID, IN, unsigned int, contextID,
	          Properties::NON_VIRTUAL,
	          __bool__getCompileGLObjectsForContextID__unsigned_int,
	          "Get whether the compilation of rendering objects for specified graphics context on (true) or off(false). ",
	          "");
	I_Method1(bool, requiresExternalCompileGLObjects, IN, unsigned int, contextID,
	          Properties::NON_VIRTUAL,
	          __bool__requiresExternalCompileGLObjects__unsigned_int,
	          "Return true if an external draw thread should call compileGLObjects(. ",
	          ".) or not. ");
	I_Method0(bool, requiresCompileGLObjects,
	          Properties::NON_VIRTUAL,
	          __bool__requiresCompileGLObjects,
	          "Return true if there are pending compile operations that are required. ",
	          "If requiresCompileGLObjects() return true the application should call compileGLObjects() . ");
	I_Method2(void, compileGLObjects, IN, osg::State &, state, IN, double &, availableTime,
	          Properties::VIRTUAL,
	          __void__compileGLObjects__osg_State_R1__double_R1,
	          "Compile the rendering objects (display lists,texture objects, VBO's) on loaded subgraph. ",
	          "note, should only be called from the draw thread. Note, must only be called from a valid graphics context. ");
	I_Method1(void, compileAllGLObjects, IN, osg::State &, state,
	          Properties::VIRTUAL,
	          __void__compileAllGLObjects__osg_State_R1,
	          "Compile the rendering objects (display lists,texture objects, VBO's) on loaded subgraph. ",
	          "note, should only be called from the draw thread. Note, must only be called from a valid graphics context. ");
	I_Method0(unsigned int, getFileRequestListSize,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getFileRequestListSize,
	          "Report how many items are in the _fileRequestList queue. ",
	          "");
	I_Method0(unsigned int, getDataToCompileListSize,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getDataToCompileListSize,
	          "Report how many items are in the _dataToCompileList queue. ",
	          "");
	I_Method0(unsigned int, getDataToMergeListSize,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getDataToMergeListSize,
	          "Report how many items are in the _dataToCompileList queue. ",
	          "");
	I_Method0(bool, getRequestsInProgress,
	          Properties::NON_VIRTUAL,
	          __bool__getRequestsInProgress,
	          "Report whether any requests are in the pager. ",
	          "");
	I_Method0(double, getMinimumTimeToMergeTile,
	          Properties::NON_VIRTUAL,
	          __double__getMinimumTimeToMergeTile,
	          "Get the minimum time between the first request for a tile to be loaded and the time of its merge into the main scene graph. ",
	          "");
	I_Method0(double, getMaximumTimeToMergeTile,
	          Properties::NON_VIRTUAL,
	          __double__getMaximumTimeToMergeTile,
	          "Get the maximum time between the first request for a tile to be loaded and the time of its merge into the main scene graph. ",
	          "");
	I_Method0(double, getAverageTimeToMergeTiles,
	          Properties::NON_VIRTUAL,
	          __double__getAverageTimeToMergeTiles,
	          "Get the average time between the first request for a tile to be loaded and the time of its merge into the main scene graph. ",
	          "");
	I_Method0(void, resetStats,
	          Properties::NON_VIRTUAL,
	          __void__resetStats,
	          "Reset the Stats variables. ",
	          "");
	I_StaticMethod0(osg::ref_ptr< osgDB::DatabasePager > &, prototype,
	                __osg_ref_ptrT1_DatabasePager__R1__prototype_S,
	                "get the prototype singleton used by DatabasePager::create(). ",
	                "");
	I_StaticMethod0(osgDB::DatabasePager *, create,
	                __DatabasePager_P1__create_S,
	                "create a DatabasePager by cloning DatabasePager::prototype(). ",
	                "");
	I_ProtectedMethod1(bool, isCompiled, IN, osg::Texture *, texture,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __bool__isCompiled__osg_Texture_P1,
	                   "",
	                   "");
	I_ProtectedMethod1(bool, isCompiled, IN, osg::StateSet *, stateSet,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __bool__isCompiled__osg_StateSet_P1,
	                   "",
	                   "");
	I_ProtectedMethod1(bool, isCompiled, IN, const osg::Drawable *, drawable,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __bool__isCompiled__C5_osg_Drawable_P1,
	                   "",
	                   "");
	I_ProtectedMethod1(void, removeExpiredSubgraphs, IN, const osg::FrameStamp &, frameStamp,
	                   Properties::VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__removeExpiredSubgraphs__C5_osg_FrameStamp_R1,
	                   "Iterate through the active PagedLOD nodes children removing children which havn't been visited since specified expiryTime. ",
	                   "note, should be only be called from the update thread. ");
	I_ProtectedMethod1(void, expiry_removeExpiredSubgraphs, IN, const osg::FrameStamp &, frameStamp,
	                   Properties::VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__expiry_removeExpiredSubgraphs__C5_osg_FrameStamp_R1,
	                   "Old expiry delay based removeExpiredSubgraphs. ",
	                   "");
	I_ProtectedMethod1(void, capped_removeExpiredSubgraphs, IN, const osg::FrameStamp &, frameStamp,
	                   Properties::VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__capped_removeExpiredSubgraphs__C5_osg_FrameStamp_R1,
	                   "New capped based removeExpiredSubgraphs. ",
	                   "");
	I_ProtectedMethod1(void, addLoadedDataToSceneGraph, IN, const osg::FrameStamp &, frameStamp,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__addLoadedDataToSceneGraph__C5_osg_FrameStamp_R1,
	                   "Add the loaded data to the scene graph. ",
	                   "");
	I_SimpleProperty(bool, AcceptNewDatabaseRequests, 
	                 __bool__getAcceptNewDatabaseRequests, 
	                 __void__setAcceptNewDatabaseRequests__bool);
	I_SimpleProperty(double, AverageTimeToMergeTiles, 
	                 __double__getAverageTimeToMergeTiles, 
	                 0);
	I_IndexedProperty(bool, CompileGLObjectsForContextID, 
	                  __bool__getCompileGLObjectsForContextID__unsigned_int, 
	                  __void__setCompileGLObjectsForContextID__unsigned_int__bool, 
	                  0);
	I_SimpleProperty(unsigned int, DataToCompileListSize, 
	                 __unsigned_int__getDataToCompileListSize, 
	                 0);
	I_SimpleProperty(unsigned int, DataToMergeListSize, 
	                 __unsigned_int__getDataToMergeListSize, 
	                 0);
	I_SimpleProperty(bool, DatabasePagerThreadPause, 
	                 __bool__getDatabasePagerThreadPause, 
	                 __void__setDatabasePagerThreadPause__bool);
	I_ArrayProperty(osgDB::DatabasePager::DatabaseThread *, DatabaseThread, 
	                __DatabaseThread_P1__getDatabaseThread__unsigned_int, 
	                0, 
	                __unsigned_int__getNumDatabaseThreads, 
	                0, 
	                0, 
	                0);
	I_SimpleProperty(bool, DeleteRemovedSubgraphsInDatabaseThread, 
	                 __bool__getDeleteRemovedSubgraphsInDatabaseThread, 
	                 __void__setDeleteRemovedSubgraphsInDatabaseThread__bool);
	I_SimpleProperty(bool, DoPreCompile, 
	                 __bool__getDoPreCompile, 
	                 __void__setDoPreCompile__bool);
	I_SimpleProperty(osgDB::DatabasePager::DrawablePolicy, DrawablePolicy, 
	                 __DrawablePolicy__getDrawablePolicy, 
	                 __void__setDrawablePolicy__DrawablePolicy);
	I_SimpleProperty(double, ExpiryDelay, 
	                 __double__getExpiryDelay, 
	                 __void__setExpiryDelay__double);
	I_SimpleProperty(int, ExpiryFrames, 
	                 __int__getExpiryFrames, 
	                 __void__setExpiryFrames__int);
	I_SimpleProperty(unsigned int, FileRequestListSize, 
	                 __unsigned_int__getFileRequestListSize, 
	                 0);
	I_SimpleProperty(unsigned int, MaximumNumOfObjectsToCompilePerFrame, 
	                 __unsigned_int__getMaximumNumOfObjectsToCompilePerFrame, 
	                 __void__setMaximumNumOfObjectsToCompilePerFrame__unsigned_int);
	I_SimpleProperty(double, MaximumTimeToMergeTile, 
	                 __double__getMaximumTimeToMergeTile, 
	                 0);
	I_SimpleProperty(double, MinimumTimeAvailableForGLCompileAndDeletePerFrame, 
	                 __double__getMinimumTimeAvailableForGLCompileAndDeletePerFrame, 
	                 __void__setMinimumTimeAvailableForGLCompileAndDeletePerFrame__double);
	I_SimpleProperty(double, MinimumTimeToMergeTile, 
	                 __double__getMinimumTimeToMergeTile, 
	                 0);
	I_SimpleProperty(double, ReleaseDelay, 
	                 __double__getReleaseDelay, 
	                 __void__setReleaseDelay__double);
	I_SimpleProperty(int, ReleaseFrames, 
	                 __int__getReleaseFrames, 
	                 __void__setReleaseFrames__int);
	I_SimpleProperty(bool, RequestsInProgress, 
	                 __bool__getRequestsInProgress, 
	                 0);
	I_SimpleProperty(OpenThreads::Thread::ThreadPriority, SchedulePriority, 
	                 0, 
	                 __int__setSchedulePriority__OpenThreads_Thread_ThreadPriority);
	I_SimpleProperty(double, TargetFrameRate, 
	                 __double__getTargetFrameRate, 
	                 __void__setTargetFrameRate__double);
	I_SimpleProperty(unsigned int, TargetMaximumNumberOfPageLOD, 
	                 __unsigned_int__getTargetMaximumNumberOfPageLOD, 
	                 __void__setTargetMaximumNumberOfPageLOD__unsigned_int);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osgDB::DatabasePager::DatabaseThread::Mode)
	I_DeclaringFile("osgDB/DatabasePager");
	I_EnumLabel(osgDB::DatabasePager::DatabaseThread::HANDLE_ALL_REQUESTS);
	I_EnumLabel(osgDB::DatabasePager::DatabaseThread::HANDLE_NON_HTTP);
	I_EnumLabel(osgDB::DatabasePager::DatabaseThread::HANDLE_ONLY_HTTP);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgDB::DatabasePager::DatabaseThread)
	I_DeclaringFile("osgDB/DatabasePager");
	I_BaseType(osg::Referenced);
	I_BaseType(OpenThreads::Thread);
	I_Constructor3(IN, osgDB::DatabasePager *, pager, IN, osgDB::DatabasePager::DatabaseThread::Mode, mode, IN, const std::string &, name,
	               ____DatabaseThread__DatabasePager_P1__Mode__C5_std_string_R1,
	               "",
	               "");
	I_Constructor2(IN, const osgDB::DatabasePager::DatabaseThread &, dt, IN, osgDB::DatabasePager *, pager,
	               ____DatabaseThread__C5_DatabaseThread_R1__DatabasePager_P1,
	               "",
	               "");
	I_Method1(void, setDone, IN, bool, done,
	          Properties::NON_VIRTUAL,
	          __void__setDone__bool,
	          "",
	          "");
	I_Method0(bool, getDone,
	          Properties::NON_VIRTUAL,
	          __bool__getDone,
	          "",
	          "");
	I_Method1(void, setActive, IN, bool, active,
	          Properties::NON_VIRTUAL,
	          __void__setActive__bool,
	          "",
	          "");
	I_Method0(bool, getActive,
	          Properties::NON_VIRTUAL,
	          __bool__getActive,
	          "",
	          "");
	I_Method0(int, cancel,
	          Properties::VIRTUAL,
	          __int__cancel,
	          "Cancel the thread. ",
	          "Equivalent to SIGKILL.0 if normal, -1 if errno set, errno code otherwise.  ");
	I_Method0(void, run,
	          Properties::VIRTUAL,
	          __void__run,
	          "Thread's run method. ",
	          "Must be implemented by derived classes. This is where the action happens. ");
	I_SimpleProperty(bool, Active, 
	                 __bool__getActive, 
	                 __void__setActive__bool);
	I_SimpleProperty(bool, Done, 
	                 __bool__getDone, 
	                 __void__setDone__bool);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::observer_ptr< osg::GraphicsContext >)
	I_DeclaringFile("osg/observer_ptr");
	I_BaseType(osg::Observer);
	I_Constructor0(____observer_ptr,
	               "",
	               "");
	I_Constructor1(IN, osg::GraphicsContext *, t,
	               Properties::NON_EXPLICIT,
	               ____observer_ptr__T_P1,
	               "",
	               "");
	I_Constructor1(IN, const osg::observer_ptr< osg::GraphicsContext > &, rp,
	               Properties::NON_EXPLICIT,
	               ____observer_ptr__C5_observer_ptr_R1,
	               "",
	               "");
	I_Method0(osg::ref_ptr< osg::GraphicsContext >, lock,
	          Properties::NON_VIRTUAL,
	          __ref_ptrT1_T___lock,
	          "",
	          "");
	I_Method0(osg::GraphicsContext *, get,
	          Properties::NON_VIRTUAL,
	          __T_P1__get,
	          "",
	          "");
	I_Method0(bool, valid,
	          Properties::NON_VIRTUAL,
	          __bool__valid,
	          "",
	          "");
	I_ProtectedMethod1(void, objectDeleted, IN, void *, x,
	                   Properties::VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__objectDeleted__void_P1,
	                   "objectDeleted is called when the observed object is about to be deleted. ",
	                   "The observer will be automatically removed from the observerd objects observer set so there is no need for the objectDeleted implementation to call removeObserver() on the observed object. ");
	I_SimpleProperty(osg::GraphicsContext *, , 
	                 __T_P1__get, 
	                 0);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::ref_ptr< osg::PagedLOD >)
	I_DeclaringFile("osg/ref_ptr");
	I_Constructor0(____ref_ptr,
	               "",
	               "");
	I_Constructor1(IN, osg::PagedLOD *, ptr,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__T_P1,
	               "",
	               "");
	I_Constructor1(IN, const osg::ref_ptr< osg::PagedLOD > &, rp,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__C5_ref_ptr_R1,
	               "",
	               "");
	I_Method0(osg::PagedLOD *, get,
	          Properties::NON_VIRTUAL,
	          __T_P1__get,
	          "",
	          "");
	I_Method0(bool, valid,
	          Properties::NON_VIRTUAL,
	          __bool__valid,
	          "",
	          "");
	I_Method0(osg::PagedLOD *, release,
	          Properties::NON_VIRTUAL,
	          __T_P1__release,
	          "",
	          "");
	I_Method1(void, swap, IN, osg::ref_ptr< osg::PagedLOD > &, rp,
	          Properties::NON_VIRTUAL,
	          __void__swap__ref_ptr_R1,
	          "",
	          "");
	I_SimpleProperty(osg::PagedLOD *, , 
	                 __T_P1__get, 
	                 0);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::ref_ptr< osgDB::DatabasePager >)
	I_DeclaringFile("osg/ref_ptr");
	I_Constructor0(____ref_ptr,
	               "",
	               "");
	I_Constructor1(IN, osgDB::DatabasePager *, ptr,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__T_P1,
	               "",
	               "");
	I_Constructor1(IN, const osg::ref_ptr< osgDB::DatabasePager > &, rp,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__C5_ref_ptr_R1,
	               "",
	               "");
	I_Method0(osgDB::DatabasePager *, get,
	          Properties::NON_VIRTUAL,
	          __T_P1__get,
	          "",
	          "");
	I_Method0(bool, valid,
	          Properties::NON_VIRTUAL,
	          __bool__valid,
	          "",
	          "");
	I_Method0(osgDB::DatabasePager *, release,
	          Properties::NON_VIRTUAL,
	          __T_P1__release,
	          "",
	          "");
	I_Method1(void, swap, IN, osg::ref_ptr< osgDB::DatabasePager > &, rp,
	          Properties::NON_VIRTUAL,
	          __void__swap__ref_ptr_R1,
	          "",
	          "");
	I_SimpleProperty(osgDB::DatabasePager *, , 
	                 __T_P1__get, 
	                 0);
END_REFLECTOR

STD_LIST_REFLECTOR(std::list< osg::ref_ptr< osg::PagedLOD > >)

STD_MAP_REFLECTOR(std::map< unsigned int COMMA  osgDB::DatabasePager::DataToCompile >)

STD_PAIR_REFLECTOR(std::pair< osgDB::DatabasePager::StateSetList COMMA  osgDB::DatabasePager::DrawableList >)

STD_SET_REFLECTOR(std::set< osg::ref_ptr< osg::StateSet > >)

STD_SET_REFLECTOR(std::set< unsigned int >)

STD_VECTOR_REFLECTOR(std::vector< osg::observer_ptr< osg::GraphicsContext > >)

