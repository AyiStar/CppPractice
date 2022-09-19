
aux_source_directory(. SRCLIST)

foreach(SRC_NAME ${SRCLIST})
    string(REPLACE ".cpp" ".out" EXE_NAME ${SRC_NAME})
    get_filename_component(EXE_NAME ${EXE_NAME} NAME)
    add_executable(${EXE_NAME} ${SRC_NAME})
    target_link_libraries(${EXE_NAME} PRIVATE Catch2::Catch2WithMain)
endforeach()
