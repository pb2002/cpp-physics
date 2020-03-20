#pragma once
#define DELTA_TIME (1/60.0)
#define S_WIDTH 800
#define S_HEIGHT 600
#define W_GRID 10
inline int w2s_x(double x) { return (x * S_HEIGHT / W_GRID) + S_WIDTH / 2; }
inline int w2s_y(double y) { return (-y * S_HEIGHT / W_GRID) + S_HEIGHT / 2; }