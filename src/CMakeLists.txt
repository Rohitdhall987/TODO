file(GLOB TODO_SRC
    "*.cpp"
    "*.h"
)

add_executable(TODO ${TODO_SRC})

target_include_directories(TODO PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${CURSES_INCLUDE_DIRS}
)

target_link_libraries(TODO PRIVATE
    nlohmann_json::nlohmann_json
    ${CURSES_LIBRARIES}
)

