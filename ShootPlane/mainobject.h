#ifndef MAINOBJECT_H_
#define MAINOBJECT_H_
#include "base.h"
#include "bulletobject.h"
#include <vector>
class MainObject: public LTexture
{
public:
    static const int x_val=10;
    static const int y_val=10;
    MainObject();
    ~MainObject();
    void handleinput(SDL_Event e,SDL_Renderer* renderer);
    void handlemove();

    void setbulletlist(vector<BulletObject*> bulletlist){q_bullet_list_=bulletlist;}
    vector<BulletObject*> getbullet() {return q_bullet_list_;}
    void setbulletpow(int x) { bullet_pow=x;}
    void makebullet(SDL_Renderer *renderer);
    void removebullet(int& ind);
    int getxpos() {return x_pos_;}
    int getypos() {return y_pos_;}
    int getbulletpow() {return bullet_pow;}
private:
    int x_pos_,x_val_;
    int y_pos_,y_val_;
    int bullet_pow;
    vector<BulletObject*> q_bullet_list_;

};
#endif // MAINOBJECT_H_
