set(Sources
        # Sources
        "DecisionTreeNode.cpp"
)

set(Dirs
        "../include"
)

add_library(src ${Sources})
target_include_directories(src PUBLIC ${Dirs})