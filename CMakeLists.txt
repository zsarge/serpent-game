cmake_minimum_required(VERSION 3.16)

project(serpent-game)

file(GLOB SOURCES "src/*.cpp")

add_executable(
	serpent.out
	${SOURCES}
)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(serpent.out ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

