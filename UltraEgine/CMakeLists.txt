# CMakeList.txt : CMake project for UltraEgine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.15)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("UltraEgine")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
# Add source to this project's executable.
add_library(UltraEgine "Src/UltraEgine.cpp" "Headers/UltraEgine.h" "Src/Window.cpp" "Headers/Window.h" "Src/Text_Component.cpp" "Headers/Text_Component.h" "Src/Texture2D.cpp" "Headers/Texture2D.h" "Src/Button.cpp" "Headers/Button.h")

  
target_link_libraries( UltraEgine PUBLIC  Mygame_compiler_flags SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf)

target_include_directories(UltraEgine PUBLIC
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/UltraEgine/Headers
   )



set(UltraEgine installable_libs Mygame_compiler_flags)
install(TARGETS UltraEgine DESTINATION lib)
install(FILES Headers/UltraEgine.h Headers/Window.h Headers/Text_Component.h Headers/Texture2D.h Headers/Button.h DESTINATION Include)
install(FILES Src/UltraEgine.cpp DESTINATION src)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET UltraEgine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
