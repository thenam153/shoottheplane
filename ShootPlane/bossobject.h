#ifndef BOSSOBJECT_H_
#define BOSSOBJECT_H_
#include "base.h"
#include "bulletobject.h"
#include <vector>

class bossobject: public LTexture
{
public:
    bossobject();
    ~bossobject();
    void handlemove();
    void setxval(int x_val) {x_val_=x_val;}
    void setyval(int y_val) {y_val_=y_val;}

    void setxpos(int x_pos) {x_pos_=x_pos;}
    void setypos(int y_pos) {y_pos_=y_pos;}


    int getxval(){return x_val_;}
    int getyval(){return y_val_;}

    int getxpos() {return x_pos_;}
    int getypos() {return y_pos_;}

    int getheal() {return heal;}
    void setheal(int x) {heal=x;}
    void setbulletlist(vector<BulletObject*> bulletlist){q_bullet_list_=bulletlist;}
    vector<BulletObject*> getbullet() {return q_bullet_list_;}
    void initbullet(BulletObject* p_bullet,SDL_Renderer* renderer);
    void makebullet(SDL_Renderer *renderer);
    void resetbullet(BulletObject* p_bullet);
private:
    int x_pos_,x_val_;
    int y_pos_,y_val_;
    vector<BulletObject*>  q_bullet_list_;
    int heal;
};


#endif // BOSSOBJECT_H_
