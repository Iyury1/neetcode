cmake_minimum_required(VERSION 3.10)


project(Practice)


add_executable(Practice)


target_sources(Practice PRIVATE
    MaxConsecutiveOnes.cpp
    ValidParenthesis.cpp
    DesignLinkedList.cpp
    ReverseLinkedList.cpp
    MergeLinkedLists.cpp
)