if(DEFINED ENV{CPPUTEST_HOME})
    message(STATUS "Using CppUTest home: $ENV{CPPUTEST_HOME}")
    set(CPPUTEST_INCLUDE_DIRS $ENV{CPPUTEST_HOME}include)
    set(CPPUTEST_LIBRARIES $ENV{CPPUTEST_HOME}lib)
else()
    find_package(PkgConfig REQUIRED)
    pkg_search_module(CPPUTEST REQUIRED cpputest>=3.8)
    message(STATUS "Found CppUTest version ${CPPUTEST_VERSION}")
endif()

set(TEST_APP_NAME ${APP_NAME}_tests)
set(TEST_SOURCES
    AllTests.cpp
    test-mysum.cpp
)

find_library(CPPUTEST_LIBRARY CppUTest HINTS ${CPPUTEST_LIBRARIES}) 
find_library(CPPUTESTEXT_LIBRARY CppUTestExt HINTS ${CPPUTEST_LIBRARIES}) 

add_executable(${TEST_APP_NAME} ${TEST_SOURCES})
target_include_directories(${TEST_APP_NAME} PUBLIC ${CPPUTEST_INCLUDE_DIRS} ../src/)
target_link_libraries(${TEST_APP_NAME} ${APP_LIB_NAME} ${CPPUTEST_LIBRARY} ${CPPUTESTEXT_LIBRARY})

add_custom_command(TARGET ${TEST_APP_NAME} COMMAND ./${TEST_APP_NAME} POST_BUILD)