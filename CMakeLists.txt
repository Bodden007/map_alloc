cmake_minimum_required (VERSION 3.26)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project (map_alloc VERSION ${PROJECT_VERSION})
add_executable (map_alloc main.cpp) 
 
set_target_properties(map_alloc
    PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)


install(TARGETS map_alloc RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()