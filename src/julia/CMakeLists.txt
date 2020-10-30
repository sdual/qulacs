find_package(JlCxx REQUIRED)

# mkdir build
# cd build
# cmake -DWITH_JULIA=ON -DJlCxx_DIR=/Users/sdual/.julia/artifacts/6017255205dc4fbf4d962903a855a0c631f092dc/lib/cmake/JlCxx -DJulia_EXECUTABLE=/Applications/Julia-1.5.app/Contents/Resources/julia/bin/julia ..
# make

add_library(cppsimjl SHARED cppsim/state_wrapper.cpp)
#add_dependencies(cppsimjl cppsim_static)
#target_link_libraries(cppsimjl PRIVATE cppsim_static)
target_link_libraries(cppsimjl PRIVATE JlCxx::cxxwrap_julia cppsim_static ${OPTIONAL_LINK_FLAGS})

install(TARGETS cppsimjl
    RUNTIME DESTINATION lib
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib)
