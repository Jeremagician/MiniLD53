include_directories(
  ${SFML_INCLUDE_DIR}
  ${PROJECT_BINARY_DIR}/src
)


set(
  minild_sources
  main.cpp
  map.cpp map.hpp
  Game.cpp Game.hpp
  InputHandler.hpp
  FontManager.cpp FontManager.hpp
  Hero.cpp Hero.h
  Actors.cpp Actors.h
  PresentHero.cpp PresentHero.h
  PastHero.cpp PastHero.h
  TextureManager.cpp TextureManager.hpp

  # Scenes
  Scene.cpp Scene.hpp
  MainMenuScene.cpp MainMenuScene.hpp
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