# Third-party libraries may have substandard code.

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")
endif ()

set_property(DIRECTORY PROPERTY EXCLUDE_FROM_ALL 1)

add_subdirectory (ryu-cmake)

if (USE_INTERNAL_CITYHASH_LIBRARY)
    add_subdirectory (cityhash102)
endif ()

if (USE_INTERNAL_FARMHASH_LIBRARY)
    add_subdirectory (libfarmhash)
endif ()

if (USE_INTERNAL_METROHASH_LIBRARY)
    add_subdirectory (libmetrohash)
endif ()

add_subdirectory (murmurhash)

if (USE_INTERNAL_BTRIE_LIBRARY)
    add_subdirectory (libbtrie)
endif ()


if (ENABLE_JEMALLOC AND USE_INTERNAL_JEMALLOC_LIBRARY)
    add_subdirectory (jemalloc-cmake)
endif ()

if (USE_INTERNAL_CPUID_LIBRARY)
    add_subdirectory (libcpuid)
endif ()

if (USE_INTERNAL_H3_LIBRARY)
    add_subdirectory(h3-cmake)
endif ()

if (USE_INTERNAL_HDFS3_LIBRARY)
    add_subdirectory(libhdfs3-cmake)
endif ()


if (USE_BASE64)
    add_subdirectory (base64-cmake)
endif()

if (USE_FASTOPS)
    add_subdirectory (fastops-cmake)
endif()

add_subdirectory(replxx-cmake)
