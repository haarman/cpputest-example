set(APP_LIB_SOURCE
    my_sum.c
)

add_library(${APP_LIB_NAME} ${APP_LIB_SOURCE})

add_executable(${APP_NAME} main.c)
target_link_libraries(${APP_NAME} ${APP_LIB_NAME})