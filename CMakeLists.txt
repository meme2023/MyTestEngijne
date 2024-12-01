# CMakeList.txt : CMake project for Mygame, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
project ("Mygame" VERSION 1.0)
add_subdirectory(UltraEgine)
add_library(Mygame_compiler_flags INTERFACE)
target_compile_features(Mygame_compiler_flags INTERFACE cxx_std_17)

# Add source to this project's executable.
add_executable (Mygame "Mygame.cpp" "Mygame.h" )
# Create setting to make realse only to window app or WIN32
set_target_properties(Mygame PROPERTIES WIN32_EXECUTABLE $<CONFIG:Release>)
target_link_libraries(Mygame PUBLIC UltraEgine)
target_link_libraries(Mygame PUBLIC 
 "${PROJECT_BINARY_DIR}/UltraEgine"
)

target_link_libraries(Mygame PUBLIC UltraEgine Mygame_compiler_flags)

target_compile_options(Mygame_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>"
  "$<${msvc_cxx}:-W3>"
)
target_compile_options(Mygame_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)
#creating package
# type cpack -G ZIP -C Debug or Release
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Mygame_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Mygame_VERSION_MINOR}")
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(CPACK_GENERATOR "TGZ")
set(CPACK_SOURCE_GENERATOR "TGZ")
include(CPack)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
install(TARGETS Mygame DESTINATION bin)
enable_testing()
add_test(NAME Runs COMMAND Mygame 25)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Mygame PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
