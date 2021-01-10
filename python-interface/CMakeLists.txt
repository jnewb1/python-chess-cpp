cmake_minimum_required(VERSION 3.5)

# Find python and Boost - both are required dependencies
find_package(PythonLibs 3.8 REQUIRED)
find_package(Boost COMPONENTS python REQUIRED)

# Without this, any build libraries automatically have names "lib{x}.so"
set(CMAKE_SHARED_MODULE_PREFIX "")

# Add a shared module - modules are intended to be imported at runtime.
# - This is where you add the source files
add_library(python_chess MODULE chess.cpp)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../cpp-chess/include")

# Set up the libraries and header search paths for this target
target_link_libraries(python_chess cpp_chess ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
target_include_directories(python_chess PRIVATE ${PYTHON_INCLUDE_DIRS})