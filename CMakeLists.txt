# verbatim (pretty much) copied from https://dpp.dev/buildcmake.html idccc idc idc i hate cmake 
# Minimum CMake version required, we'll just use the latest version.
cmake_minimum_required(VERSION 3.22)
# Project name, version and description
project(logical-roles-bot VERSION 1.0 DESCRIPTION "Makes roles work with binary logic")
 
# Create an executable
add_executable(${PROJECT_NAME}
	src/main.cpp
	src/bot.cpp
)
 
find_package(abseil)
find_package(dpp 10.1.2)
if(NOT dpp_FOUND)
    message("Fetching D++ from GitHub...")

    include(FetchContent)
    FetchContent_Declare(dpp
        GIT_REPOSITORY https://github.com/brainboxdotcc/DPP
        GIT_TAG v10.1.2
    )
    FetchContent_MakeAvailable(dpp)
endif()

# Link the pre-installed DPP package.
target_link_libraries(${PROJECT_NAME} 
	dpp
)

# Set C++ version
set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
)
