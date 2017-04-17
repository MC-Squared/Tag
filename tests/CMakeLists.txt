cmake_minimum_required(VERSION 2.8.11)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
	  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests/googletest-download )
    if(result)
	      message(FATAL_ERROR "CMake step for googletest failed: ${result}")
      endif()
      execute_process(COMMAND ${CMAKE_COMMAND} --build .
	        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests/googletest-download )
	  if(result)
		    message(FATAL_ERROR "Build step for googletest failed: ${result}")
	    endif()

	    # Prevent overriding the parent project's compiler/linker
	    # settings on Windows
	    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

	    # Add googletest directly to our build. This defines
	    # the gtest and gtest_main targets.
	    add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/tests/googletest-build)

       #include_directories("../inc")
       include_directories(${LaserTag_SOURCE_DIR}/inc)
       include_directories(${LaserTag_SOURCE_DIR}/tests/mocks)

       set(SOURCE_FILES ${SOURCE_FILES}
           ${LaserTag_SOURCE_DIR}/src/button_controller.cpp
           button_controller_test.cpp
           )

       # Now simply link against gtest or gtest_main as needed. Eg
       add_executable(laser ${SOURCE_FILES})
       target_link_libraries(laser gtest_main gmock_main)