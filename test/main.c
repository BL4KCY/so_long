#include <stdio.h>
#include <stdlib.h>

#define MAX_HEIGHT 100  // Adjust these maximum dimensions as needed
#define MAX_WIDTH 100

typedef struct {
   int x;
   int y;
} Point;

void Floodfill(unsigned char vals[MAX_HEIGHT][MAX_WIDTH], Point q, unsigned char SEED_COLOR, unsigned char COLOR) {
   int h = sizeof(vals) / sizeof(vals[0]);
   int w = sizeof(vals[0]) / sizeof(vals[0][0]);

   if (q.y < 0 || q.y >= h || q.x < 0 || q.x >= w) {
       return;
   }

   Point stack[MAX_HEIGHT * MAX_WIDTH];  // Adjust stack size if needed
   int top = 0;
   stack[top++] = q;

   while (top > 0) {
       Point p = stack[--top];
       int x = p.x;
       int y = p.y;

       if (y < 0 || y >= h || x < 0 || x >= w) {
           continue;
       }

       unsigned char val = vals[y][x];
       if (val == SEED_COLOR) {
           vals[y][x] = COLOR;
           stack[top++] = (Point){x + 1, y};
           stack[top++] = (Point){x - 1, y};
           stack[top++] = (Point){x, y + 1};
           stack[top++] = (Point){x, y - 1};
       }
   }
}


	if (copy[y][x] == '0' || copy[y][x] == 'C')
	{
		if (copy[y][x] == '0')
			copy[y][x] = 'P';
		flood_fill(par, x + 1, y, copy);
		flood_fill(par, x - 1, y, copy);
		flood_fill(par, x, y + 1, copy);
		flood_fill(par, x, y - 1, copy);
	}
	else
		return ;
