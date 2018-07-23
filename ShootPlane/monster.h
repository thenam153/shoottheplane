#ifndef MONSTER_H_
#define MONSTER_H_
#include "base.h"
#include "bulletobject.h"
#include <vector>

class MonsterObject: public LTexture
{
public:
    MonsterObject();
    ~MonsterObject();
    void handlemove(int x_boder,int y_boder);
    void setxval(int x_val) {x_val_=x_val;}
    void setyval(int y_val) {y_val_=y_val;}

    void setxpos(int x_pos) {x_pos_=x_pos;}
    void setypos(int y_pos) {y_pos_=y_pos;}


    int getxval(){return x_val_;}
    int getyval(){return y_val_;}

    int getxpos() {return x_pos_;}
    int getypos() {return y_pos_;}
     void setbulletlist(vector<BulletObject*> bulletlist){q_bullet_list_=bulletlist;}
    vector<BulletObject*> getbullet() {return q_bullet_list_;}
    void initbullet(BulletObject* p_bullet,SDL_Renderer* renderer);
    void makebullet(SDL_Renderer *renderer);
    void resetbot(int x_boder);
    void resetbullet(BulletObject* p_bullet);
private:
    int x_pos_,x_val_;
    int y_pos_,y_val_;
    vector<BulletObject*>  q_bullet_list_;
};


#endif // MONSTER_H_
