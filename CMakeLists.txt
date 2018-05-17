cmake_minimum_required(VERSION 3.10)
project(SFMLGame)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -pedantic -mwindows")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ID:/Code/SFML/include -LD:/Code/SFML/lib")

set(FILES src/main.cpp src/Engine.cpp src/Engine.hpp src/Components/Component.hpp src/Components/Position.cpp src/Components/Position.hpp src/Components/Renderer.cpp src/Components/Renderer.hpp src/Components/Collider.cpp src/Components/Collider.hpp src/Components/Components.hpp src/Components/Component.cpp src/Entity.cpp src/Entity.hpp src/Components/FPSCounter.cpp src/Components/FPSCounter.hpp)
add_executable(SFMLGame ${FILES})

target_link_libraries(SFMLGame sfml-audio sfml-graphics sfml-window sfml-system)
