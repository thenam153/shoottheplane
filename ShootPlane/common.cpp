#include "common.h"
void timenull()
{
     srand(time(NULL));
}
int makerand(int val)
{

        int rand_=rand()%val;
        if (rand_<0||rand_>s_height-200)
        {
            rand_=s_height - rand()*(s_height-200)+10;
        }
        return rand_;
}

bool checkcollision(SDL_Rect object1,SDL_Rect object2)
{
int left_a = object1.x;
  int right_a = object1.x + object1.w;
  int top_a = object1.y;
  int bottom_a = object1.y + object1.h;

  int left_b = object2.x;
  int right_b = object2.x + object2.w;
  int top_b = object2.y;
  int bottom_b = object2.y + object2.h;


  if (left_a > left_b && left_a < right_b)
  {
    if (top_a > top_b && top_a < bottom_b)
    {
      return true;
    }
  }

  if (left_a > left_b && left_a < right_b)
  {
    if (bottom_a > top_b && bottom_a < bottom_b)
    {
      return true;
    }
  }

  if (right_a > left_b && right_a < right_b)
  {
    if (top_a > top_b && top_a < bottom_b)
    {
      return true;
    }
  }

  if (right_a > left_b && right_a < right_b)
  {
    if (bottom_a > top_b && bottom_a < bottom_b)
    {
      return true;
    }
  }


  if (left_b > left_a && left_b < right_a)
  {
    if (top_b > top_a && top_b < bottom_a)
    {
      return true;
    }
  }

  if (left_b > left_a && left_b < right_a)
  {
    if (bottom_b > top_a && bottom_b < bottom_a)
    {
      return true;
    }
  }

  if (right_b > left_a && right_b < right_a)
  {
    if (top_b > top_a && top_b < bottom_a)
    {
      return true;
    }
  }

  if (right_b > left_a && right_b < right_a)
  {
    if (bottom_b > top_a && bottom_b < bottom_a)
    {
      return true;
    }
  }


  if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
  {
    return true;
  }

  return false;

}

