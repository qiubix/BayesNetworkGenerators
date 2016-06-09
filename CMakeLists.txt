#Project name
PROJECT(BayesNetworkGenerators)

# CMake required version must be >= 2.6
cmake_minimum_required(VERSION 2.6)

# Find DisCODe installation
FIND_PACKAGE(DisCODe REQUIRED)

# PCL library
FIND_PACKAGE(PCL 1.3 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
MESSAGE("PCL include: ${PCL_INCLUDE_DIRS}")
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# Use CMake macros provided with DisCODe
set(CMAKE_MODULE_PATH ${DisCODe_DIR} ${CMAKE_MODULE_PATH})
include(DisCODeMacros)

# Testing
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
include(GoogleMock)
include(TestSuite)
set(CMAKE_AUTOMOC ON)

# Default build type
include(DefaultBuildType)
set_default_build_type(Debug)

# Set default install prefix to dist folder
IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  SET(CMAKE_INSTALL_PREFIX
      ${CMAKE_SOURCE_DIR}/dist CACHE PATH "${CMAKE_PROJECT_NAME} install prefix" FORCE
  )
ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)

