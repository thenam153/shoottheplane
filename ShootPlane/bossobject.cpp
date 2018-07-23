#include "bossobject.h"



bossobject::bossobject()
{
    x_pos_=0;
    y_pos_=0;
    x_val_=0;
    y_val_=0;
    rect_.x=0;
    rect_.y=0;
    rect_.w=mwidth;
    rect_.h=mheight;

}
bossobject::~bossobject()
{
    if (q_bullet_list_.size()>0)
    {
        for(int i=0;i<q_bullet_list_.size();i++)
        {
            BulletObject* p_bullet=q_bullet_list_.at(i);
            if (p_bullet!=NULL)
            {
                delete p_bullet;
                p_bullet=NULL;

            }
        }
        q_bullet_list_.clear();
    }
}

void bossobject::handlemove()
{
    x_pos_+=x_val_;
    if (x_pos_+mwidth>s_width||x_pos_<0)
    {
        x_pos_-=x_val_;
        x_val_=-x_val_;
        y_pos_=0;
    }
    this->setrect(x_pos_,y_pos_);
}



void  bossobject::resetbullet(BulletObject* p_bullet)
{
    p_bullet->set_x_pos(getxpos()+w_monster_boss);
    p_bullet->set_y_pos(getypos()+h_monster_boss);
    p_bullet->setrect(getxpos(),getypos());
}

void bossobject::initbullet(BulletObject* p_bullet,SDL_Renderer* renderer)
{
    if (p_bullet)
    {
        p_bullet->set_type(BulletObject::bl_1);
        p_bullet->loadfile("image/bullet_enemy.png",renderer);
        p_bullet->set_x_pos(this->getxpos()+w_monster_boss);
        p_bullet->set_y_pos(this->getypos()+h_monster_boss);
        p_bullet->setrect(this->getxpos()+w_monster_boss,this->getypos()+h_monster_boss);
        p_bullet->set_y_val(10);
        p_bullet->set_move(true);
        q_bullet_list_.push_back(p_bullet);
    }
}

void bossobject::makebullet(SDL_Renderer*renderer)
{
    for(int i=0;i<q_bullet_list_.size();i++)
    {
        BulletObject* p_bullet=q_bullet_list_.at(i);
        if (p_bullet)
        {
            if (p_bullet->get_move())
            {
                p_bullet->handlemovebot();
                p_bullet->render(p_bullet->get_x_pos(),p_bullet->get_y_pos(),NULL,0,NULL,SDL_FLIP_NONE,renderer);
            }
            else
            {
                p_bullet->set_move(true);
                p_bullet->set_x_pos(this->getxpos()+w_monster_boss);
                p_bullet->set_y_pos(this->getypos()+h_monster_boss);
                p_bullet->setrect(this->getxpos()+w_monster_boss,this->getypos()+h_monster_boss);
            }
        }
    }
}


