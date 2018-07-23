#include "bulletobject.h"

BulletObject::BulletObject()
{
    x_val_=0;
    y_val_=0;
    x_pos_=0;
    y_pos_=0;
    rect_.x=0;
    rect_.y=0;
    rect_.w=mwidth;
    rect_.h=mheight;

    is_move_=false;
    bullet_type_=none;
}
BulletObject::~BulletObject()
{

}

void BulletObject::handlemove(int x_boder,int y_boder)
{
    if (is_move_==true)
    {
        y_pos_-=y_val_;
        if (y_pos_<0) is_move_=false;
    }
    this->setrect(x_pos_+w_main,y_pos_+h_main);
}
void BulletObject::handlemovebot()
{
    if (is_move_==true)
    {
        y_pos_+=y_val_;
        if (y_pos_>s_height) is_move_=false;
    }
    this->setrect(x_pos_+w_monster,y_pos_+h_monster);
}
