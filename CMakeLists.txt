cmake_minimum_required(VERSION ${MINIMUM_CMAKE_VERSION})

set(This ByteofSin_Logging)

set(Headers
    include/Logging/iLogger.h
    include/Logging/Severity.h
    include/Logging/OutputStreamLogger.hpp
    include/Logging/Log.h
)

set(Sources 
    src/Log.cpp
)

add_library(${This} STATIC ${Headers} ${Sources})

set_target_properties(${This} PROPERTIES
    FOLDER Libraries
    LINKER_LANGUAGE CXX
)

target_include_directories(${This} PUBLIC include)
