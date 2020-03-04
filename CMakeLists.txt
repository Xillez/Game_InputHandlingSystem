# Set cmake minimum
cmake_minimum_required(VERSION 3.10)

# Set project name
set(PROJECT_NAME "input")
set(VERSION "v0.1")

# "true" to build for release or "false" to build for debug.
set(DEBUG_BUILD "true")

# "true" to enable logging or "false" to disable.
set(LOGGING "true")

if(UNIX)
  message("Linux build")
  set(LINUX 1)
  set(WINDOWS 0)
elseif(WIN32)
  message("Windows build")
  set(LINUX 0)
  set(WINDOWS 1)
endif()

# Automatic setup of release and debug build setting
if(DEBUG_BUILD STREQUAL "true")
  set(CMAKE_BUILD_TYPE "Debug")
else()
  set(CMAKE_BUILD_TYPE "Release")
  set(LOGGING "false")
endif()

# Set cmake options + custom compiler
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set project name
project(${PROJECT_NAME})

# Set the output to the bin folder
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
#set(OUTPUT_DEBUG_PATH ${EXECUTABLE_OUTPUT_PATH}/debug)
#set(OUTPUT_RELEASE_PATH ${EXECUTABLE_OUTPUT_PATH}/release)
set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/source)
set(CMAKE_SOURCE_DIR ${PROJECT_SOURCE_DIR})

# OS specific before executable addition
if(WINDOWS)
  set(OS_NAME "WIN32")
endif(WINDOWS)

if(LINUX)
  set(OS_NAME "LINUX")
endif(LINUX)

# Pass CMake settings to source header
configure_file(
  "${PROJECT_SOURCE_DIR}/config/Config.hpp.in"
  "${PROJECT_SOURCE_DIR}/config/Config.hpp"
  @ONLY
  )

# Cross platform opengl
find_package(OpenGL REQUIRED)

# OS specific before executable addition
if(WINDOWS)
  find_package(OpenGL REQUIRED)

  set(GLM_INCLUDE_DIRS ${PROJECT_INCLUDE_PATH})
  set(GLEW_INCLUDE_DIRS ${PROJECT_INCLUDE_PATH})
  set(GLEW_LIBRARIES ${PROJECT_LIB_PATH})

  include_directories(${GLM_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
  
  find_package(GLEW REQUIRED)
  if (GLEW_FOUND)
    #include_directories(${GLEW_INCLUDE_DIRS})
  endif()
endif(WINDOWS)

if(APPLE)
	#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${GLEW_INCLUDE_DIRS}")
endif(APPLE)

if(LINUX)
	#
endif(LINUX)

# Add all cpp files used in the program
add_executable(${PROJECT_NAME} 
	#src
	${PROJECT_SOURCE_DIR}/source/src/main.cpp
	${PROJECT_SOURCE_DIR}/source/src/glfw_setup.cpp
	
	#input
	${PROJECT_SOURCE_DIR}/source/input/InputHandler.cpp
	${PROJECT_SOURCE_DIR}/source/input/InputInterface.cpp
)

# Inlcude 
include(${CMAKE_CURRENT_SOURCE_DIR}/DoxygenLists.txt)

# OS specific before executable addition
if(WINDOWS)
  target_link_libraries(${PROJECT_NAME} glfw GLEW::GLEW)#${GLEW_LIBRARIES}) #Glew::Glew)
  
  execDoxygen()
endif(WINDOWS)

if(APPLE)
	#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${GLEW_INCLUDE_DIRS}")
endif(APPLE)

if(LINUX)
	find_package(GLEW REQUIRED)
	find_package(OpenGL REQUIRED)
	find_package(glfw3 3.2 REQUIRED)

	# Link the packages
	target_link_libraries(${PROJECT_NAME}
		PRIVATE ${OPENGL_LIBRARIES}
		PRIVATE ${GLEW_LIBRARY}
		PRIVATE glfw
	)
	
	execDoxygen()
endif(LINUX)

# File copy example
#file(COPY  ${PROJECT_SOURCE_DIR}/libs/dll/glew32.dll DESTINATION ${PROJECT_BINARY_DIR})




# OS specific before executable addition
if(WINDOWS)
  execDoxygen()
  #add_subdirectory(ASSIMP)
  #link_directories(${PROJECT_BINARY_DIR})
endif(WINDOWS)

if(LINUX)
  execDoxygen()
endif(LINUX)

# File copy example
#file(COPY  ${PROJECT_SOURCE_DIR}/libs/dll/glew32.dll DESTINATION ${PROJECT_BINARY_DIR})