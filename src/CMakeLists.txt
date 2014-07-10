include_directories(
  ${SFML_INCLUDE_DIR}
)


set(
  minild_sources
  main.cpp
)

add_executable(
  minild
  ${minild_sources}
)

target_link_libraries(
  minild
  ${SFML_LIBRARIES}
  ${SFML_DEPENDENCIES}
)