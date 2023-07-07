#include <stdio.h>
#include <math.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

int map[MAP_WIDTH][MAP_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

typedef struct {
    float x;
    float y;
    float angle;
} Player;

void castRay(Player player, float rayAngle) {
    float rayX = player.x;
    float rayY = player.y;
    float rayDirX = cos(rayAngle);
    float rayDirY = sin(rayAngle);
    
    while (rayX >= 0 && rayX < MAP_WIDTH && rayY >= 0 && rayY < MAP_HEIGHT) {
        int mapX = (int)rayX;
        int mapY = (int)rayY;
        
        if (map[mapX][mapY] == 1) {
            // Intersection with a wall, do something (e.g., rendering or collision detection)
            break;
        }
        
        rayX += rayDirX;
        rayY += rayDirY;
    }
    
    // Calculate the distance between player and intersection point
    float distance = sqrt(pow(rayX - player.x, 2) + pow(rayY - player.y, 2));
    
    // Apply perspective distortion (optional)
    distance *= cos(player.angle - rayAngle);
    
    // Do something with the distance (e.g., rendering)
    printf("Ray angle: %f, Distance: %f\n", rayAngle, distance);
}

int main() {
    Player player;
    player.x = 2.0;
    player.y = 2.0;
    player.angle = 0.0;
    
    float FOV = M_PI / 3.0;  // 60 degrees
    
    for (int i = 0; i < 100; i++) {
        float rayAngle = player.angle - FOV / 2.0 + (float)i / 100.0 * FOV;
        castRay(player, rayAngle);
    }
    
    return 0;
}
