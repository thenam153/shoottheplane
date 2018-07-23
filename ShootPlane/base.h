#ifndef BASE_H_
#define BASE_H_
#include "common.h"

using namespace std;
class LTexture
{
public:
    LTexture();
    ~LTexture();

    bool loadfile(string path,SDL_Renderer *renderer);
    bool loadtext( string textureText,SDL_Renderer* renderer,TTF_Font* font );
    void free();
    void render(int x, int y,SDL_Rect* clip=NULL,double angle=0.0,SDL_Point* center=NULL,SDL_RendererFlip flip=SDL_FLIP_NONE,SDL_Renderer* renderer=NULL );
    void settextcolor(SDL_Color text_color) {textcolor=text_color;};
    int getwidth();
    int getheight();
    void setrect(const int& x, const int& y){rect_.x=x;rect_.y=y;rect_.w=mwidth;rect_.h=mheight;}
    SDL_Rect getrect() {return rect_;}
protected:
    SDL_Texture* mtext=NULL;
    int mwidth;
    int mheight;
    SDL_Rect rect_;
    SDL_Color textcolor;
};

#endif // BASE_H_
