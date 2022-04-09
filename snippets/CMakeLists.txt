find_package(fmt REQUIRED)

add_library(bug-or-error1 bug-or-error1.cpp)
add_library(bug-or-error2 bug-or-error2.cpp)
add_library(bug-or-error3 bug-or-error3.cpp)
add_library(bug-or-error4 bug-or-error4.cpp)
add_library(bug-or-error5 bug-or-error5.cpp)
add_library(bug-or-error6 bug-or-error6.cpp)

add_library(if-youre-lucky if-youre-lucky.cpp)
target_compile_features(if-youre-lucky
                        PUBLIC cxx_std_20)

add_executable(vector-overflow vector-overflow.cpp)
target_compile_features(vector-overflow PUBLIC cxx_std_20)
target_link_libraries(vector-overflow PRIVATE fmt::fmt)
if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug" OR "${CMAKE_BUILD_TYPE}" STREQUAL
                                             "Test")
  add_test(vector-overflow vector-overflow)
  set_tests_properties(vector-overflow PROPERTIES WILL_FAIL ON)
endif()
