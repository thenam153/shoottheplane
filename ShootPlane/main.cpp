#include "base.h"
#include "mainobject.h"
#include "monster.h"
#include "bossobject.h"
LTexture man;
MainObject human;
SDL_Renderer* renderer=NULL;
SDL_Window* window=NULL;
TTF_Font* font=NULL;
SDL_Color textcolor={0,0,0};
SDL_Color text_color={200,125,255};


LTexture score[10];
LTexture heart;
LTexture plane_break[3];
LTexture enemy_break;

LTexture begin1;
LTexture play;
LTexture suppost;
LTexture suppost1;

LTexture out;
LTexture out1;
LTexture out2;

LTexture huongdan;
LTexture caidat;
LTexture thoat;

LTexture gameover;
LTexture music_off_on;
LTexture music1;
LTexture music2;
LTexture music3;
LTexture music4;
LTexture music5;
LTexture music6;
LTexture game_over;

LTexture f_ten;
LTexture ok;
LTexture daluu;

LTexture rs;
LTexture quit_rs;

LTexture bang_1; // hieu ung no "bang bang "
LTexture pow;

LTexture hightscore;
LTexture tencao[5];
LTexture diemcao[5];
LTexture diemcao_out;
LTexture diemcao_bg;

LTexture diem_r;
LTexture die[5];

string ten[3];
string diem[10];
int diem1[3];

bool ss(string path,int diem2)
{
    ifstream infile;
    infile.open(path.c_str());
 	for (int i=0;i<3;i++)
 	{
        infile >> ten[i];
        infile >> diem[i];
        diem1[i]=atoi(diem[i].c_str());
	}
	for(int i=0;i<3;i++)
        if (diem2>diem1[i])
            {
                infile.close();
                return true;
            }
    return false;
    infile.close();
}
void openfile(string path,string tenso,int diemso)
{
    ifstream infile;
    infile.open(path.c_str());
 	for (int i=0;i<3;i++)
 	{
        infile >> ten[i];
        infile >> diem[i];
        diem1[i]=atoi(diem[i].c_str());
	}
    infile.close();
    ofstream outfile;
    outfile.open(path.c_str());
    bool ghi=false;
    string data;
    int vt=0;
    for(int i=0;i<3;i++)
        if (diemso>diem1[i])
            {
                vt=i;
                ghi=true;
                break;
            }
    if (ghi)
    {
        for(int i=0;i<3;i++)
        {
            if (vt==i)
            {
                outfile << tenso << endl;
                outfile << diemso << endl;
            }
            else
            {
                outfile<<ten[i]<<endl;
                outfile<<diem1[i]<<endl;
            }
        }
    }
    else
    {
        for(int i=0;i<3;i++)
        {
            outfile<<ten[i]<<endl;
            outfile<<diem1[i]<<endl;
        }
    }
    outfile.close();
}

bool init();
bool loadmedia();
void close();
void diemso(int s_score);
bool loadmedia()
{
    font=TTF_OpenFont("ttf/comicbd.ttf",54);
    if (font==NULL)
    {
        return false;
    }
    else
    {
        textcolor={0,0,0};
    }
    if (!man.loadfile("image/background.png",renderer))
        return false;
    if (!human.loadfile("image/myplane.png",renderer))
        return false;
    if (!plane_break[0].loadfile("image/plane_break1.png",renderer))
        return false;
    if (!plane_break[1].loadfile("image/plane_break2.png",renderer))
        return false;
    if (!plane_break[2].loadfile("image/plane_break3.png",renderer))
        return false;
    if (!score[0].loadfile("image/0.png",renderer))
        return false;
    if (!score[1].loadfile("image/1.png",renderer))
        return false;
    if (!score[2].loadfile("image/2.png",renderer))
        return false;
    if (!score[3].loadfile("image/3.png",renderer))
        return false;
    if (!score[4].loadfile("image/4.png",renderer))
        return false;
    if (!score[5].loadfile("image/5.png",renderer))
        return false;
    if (!score[6].loadfile("image/6.png",renderer))
        return false;
    if (!score[7].loadfile("image/7.png",renderer))
        return false;
    if (!score[8].loadfile("image/8.png",renderer))
        return false;
    if (!score[9].loadfile("image/9.png",renderer))
        return false;
    if (!suppost1.loadfile("image/huongdan.png",renderer))
        return false;
    if(!out.loadfile("image/out.png",renderer))
        return false;
    if (!gameover.loadfile("image/gameover.png",renderer))
        return false;
    if (!heart.loadfile("image/heart.png",renderer))
        return false;
    if (!music_off_on.loadfile("image/music_on_off.png",renderer))
        return false;
    if (!rs.loadfile("image/play_rs.png",renderer))
        return false;
    if (!quit_rs.loadfile("image/quit_rs.png",renderer))
        return false;
    if (!bang_1.loadfile("image/bang_1.png",renderer))
        return false;
    if (!pow.loadfile("image/pow_dem.png",renderer))
        return false;
    if (!die[0].loadfile("image/boss_die_1.png",renderer))
        return false;
    if (!die[1].loadfile("image/boss_die_2.png",renderer))
        return false;
    if (!die[2].loadfile("image/boss_die_3.png",renderer))
        return false;
    if (!die[3].loadfile("image/boss_die_4.png",renderer))
        return false;
    if (!die[4].loadfile("image/boss_die_5.png",renderer))
        return false;
    if (!diemcao_bg.loadfile("image/diemcao_bg.png",renderer))
        return false;
    return true;
}
void close()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}
int getso(int core)
{
    int so=1;
    while(core!=0)
    {
        so++;
        core=core/10;
    }
    return so;
}
bool init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING)<0)
    {
        return false;
    }
    window=SDL_CreateWindow("Game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,s_width,s_height,SDL_WINDOW_SHOWN);
    if (window==NULL)
    {
        return false;
    }
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if (renderer==NULL)
        {
            return false;
        }
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            return false;
        }
    if( TTF_Init() == -1 )
        {
            return false;
        }
    return true;
}

int main(int argc, char*argv[])
{
    if (!init()) return -1;
    if (!loadmedia()) return -1;
    //
    b_music=Mix_LoadMUS("music/game_music.mp3");
    //
    if (Mix_PlayingMusic()==0)
    {
        Mix_PlayMusic(b_music,-1);
    }
    //
    VONG_LAP:
    //
    bool isrun=true;

    bool run=false;

    SDL_Event e;

    int mang=10;

    int _bg=0;

    int s_score=0;

    bool bullet_POW=true;

    bool boss_live=false;

    bool firt_boss=true;

    int lastboss=0;

    int m_boss=30;

    human.setbulletpow(3);
    //
    bossobject boss_1;

    if (!boss_1.loadfile("image/boss_1.png",renderer))
    {
        return false;
    }
    else
    {
            boss_1.setxpos(147);
            boss_1.setypos(-250);
            boss_1.setxval(3);

            BulletObject* p__bullet=new BulletObject();
            boss_1.initbullet(p__bullet,renderer);
    }

    // monster

    MonsterObject *monster= new MonsterObject[monster_];

    for (int m = 0; m < monster_; m++)
    {
        MonsterObject *p_monster = monster+m;

        if (p_monster)
        {
            if (!p_monster->loadfile("image/enemy.png",renderer))
            {
                SDL_Quit();
                return 0;
            }
            int rand_=makerand(200-m);
            p_monster->setxpos(rand_);
            p_monster->setypos(s_width+m*200);
            p_monster->setyval(5);

            BulletObject* p_bullet=new BulletObject();
            p_monster->initbullet(p_bullet,renderer);

        }
    }

    int vonglap=0;

    while(run==false)
    {
        while (SDL_PollEvent(&e))
        {
            if(e.type==SDL_QUIT)
                {
                    run=true;isrun=false;
                }
            if (e.motion.x>80&&e.motion.x<195&&e.motion.y<175&&e.motion.y>110)
                {
                   if (e.type==SDL_MOUSEBUTTONDOWN&&vonglap==0)
                   vonglap=1;
                   begin1.settextcolor(text_color);
                }
                else
                    {begin1.settextcolor(textcolor);}
            if (e.motion.x>80&&e.motion.x<315&&e.motion.y<290&&e.motion.y>235)
                {
                   if (e.type==SDL_MOUSEBUTTONDOWN&&vonglap==0)
                   vonglap=5;
                   hightscore.settextcolor(text_color);
                }
                else
                    {hightscore.settextcolor(textcolor);}
            if (e.motion.x>80&&e.motion.x<335&&e.motion.y<425&&e.motion.y>360)
                {
                    if (e.type==SDL_MOUSEBUTTONDOWN&&vonglap==0)
                    vonglap=2;
                    huongdan.settextcolor(text_color);
                }
                else {huongdan.settextcolor(textcolor);}
            if (e.motion.x>80&&e.motion.x<230&&e.motion.y<675&&e.motion.y>610)
                {
                    if (e.type==SDL_MOUSEBUTTONDOWN&&vonglap==0)
                    vonglap=3;
                    thoat.settextcolor(text_color);
                }
                else
                {
                    thoat.settextcolor(textcolor);
                }
            if (e.motion.x>80&&e.motion.x<250&&e.motion.y<550&&e.motion.y>485)
                {
                    if (e.type==SDL_MOUSEBUTTONDOWN&&vonglap==0)
                    vonglap=4;
                    caidat.settextcolor(text_color);
                }
                else
                {
                   caidat.settextcolor(textcolor);
                }

                // xong

                if ( vonglap==1)
                {
                    if (e.motion.x>91&&e.motion.x<373&&e.motion.y<592&&e.motion.y>512)
                        {
                            if (e.type==SDL_MOUSEBUTTONDOWN)
                            run=true;
                            play.settextcolor(text_color);
                        }
                else
                    {
                        play.settextcolor(textcolor);
                    }
                }
                if (vonglap==2)
                {
                    if (e.motion.x>28&&e.motion.x<417&&e.motion.y<218&&e.motion.y>120)
                    {
                        if (e.type==SDL_MOUSEBUTTONDOWN)
                        vonglap=0;
                        suppost.settextcolor(text_color);
                    }
                    else
                    {
                        suppost.settextcolor(textcolor);
                    }
                }
                if (vonglap==3)
                {
                    if (e.motion.x>50&&e.motion.x<155&&e.motion.y<465&&e.motion.y>380)
                    {
                        if (e.type==SDL_MOUSEBUTTONDOWN)
                         {
                            run=true;
                            isrun=false;
                         }
                         out1.settextcolor(text_color);
                    }
                    else
                        {
                            out1.settextcolor(textcolor);
                        }
                    if(e.motion.x>302&&e.motion.x<380&&e.motion.y<465&&e.motion.y>380)
                    {
                         if (e.type==SDL_MOUSEBUTTONDOWN)
                            vonglap=0;
                            out2.settextcolor(text_color);
                    }
                    else
                    {
                        out2.settextcolor(textcolor);
                    }
                }
                if (vonglap==4)
                {
                    if(e.motion.x>10&&e.motion.x<430&&e.motion.y<143&&e.motion.y>53)
                    {
                        if (e.type==SDL_MOUSEBUTTONDOWN)
                            vonglap=0;
                        music1.settextcolor(text_color);
                    }
                    else
                    {
                        music1.settextcolor(textcolor);
                    }


                    if(e.motion.x>70&&e.motion.x<160&&e.motion.y<320&&e.motion.y>253)
                    {
                        if (e.type==SDL_MOUSEBUTTONDOWN)
                        if (Mix_PlayingMusic()==0)
                        {
                            Mix_PlayMusic(b_music,-1);
                        }
                        music2.settextcolor(text_color);
                    }
                    else
                    {
                        music2.settextcolor(textcolor);
                    }
                     if(e.motion.x>253&&e.motion.x<350&&e.motion.y<320&&e.motion.y>253)
                    {
                          if (e.type==SDL_MOUSEBUTTONDOWN)
                          if (Mix_PlayingMusic()==1)
                        {
                            Mix_HaltMusic();
                        }
                        music3.settextcolor(text_color);
                    }
                    else
                    {
                        music3.settextcolor(textcolor);
                    }



                    if(e.motion.x>10&&e.motion.x<444&&e.motion.y<440&&e.motion.y>374)
                    {
                         if (e.type==SDL_MOUSEBUTTONDOWN){
                        if (Mix_PlayingMusic()==1)
                        {
                            Mix_HaltMusic();
                        }
                         b_music=Mix_LoadMUS("music/chayngaydi.mp3");
    //
                        if (Mix_PlayingMusic()==0)
                        {
                        Mix_PlayMusic(b_music,-1);
                        }}
                        music4.settextcolor(text_color);
                    }
                    else
                    {
                        music4.settextcolor(textcolor);
                    }
                     if(e.motion.x>10&&e.motion.x<330&&e.motion.y<543&&e.motion.y>465)
                    {
                         if (e.type==SDL_MOUSEBUTTONDOWN)
                            {
                            if (Mix_PlayingMusic()==1)
                            {
                                Mix_HaltMusic();
                            }
                            b_music=Mix_LoadMUS("music/b_game.mp3");
    //
                            if (Mix_PlayingMusic()==0)
                            {
                                Mix_PlayMusic(b_music,-1);
                            }
                            }
                        music5.settextcolor(text_color);
                    }
                    else
                    {
                        music5.settextcolor(textcolor);
                    }

                    if(e.motion.x>10&&e.motion.x<310&&e.motion.y<637&&e.motion.y>566)
                    {
                         if (e.type==SDL_MOUSEBUTTONDOWN)
                        {
                         if (Mix_PlayingMusic()==1)
                            {
                                Mix_HaltMusic();
                            }
                         b_music=Mix_LoadMUS("music/Bua_Yeu.mp3");
    //
                        if (Mix_PlayingMusic()==0)
                        {
                            Mix_PlayMusic(b_music,-1);
                        }
                        }
                        music6.settextcolor(text_color);
                    }
                    else
                    {
                        music6.settextcolor(textcolor);
                    }
                }

                if (vonglap==5)
                {
                    if(e.motion.x>10&&e.motion.x<430&&e.motion.y<143&&e.motion.y>53)
                    {
                        if (e.type==SDL_MOUSEBUTTONDOWN)
                        vonglap=0;
                        diemcao_out.settextcolor(text_color);
                    }
                    else
                    {
                        diemcao_out.settextcolor(textcolor);
                    }
                }

            }

        SDL_RenderClear(renderer);
        man.render(0,0,NULL,0,NULL,SDL_FLIP_NONE,renderer);
        switch(vonglap)
        {
        case 0:
            begin1.loadtext("Choi",renderer,font);
            begin1.render(80,110,NULL,0,NULL,SDL_FLIP_NONE,renderer);
            hightscore.loadtext("Diem cao",renderer,font);
            hightscore.render(80,235,NULL,0,NULL,SDL_FLIP_NONE,renderer);
            huongdan.loadtext("Huong dan",renderer,font);
            huongdan.render(80,360,NULL,0,NULL,SDL_FLIP_NONE,renderer);
            caidat.loadtext("Cai dat",renderer,font);
            caidat.render(80,485,NULL,0,NULL,SDL_FLIP_NONE,renderer);
            thoat.loadtext("Thoat",renderer,font);
            thoat.render(80,610,NULL,0,NULL,SDL_FLIP_NONE,renderer);
            break;
        case 1:
            play.loadtext("BAT DAU!",renderer,font);
            play.render(90,515,NULL,0,NULL,SDL_FLIP_NONE,renderer);break;
        case 2:
            suppost1.render(0,0,NULL,0,NULL,SDL_FLIP_NONE,renderer);
            suppost.loadtext("Quay dau",renderer,font);
            suppost.render(155,110,NULL,0,NULL,SDL_FLIP_NONE,renderer);break;
        case 3:
            out.render(0,0,NULL,0,NULL,SDL_FLIP_NONE,renderer);
            out1.loadtext("Yes",renderer,font);
            out1.render(50,380,NULL,0,NULL,SDL_FLIP_NONE,renderer);
            out2.loadtext("No",renderer,font);
            out2.render(302,380,NULL,0,NULL,SDL_FLIP_NONE,renderer);
        break;
        case 4:
                music_off_on.render(0,0,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                music1.loadtext("Quay dau",renderer,font);
                music1.render(155,49,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                music2.loadtext("Bat",renderer,font);
                music2.render(70,253,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                music3.loadtext("Tat",renderer,font);
                music3.render(253,253,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                music4.loadtext("Chay Ngay Di ",renderer,font);
                music4.render(10,374,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                music5.loadtext("Nguoi Am Phu",renderer,font);
                music5.render(10,465,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                music6.loadtext("Bua Yeu",renderer,font);
                music6.render(10,566,NULL,0,NULL,SDL_FLIP_NONE,renderer);break;

        case 5:
                string ten_5[3]={"1 ","2 ","3 "},ten_;
                string diem_5[3];
                diemcao_bg.render(0,0,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                diemcao_out.loadtext("Quay dau",renderer,font);
                diemcao_out.render(155,49,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                ifstream infile;
                infile.open("hightscore.txt");
                for (int i=0;i<3;i++)
                {
                    infile >> ten_;
                    ten_5[i]+=ten_;
                    infile >> diem_5[i];
                    tencao[i].loadtext(ten_5[i],renderer,font);
                    tencao[i].render(50,(i+1)*65+200,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                    diemcao[i].loadtext(diem_5[i],renderer,font);
                    diemcao[i].render(300,(i+1)*65+200,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                }
                infile.close();
        break;
        }
        SDL_RenderPresent(renderer);
    }

    if (run)
    {
    while (isrun)
    {

        while (SDL_PollEvent(&e))
        {
            if(e.type==SDL_QUIT)
                isrun=false;
            if (e.type==SDL_KEYDOWN)
            {
                if(e.key.keysym.sym==SDLK_ESCAPE) //P
                {
                    while(true)
                    {
                        quit_rs.render(s_width/2-quit_rs.getwidth(),s_height/2-10,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                        rs.render(s_width/2+rs.getwidth(),s_height/2,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                        SDL_RenderPresent(renderer);
                        while(SDL_PollEvent(&e))
                        {
                        if (e.type==SDL_MOUSEBUTTONDOWN)
                        {
                            if (e.motion.x>80&&e.motion.x<218&&e.motion.y>395&&e.motion.y<455)
                                goto VONG_LAP;
                            else
                                goto RESUME;
                        }
                        }
                    }
                }
            }

            RESUME:

            human.handleinput(e,renderer);
        }

        // Bg
         _bg+=3;
        if (boss_live==true) {_bg-=3;}

        if (_bg>man.getheight()) _bg=0;

        man.render(0,_bg,NULL,0,NULL,SDL_FLIP_NONE,renderer);

        man.render(0,_bg-man.getheight(),NULL,0,NULL,SDL_FLIP_NONE,renderer);


        //diem so
        int diem=s_score;

        int x=getso(s_score)*15;
        // + pow
        if (s_score%10==0&&s_score!=0&&bullet_POW)
        {
            get_pow=Mix_LoadWAV("music/get_bomb.wav");
            Mix_PlayChannel(-1,get_pow,0);
            human.setbulletpow(human.getbulletpow()+1);
            bullet_POW=false;
        }

        if (diem==0) score[0].render(x,0,NULL,0,NULL,SDL_FLIP_NONE,renderer);
        else
        {
            while(diem!=0)
            {
                score[diem%10].render(x,0,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                diem=diem/10;
                x-=15;
            }
        }
        //mang song

        int x_=0;

        for (int mg=0;mg<mang;mg++)
        {
            heart.render(x_,30,NULL,0,NULL,SDL_FLIP_NONE,renderer);x_+=30;
        }
        // POW
        int x__=0;
        for(int ipow=0;ipow<human.getbulletpow();ipow++)
        {
            pow.render(x__,60,NULL,0,NULL,SDL_FLIP_NONE,renderer);x__+=30;
        }
        //
        human.handlemove();
        human.render(human.getxpos(),human.getypos(),NULL,0,NULL,SDL_FLIP_NONE,renderer);
        human.makebullet(renderer);

        if (boss_live==false)
        {
        for(int mm=0;mm<monster_;mm++)
        {
            MonsterObject* p_moster=monster+mm;
            if (p_moster)
            {
                p_moster->handlemove(s_width,s_height);
                p_moster->render(p_moster->getrect().x,p_moster->getrect().y,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                p_moster->makebullet(renderer);

    // dan no voi minh
                bool is_coll=true;;
                vector<BulletObject*> bullet_arr=p_moster->getbullet();
                for (int bl=0;bl<bullet_arr.size();bl++)
                {
                    BulletObject* p_bullet=bullet_arr.at(bl);
                    if (p_bullet)
                    {


                        is_coll=checkcollision(p_bullet->getrect(),human.getrect());

                        if (is_coll==true)
                        {
                            p_moster->resetbullet(p_bullet);
                            break;
                        }
                    }
                }
// 2 thang voi nhau
                bool is_col=checkcollision(human.getrect(),p_moster->getrect());
                if (is_coll)
                {

                    mang--;
                    dead=Mix_LoadWAV("music/game_over.wav");
                    Mix_PlayChannel(-1,dead,0);

                }
                if (is_col)
                {
                    p_moster->resetbot(s_width-200);
                    dead=Mix_LoadWAV("music/game_over.wav");
                    Mix_PlayChannel(-1,dead,0);
                    mang--;
                }
  //dan minh vs no
                vector<BulletObject*> bullet_list=human.getbullet();
                for(int im=0;im <bullet_list.size();im++)
                {
                    BulletObject* p_bullet=bullet_list.at(im);
                    if (p_bullet!=NULL)
                    {
                        if (p_bullet->get_type()==2){
                        bool ret_col=checkcollision(p_bullet->getrect(),p_moster->getrect());
                        if (ret_col)
                        {
                            human.removebullet(im);
                            bang_1.render(p_moster->getxpos(),p_moster->getypos(),NULL,0,NULL,SDL_FLIP_NONE,renderer);
                            p_moster->resetbot(s_width);
                                s_score++;
                            enemy1_down=Mix_LoadWAV("music/enemy1_down.wav");
                            Mix_PlayChannel(-1,enemy1_down,0);
                        }
                        }
                        else if (p_bullet->get_type()==1)
                        {
                            if (p_bullet->get_y_pos()<200){
                            human.removebullet(im);

                            s_score+=monster_;
                            }
                            bang_1.render(p_moster->getxpos(),p_moster->getypos(),NULL,0,NULL,SDL_FLIP_NONE,renderer);
                            p_moster->resetbot(s_width);

                            enemy1_down=Mix_LoadWAV("music/enemy1_down.wav");
                            Mix_PlayChannel(-1,enemy1_down,0);

                        }

                    }
                }


            }
            if (s_score%10!=0) {bullet_POW=true;}
            if (s_score%m_boss==0&&boss_live==false&&s_score!=0) {boss_live=true;boss_1.setheal(20);m_boss=m_boss*5/2;}
            if (mang<=0)
                {
                    string ten1=" ";
                    bool kiemten=false;
                    bool kiemten2=true;
                    bool i_s=true;
                    if (i_s)
                    {
                    for (int i=0;i<30;i++)
                    {
                        plane_break[i/10].render(human.getxpos(),human.getypos(),NULL,0,NULL,SDL_FLIP_NONE,renderer);
                        SDL_RenderPresent(renderer);
                    }
                    if (ss("hightscore.txt",s_score)) {
                            while(i_s)
                    {
                        gameover.render(0,0,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                        game_over.loadtext("Game Over!",renderer,font);
                        game_over.render(63,500,NULL,0,NULL,SDL_FLIP_NONE,renderer);

                        while(SDL_PollEvent(&e))
                        {
                            if (e.type==SDL_QUIT)
                            {
                             i_s=false;
                            }
                            if (e.motion.x>63&&e.motion.x<380&&e.motion.y>500&&e.motion.y<570)
                            {


                            if (e.type==SDL_MOUSEBUTTONDOWN)
                            {
                                goto VONG_LAP;
                            }
                            game_over.settextcolor(text_color);
                            }
                            else
                            {
                                game_over.settextcolor(textcolor);
                            }

                    if (e.type==SDL_KEYDOWN)
                    {
                        switch(e.key.keysym.sym)
                            {
                                    case SDLK_a: ten1+="a";break;
                                    case SDLK_b: ten1+="b";break;
                                    case SDLK_c: ten1+="c";break;
                                    case SDLK_d: ten1+="d";break;
                                    case SDLK_e: ten1+="e";break;
                                    case SDLK_f: ten1+="f";break;
                                    case SDLK_g: ten1+="g";break;
                                    case SDLK_h: ten1+="h";break;
                                    case SDLK_i: ten1+="i";break;
                                    case SDLK_k: ten1+="k";break;
                                    case SDLK_l: ten1+="l";break;
                                    case SDLK_m: ten1+="m";break;
                                    case SDLK_n: ten1+="n";break;
                                    case SDLK_o: ten1+="o";break;
                                    case SDLK_p: ten1+="p";break;
                                    case SDLK_q: ten1+="q";break;
                                    case SDLK_r: ten1+="r";break;
                                    case SDLK_s: ten1+="s";break;
                                    case SDLK_t: ten1+="t";break;
                                    case SDLK_u: ten1+="u";break;
                                    case SDLK_v: ten1+="v";break;
                                    case SDLK_x: ten1+="x";break;
                                    case SDLK_y: ten1+="y";break;
                                    case SDLK_z: ten1+="z";break;
                                    case SDLK_BACKSPACE:
                                        ten1=" ";break;
                                    case SDLK_SPACE: kiemten=true;break;
                            }
                        }
                        if (e.motion.x>350&&e.motion.x<420&&e.motion.y>100&&e.motion.y<170)
                        {
                            if (e.type==SDL_MOUSEBUTTONDOWN)
                            {

                                kiemten=true;
                            }
                            ok.settextcolor(text_color);

                        }
                        else
                        {
                            ok.settextcolor(textcolor);
                        }

                    }


                    f_ten.loadtext(ten1,renderer,font);
                    f_ten.render(50,100,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                    ok.loadtext("OK",renderer,font);
                    ok.render(350,100,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                    if (kiemten2==false)
                    {

                        daluu.loadtext("Da luu",renderer,font);
                        daluu.render(120,200,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                    }
                    SDL_RenderPresent(renderer);
                    if (kiemten&&kiemten2)
                    {
                        openfile("hightscore.txt",ten1,s_score);
                        kiemten2=false;
                    }
                    }
                    }
                else
                    {
                    while(i_s)
                    {
                        man.render(0,0,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                        game_over.loadtext("Game Over!",renderer,font);
                        game_over.render(63,500,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                        SDL_RenderPresent(renderer);
                        while(SDL_PollEvent(&e))
                        {
                            if (e.type==SDL_QUIT)
                            {
                             i_s=false;
                            }
                            if (e.motion.x>63&&e.motion.x<380&&e.motion.y>500&&e.motion.y<570)
                            {


                            if (e.type==SDL_MOUSEBUTTONDOWN)
                            {
                                goto VONG_LAP;
                            }
                            game_over.settextcolor(text_color);
                            }
                            else
                            {
                                game_over.settextcolor(textcolor);
                            }
                        }

                    }
                    }
                    isrun=false;
                    }
                }
        }
       }
       else
        {
            if (boss_live==true)
            {
                if (firt_boss==true)
                {

                    boss_1.setypos(boss_1.getypos()+5);
                    boss_1.render(boss_1.getxpos(),boss_1.getypos(),NULL,0,NULL,SDL_FLIP_NONE,renderer);
                    SDL_Delay(30);
                    if (boss_1.getypos()>=0)
                    {firt_boss=false;

                    }
                }
                else
                {
            {
                boss_1.handlemove();
                boss_1.render(boss_1.getrect().x,boss_1.getrect().y,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                boss_1.makebullet(renderer);



                bool is_coll=true;;
                vector<BulletObject*> bullet_arr=boss_1.getbullet();
                for (int bl=0;bl<bullet_arr.size();bl++)
                {
                    BulletObject* p_bullet=bullet_arr.at(bl);
                    if (p_bullet)
                    {
                        is_coll=checkcollision(p_bullet->getrect(),human.getrect());

                        if (is_coll==true)
                        {
                            boss_1.resetbullet(p_bullet);
                            break;
                        }
                    }
                }
//check
                bool is_col=checkcollision(human.getrect(),boss_1.getrect());
                if (is_coll)
                {

                    mang--;
                    dead=Mix_LoadWAV("music/game_over.wav");
                    Mix_PlayChannel(-1,dead,0);

                }
                if (is_col)
                {
                    dead=Mix_LoadWAV("music/game_over.wav");
                    Mix_PlayChannel(-1,dead,0);
                    mang--;
                }
  //check main bullet -> with monster
                vector<BulletObject*> bullet_list=human.getbullet();
                for(int im=0;im <bullet_list.size();im++)
                {
                    BulletObject* p_bullet=bullet_list.at(im);
                    if (p_bullet!=NULL)
                    {
                        if (p_bullet->get_type()==2){
                        bool ret_col=checkcollision(p_bullet->getrect(),boss_1.getrect());
                        if (ret_col)
                        {
                            human.removebullet(im);
                            boss_1.setheal(boss_1.getheal()-1);
                            bang_1.render(p_bullet->get_x_pos(),boss_1.getypos()+boss_1.getheight()-30,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                            enemy1_down=Mix_LoadWAV("music/enemy1_down.wav");

                            Mix_PlayChannel(-1,enemy1_down,0);
                        }
                        }
                        if (p_bullet->get_type()==1)
                        {
                            if (p_bullet->get_y_pos()<200){
                            human.removebullet(im);
                            boss_1.setheal(boss_1.getheal()-2);
                            }
                            bang_1.render(p_bullet->get_x_pos(),boss_1.getypos()+boss_1.getheight()-30,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                            enemy1_down=Mix_LoadWAV("music/enemy1_down.wav");
                            Mix_PlayChannel(-1,enemy1_down,0);

                        }

                    }
                }


            }
            if (boss_1.getheal()<=0)
            {
                for (int idie=0;idie<boss_die;idie++)
                {
                    die[idie/boss_fame].render(boss_1.getxpos(),boss_1.getypos(),NULL,0,NULL,SDL_FLIP_NONE,renderer);
                    boss_come=Mix_LoadWAV("music/big_spaceship_flying.wav");
                    Mix_PlayChannel(-1,enemy1_down,0);
                    SDL_RenderPresent(renderer);
                }
                 boss_1.setxpos(147);
                boss_1.setypos(-250);
                boss_1.setxval(6);
                s_score+=20;
                boss_live=false;
                firt_boss=true;
                mang+=2;

            }
            if (s_score%10!=0) {bullet_POW=true;}
           if (mang<=0)
                {
                    string ten1=" ";
                    bool kiemten=false;
                    bool kiemten2=true;
                    bool i_s=true;
                    if (i_s)
                    {
                    for (int i=0;i<30;i++)
                    {
                        plane_break[i/10].render(human.getxpos(),human.getypos(),NULL,0,NULL,SDL_FLIP_NONE,renderer);
                        SDL_RenderPresent(renderer);
                    }
                    if (ss("hightscore.txt",s_score)) {
                            while(i_s)
                    {
                        gameover.render(0,0,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                        game_over.loadtext("Game Over!",renderer,font);
                        game_over.render(63,500,NULL,0,NULL,SDL_FLIP_NONE,renderer);

                        while(SDL_PollEvent(&e))
                        {
                            if (e.type==SDL_QUIT)
                            {
                             i_s=false;
                            }
                            if (e.motion.x>63&&e.motion.x<380&&e.motion.y>500&&e.motion.y<570)
                            {


                            if (e.type==SDL_MOUSEBUTTONDOWN)
                            {
                                goto VONG_LAP;
                            }
                            game_over.settextcolor(text_color);
                            }
                            else
                            {
                                game_over.settextcolor(textcolor);
                            }

                    if (e.type==SDL_KEYDOWN)
                    {
                        switch(e.key.keysym.sym)
                            {
                                    case SDLK_a: ten1+="a";break;
                                    case SDLK_b: ten1+="b";break;
                                    case SDLK_c: ten1+="c";break;
                                    case SDLK_d: ten1+="d";break;
                                    case SDLK_e: ten1+="e";break;
                                    case SDLK_f: ten1+="f";break;
                                    case SDLK_g: ten1+="g";break;
                                    case SDLK_h: ten1+="h";break;
                                    case SDLK_i: ten1+="i";break;
                                    case SDLK_k: ten1+="k";break;
                                    case SDLK_l: ten1+="l";break;
                                    case SDLK_m: ten1+="m";break;
                                    case SDLK_n: ten1+="n";break;
                                    case SDLK_o: ten1+="o";break;
                                    case SDLK_p: ten1+="p";break;
                                    case SDLK_q: ten1+="q";break;
                                    case SDLK_r: ten1+="r";break;
                                    case SDLK_s: ten1+="s";break;
                                    case SDLK_t: ten1+="t";break;
                                    case SDLK_u: ten1+="u";break;
                                    case SDLK_v: ten1+="v";break;
                                    case SDLK_x: ten1+="x";break;
                                    case SDLK_y: ten1+="y";break;
                                    case SDLK_z: ten1+="z";break;
                                    case SDLK_BACKSPACE:
                                        ten1=" ";break;
                                    case SDLK_SPACE: kiemten=true;break;
                            }
                        }
                        if (e.motion.x>350&&e.motion.x<420&&e.motion.y>100&&e.motion.y<170)
                        {
                            if (e.type==SDL_MOUSEBUTTONDOWN)
                            {

                                kiemten=true;
                            }
                            ok.settextcolor(text_color);

                        }
                        else
                        {
                            ok.settextcolor(textcolor);
                        }

                    }

                    f_ten.loadtext(ten1,renderer,font);
                    f_ten.render(50,100,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                    ok.loadtext("OK",renderer,font);
                    ok.render(350,100,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                    if (kiemten2==false)
                    {

                         daluu.loadtext("Da luu",renderer,font);
                    daluu.render(120,200,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                    }
                    SDL_RenderPresent(renderer);
                    if (kiemten&&kiemten2)
                    {
                        openfile("hightscore.txt",ten1,s_score);
                        kiemten2=false;
                    }
                    }

                    }

                else
                        {
                    while(i_s)
                    {
                        man.render(0,0,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                        game_over.loadtext("Game Over!",renderer,font);
                        game_over.render(63,500,NULL,0,NULL,SDL_FLIP_NONE,renderer);
                        SDL_RenderPresent(renderer);
                        while(SDL_PollEvent(&e))
                        {
                            if (e.type==SDL_QUIT)
                            {
                             i_s=false;
                            }
                            if (e.motion.x>63&&e.motion.x<380&&e.motion.y>500&&e.motion.y<570)
                            {


                            if (e.type==SDL_MOUSEBUTTONDOWN)
                            {
                                goto VONG_LAP;
                            }
                            game_over.settextcolor(text_color);
                            }
                            else
                            {
                                game_over.settextcolor(textcolor);
                            }
                        }

                    }
                    }
                    isrun=false;
                    }
                }
        }
        }
        }
        SDL_RenderPresent(renderer);
    }
    }
    close();
    return 0;
}
