set(LIBRARY_DIR "${ClickHouse_SOURCE_DIR}/contrib/gperftools/src")

add_library(tcmalloc_minimal
            # internal
            ${LIBRARY_DIR}/common.cc
            ${LIBRARY_DIR}/internal_logging.cc
            ${LIBRARY_DIR}/system-alloc.cc
            ${LIBRARY_DIR}/memfs_malloc.cc
            ${LIBRARY_DIR}/central_freelist.cc
            ${LIBRARY_DIR}/page_heap.cc
            ${LIBRARY_DIR}/sampler.cc
            ${LIBRARY_DIR}/span.cc
            ${LIBRARY_DIR}/stack_trace_table.cc
            ${LIBRARY_DIR}/static_vars.cc
            ${LIBRARY_DIR}/symbolize.cc
            ${LIBRARY_DIR}/thread_cache.cc
            ${LIBRARY_DIR}/malloc_hook.cc
            ${LIBRARY_DIR}/malloc_extension.cc
            ${LIBRARY_DIR}/base/low_level_alloc.cc
            ${LIBRARY_DIR}/heap-profile-table.cc
            ${LIBRARY_DIR}/heap-profiler.cc
            ${LIBRARY_DIR}/raw_printer.cc
            ${LIBRARY_DIR}/fake_stacktrace_scope.cc
            ${LIBRARY_DIR}/emergency_malloc.cc
            ${LIBRARY_DIR}/emergency_malloc_for_stacktrace.cc
            ${LIBRARY_DIR}/memory_region_map.cc
            # stacktrace
            ${LIBRARY_DIR}/stacktrace.cc
            ${LIBRARY_DIR}/base/elf_mem_image.cc
            ${LIBRARY_DIR}/base/vdso_support.cc
            # spinlock
            ${LIBRARY_DIR}/base/spinlock.cc
            ${LIBRARY_DIR}/base/spinlock_internal.cc
            ${LIBRARY_DIR}/base/atomicops-internals-x86.cc
            # maybe threads
            ${LIBRARY_DIR}/maybe_threads.cc
            ${LIBRARY_DIR}/emergency_malloc_for_stacktrace.cc
            # logging
            ${LIBRARY_DIR}/base/logging.cc
            ${LIBRARY_DIR}/base/dynamic_annotations.c
            # sysinfo
            ${LIBRARY_DIR}/base/sysinfo.cc
            # heap checker
            ${LIBRARY_DIR}/base/thread_lister.c
            ${LIBRARY_DIR}/base/linuxthreads.cc
            ${LIBRARY_DIR}/heap-checker.cc
            ${LIBRARY_DIR}/heap-checker-bcad.cc
            # tcmalloc
            ${LIBRARY_DIR}/tcmalloc.cc
            )

target_include_directories(tcmalloc_minimal PRIVATE ${LIBRARY_DIR}/)
target_compile_definitions(tcmalloc_minimal INTERFACE USE_JEMALLOC=0 USE_TCMALLOC_CPP=0)
target_link_libraries(allocator INTERFACE tcmalloc_minimal)

message(STATUS "Using tcmalloc_minimal")
