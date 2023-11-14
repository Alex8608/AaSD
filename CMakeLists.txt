# CMakeList.txt: проект CMake для lab1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

if(MSVC)
    # Генерируем статическую заглушку для динамических библиотек
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    # Включаем высокий уровень предупреждений
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

project ("AaSD")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (lab1 "lab1/lab1.cpp" "lab1/lab1.h")

add_executable (lab2 "lab2/lab2.cpp" "lab2/lab2.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
