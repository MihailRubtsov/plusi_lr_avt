cmake_minimum_required(VERSION 3.16)
project(StudentSorter LANGUAGES CXX)

# Настройка Qt6
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Основные исходные файлы
set(MAIN_SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/sortwindow.cpp
    src/fileprocessor.cpp
    work_with_files.cpp
    add_to_file.cpp
    file_g_p.cpp
    Student.cpp
    generatr.cpp
    src/generat.cpp
)

# Заголовочные файлы
set(HEADERS
    include/mainwindow.h
    include/sortwindow.h
    include/fileprocessor.h
    work_with_files.h
    add_to_file.h
    file_g_p.h
    Student.h
    generatr.h
    include/generat.h
)

# Файлы сортировки из папки sortirov
set(SORT_SOURCES
    sortirov/sich_sort.cpp
    sortirov/sort_b.cpp
    sortirov/sort_v.cpp
)

# Создаем исполняемый файл
add_executable(StudentSorter
    ${MAIN_SOURCES}
    ${HEADERS}
    ${SORT_SOURCES}
)

# Подключаем Qt модули
target_link_libraries(StudentSorter PRIVATE
    Qt6::Core
    Qt6::Widgets
)

# Указываем пути для include
target_include_directories(StudentSorter PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/sortirov
)

# Настройки стандарта C++
set_target_properties(StudentSorter PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

# Для файлов сортировки (если они не используют Qt)
set_source_files_properties(${SORT_SOURCES} PROPERTIES SKIP_AUTOMOC ON)

set(CMAKE_EXE_LINKER_FLAGS "-Wl,-rpath,/usr/lib/x86_64-linux-gnu -Wl,--disable-new-dtags")