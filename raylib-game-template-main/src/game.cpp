/*******************************************************************************************
 *
 *   raylib [core] example - Mouse input
 *
 *   Example complexity rating: [★☆☆☆] 1/4
 *
 *   Example originally created with raylib 1.0, last time updated with
 *raylib 5.5
 *
 *   Example licensed under an unmodified zlib/libpng license, which is an
 *OSI-certified, BSD-like license that allows static linking with closed source
 *software
 *
 *   Copyright (c) 2014-2025 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include "FileTools.hpp"
#include "SlideView.hpp"
#include "raylib.h"
#include <iostream>
#include <string>

int getSlideID(std::string path) {
  return std::stoi(path.substr(path.size() - 9, path.size() - 8));
}
int getSubSlideID(std::string path) {
  return std::stoi(path.substr(path.size() - 6, path.size() - 4));
} //------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void) {
  // Initialization
  //--------------------------------------------------------------------------------------
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "raylib [core] example - mouse input");
  ToggleFullscreen();

  Vector2 ballPosition = {-100.0f, -100.0f};
  Color ballColor = DARKBLUE;
  int isCursorHidden = 0;

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second

  ClicZone left_zone((Rectangle){0, 0, 384, 1080}, 0);
  ClicZone right_zone((Rectangle){1920 - 384, 0, 1920, 1080}, 0);
  ClicZone forward_zone((Rectangle){385, 0, 1920 - 385, 1080}, 0);

  std::vector<std::string> imagePath;
  getFilesInDirectory("src/resources/RayLibTest/", imagePath);

  std::vector<SlideView *> slides;
  for (unsigned int i = 0; i < imagePath.size(); ++i) {
    slides.push_back(new SlideView(imagePath[i]));
  }

  for (std::vector<SlideView *>::iterator it_p = slides.begin();
       it_p != slides.end(); ++it_p) {
    for (std::vector<SlideView *>::iterator it_s = slides.begin();
         it_s != slides.end(); ++it_s) {
      if (getSlideID((*it_p)->getSlideImagePath()) ==
              getSlideID((*it_s)->getSlideImagePath()) + 1 ||
          getSlideID((*it_p)->getSlideImagePath()) ==
              getSlideID((*it_s)->getSlideImagePath()) - 1) {
        if (getSubSlideID((*it_p)->getSlideImagePath()) == 0 &&
            getSubSlideID((*it_s)->getSlideImagePath()) == 0) {
          (*it_p)->addSlideMap(std::pair<SLIDE_STRUCT>(*it_s, forward_zone));
        }
        if (getSubSlideID((*it_p)->getSlideImagePath()) == 180 &&
            getSubSlideID((*it_s)->getSlideImagePath()) == 180) {
          (*it_s)->addSlideMap(std::pair<SLIDE_STRUCT>(*it_p, forward_zone));
        }
      }
    }
  }

  for (unsigned int i = 0; i < slides.size(); ++i) {
  }

  Image bkgrnd = LoadImage(slides[0]->getSlideImagePath().c_str());
  Texture2D texture = LoadTextureFromImage(bkgrnd);
  UnloadImage(bkgrnd);

  //---------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    if (IsKeyPressed(KEY_H)) {
      if (isCursorHidden == 0) {
        HideCursor();
        isCursorHidden = 1;
      } else {
        ShowCursor();
        isCursorHidden = 0;
      }
    }

    // GettMousePosition();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))

      // Draw
      //----------------------------------------------------------------------------------
      BeginDrawing();
    DrawTexture(texture, 0, 0, WHITE);
    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
