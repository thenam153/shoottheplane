#include "monster.h"



MonsterObject::MonsterObject()
{
        x_pos_=s_width*0.4;
        y_pos_=0;
        x_val_=0;
        y_val_=0;
          rect_.x=0;
    rect_.y=0;
    rect_.w=mwidth;
    rect_.h=mheight;

}
MonsterObject::~MonsterObject()
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

void MonsterObject::handlemove(int x_boder,int y_boder)
{
    y_pos_+=y_val_;
    if (y_pos_>s_height)
    {
        x_pos_=makerand(400);
        y_pos_=0;
    }
    this->setrect(x_pos_,y_pos_);
}

void MonsterObject::resetbot(int x_boder)
{
    x_pos_=makerand(400);
    y_pos_=-makerand(200)-50;
    /*
    for(int i=0; i<q_bullet_list_.size();i++)
    {
        BulletObject* p_bullet=q_bullet_list_.at(i);
        if (p_bullet)
        {
            resetbullet(p_bullet);
        }
    }*/
}

void  MonsterObject::resetbullet(BulletObject* p_bullet)
{
    p_bullet->set_x_pos(getxpos());
    p_bullet->set_y_pos(getypos());
    p_bullet->setrect(getxpos()+w_monster,getypos()+h_monster);
}

void MonsterObject::initbullet(BulletObject* p_bullet,SDL_Renderer* renderer)
{
    if (p_bullet)
    {
        p_bullet->set_type(BulletObject::bl_1);
        p_bullet->loadfile("image/bullet_enemy.png",renderer);
        p_bullet->set_x_pos(this->getxpos());
        p_bullet->set_y_pos(this->getypos());
        p_bullet->setrect(this->getxpos()+w_monster,this->getypos()+h_monster);
        p_bullet->set_y_val(7);
        p_bullet->set_move(true);
        q_bullet_list_.push_back(p_bullet);
    }
}

void MonsterObject::makebullet(SDL_Renderer*renderer)
{
    for(int i=0;i<q_bullet_list_.size();i++)
    {
        BulletObject* p_bullet=q_bullet_list_.at(i);
        if (p_bullet)
        {
            if (p_bullet->get_move())
            {
                p_bullet->handlemovebot();
                p_bullet->render(p_bullet->get_x_pos()+w_monster,p_bullet->get_y_pos()+h_monster,NULL,0,NULL,SDL_FLIP_NONE,renderer);
            }
            else
            {
                p_bullet->set_move(true);
                p_bullet->set_x_pos(this->getxpos());
                p_bullet->set_y_pos(this->getypos());
                p_bullet->setrect(this->getxpos()+w_monster,this->getypos()+h_monster);
            }
        }
    }
}

