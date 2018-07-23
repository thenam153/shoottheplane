#ifndef BULLETOBJECT_H_
#define BULLETOBJECT_H_
#include "base.h"

class BulletObject:public LTexture
{
public:
    enum btype
    {
        none=0,
        bl_1=1,
        bl_2=2,
    };
    BulletObject();
    ~BulletObject();
    void handlemove(int x_boder,int y_boder);
    void handlemovebot();

    int get_type() {return bullet_type_;}

    void set_type(const int& type ) {bullet_type_=type;}
    bool get_move() {return is_move_;}
    void set_move(bool is_move) {is_move_=is_move;}

    void set_x_val(int x_val) {x_val_=x_val;}
    void set_y_val(int y_val) {y_val_=y_val;}

    void set_x_pos(int x_pos) {x_pos_=x_pos;}
    void set_y_pos(int y_pos) {y_pos_=y_pos;}

    int get_x_pos() {return x_pos_;}
    int get_y_pos() {return y_pos_;}
private:
    int x_pos_,x_val_;
    int y_pos_,y_val_;
    int bullet_type_;
    bool is_move_;
};
#endif // BULLETOBJECT_H_
