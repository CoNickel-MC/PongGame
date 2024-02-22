#include "raylib.h"

class ball {
	private:
		int ballXVel;int ballYVel;
		int collisions;
	public:
		int ballX;
		int ballY;
		void ballCollision(char collidedWith) {
			if (collidedWith == 'u') {

			}
			else {

			}

		};
		void ballMove() {

		};
};
void CollisionCheck() {

};
int main() {
	const int winWidth = 800;
	const int winHeight = 550;
	float userY = 20.0f;
	float compY = 20.0f;
	Rectangle userPosition;
	Rectangle CompPosition;
	Rectangle BallPosition;


	InitWindow(winWidth, winHeight, "PongGame");
	SetTargetFPS(60);



	while (!WindowShouldClose()) {
		if (IsKeyDown(KEY_S) && userY<(winHeight-80)) {userY += 2.5f;}
		if (IsKeyDown(KEY_W) &&  userY>(5)) {userY -= 2.5f;}


		userPosition = {5, userY, 15, 75};
		CompPosition = {winWidth - 20, compY, 15, 75};
		Camera2D camera = {0};
		camera.offset = { winWidth / 2.0f, winHeight / 2.0f };
		camera.rotation = 0.0f;
		camera.zoom = 1.0f;
		camera.target = { 0,0 };

		BeginDrawing();
		ClearBackground(RED);
		DrawRectangleRec({ 2,2,396,546 }, SKYBLUE);
			DrawRectangleRounded(userPosition, 0.5f, 20.0f, BLUE);					//User paddle
			DrawRectangleRounded(CompPosition, 0.5f, 20.0f, DARKBLUE);				//Comp paddle
		EndDrawing();
	}
	CloseWindow();
	return 0;
}