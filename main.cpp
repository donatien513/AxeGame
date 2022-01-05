#include "raylib.h"

int main() {
  // Window dimension
  int WINDOW_WIDTH{800};
  int WINDOW_HEIGHT{600};

  // player circle
  int circle_x{12};
  int circle_y{WINDOW_HEIGHT / 2};
  int circle_radius{8};
  int player_move_speed{4};
  int circle_edge_top{circle_y - circle_radius};
  int circle_edge_bottom{circle_y + circle_radius};
  int circle_edge_left{circle_x - circle_radius};
  int circle_edge_right{circle_x + circle_radius};

  // Axe
  int axe_width{32};
  int axe_height{64};

  int axe_x{(WINDOW_WIDTH / 2) - (axe_width / 2)};
  int axe_y{0};
  int axe_move_speed_with_direction{8}; 

  int axe_edge_top{axe_y};
  int axe_edge_bottom{axe_height + axe_y};
  int axe_edge_left{axe_x + axe_width};
  int axe_edge_right{axe_x};

  // Window opening
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Axe game");
  SetTargetFPS(60);

  bool collision_with_axe{false};
  int game_over_text_x{WINDOW_WIDTH / 3};
  int game_over_text_y{WINDOW_HEIGHT / 2};

  /**
   * G A M E   L O G I C
   */
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);

    collision_with_axe =
      (circle_edge_top <= axe_edge_bottom) &&
      (circle_edge_bottom >= axe_edge_top) &&
      (circle_edge_left <= axe_edge_right) &&
      (circle_edge_right >= axe_edge_left);

    if (collision_with_axe) {
      DrawText("Game Over", game_over_text_x, game_over_text_y, 32, RED);
    } else {
      // Axe
      DrawRectangle(axe_x, axe_y, axe_width, axe_height, GRAY);

      // Move axe
      axe_y += axe_move_speed_with_direction;
      if ((axe_y + axe_height) > WINDOW_HEIGHT || axe_y <= 0) {
        axe_move_speed_with_direction = -axe_move_speed_with_direction;
      }
      axe_edge_top = axe_y;
      axe_edge_bottom = axe_y + axe_height;
      axe_edge_left = axe_x;
      axe_edge_right = axe_x + axe_width;

      // Player
      DrawCircle(circle_x, circle_y, circle_radius, RED);

      // Keys control
      if (IsKeyDown(KEY_UP) && (circle_y - circle_radius) > 0) {
        circle_y -= player_move_speed;
      } else if (IsKeyDown(KEY_DOWN) && (circle_y + circle_radius) < WINDOW_HEIGHT) {
        circle_y += player_move_speed;
      }

      if (IsKeyDown(KEY_LEFT) && (circle_x - circle_radius) > 0) {
        circle_x -= player_move_speed;
      } else if (IsKeyDown(KEY_RIGHT) && (circle_x + circle_radius) < WINDOW_WIDTH) {
        circle_x += player_move_speed;
      }
      circle_edge_top = circle_y - circle_radius;
      circle_edge_bottom = circle_y + circle_radius;
      circle_edge_left = circle_x - circle_radius;
      circle_edge_right = circle_x + circle_radius;
    }

    EndDrawing();
  }
  return 0;
}
