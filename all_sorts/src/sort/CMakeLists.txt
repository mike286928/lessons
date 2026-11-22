set(SOURCES
    sort.cpp
)

add_library(${SORT_LIB} SHARED ${SOURCES})

target_include_directories(${SORT_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(WIN32)
    set_target_properties(${SORT_LIB} PROPERTIES
        WINDOWS_EXPORT_ALL_SYMBOLS ON
        PREFIX ""
    )
endif()
