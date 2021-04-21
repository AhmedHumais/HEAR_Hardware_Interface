cmake_minimum_required(VERSION 2.8.3)
project(hear_hardware_interface)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  hear_architecture
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS
    roscpp
    hear_architecture
)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include/HEAR_NAVIO_Interface/Navio2
  ${CMAKE_CURRENT_SOURCE_DIR}/include/HEAR_NAVIO_Interface/Navio2/Common
  ${catkin_INCLUDE_DIRS}
)

FILE(GLOB SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Navio2_cpp/*.cpp)

add_library(${PROJECT_NAME}
${SOURCE_FILES}
)

add_executable(${PROJECT_NAME}_node ${SOURCE_FILES})
add_dependencies(${PROJECT_NAME}_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})
