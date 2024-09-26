cmake_minimum_required(VERSION 3.8)
project(fbx-writer)

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
add_executable(fbx-writer main.cpp ${SOURCE_FILES})
target_link_libraries(fbx-writer ${ZLIB_LIBRARIES})

add_executable(fbxdump fbxdump.cpp ${SOURCE_FILES})
target_link_libraries(fbxdump ${ZLIB_LIBRARIES})

# Добавить сборку динамической библиотеки (DLL для Windows, .dylib для macOS, .so для Linux)
add_library(fbx-writer-lib SHARED ${SOURCE_FILES})

# Условные настройки для различных операционных систем
if(WIN32)
    # Настройки для Windows
    target_compile_definitions(fbx-writer-lib PRIVATE FBXWRITER_EXPORTS)
    set_target_properties(fbx-writer-lib PROPERTIES SUFFIX ".dll")
elseif(APPLE)
    # Настройки для macOS
    set_target_properties(fbx-writer-lib PROPERTIES SUFFIX ".dylib")
    # Можно добавить дополнительные флаги для macOS, если требуется
elseif(UNIX)
    # Настройки для Linux (Ubuntu)
    set_target_properties(fbx-writer-lib PROPERTIES SUFFIX ".so")
    # Можно добавить специфичные флаги компиляции для Linux, если требуется
endif()

# Линковка с ZLIB для библиотеки
target_link_libraries(fbx-writer-lib ${ZLIB_LIBRARIES})
