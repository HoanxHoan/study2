add_executable(vec_create_ut vec_create_ut.c)
add_executable(vec_traverse_ut vec_traverse_ut.c)
add_executable(vec_stack_ut vec_stack_ut.c)

foreach (p vec_create_ut vec_traverse_ut vec_stack_ut)
  target_link_libraries(${p} bkcgen)
endforeach()