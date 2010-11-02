/* ********************************************************************** */
/* ap_linexprconsgenXXX_conv.c: conversion between linear expressions and constraints */
/* ********************************************************************** */

#include "ap_linexprconsgenXXX_conv.h"

#include "boundXXX.h"
#include "itvXXX.h"
#include "eitvXXX.h"

#include "itvXXX_conv.h"
#include "itvD_conv.h"
#include "itvMPQ_conv.h"
#include "itvMPFR_conv.h"


#define _APXXX_MARK_

MACRO_MAINZ
bool ap_linexprXXX_set_linexprZZZ(ap_linexprXXX_t a, ap_linexprZZZ_t b, num_internal_t intern)
{
  size_t i;
  bool res = eitvXXX_set_eitvZZZ(a->cst,b->cst,intern);
  ap_linexprXXX_resize(a,b->size);
  for (i=0; i<a->size; i++){
    a->linterm[i]->dim = b->linterm[i]->dim;
    res = eitvXXX_set_eitvZZZ(a->linterm[i]->eitv,b->linterm[i]->eitv,intern) || res;
  }
  return res;
}
bool ap_linexprXXX_array_set_linexprZZZ_array(ap_linexprXXX_array_t a, ap_linexprZZZ_array_t b, num_internal_t intern)
{
  size_t i;
  bool res = true;
  ap_linexprXXX_array_resize(a,b->size);
  for (i=0; i<b->size; i++){
    res = ap_linexprXXX_set_linexprZZZ(a->p[i],b->p[i],intern) && res;
  }
  return res;
}
bool ap_linconsXXX_set_linconsZZZ(ap_linconsXXX_t a, ap_linconsZZZ_t b, num_internal_t intern)
{
  bool res;
  res = ap_linexprXXX_set_linexprZZZ(a->linexpr,b->linexpr,intern);
  a->constyp = b->constyp;
  mpq_set(a->mpq,b->mpq);
  return res;
}
bool ap_linconsXXX_array_set_linconsZZZ_array(ap_linconsXXX_array_t a, ap_linconsZZZ_array_t b, num_internal_t intern)
{
  size_t i;
  bool res = true;
  ap_linconsXXX_array_resize(a,b->size);
  for (i=0; i<b->size; i++){
    res = ap_linconsXXX_set_linconsZZZ(a->p[i],b->p[i],intern) && res;
  }
  return res;
}
bool ap_lingenXXX_set_lingenZZZ(ap_lingenXXX_t a, ap_lingenZZZ_t b, num_internal_t intern)
{
  bool res;
  res = ap_linexprXXX_set_linexprZZZ(a->linexpr,b->linexpr,intern);
  a->gentyp = b->gentyp;
  return res;
}
bool ap_lingenXXX_array_set_lingenZZZ_array(ap_lingenXXX_array_t a, ap_lingenZZZ_array_t b, num_internal_t intern)
{
  size_t i;
  bool res = true;
  ap_lingenXXX_array_resize(a,b->size);
  for (i=0; i<b->size; i++){
    res = ap_lingenXXX_set_lingenZZZ(a->p[i],b->p[i],intern) && res;
  }
  return res;
}

#if !defined(_APZZZ_MARK_) && !defined(_APD_MARK_) && !defined(_APMPQ_MARK_) && !defined(_APMPFR_MARK_)
bool ap_linexprZZZ_set_linexprXXX(ap_linexprZZZ_t a, ap_linexprXXX_t b, num_internal_t intern)
{
  size_t i;
  bool res = eitvZZZ_set_eitvXXX(a->cst,b->cst,intern);
  ap_linexprZZZ_resize(a,b->size);
  for (i=0; i<a->size; i++){
    a->linterm[i]->dim = b->linterm[i]->dim;
    res = eitvZZZ_set_eitvXXX(a->linterm[i]->eitv,b->linterm[i]->eitv,intern) || res;
  }
  return res;
}
bool ap_linexprZZZ_array_set_linexprXXX_array(ap_linexprZZZ_array_t a, ap_linexprXXX_array_t b, num_internal_t intern)
{
  size_t i;
  bool res = true;
  ap_linexprZZZ_array_resize(a,b->size);
  for (i=0; i<b->size; i++){
    res = ap_linexprZZZ_set_linexprXXX(a->p[i],b->p[i],intern) && res;
  }
  return res;
}
bool ap_linconsZZZ_set_linconsXXX(ap_linconsZZZ_t a, ap_linconsXXX_t b, num_internal_t intern)
{
  bool res;
  res = ap_linexprZZZ_set_linexprXXX(a->linexpr,b->linexpr,intern);
  a->constyp = b->constyp;
  return res;
}
bool ap_linconsZZZ_array_set_linconsXXX_array(ap_linconsZZZ_array_t a, ap_linconsXXX_array_t b, num_internal_t intern)
{
  size_t i;
  bool res = true;
  ap_linconsZZZ_array_resize(a,b->size);
  for (i=0; i<b->size; i++){
    res = ap_linconsZZZ_set_linconsXXX(a->p[i],b->p[i],intern) && res;
  }
  return res;
}
bool ap_lingenZZZ_set_lingenXXX(ap_lingenZZZ_t a, ap_lingenXXX_t b, num_internal_t intern)
{
  bool res;
  res = ap_linexprZZZ_set_linexprXXX(a->linexpr,b->linexpr,intern);
  a->gentyp = b->gentyp;
  return res;
}
bool ap_lingenZZZ_array_set_lingenXXX_array(ap_lingenZZZ_array_t a, ap_lingenXXX_array_t b, num_internal_t intern)
{
  size_t i;
  bool res = true;
  ap_lingenZZZ_array_resize(a,b->size);
  for (i=0; i<b->size; i++){
    res = ap_lingenZZZ_set_lingenXXX(a->p[i],b->p[i],intern) && res;
  }
  return res;
}
#endif

ENDMACRO

#undef _APXXX_MARK_