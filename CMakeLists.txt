cmake_minimum_required(VERSION 3.10)


project(Practice)


add_executable(Practice)


target_sources(Practice PRIVATE
    "MaxConsecutiveOnes.cpp"
    "Stack/ValidParenthesis.cpp"
    "LinkedList/DesignLinkedList.cpp"
    "LinkedList/ReverseLinkedList.cpp"
    "LinkedList/MergeLinkedLists.cpp"
    "LinkedList/BrowserHistory.cpp"
)