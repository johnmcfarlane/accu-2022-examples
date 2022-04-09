find_package(fmt REQUIRED)
find_package(Catch2 REQUIRED)

# pid library
add_library(pid pid.cpp)
set_target_properties(pid PROPERTIES PUBLIC_HEADER pid.h)
target_compile_features(pid PUBLIC cxx_std_20)
install(
  TARGETS pid
  EXPORT PidTargets
  PUBLIC_HEADER DESTINATION include)

# pid library unit test
add_library(catch2-main catch2-main.cpp)
target_link_libraries(catch2-main PUBLIC Catch2::Catch2)

add_executable(pid_unit_test pid.h-test.cpp)
target_link_libraries(pid_unit_test PRIVATE catch2-main pid)

add_test(pid_unit_test pid_unit_test)

# simulate support library
add_library(simulate simulate.cpp)
target_link_libraries(simulate PRIVATE fmt::fmt pid)

# approval test (happy)
add_executable(simulate_approval_happy_test simulate.h-happy-test.cpp)
target_compile_features(simulate_approval_happy_test PUBLIC cxx_std_20)
target_link_libraries(simulate_approval_happy_test PRIVATE simulate)

add_test(simulate_approval_happy_test simulate_approval_happy_test)
set_tests_properties(
  simulate_approval_happy_test PROPERTIES PASS_REGULAR_EXPRESSION
                                          "99,9.88718,-0.00853867")

# death test (-ve parameter)
add_executable(simulate_approval_negative_parameter_test
               simulate.h-negative-parameter-test.cpp)
target_compile_features(simulate_approval_negative_parameter_test
                        PUBLIC cxx_std_20)
target_link_libraries(simulate_approval_negative_parameter_test
                      PRIVATE simulate)

if("${CMAKE_BUILD_TYPE}" STREQUAL "Test")
  add_test(simulate_approval_negative_parameter_test
           simulate_approval_negative_parameter_test)
  set_tests_properties(simulate_approval_negative_parameter_test
                       PROPERTIES WILL_FAIL ON)
endif()
