cmake_minimum_required(VERSION 3.10)  # CMake version check
project(simple_example)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES Abstract_Factory.cpp)

include_directories(.)

#Add library
add_library(third_party_library
            macFactory.cpp
            winFactory.cpp )

# Add executable target with source files listed in SOURCE_FILES variable
add_executable( client_code 
                client_code.cpp)

target_link_libraries(  client_code
                        third_party_library
                        )
