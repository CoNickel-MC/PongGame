#include "raylib.h"

class ball {
	private:
		int XVel = 4;int YVel = 4;
		int collisions = 0;
	public:
		int X = 400; int Y = 275; float Size = 15.0f;
		void Move() {
			X += XVel;
			Y += YVel;
		};
		void Collision(char collidedWith) {
			if (collidedWith == 'u') {

			}
			else {

			}

		};

};

class user {
	private:
		float YVel = 5.0f;
	public:
		float Y = 20;
		Rectangle Position = { 5,Y,15,75 };
		void Move(char dir) {
			if (dir == 'u') {
				Y -= YVel;
			}
			else if (dir == 'd') {
				Y += YVel;
			};
		};
		void PosUpdate() {
			Position = { 5,Y,15,75 };
		};

};

class comp {
	private:
		float YVel = 5.0f;
	public:
		float Y = 20.0f;
		Rectangle Position = { 780,Y,15,75 };
		void Move(char dir) {
			Y += YVel;
		};
		void PosUpdate() {
			Position = { 780,Y,15,75 };
		};

};


void CollisionCheck() {

};
int main() {
	const int winWidth = 800;
	const int winHeight = 550;
	user user;
	comp comp;
	ball ball;


	InitWindow(winWidth, winHeight, "PongGame");
	SetTargetFPS(60);



	while (!WindowShouldClose()) {
		user.PosUpdate();
		comp.PosUpdate();
		if (IsKeyDown(KEY_S) && user.Y < (winHeight - 80)) { user.Move('d'); };
		if (IsKeyDown(KEY_W) && user.Y > (5)) { user.Move('u'); };

		Camera2D camera = {0};
		camera.offset = { winWidth / 2.0f, winHeight / 2.0f };
		camera.rotation = 0.0f;
		camera.zoom = 1.0f;
		camera.target = { 0,0 };

		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawRectangleRec({ 2,2,397,546 }, Color{ 120, 180, 255, 255 });
			DrawRectangleRec({ 401,2,397,546 }, Color{ 100, 200, 255, 255 });



			DrawCircle(ball.X, ball.Y, ball.Size, YELLOW);
			DrawRectangleRounded(user.Position, 0.5f, 20, BLUE);					//User paddle
			DrawRectangleRounded(comp.Position, 0.5f, 20, DARKBLUE);				//Comp paddle
		EndDrawing();
	}
	CloseWindow();
	return 0;
}