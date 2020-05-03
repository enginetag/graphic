cmake_minimum_required(VERSION 3.16)
project(graphic)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

#устанавливаем путь до корневого каталога SFML
set(SFML_ROOT_DIR "C:/sfml")
#Генерируем SFML_DIR на основании SFML_ROOT_DIR
set(SFML_DIR "${SFML_ROOT_DIR}/lib/cmake/SFML")

#Ищем компоненты graphics window system библиотеки SFML 2.5
find_package(SFML REQUIRED system window graphics network audio)
#find_package(SFML 2.5 REQUIRED COMPONENTS system window graphics network audio)

#Устанавливаем переменную SFML_LIBRARIES со списком библиотек
set(SFML_LIBRARIES sfml-graphics sfml-window sfml-system)

#Выводим список библиотек
message(STATUS "SFML libraries: ${SFML_LIBRARIES}")

add_executable(${PROJECT_NAME} main.cpp)

#Добавляем библиотеки на линковку с целью
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})


#[[
#include_directories(${SFML_INCLUDE_DIR})
include_directories("c:/sfml/include")


link_directories("C:/sfml/lib")

add_executable(graphic main.cpp)

#target_link_libraries(graphic ${SFML_LIBRARIES})
target_link_libraries(graphic "c:/sfml/lib")
]]
