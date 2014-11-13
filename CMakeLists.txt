cmake_minimum_required(VERSION 2.8)
project(LibLZ)

option(ENABLE_STATIC "Enable Static Libraries" Off)
option(ENABLE_SHARED "Enable Shared Libraries [DEFAULT]" On)

if (ENABLE_STATIC)
		unset(ENABLE_SHARED)
		set(LIBLZ_OBJ_TYPE STATIC)
else()
		set(LIBLZ_OBJ_TYPE SHARED)
endif()

set(LIBLZ_INS_PATH ${PROJECT_BINARY_DIR}/install)
set(LIBLZ_LIB_PATH ${LIBLZ_INS_PATH}/lib)
set(LIBLZ_INC_PATH ${LIBLZ_INS_PATH}/include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIBLZ_LIB_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIBLZ_LIB_PATH})

###########################################################
# RPATHING CRAP
# use, i.e. don't skip the full RPATH for the build tree
set(CMAKE_SKIP_BUILD_RPATH  FALSE)

# when building, don't use the install RPATH already
# (but later on when installing)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# the RPATH to be used when installing, but only if it's not
# a system directory
list(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)

IF("${isSystemDir}" STREQUAL "-1")
   set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
endif("${isSystemDir}" STREQUAL "-1")





include(CheckCCompilerFlag)

check_c_compiler_flag(-fvisibility=hidden HAS_VISIBILITY_HIDDEN)

if(HAS_VISIBILITY_HIDDEN)
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fvisibility=hidden")
		add_definitions(-DHAS_VISIBILITY_HIDDEN)
endif()



include_directories(
		${LIBLZ_INC_PATH}
		${CMAKE_CURRENT_SOURCE_DIR}/src
)



add_subdirectory(src)
