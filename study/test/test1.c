#include "mlx.h"
#include <stdio.h>

typedef struct s_vars {
    void *mlx;
    void *win;
} t_vars;

void draw_line(int x0, int y0, int x1, int y1, t_vars *vars) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int stepX, stepY;
    
    if (dx >= 0)
        stepX = 1;
    else {
        stepX = -1;
        dx = -dx;
    }
    
    if (dy >= 0)
        stepY = 1;
    else {
        stepY = -1;
        dy = -dy;
    }
    
    int deltaX2 = dx << 1;
    int deltaY2 = dy << 1;
    
    mlx_pixel_put(vars->mlx, vars->win, x0, y0, 0x00FFFFFF);
    
    if (dx > dy) {
        int error = deltaY2 - dx;
        while (x0 != x1) {
            if (error >= 0) {
                y0 += stepY;
                error -= deltaX2;
            }
            x0 += stepX;
            error += deltaY2;
            mlx_pixel_put(vars->mlx, vars->win, x0, y0, 0x00FFFFFF);
        }
    }
    else {
        int error = deltaX2 - dy;
        while (y0 != y1) {
            if (error >= 0) {
                x0 += stepX;
                error -= deltaY2;
            }
            y0 += stepY;
            error += deltaX2;
            mlx_pixel_put(vars->mlx, vars->win, x0, y0, 0x00FFFFFF);
        }
    }
}

int main(void) {
    t_vars vars;
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 500, 500, "Bresenham Line");
    
    draw_line(50, 50, 400, 400, &vars);
    
    mlx_loop(vars.mlx);
    
    return 0;
}
