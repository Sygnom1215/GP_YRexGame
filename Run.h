#pragma once

int map[size_y][size_x]; //전역변수
int speed = spd;
int score = 0;
int otime = oti;

void Openscreen();
void Mapbase();
void Mapping();
void Jump(int a);
void Obstaclemaker();
void Obstaclemove();
int Gameover();
void Score();
int Endscreen();
