/**
* @file test.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include"entite.h"
/**
* @brief To initialize the entite e .
* @param E the entite
* @return Nothing
*/

void initialiser_entite(ent *E)
{


E->spriteleft = IMG_Load("walk-left.png");
E->spriteright=IMG_Load("walk-right.png");
	E->dst.x = 0;
	E->dst.y = 0;


E->position_entite.x=0;
//E->position_entite.y=0;
E->position_map.x=0;
//E->position_map.y=0;
E->frame.x=0;
//E->frame.y=0;
E->frame.w = SPRITE_W;
E->frame.h = SPRITE_H;
E->dst.x=0;
//E->dst.y=0;


E->image_entite=NULL;


E->pos_alea_max_x=0;
E->pos_alea_min_x=0;

//E->pos_alea_max_y=0;
//E->pos_alea_min_y=0;

E-> pos_max_x=0;
E-> pos_min_x=0;

//E-> pos_min_y=0;
//E->pos_max_y=0;


}



/**
* @brief To random position of the entite e .
* @param positionmax the position
* @param positionmin the position
* @return position
*/


int position_aleatoire(int positionmax,int positionmin)
{
int pos;
 srand(time(NULL));
pos=rand()%(positionmax-positionmin+1)+positionmin;


return pos;
}



/**
* @brief To random move the entite e .
* @param E the entite
* @param scren the screen
* @param scren the background 
* @return Nothing
*/

void deplacement_aleatoire_animation(ent E,SDL_Surface *screen,SDL_Surface* backg)
{

int tempsPrecedent = 0, tempsActuel = 0;

int pos;
static int k=0;
int i,j;
    



E.pos_max_x=screen->w ;
E.image_entite->w ;

pos=position_aleatoire(E.pos_max_x,E.pos_min_x);
int continuer=1;

while (continuer)

       {
 tempsActuel = SDL_GetTicks();


 initialiser_entite(&E);
        if (tempsActuel - tempsPrecedent > 30) /* Si 30 ms se sont écoulées depuis le dernier tour de boucle */
        {
           
              if(k==0)

                   { 
                     if(E.position_entite.x<pos)
                          {
for(j=0;j<1;j++)
		{
for(i = 0; i<MAX_FRAMES; i++)
		{

                   
                        E.frame.x = i*(Sint16)SPRITE_W;
			//E.frame.y = j*(Sint16)SPRITE_H;//0;
			E.frame.w = SPRITE_W;
			E.frame.h = SPRITE_H;
                        SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0)) ;
			SDL_BlitSurface(backg, NULL, screen, NULL);
			SDL_BlitSurface(E.spriteright, &E.frame, screen, &E.dst);
                        
			SDL_Flip(screen);
                        
			E.dst.x+=20;
                       
                SDL_Delay(500);
		}


              } 

                      
}
                else (k=1);
}
                     

                   
             if(k==1)
                 {
                    if(E.position_entite.x>=E.pos_min_x)//E.pos_min_x)
                            {

 for(j=0;j<1;j++)
{
       for(i = (MAX_FRAMES - 1); i>=0; i--)
            {
			E.frame.x = i*(Sint16)SPRITE_W;
			//E.frame.y = j*(Sint16)SPRITE_H;
			E.frame.w = SPRITE_W;
			E.frame.h = SPRITE_H;
                        SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0)) ;
			SDL_BlitSurface(backg, NULL, screen, NULL);
			SDL_BlitSurface(E.spriteleft, &E.frame, screen, &E.dst);
			SDL_Flip(screen);
                        
                         E.dst.x-=20;

			SDL_Delay(500);
	    }
}
                      

                            }
 else
                         k=0;
}
                   
                               
                                    
            tempsPrecedent = tempsActuel; 
        }






 }  
   

}
