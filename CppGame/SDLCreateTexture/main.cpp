#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL2/SDL.h>
#include <SDL.h>
//Moving Rectangle
int main ( int argc, char** argv )
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Event event;
    SDL_Rect r;
    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    window = SDL_CreateWindow("SDL_CreateTexture",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                1024, 768,
                SDL_WINDOW_RESIZABLE);

    r.w = 100;
    r.h = 50;

    renderer = SDL_CreateRenderer(window, -1, 0);

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                SDL_TEXTUREACCESS_TARGET, 1024, 768);



//    // make sure SDL cleans up before exit
//    atexit(SDL_Quit);
//
//    // create a new window
//    SDL_Surface* screen = SDL_SetVideoMode(640, 480, 16,
//                                           SDL_HWSURFACE|SDL_DOUBLEBUF);
//    if ( !screen )
//    {
//        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
//        return 1;
//    }
//
//    // load an image
//    SDL_Surface* bmp = SDL_LoadBMP("cb.bmp");
//    if (!bmp)
//    {
//        printf("Unable to load bitmap: %s\n", SDL_GetError());
//        return 1;
//    }
//
//    // centre the bitmap on screen
//    SDL_Rect dstrect;
//    dstrect.x = (screen->w - bmp->w) / 2;
//    dstrect.y = (screen->h - bmp->h) / 2;
//
//    // program main loop
//    bool done = false;
    while (1)
    {
        // message processing loop
        //SDL_Event event;
        SDL_PollEvent(&event);

            // check for messages
        if(event.type == SDL_QUIT) break;
        r.x = rand()%500;
        r.y = rand()%500;

        SDL_SetRenderTarget(renderer, texture);
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00,0x00,0x00);
        SDL_RenderClear(renderer);
        SDL_RenderDrawRect(renderer, &r);
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00,0x00,0x00);
        SDL_RenderFillRect(renderer, &r);
        SDL_SetRenderTarget(renderer, NULL);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);

                // exit if the window is closed
//            case SDL_QUIT:
//                done = true;
//                break;
//
//                // check for keypresses
//            case SDL_KEYDOWN:
//                {
//                    // exit if ESCAPE is pressed
//                    if (event.key.keysym.sym == SDLK_ESCAPE)
//                        done = true;
//                    break;
//                }
//            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE

        // clear screen
        //SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        // draw bitmap
        //SDL_BlitSurface(bmp, 0, screen, &dstrect);

        // DRAWING ENDS HERE

        // finally, update the screen :)
        //SDL_Flip(screen);
    //} // end main loop

    // free loaded bitmap
    //SDL_FreeSurface(bmp);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}
