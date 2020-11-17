cmake_minimum_required(VERSION 3.7)
project(cmakeCppUTestExample VERSION 0.1.0)

add_compile_options(-Wall -Werror)

set(APP_NAME exampleApp)
set(APP_LIB_NAME exampleAppLib)

add_subdirectory(src)

option(COMPILE_TESTS "Compile the tests" OFF)
if(COMPILE_TESTS)
  add_subdirectory(unittests)
endif(COMPILE_TESTS)