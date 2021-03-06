/*
** point.c for rush in /home/lavand_m/Desktop/piscine/piscinecpprush1
**
** Made by Maxime
** Login   <lavand_m@epitech.net>
**
** Started on  Sat Jan 11 10:57:16 2014 Maxime
** Last update Sat Jan 11 15:44:10 2014 Maxime
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "point.h"

typedef struct
{
  Class base;
  int x, y;
  char *str;
} PointClass;

static void Point_ctor(Object* self, va_list *ap)
{
  PointClass *a;

  a = (PointClass *) self;
  a->x = (int)va_arg(*ap, int);
  a->y = (int)va_arg(*ap, int);
  a->str = NULL;
}

static void Point_dtor(Object* self)
{
  PointClass *a;

  a = (PointClass *) self;
  if (a != NULL)
    free(a->str);
}

static char const *Point_str(Object* self)
{
  PointClass *a;

  a = (PointClass *) self;
  if (self != NULL && !strcmp(a->base.__name__, "Point"))
    {
      if (a->str != NULL)
        free(a->str);
      a->str = malloc(200);
      snprintf(a->str, 199, "<%s (%d, %d)>", (a->base).__name__, a->x, a->y);
      return(a->str);
    }
  return NULL;
}

static PointClass _description = {
  { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, &Point_str },
  0, 0, NULL
};

Class* Point = (Class*) &_description;
