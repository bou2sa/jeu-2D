#include"vie.h"

void init_vie(vie *v) 
{
 (v->position.x)=0;
 (v->position.y)=0;
 (v->val)=0 ;
 (v->image[1])=IMG_Load("vie0.png") ;
 (v->image[2])=IMG_Load("vie1.png") ;
 (v->image[3])=IMG_Load("vie2.png") ;
 (v->image[4])=IMG_Load("vie3.png") ;
 (v->image[5])=IMG_Load("vie4.png") ;
 (v->image[6])=IMG_Load("gameover.jpg") ;

}

void displayvie(vie v ,SDL_Surface *ecran) 
{

SDL_BlitSurface(v.image[(v.val)/25],NULL,ecran,&(v.position));
}


void vie_freevie(vie *v ) 
{
SDL_FreeSurface(v->image[0]);
SDL_FreeSurface(v->image[1]);
SDL_FreeSurface(v->image[2]);
SDL_FreeSurface(v->image[3]);
SDL_FreeSurface(v->image[4]);
SDL_FreeSurface(v->image[5]);
}

 
   
              



 
 






			
			
