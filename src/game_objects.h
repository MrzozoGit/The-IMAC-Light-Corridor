#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>

// Tool struct for colors
typedef struct Colors {
    int r, g, b, h, s, l;
    
    Colors() {}

    Colors(int r, int g, int b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }

} Colors;

// Tool struct for 3D positions
typedef struct Position {
    GLfloat x, y, z; // y -> profondeur

    Position() {}

    Position(GLfloat x, GLfloat y, GLfloat z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
} Position;

// Tool struct for 3D speed
typedef struct Speed {
    GLfloat x, y, z;

    Speed() {}

    Speed(GLfloat x, GLfloat y, GLfloat z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
} Speed;

// Ball struct
typedef struct Ball {
    int radius;
    Position pos;
    Speed speed;
    GLuint* texture; // texture from the textures array
    // Light light;

    Ball() {}

    Ball(int rad, Position pos, Speed speed, GLuint* texture) {
        this->radius = rad;
        this->pos = pos;
        this->speed = speed;
        this->texture = texture;
    }
} Ball;

// Wall struct
typedef struct Wall {
    int width;
    int height;
    Position pos;
    float depth;
    GLuint* texture;

    Wall() {}

    Wall(int width, int height, Position pos, float depth) {
        this->width = width;
        this->height = height;
        this->pos = pos;
        this->depth=depth;
    }

    Wall(int width, int height, Position pos, GLuint* texture) {
        this->width = width;
        this->height = height;
        this->pos = pos;
        this->texture = texture;
    }
} Wall;

// WallStep struct for obtacles groups, situated at precise steps inside the corridor
typedef struct WallStep {
    float width;
    float height;
    float depth; // Correspond au fond du wallStep sur l'axe Y
    Position pos;
    std::vector<Wall> walls;

    WallStep() {

    }

    WallStep(float depth) {
        this->depth = depth;
    }

    WallStep(float width, float height, Position pos, std::vector<Wall> walls) {
        this->width = width;
        this->height = height;
        this->pos = pos;
        this->walls = walls;
    }
} WallStep;

// Corridor struct
typedef struct Corridor {
    int width;
    int height;
    float depthOfAStep;
    int numberOfSteps;
    std::vector<WallStep> wallSteps;
    GLuint* sideWallsTexture;
    GLuint* groundTexture;
    GLuint* ceilingTexture;

    Corridor() {}

    Corridor(float depthOfAStep, int numberOfSteps) {
        this->depthOfAStep = depthOfAStep;
        this->numberOfSteps = numberOfSteps;
    }

    // Corridor(int width, int height) {
    //     this->width = width;
    //     this->height = height;
    // }

    Corridor(std::vector<WallStep> wallSteps) {
        this->wallSteps = wallSteps;
    }

    Corridor(int width, int height, std::vector<WallStep> wallSteps, GLuint* sideWallsTexture, GLuint* groundTexture, GLuint* ceilingTexture) {
        this->width = width;
        this->height = height;
        this->wallSteps = wallSteps;
        this->sideWallsTexture = sideWallsTexture;
        this->groundTexture = groundTexture;
        this->ceilingTexture = ceilingTexture;
    }
} Corridor;

// Player struct for the racket that the player controls
typedef struct Player : Wall {
    // Light light;

    Player() {}
} Player;

// General game struct containing all the elements needed
typedef struct Game {
    Player player;
    Corridor corridor;
    std::vector<Ball> balls;
    int lives;
    int gameState;
    int renderSkinId;

    Game() {}

    Game(Player player, Corridor corridor, std::vector<Ball> balls, int lives, int gameState, int renderSkinId) {
        this->player = player;
        this->corridor = corridor;
        this->balls = balls;
        this->lives = lives;
        this->gameState = gameState;
        this->renderSkinId = renderSkinId;
    }
} Game;

#endif