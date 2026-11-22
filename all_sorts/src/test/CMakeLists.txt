set(SOURCES
    test_bubble_sort_classic.cpp
)

add_executable(test_bubble_sort_classic ${SOURCES})

target_link_libraries(test_bubble_sort_classic
    gtest
    ${SORT_LIB}
)

add_test(NAME test_bubble_sort_classic COMMAND test_bubble_sort_classic)

set(SOURCES
        test_bubble_sort_no_swaped_optimized.cpp
)

add_executable(test_bubble_sort_no_swaped_opt ${SOURCES})

target_link_libraries(test_bubble_sort_no_swaped_opt
    gtest
    ${SORT_LIB}
)

add_test(NAME test_bubble_sort_no_swaped_optimized COMMAND test_bubble_sort_no_swaped_opt)

set(SOURCES
        test_bubble_sort_last_swap_optimized.cpp
)

add_executable(test_bubble_sort_last_swap_opt ${SOURCES})

target_link_libraries(test_bubble_sort_last_swap_opt
    gtest
    ${SORT_LIB}
)

add_test(NAME test_bubble_sort_last_swap_optimized COMMAND test_bubble_sort_last_swap_opt)

set(SOURCES
    test_shaker_sort.cpp
)

add_executable(test_shaker_sort ${SOURCES})

target_link_libraries(test_shaker_sort
    gtest
    ${SORT_LIB}
)

add_test(NAME test_shaker_sort COMMAND test_shaker_sort)

set(SOURCES
        test_shaker_sort_last_swap_optimized.cpp
)

add_executable(test_shaker_sort_last_swap_opt ${SOURCES})

target_link_libraries(test_shaker_sort_last_swap_opt
    gtest
    ${SORT_LIB}
)

add_test(NAME test_shaker_sort_last_swap_optimized COMMAND test_shaker_sort_last_swap_opt)

set(SOURCES
    test_odd_even_sort.cpp
)

add_executable(test_odd_even_sort ${SOURCES})

target_link_libraries(test_odd_even_sort
    gtest
    ${SORT_LIB}
)

add_test(NAME test_odd_even_sort COMMAND test_odd_even_sort)

set(SOURCES
    test_comb_sort.cpp
)

add_executable(test_comb_sort ${SOURCES})

target_link_libraries(test_comb_sort
    gtest
    ${SORT_LIB}
)

add_test(NAME test_comb_sort COMMAND test_comb_sort)

set(SOURCES
    test_selection_sort.cpp
)

add_executable(test_selection_sort ${SOURCES})

target_link_libraries(test_selection_sort
    gtest
    ${SORT_LIB}
)

add_test(NAME test_selection_sort COMMAND test_selection_sort)

set(SOURCES
    test_insertion_sort.cpp
)

add_executable(test_insertion_sort ${SOURCES})

target_link_libraries(test_insertion_sort
    gtest
    ${SORT_LIB}
)

add_test(NAME test_insertion_sort COMMAND test_insertion_sort)

set(SOURCES
    test_binary_insertion_sort.cpp
)

add_executable(test_binary_insertion_sort ${SOURCES})

target_link_libraries(test_binary_insertion_sort
    gtest
    ${SORT_LIB}
)

add_test(NAME test_binary_insertion_sort COMMAND test_binary_insertion_sort)

set(SOURCES
    test_shell_sort.cpp
)

add_executable(test_shell_sort ${SOURCES})

target_link_libraries(test_shell_sort
    gtest
    ${SORT_LIB}
)

add_test(NAME test_shell_sort COMMAND test_shell_sort)
