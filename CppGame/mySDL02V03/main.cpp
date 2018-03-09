#ifdef __cplusplus
    #include <cstdlib>
    #include <iostream>
#else
    #include <stdlib.h>
#endif

//#include <SDL/SDL.h>
#include <SDL2/SDL.h>

enum KeyPressSurfaces {
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

//Starts up SDL and creates window
bool init();
//Loads media
bool loadMedia();
//Frees media and shuts down SDL
void close();
//The window we'll be rendering to
SDL_Window *gWindow = NULL;
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
//The image we will load and show on the screen
SDL_Surface* loadSurface( std::string path );
//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];
//Current displayed image
SDL_Surface* gCurrentSurface = NULL;
//Main loop flag
bool quit = false;
//Event handler
SDL_Event e;

SDL_Surface* loadSurface( std::string path )
{
    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    if( loadedSurface == NULL){
        printf("Imaginea nu poate fi incarcata %s! SDL Error: %s\n",
                path.c_str(), SDL_GetError() );
    }
    return loadedSurface;
}

bool init(){
    //Initialization flag
    bool success = true;
     if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    } else {
        gWindow = SDL_CreateWindow("SDL_Tutorial", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,1200, 880, SDL_WINDOW_SHOWN);
        if(gWindow == NULL){
            printf("Window not open! \n");
        } else {
             gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return success;
}

bool loadMedia(){
    //Loading success flag
    bool success = true;
    //load splash image
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "cb.bmp" );
    if(gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL){
        printf ("Imaginea nu a fost incarcata!");
        success = false;
    }
    //Load up surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface( "cb.bmp" );
    if(gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL){
        printf ("Imaginea nu a fost incarcata!");
        success = false;
    }

    return success;
}

void close(){
    //Dealocate surface
    //SDL_FreeSurface(gHelloWorld);
    //gHelloWorld = NULL;
    //Destroy window
    SDL_DestroyWindow( gWindow);
    gWindow = NULL;
    //Quit SDL subsystems
    SDL_Quit();
}
int main ( int argc, char** argv )
{
    //Start up SDL and create window
    if(!init()){
        printf("Initializare nereusita!");
    } else {
        //Load media
        if(!loadMedia()){
            printf("Incarcare imagine nereusita!");
        } else {

            //Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}
            //Aply the image
            //SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
            //Update the surface
            SDL_UpdateWindowSurface( gWindow);
            //Wait two seconds
            //SDL_Delay(2000);
            }
        }
    }
    //free resource and close SDL
    close();
    return 0;
}
