cmake_minimum_required(VERSION 3.8)
project(Cplusplus_Tutorials)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
#        Vector-Iterator-Manipulation/vector_delete_all_elements_iterator.cpp
#        Vector-Iterator-Manipulation/vector_delete_element_iterator.cpp
#        Vector-Iterator-Manipulation/vector_insert_at_the_end_iterator.cpp
#        Vector-Iterator-Manipulation/vector_insert_iterator.cpp
#        bitset-tutorial.cpp
#        const_pointers.cpp
#        const_tutorial.cpp
#        fibonacci_overflow.cpp
#        flip_question_interview_bit.cpp
#        function_pointer.cpp
#        function_return_dynamic_intitalized.cpp
#        function_return_reference_error.cpp
#        function_return_variable.cpp
#        hashmap_tutorial.cpp
#        int_to_long.cpp
#        integer_pointer.cpp
#        Kruskals_Span_Tree.cpp
#        lambda-ex.cpp
#        map_tutorial.cpp
#        math_functions_tutorial.cpp
#        memory_manager.c
#        metastrings.cpp
#        Prims_Span_Tree.cpp
#        radix_sort.cpp
#        reverseiterator_tutorial.cpp
#        Split_strings.cpp
#        stack_tutorial.cpp
#        string_functions.cpp
#        strings_tutorial.cpp
#        strings_tutorial2.cpp
#        stringtokenizer.cpp
#        stringtokenizer_istringstream.cpp
#        structures_inheritance.cpp
#        TopologicalSort.cpp
#        Trie.cpp
#        unordered_map_tutorial.cpp
#        "vector_comparator_tutorial(non-static).cpp"
#        vector_comparator_tutorial.cpp
#        vector_iterator_tutorial.cpp
#        vector_tutorial.cpp
#        vector_tutorial_sort.cpp
#        AbstractClasses/AbstractClassDemo.cpp
#        AbstractClasses/VirtualFunctionDemo.cpp
#        SystemDesign/TinyUrl.cpp
#        SystemDesign/TinyUrl.h
        AbstractClasses/DiamondProblem.cpp)

include_directories(.)
include_directories(Vector-Iterator-Manipulation)

add_executable(Cplusplus_Tutorials ${SOURCE_FILES})