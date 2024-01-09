


#include "mlx.h"


void *mlx;
void *win1;
void *win2;



int gere_mouse(int x,int y,int button,void*toto)
{
  printf("Mouse event - new win\n");
  mlx_destroy_window(mlx,win1);
  win1 = mlx_new_window(mlx,random()%500,random()%500,"new win");
  mlx_mouse_hook(win1,gere_mouse,0);
}


int main()
{#include <stdio.h>
#include <stdlib.h>

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
 
    while (1) {
        printf("(%d, %d)\n", x1, y1);
 
        if (x1 == x2 && y1 == y2)
            break;
 
        int e2 = 2 * err;
 
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
 
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

int main() {
    int x1, y1, x2, y2;
    printf("Enter the starting point (x1, y1): ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the ending point (x2, y2): ");
    scanf("%d%d", &x2, &y2);
 
    printf("Points on the line:\n");
    drawLine(x1, y1, x2, y2);
 
    return 0;
}

  srandom(time(0));
  mlx = mlx_init();
  win1 = mlx_new_window(mlx,300,300,"win1");
  win2 = mlx_new_window(mlx,600,600,"win2");
  mlx_mouse_hook(win1,gere_mouse,0);
  mlx_mouse_hook(win2,gere_mouse,0);
  mlx_loop(mlx);
}
