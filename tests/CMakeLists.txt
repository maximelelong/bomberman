# Find all .cpp files in the current directory (these are the tests)
file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

# For each test file, create an executable and link it to the main library
foreach(testSrc ${TEST_SRCS})
    # Extract the filename without an extension (NAME_WE)
    get_filename_component(testName ${testSrc} NAME_WE)

    # Add compile target
    add_executable(${testName} ${testSrc})

    # Link to project library
    target_link_libraries(${testName} PRIVATE ${PROJECT_NAME}_lib)

    # Put executable into testBin folder
    set_target_properties(${testName} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/testBin)

    # Finally add it to test execution
    add_test(NAME ${testName}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/testBin
        COMMAND ${CMAKE_BINARY_DIR}/testBin/${testName} )
endforeach(testSrc)

