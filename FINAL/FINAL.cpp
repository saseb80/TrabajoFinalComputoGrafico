#include"pch.h"
#include<iostream>
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "Vector2.h"
#include "Matriz.h"
#include <list>

using namespace std;
//Screen dimension constants
const int SCREEN_WIDTH = 1280;  //640
const int SCREEN_HEIGHT = 720;  //480

//Starts up SDL and creates window
bool init();


//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

void Linea() {

}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

			}
		}
	}

	return success;
}


void close()
{
	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;


	SDL_Quit();
}

void DibujarPixel(float x, float y) {


	Vector2 v2(x, y);
	SDL_Rect rect;
	rect.x = (x)-SCREEN_WIDTH/2;
	rect.y = -(y)+SCREEN_HEIGHT/2;
	rect.w = 5;
	rect.h = 5;

	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(gRenderer, &rect);
	SDL_RenderDrawPoint(gRenderer, v2.getX() + SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - v2.getY());


}

void Circulo(int r, float xc, float yc) {
	Vector2 pix;
	float p;
	float x = 0;
	float y = r;
	x;
	y;
	p = (5 / 4) - r;
	for (int i = 0; x <= y; i++) {
		if (p <= 0) {
			x = x + 1;
			y = y;
			p = p + (2 * x) + 3;
		}
		else if (p > 0) {
			x = x + 1;
			y = y - 1;
			p = (2 * x) - (2 * y) + 5 + p;
		}
		DibujarPixel(x + xc, y + yc);
		DibujarPixel(x + xc, -y + yc);
		DibujarPixel(-x + xc, y + yc);
		DibujarPixel(-x + xc, -y + yc);
		DibujarPixel(y + xc, x + yc);
		DibujarPixel(y + xc, -x + yc);
		DibujarPixel(-y + xc, x + yc);
		DibujarPixel(-y + xc, -x + yc);
	}
}

void DibujarLinea(float xa, float ya, float xb, float yb) {

	float x, y;
	float xiner, yiner;
	float dx, dy;

	int i = 0;
	float deno;

	dx = xb - xa;
	dy = yb - ya;

	if (dy < dx) {
		deno = dx;
	}

	if (dy >= dx) {
		deno = dy;
	}
	xiner = dx / deno;
	yiner = dy / deno;

	x = xa;
	y = ya;

	for (i; i <= deno; i++) {
		DibujarPixel(round(x), round(y));
		x = x + xiner;
		y = y + yiner;
	}
}

void Bezier(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {

	float x;
	float y;


	for (float i = 0; i < 1;i = i + 0.0001) {


		//x = pow(1 - i, 3) * x0 + 3 * t * pow(1 - t, 2) * x1 + 3 * pow(t, 2) * (1 - t) * x2 + pow(t, 3) * x3;

		//y = pow(1 - t, 3) * y0 + 3 * t * pow(1 - t, 2) * y1 + 3 * pow(t, 2) * (1 - t) * y2 + pow(t, 3) * y3;

		x = ((1 - i)*(1 - i)*(1 - i)*(x0)) + (3 * i*(1 - i)*(1 - i)*(x1)) + (3 * i*i*(1 - i)*(x2)) + (i*i*i*(x3));
		y = ((1 - i)*(1 - i)*(1 - i)*(y0)) + (3 * i*(1 - i)*(1 - i)*(y1)) + (3 * i*i*(1 - i)*(y2)) + (i*i*i*(y3));

		DibujarPixel(x, y);
	}
}

//void funcionChida() {
//	
//	
//	int x, y;
//	SDL_Event event;
//	while (1) {
//	if (event.type == SDL_MOUSEMOTION) {
//	x = event.motion.x;
//	y = event.motion.y;
//	DibujarPixel(x, y);
//	}
//	}	
//}


int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		//While application is running
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);
		while (!quit)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			}

			//Clear screen



			//Draw vertical line of yellow dots
			SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);      //RAYAS PUNTEADAS VERTICALES
			for (int y = 0; y < SCREEN_HEIGHT; y += 4)
			{
				SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, y);
				for (int i = 0; i < SCREEN_WIDTH; i += 20)
				{
					//SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
					SDL_RenderDrawPoint(gRenderer, i, y);
				}

			}
			SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);    //RAYAS PUNTTEADAS HORIZONTALES
			for (int x = 0; x < SCREEN_WIDTH; x += 4)
			{
				SDL_RenderDrawPoint(gRenderer, x, SCREEN_HEIGHT / 2);
				for (int i = 0; i < SCREEN_WIDTH; i += 20)
				{
					//SDL_RenderDrawPoint(gRenderer, i, SCREEN_HEIGHT / 2);
					SDL_RenderDrawPoint(gRenderer, x, i);
				}
			}

			//PLANO CARTESIANO XD

			SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
			for (int x = 0; x < SCREEN_HEIGHT; x += 1)
			{
				SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, x);

			}
			SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
			for (int x = 0; x < SCREEN_WIDTH; x += 1)
			{
				SDL_RenderDrawPoint(gRenderer, x, SCREEN_HEIGHT / 2);
			}



			Matriz m(2, 2);
			m.setCols(2);
			m.setRows(2);
			m(0, 0) = 1;
			m(0, 1) = 1;
			m(1, 0) = 1;
			m(1, 1) = 1;
			Matriz m1(2, 2);
			m1.setCols(2);
			m1.setRows(2);
			m1(0, 0) = 2;
			m1(0, 1) = 2;
			m1(1, 0) = 2;
			m1(1, 1) = 2;

			//m.suma(m,m1);

			bool lol = true;

			while (lol == true) {
				Vector2 v1(1, 1);
				int x1, x2, x3, x4, y1, y2, y3, y4;
				int r, xc, yc;
				int bx0, bx1, bx2, bx3, by0, by1, by2, by3;
				int caso;
				int caso2;
				int caso3;

				int grados;
				int tamaniox;
				int tamanioy;

				int xw, yw;
				int xi, yi, xf, yf;
				Vector2 lineaI(0, 0);
				Vector2 lineaF(0, 0);

				Vector2 b0(1, 1);
				Vector2 b1(1, 1);
				Vector2 b2(2, 2);
				Vector2 b3(3, 3);

				int xxx;

				printf("Que quieres hacer?\nDibujar pixel: 1\nDibujar circulo: 2\nDibujar  Curva de Bezier: 3\nDibujar linea: 4\nLimpiar pantalla: 5\nSalir: 6\n");
				cin >> caso;

				switch (caso) {
				case 1:
					printf("Escribe las coordenadas:\n");
					printf("x: ");
					cin >> xw;
					printf("y: ");
					cin >> yw;
					v1.setX(xw);
					v1.setY(yw);
					DibujarPixel(v1.getX(), v1.getY());
					break;
				case 2:
					printf("Escribe el radio: ");
					cin >> r;
					printf("Ahora escribe sus coordenadas: \n");
					printf("x: ");
					cin >> xc;
					printf("y: ");
					cin >> yc;
					Circulo(r, xc, yc);
					lol = false;
					break;
				case 3:
					printf("Escribe los puntos: \n");
					printf("x0: ");
					cin >> bx0;
					printf("y0: ");
					cin >> by0;
					printf("x1: ");
					cin >> bx1;
					printf("y1: ");
					cin >> by1;
					printf("x2: ");
					cin >> bx2;
					printf("y2: ");
					cin >> by2;
					printf("x3: ");
					cin >> bx3;
					printf("y3: ");
					cin >> by3;
					b0.setX(bx0);
					b0.setY(by0);
					b1.setX(bx1);
					b1.setY(by1);
					b2.setX(bx2);
					b2.setY(by2);
					b3.setX(bx3);
					b3.setY(by3);
					Bezier(b0.getX(), b0.getY(), b1.getX(), b1.getY(), b2.getX(), b2.getY(), b3.getX(), b2.getY());
					break;

				case 4:
					printf("Escribe las coordenadas de inicio: \n");
					printf("x: ");
					cin >> xi;
					printf("yi: ");
					cin >> yi;
					printf("Ahora las coordenadas finales: \n");
					printf("x: ");
					cin >> xf;
					printf("y: ");
					cin >> yf;
					lineaI.setX(xi);
					lineaI.setY(yi);
					lineaF.setX(xf);
					lineaF.setY(yf);
					DibujarLinea(lineaI.getX(), lineaI.getY(), lineaF.getX(), lineaF.getY());
					break;
				case 5:
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
					SDL_RenderClear(gRenderer);
					SDL_RenderPresent(gRenderer);
					lol = false;
					break;
				case 6:
					close();
					return 0;
					break;
				default:
					printf("camara\n");
					lol = false;
					break;
				}
				cout << "Quieres hacer alguna operacion ? \nSi=1 \nNo=2\n";
				cin >> caso2;
				if (caso2 == 1) {
					cout << "Que quieres hacer?\n";
					cout << "Rotar pixel: 1\n";
					cout << "Escalar pixel: 2\n";
					cout << "Rotar Linea: 3\n";
					cout << "Escalar Linea: 4\n";
					cout << "Rotar Curva: 5\n";
					cout << "Escalar Curva: 6\n";
					cin >> caso3;
					switch (caso3) {
					case 1:
						cout << "Escribe los grados que quieres rotarlo: ";
						cin >> grados;
						v1.rotacion(grados);
						DibujarPixel(v1.getX(), v1.getY());
						lol = false;
						break;
					case 2:
						cout << "Escribe las veces que quieres aumentarlo: " << endl;
						cout << "x: ";
						cin >> tamaniox;
						cout << "y: ";
						cin >> tamanioy;
						v1.escalamiento(tamaniox, tamanioy);
						DibujarPixel(v1.getX(), v1.getY());
						lol = false;
						break;
					case 3:
						cout << "Escribe los grados que quieres rotarla: ";
						cin >> grados;
						lineaI.rotacion(grados);
						lineaF.rotacion(grados);
						DibujarLinea(lineaI.getX(), lineaI.getY(), lineaF.getX(), lineaF.getY());
						lol = false;
						break;
					case 4:
						cout << "Escribe las veces que quieres aumentarla: " << endl;
						cout << "x: ";
						cin >> tamaniox;
						cout << "y: ";
						cin >> tamanioy;
						lineaI.escalamiento(tamaniox, tamanioy);
						lineaF.escalamiento(tamaniox, tamanioy);
						DibujarLinea(lineaI.getX(), lineaI.getY(), lineaF.getX(), lineaF.getY());
						lol = false;
						break;
					case 5:
						cout << "Escribe los grados que quieres rotarla: ";
						cin >> grados;
						b0.rotacion(grados);
						b1.rotacion(grados);
						b2.rotacion(grados);
						b3.rotacion(grados);
						Bezier(b0.getX(), b0.getY(), b1.getX(), b1.getY(), b2.getX(), b2.getY(), b3.getX(), b2.getY());
						lol = false;
						break;
					case 6:
						cout << "Escribe las veces que quieres aumentarla: " << endl;
						cout << "x: ";
						cin >> tamaniox;
						cout << "y: ";
						cin >> tamanioy;
						b0.escalamiento(tamaniox, tamanioy);
						b1.escalamiento(tamaniox, tamanioy);
						b2.escalamiento(tamaniox, tamanioy);
						b3.escalamiento(tamaniox, tamanioy);
						DibujarLinea(lineaI.getX(), lineaI.getY(), lineaF.getX(), lineaF.getY());
						lol = false;
						break;
					default:
						cout << "No escogiste nada";
						lol = false;
					}
				}
				else {
					lol = false;
				}

			}

			//Update screen
			SDL_RenderPresent(gRenderer);
		}

	}
	//Free resources and close SDL
	close();
	return 0;
}