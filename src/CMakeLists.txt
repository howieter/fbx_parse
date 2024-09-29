cmake_minimum_required(VERSION 3.8)
project(fbx-dump)

# Установить стандарт C++ и общие флаги компиляции для всех платформ
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Найти и подключить ZLIB
find_package(ZLIB REQUIRED)

# Указать директории для включения
include_directories(${ZLIB_INCLUDE_DIRS})

# Указать исходные файлы
set(SOURCE_FILES fbxdocument.cpp fbxnode.cpp fbxutil.cpp fbxproperty.cpp)

# Собрать исполняемые файлы
add_executable(fbx-dump main.cpp ${SOURCE_FILES})
target_link_libraries(fbx-dump ${ZLIB_LIBRARIES})

add_executable(fbxdump fbxdump.cpp ${SOURCE_FILES})
target_link_libraries(fbxdump ${ZLIB_LIBRARIES})

# Добавить сборку динамической библиотеки
add_library(fbx-dump-lib SHARED ${SOURCE_FILES})

# Сборка либы для различных ОС
if(APPLE)
    set_target_properties(fbx-dump-lib PROPERTIES SUFFIX ".dylib")
elseif(UNIX)
    set_target_properties(fbx-dump-lib PROPERTIES SUFFIX ".so")
endif()

# Линковка с ZLIB для библиотеки
target_link_libraries(fbx-dump-lib ${ZLIB_LIBRARIES})
