#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

//#include <SDL2/SDL.h>
#include <SDL/SDL.h>
#include <string>
#include <iostream>
// Dimensiunea ecranului x, y setari
const int SCREEN_WIDTH  = 1240;
const int SCREEN_HEIGHT = 640;
/**
* Log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
void logSDLError(std::ostream &os, const std::string &msg){
    os<<msg<<" error: "<<SDL_GetError()<<std::endl;
}

//SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren){
//    //Initialize to nullptr to avoid dangling pointer issues
//    SDL_Texture *texture = nullptr;
//    //Load the image
//    SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
//    //If the loading went ok, convert to texture and return the texture
//    if(loadedImage != nullptr){
//        texture = SDL_CreateTextureFromSurface(ren, loadedImage);
//        SDL_FreeSurface(loadedImage);
//        //Make sure converting went ok too
//        if(texture == nullptr){
//            logSDLError(std::cout, "CreateTextureFromSurface");
//        }
//    }
//    else {
//        logSDLError(std::cout, "LoadBMP");
//    }
//    return texture;
//}


int main ( int argc, char** argv )
{
    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);
    //Initializing SDL_ttf
//    if(TTF_Init() != 0){
//        logSDLError(std::cout, "TTF_Init");
//        SDL_Quit();
//        return 1;
//    }

    // create a new window
    SDL_Surface* screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 16,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !screen )
    {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }

    // load an image
    SDL_Surface* bmp = SDL_LoadBMP("fot.bmp");
    if (!bmp)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }

    // centre the bitmap on screen
    SDL_Rect dstrect;
    dstrect.x = (screen->w - bmp->w) / 2;
    dstrect.y = (screen->h - bmp->h) / 2;

    // program main loop
    bool done = false;
    while (!done)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    break;
                }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE

        // clear screen
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        // draw bitmap
        SDL_BlitSurface(bmp, 0, screen, &dstrect);

        // DRAWING ENDS HERE

        // finally, update the screen :)
        SDL_Flip(screen);
    } // end main loop

    // free loaded bitmap
    SDL_FreeSurface(bmp);

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}
