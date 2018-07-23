#include "mainobject.h"

MainObject::MainObject()
{
    x_pos_=200;
    y_pos_=600;
    rect_.x=200;
    rect_.y=600;
    rect_.w=mwidth;
    rect_.h=mheight;
}
MainObject::~MainObject()
{

}
void MainObject::handleinput(SDL_Event e,SDL_Renderer* renderer)
{

    if (e.type==SDL_KEYDOWN&&e.key.repeat==0)
    {
        switch(e.key.keysym.sym)
        {
        case SDLK_w: y_val_-=y_val;break;
        case SDLK_s: y_val_+=y_val;break;
        case SDLK_a: x_val_-=x_val;break;
        case SDLK_d: x_val_+=x_val;break;
        }
    }
    else
    if (e.type==SDL_KEYUP&&e.key.repeat==0)
    {
        switch(e.key.keysym.sym)
        {
        case SDLK_w: y_val_+=y_val;break;
        case SDLK_s: y_val_-=y_val;break;
        case SDLK_a: x_val_+=x_val;break;
        case SDLK_d: x_val_-=x_val;break;

        }
    }else
    if (e.type==SDL_MOUSEMOTION)
        {
            x_pos_=e.motion.x-38;
            y_pos_=e.motion.y-35;
        }
    if (e.type==SDL_MOUSEBUTTONDOWN||(e.type==SDL_KEYDOWN&&e.key.repeat==0))
    {
        BulletObject* p_bullet= new BulletObject();
        if ((e.button.button==SDL_BUTTON_RIGHT||e.key.keysym.sym==SDLK_SPACE)&&bullet_pow!=0)
        {
            p_bullet->loadfile("image/bullet_1.png",renderer);
            p_bullet->set_type(BulletObject::bl_1);
            bullet_shoot=Mix_LoadWAV("music/bullet.wav");
            bullet_pow--;
            Mix_PlayChannel(-1,bullet_shoot,0);
        }
        else if(e.button.button==SDL_BUTTON_LEFT)
        {
            p_bullet->loadfile("image/bullet.png",renderer);
            p_bullet->set_type(BulletObject::bl_2);
            bullet_shoot=Mix_LoadWAV("music/bullet.wav");
            Mix_PlayChannel(-1,bullet_shoot,0);
        }
        p_bullet->set_y_pos(this->getypos());
        p_bullet->set_x_pos(this->getxpos());
        p_bullet->setrect(x_pos_+w_main,y_pos_+h_main);
        p_bullet->set_move(true);
        p_bullet->set_y_val(20);
        q_bullet_list_.push_back(p_bullet);
    }
    if (e.type==SDL_MOUSEBUTTONUP)
    {

    }
}
void MainObject::makebullet(SDL_Renderer* renderer)
{
    for(int i=0;i<q_bullet_list_.size();i++)
    {
        BulletObject* p_bullet=q_bullet_list_.at(i);
        if(p_bullet!=NULL)
        {

            if (p_bullet->get_move())
            {
                p_bullet->handlemove(s_width,s_height);
                p_bullet->render(p_bullet->get_x_pos()+w_main,p_bullet->get_y_pos()+h_main,NULL,0,NULL,SDL_FLIP_NONE,renderer);
            }
            else
            {
                if (p_bullet!=NULL)
                {
                    q_bullet_list_.erase(q_bullet_list_.begin()+i);
                    delete p_bullet;
                    p_bullet=NULL;
                }
            }
        }
    }
}
void MainObject::removebullet(int &ind)
{
    for(int i=0;i<q_bullet_list_.size();i++)
    {
        if (ind<q_bullet_list_.size())
        {
            BulletObject* p_bullet=q_bullet_list_.at(ind);
            q_bullet_list_.erase(q_bullet_list_.begin()+ind);
            if (p_bullet!=NULL)
            {
                delete p_bullet;
                p_bullet=NULL;
            }


        }
    }
}


void MainObject::handlemove()
{
    x_pos_+=x_val_;

    if (x_pos_<0||x_pos_+mwidth>s_width)
    {
        x_pos_-=x_val_;
    }
    y_pos_+=y_val_;
    if (y_pos_<0||y_pos_+mheight>s_height)
    {
        y_pos_-=y_val_;
    }
    this->setrect(x_pos_,y_pos_);
}

