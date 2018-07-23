#include "base.h"

LTexture::LTexture()
{
    mtext=NULL;
    mwidth=0;
    mheight=0;
    rect_.x=0;
    rect_.y=0;
    rect_.w=mwidth;
    rect_.h=mheight;
}


LTexture::~LTexture()
{
    free();
}

bool LTexture::loadfile(string path,SDL_Renderer *renderer)
{
    SDL_Texture* text=NULL;
    SDL_Surface* sur=IMG_Load(path.c_str());
    if(sur==NULL)
    {
        cout<<"Loi";
        return false;
    }
    SDL_SetColorKey(sur,SDL_TRUE,SDL_MapRGBA(sur->format,0,255,255,125));

    text=SDL_CreateTextureFromSurface(renderer,sur);
    if (text==NULL)
    {
        cout<<"Loi 1"<<SDL_GetError();
        return false;
    }
    mtext=text;
    mwidth=sur->w;
    mheight=sur->h;
    return mtext!=NULL;
}

bool LTexture::loadtext( string textureText,SDL_Renderer* renderer,TTF_Font* font )
{

	free();


	SDL_Surface* textSurface = TTF_RenderText_Solid( font, textureText.c_str(), textcolor );
	if( textSurface == NULL )
	{
		return false;
	}
	else
	{

        mtext = SDL_CreateTextureFromSurface( renderer, textSurface );
		if( mtext == NULL )
		{
			return false;
		}
		else
		{

			mwidth = textSurface->w;
			mheight = textSurface->h;
		}


		SDL_FreeSurface( textSurface );
	}


	return mtext != NULL;
}
void LTexture::free()
{
    if(mtext!=NULL)
    {
        SDL_DestroyTexture(mtext);
        mtext=NULL;
        mwidth=0;
        mheight=0;
    }
}
void LTexture::render(int x, int y,SDL_Rect* clip,double angle,SDL_Point* center,SDL_RendererFlip flip,SDL_Renderer* renderer)
{
    SDL_Rect sour={x,y,mwidth,mheight};
    if (clip!=NULL)
    {
        sour.w=clip->w;
        sour.h=clip->h;
    }
    SDL_RenderCopyEx(renderer,mtext,clip,&sour,angle,center,flip);
}

int LTexture::getheight()
{
   return mheight;
}
int LTexture::getwidth()
{
    return mwidth;
}

