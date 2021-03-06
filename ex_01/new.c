/*
** new.c for new in /home/debas_e/Project/piscine_cpp/Rush/piscinecpprush1/ex_01
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Sat Jan 11 09:28:41 2014 Etienne
** Last update Sat Jan 11 09:56:51 2014 Etienne
*/

#include <stdlib.h>
#include <string.h>

#include "object.h"
#include "raise.h"

Object		*new(Class *object)
{
  Object	*ret;

  ret = NULL;
  if (object != NULL)
    {
      if ((ret = malloc(object->__size__)) == NULL)
        raise("Out of memory");
      memcpy(ret, object, object->__size__);
      if (((Class*)ret)->__init__ != NULL)
        ((Class*)ret)->__init__(ret);
    }
  return (ret);
}


void		delete(Object* ptr)
{
  if (ptr != NULL)
    {
      Class *base = (Class*)ptr;
      if (base->__del__ != NULL)
        base->__del__(ptr);
      free(ptr);
    }
}
