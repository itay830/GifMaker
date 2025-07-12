cmake_minimum_required(VERSION 3.25)
project(GifMaker C)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(FetchContent)

function(include_dependency libName gitURL gitTag)
  FetchContent_Declare(${libName}
          GIT_REPOSITORY ${gitURL}
          GIT_TAG ${gitTag}
          GIT_SHALLOW TRUE
          GIT_PROGRESS TRUE
  )
  FetchContent_MakeAvailable(${libName})
endfunction()

# raylib
set(RAYLIB raylib)
find_package(${RAYLIB} QUIET)
if (NOT ${RAYLIB}_FOUND)
  message(STATUS "${RAYLIB} from Github")
  include_dependency(${RAYLIB} https://github.com/raysan5/raylib.git 5.5)
endif ()

# raygui
set(RAYGUI raygui)
find_package(${RAYGUI} QUIET)
if (NOT ${RAYGUI}_FOUND)
  message(STATUS "${RAYGUI} from Github")
  include_dependency(${RAYGUI} https://github.com/raysan5/raygui.git 4.0)
endif ()

add_executable(GifMaker main.c
        src/Models/LinkedList.c
        src/includeSrc/LinkedList.h
        src/MainController.c
        src/includeSrc/MainController.h
        src/MainViewBuilder.c
        src/includeSrc/MainViewBuilder.h
        src/MainInteractor.c
        src/includeSrc/MainInteractor.h
        src/MainModel.c
        src/includeSrc/MainModel.h
        src/interfaces/GameRayController.c
        src/interfaces/includeInterface/GameRayController.h
        src/Models/GameLoop.c
        src/includeSrc/GameLoop.h
        src/Models/Clock.c
        src/includeSrc/Clock.h
        src/gui/Button.c
        src/gui/includeGui/Button.h
)

target_include_directories(GifMaker PRIVATE
        ${CMAKE_SOURCE_DIR}/cmake-build-debug/_deps/raygui-src/src
)
target_link_libraries(GifMaker PRIVATE
        ${RAYLIB}
)
