SET(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(.)

# ##############################################################################
# Find required libraries
# ##############################################################################

# Find Boost, at least ver. 1.41
FIND_PACKAGE(Boost 1.41.0 COMPONENTS system REQUIRED)
include_directories(SYSTEM ${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})

# Find another necessary libraries

# Find another DCLs our one depends on
# Use macro: DISCODE_FIND_DCL(<DCL_NAME>)

# ##############################################################################
# Add source directories
# ##############################################################################

# BayesNetwork components
ADD_SUBDIRECTORY(Components)

# BayesNetwork types
ADD_SUBDIRECTORY(Types)

# Prepare config file to use from another DCLs
CONFIGURE_FILE(BayesNetworkGeneratorsConfig.cmake.in ${CMAKE_INSTALL_PREFIX}/BayesNetworkGeneratorsConfig.cmake @ONLY)
