/***** Autogenerated from runpath.in; changes will be overwritten *****/

#line 1 "runtimebase.in"
/*****
 * runtimebase.in
 * Andy Hammerlindl  2009/07/28
 *
 * Common declarations needed for all code-generating .in files.
 *
 *****/


#line 1 "runpath.in"
/*****
 * runpicture.in
 *
 * Runtime functions for picture operations.
 *
 *****/

#line 1 "runtimebase.in"
#include "stack.h"
#include "types.h"
#include "builtin.h"
#include "entry.h"
#include "errormsg.h"
#include "array.h"
#include "triple.h"
#include "callable.h"

using vm::stack;
using vm::error;
using vm::array;
using vm::read;
using vm::callable;
using types::formal;
using types::function;
using camp::triple;

#define PRIMITIVE(name,Name,asyName) using types::prim##Name;
#include <primitives.h>
#undef PRIMITIVE

typedef double real;

void unused(void *);

namespace run {
array *copyArray(array *a);
array *copyArray2(array *a);
array *copyArray3(array *a);

inline size_t checkdimension(const array *a, size_t dim)
{
  size_t size=checkArray(a);
  if(dim && size != dim) {
    ostringstream buf;
    buf << "array of length " << dim << " expected";
    error(buf);
  }
  return size;
}

template<class T>
void copyArrayC(T* &dest, const array *a, size_t dim=0,
                GCPlacement placement=NoGC)
{
  size_t size=checkdimension(a,dim);
  dest=(placement == NoGC) ? new T[size] : new(placement) T[size];
  for(size_t i=0; i < size; i++) 
    dest[i]=read<T>(a,i);
}

template<class T>
void copyArray2C(T* &dest, const array *a, bool square=true, size_t dim2=0,
                 GCPlacement placement=NoGC)
{
  size_t n=checkArray(a);
  size_t m=(square || n == 0) ? n : checkArray(read<array*>(a,0));
  if(n > 0 && dim2 && m != dim2) {
    ostringstream buf;
    buf << "second matrix dimension must be " << dim2;
    error(buf);
  }
  
  dest=(placement == NoGC) ? new T[n*m] : new(placement) T[n*m];
  for(size_t i=0; i < n; i++) {
    array *ai=read<array*>(a,i);
    size_t aisize=checkArray(ai);
    if(aisize == m) {
      T *desti=dest+i*m;
      for(size_t j=0; j < m; j++) 
        desti[j]=read<T>(ai,j);
    } else
      error(square ? "matrix must be square" : "matrix must be rectangular");
  }
}

double *copyTripleArray2Components(array *a, bool square=true, size_t dim2=0,
                                   GCPlacement placement=NoGC);
}

function *realRealFunction();

#define CURRENTPEN processData().currentpen

#line 16 "runpath.in"
#include "path.h"
#include "arrayop.h"
#include "predicates.h"

using namespace camp;
using namespace vm;

typedef array realarray;
typedef array realarray2;
typedef array patharray;

using types::realArray;
using types::realArray2;
using types::pathArray;

Int windingnumber(array *p, camp::pair z)
{
  size_t size=checkArray(p);
  Int count=0;
  for(size_t i=0; i < size; i++) 
    count += read<path *>(p,i)->windingnumber(z);
  return count;
}

// Autogenerated routines:



namespace run {
#line 43 "runpath.in"
void nullPath(stack *Stack)
{
#line 44 "runpath.in"
  {Stack->push<path>(nullpath); return;}
}

#line 48 "runpath.in"
// bool ==(path a, path b);
void gen_runpath1(stack *Stack)
{
  path b=vm::pop<path>(Stack);
  path a=vm::pop<path>(Stack);
#line 49 "runpath.in"
  {Stack->push<bool>(a == b); return;}
}

#line 53 "runpath.in"
// bool !=(path a, path b);
void gen_runpath2(stack *Stack)
{
  path b=vm::pop<path>(Stack);
  path a=vm::pop<path>(Stack);
#line 54 "runpath.in"
  {Stack->push<bool>(!(a == b)); return;}
}

#line 58 "runpath.in"
// pair point(path p, Int t);
void gen_runpath3(stack *Stack)
{
  Int t=vm::pop<Int>(Stack);
  path p=vm::pop<path>(Stack);
#line 59 "runpath.in"
  {Stack->push<pair>(p.point((Int) t)); return;}
}

#line 63 "runpath.in"
// pair point(path p, real t);
void gen_runpath4(stack *Stack)
{
  real t=vm::pop<real>(Stack);
  path p=vm::pop<path>(Stack);
#line 64 "runpath.in"
  {Stack->push<pair>(p.point(t)); return;}
}

#line 68 "runpath.in"
// pair precontrol(path p, Int t);
void gen_runpath5(stack *Stack)
{
  Int t=vm::pop<Int>(Stack);
  path p=vm::pop<path>(Stack);
#line 69 "runpath.in"
  {Stack->push<pair>(p.precontrol((Int) t)); return;}
}

#line 73 "runpath.in"
// pair precontrol(path p, real t);
void gen_runpath6(stack *Stack)
{
  real t=vm::pop<real>(Stack);
  path p=vm::pop<path>(Stack);
#line 74 "runpath.in"
  {Stack->push<pair>(p.precontrol(t)); return;}
}

#line 78 "runpath.in"
// pair postcontrol(path p, Int t);
void gen_runpath7(stack *Stack)
{
  Int t=vm::pop<Int>(Stack);
  path p=vm::pop<path>(Stack);
#line 79 "runpath.in"
  {Stack->push<pair>(p.postcontrol((Int) t)); return;}
}

#line 83 "runpath.in"
// pair postcontrol(path p, real t);
void gen_runpath8(stack *Stack)
{
  real t=vm::pop<real>(Stack);
  path p=vm::pop<path>(Stack);
#line 84 "runpath.in"
  {Stack->push<pair>(p.postcontrol(t)); return;}
}

#line 88 "runpath.in"
// pair dir(path p, Int t, Int sign=0, bool normalize=true);
void gen_runpath9(stack *Stack)
{
  bool normalize=vm::pop<bool>(Stack,true);
  Int sign=vm::pop<Int>(Stack,0);
  Int t=vm::pop<Int>(Stack);
  path p=vm::pop<path>(Stack);
#line 89 "runpath.in"
  {Stack->push<pair>(p.dir(t,sign,normalize)); return;}
}

#line 93 "runpath.in"
// pair dir(path p, real t, bool normalize=true);
void gen_runpath10(stack *Stack)
{
  bool normalize=vm::pop<bool>(Stack,true);
  real t=vm::pop<real>(Stack);
  path p=vm::pop<path>(Stack);
#line 94 "runpath.in"
  {Stack->push<pair>(p.dir(t,normalize)); return;}
}

#line 98 "runpath.in"
// pair accel(path p, Int t, Int sign=0);
void gen_runpath11(stack *Stack)
{
  Int sign=vm::pop<Int>(Stack,0);
  Int t=vm::pop<Int>(Stack);
  path p=vm::pop<path>(Stack);
#line 99 "runpath.in"
  {Stack->push<pair>(p.accel(t,sign)); return;}
}

#line 103 "runpath.in"
// pair accel(path p, real t);
void gen_runpath12(stack *Stack)
{
  real t=vm::pop<real>(Stack);
  path p=vm::pop<path>(Stack);
#line 104 "runpath.in"
  {Stack->push<pair>(p.accel(t)); return;}
}

#line 108 "runpath.in"
// real radius(path p, real t);
void gen_runpath13(stack *Stack)
{
  real t=vm::pop<real>(Stack);
  path p=vm::pop<path>(Stack);
#line 109 "runpath.in"
  pair v=p.dir(t,false);
  pair a=p.accel(t);
  real d=dot(a,v);
  real v2=v.abs2();
  real a2=a.abs2();
  real denom=v2*a2-d*d;
  real r=v2*sqrt(v2);
  {Stack->push<real>(denom > 0 ? r/sqrt(denom) : 0.0); return;}
}

#line 120 "runpath.in"
// path reverse(path p);
void gen_runpath14(stack *Stack)
{
  path p=vm::pop<path>(Stack);
#line 121 "runpath.in"
  {Stack->push<path>(p.reverse()); return;}
}

#line 125 "runpath.in"
// path subpath(path p, Int a, Int b);
void gen_runpath15(stack *Stack)
{
  Int b=vm::pop<Int>(Stack);
  Int a=vm::pop<Int>(Stack);
  path p=vm::pop<path>(Stack);
#line 126 "runpath.in"
  {Stack->push<path>(p.subpath((Int) a, (Int) b)); return;}
}

#line 130 "runpath.in"
// path subpath(path p, real a, real b);
void gen_runpath16(stack *Stack)
{
  real b=vm::pop<real>(Stack);
  real a=vm::pop<real>(Stack);
  path p=vm::pop<path>(Stack);
#line 131 "runpath.in"
  {Stack->push<path>(p.subpath(a,b)); return;}
}

#line 135 "runpath.in"
// path nurb(pair z0, pair z1, pair z2, pair z3,          real w0, real w1, real w2, real w3, Int m);
void gen_runpath17(stack *Stack)
{
  Int m=vm::pop<Int>(Stack);
  real w3=vm::pop<real>(Stack);
  real w2=vm::pop<real>(Stack);
  real w1=vm::pop<real>(Stack);
  real w0=vm::pop<real>(Stack);
  pair z3=vm::pop<pair>(Stack);
  pair z2=vm::pop<pair>(Stack);
  pair z1=vm::pop<pair>(Stack);
  pair z0=vm::pop<pair>(Stack);
#line 137 "runpath.in"
  {Stack->push<path>(nurb(z0,z1,z2,z3,w0,w1,w2,w3,m)); return;}
}

#line 141 "runpath.in"
// Int length(path p);
void gen_runpath18(stack *Stack)
{
  path p=vm::pop<path>(Stack);
#line 142 "runpath.in"
  {Stack->push<Int>(p.length()); return;}
}

#line 146 "runpath.in"
// bool cyclic(path p);
void gen_runpath19(stack *Stack)
{
  path p=vm::pop<path>(Stack);
#line 147 "runpath.in"
  {Stack->push<bool>(p.cyclic()); return;}
}

#line 151 "runpath.in"
// bool straight(path p, Int t);
void gen_runpath20(stack *Stack)
{
  Int t=vm::pop<Int>(Stack);
  path p=vm::pop<path>(Stack);
#line 152 "runpath.in"
  {Stack->push<bool>(p.straight(t)); return;}
}

#line 156 "runpath.in"
// path unstraighten(path p);
void gen_runpath21(stack *Stack)
{
  path p=vm::pop<path>(Stack);
#line 157 "runpath.in"
  {Stack->push<path>(p.unstraighten()); return;}
}

#line 161 "runpath.in"
// bool piecewisestraight(path p);
void gen_runpath22(stack *Stack)
{
  path p=vm::pop<path>(Stack);
#line 162 "runpath.in"
  {Stack->push<bool>(p.piecewisestraight()); return;}
}

#line 166 "runpath.in"
// real arclength(path p);
void gen_runpath23(stack *Stack)
{
  path p=vm::pop<path>(Stack);
#line 167 "runpath.in"
  {Stack->push<real>(p.arclength()); return;}
}

#line 171 "runpath.in"
// real arctime(path p, real dval);
void gen_runpath24(stack *Stack)
{
  real dval=vm::pop<real>(Stack);
  path p=vm::pop<path>(Stack);
#line 172 "runpath.in"
  {Stack->push<real>(p.arctime(dval)); return;}
}

#line 176 "runpath.in"
// real dirtime(path p, pair z);
void gen_runpath25(stack *Stack)
{
  pair z=vm::pop<pair>(Stack);
  path p=vm::pop<path>(Stack);
#line 177 "runpath.in"
  {Stack->push<real>(p.directiontime(z)); return;}
}

#line 181 "runpath.in"
// realarray* intersect(path p, path q, real fuzz=-1);
void gen_runpath26(stack *Stack)
{
  real fuzz=vm::pop<real>(Stack,-1);
  path q=vm::pop<path>(Stack);
  path p=vm::pop<path>(Stack);
#line 182 "runpath.in"
  bool exact=fuzz <= 0.0;
  if(fuzz < 0)
    fuzz=BigFuzz*::max(::max(length(p.max()),length(p.min())),
                       ::max(length(q.max()),length(q.min())));
  std::vector<real> S,T;
  real s,t;
  if(intersections(s,t,S,T,p,q,fuzz,true,exact)) {
    array *V=new array(2);
    (*V)[0]=s;
    (*V)[1]=t;
    {Stack->push<realarray*>(V); return;}
  }
  {Stack->push<realarray*>(new array(0)); return;}
}

#line 198 "runpath.in"
// realarray2* intersections(path p, path q, real fuzz=-1);
void gen_runpath27(stack *Stack)
{
  real fuzz=vm::pop<real>(Stack,-1);
  path q=vm::pop<path>(Stack);
  path p=vm::pop<path>(Stack);
#line 199 "runpath.in"
  bool exact=fuzz <= 0.0;
  if(fuzz < 0.0)
    fuzz=BigFuzz*::max(::max(length(p.max()),length(p.min())),
                       ::max(length(q.max()),length(q.min())));
  real s,t;
  std::vector<real> S,T;
  intersections(s,t,S,T,p,q,fuzz,false,true);
  size_t n=S.size();
  if(n == 0 && !exact) {
    if(intersections(s,t,S,T,p,q,fuzz,true,false)) {
      array *V=new array(1);
      array *Vi=new array(2);
      (*V)[0]=Vi;
      (*Vi)[0]=s;
      (*Vi)[1]=t;
      {Stack->push<realarray2*>(V); return;}
    }
  }
  array *V=new array(n);
  for(size_t i=0; i < n; ++i) {
    array *Vi=new array(2);
    (*V)[i]=Vi;
    (*Vi)[0]=S[i];
    (*Vi)[1]=T[i];
  }
  stable_sort(V->begin(),V->end(),run::compare2<real>());
  {Stack->push<realarray2*>(V); return;}
}

#line 229 "runpath.in"
// realarray* intersections(path p, explicit pair a, explicit pair b, real fuzz=-1);
void gen_runpath28(stack *Stack)
{
  real fuzz=vm::pop<real>(Stack,-1);
  pair b=vm::pop<pair>(Stack);
  pair a=vm::pop<pair>(Stack);
  path p=vm::pop<path>(Stack);
#line 230 "runpath.in"
  if(fuzz < 0)
    fuzz=BigFuzz*::max(::max(length(p.max()),length(p.min())),
                       ::max(length(a),length(b)));
  std::vector<real> S;
  intersections(S,p,a,b,fuzz);
  sort(S.begin(),S.end());
  size_t n=S.size();
  array *V=new array(n);
  for(size_t i=0; i < n; ++i)
    (*V)[i]=S[i];
  {Stack->push<realarray*>(V); return;}
}

// Return the intersection point of the extensions of the line segments 
// PQ and pq.
#line 246 "runpath.in"
// pair extension(pair P, pair Q, pair p, pair q);
void gen_runpath29(stack *Stack)
{
  pair q=vm::pop<pair>(Stack);
  pair p=vm::pop<pair>(Stack);
  pair Q=vm::pop<pair>(Stack);
  pair P=vm::pop<pair>(Stack);
#line 247 "runpath.in"
  pair ac=P-Q;
  pair bd=q-p;
  real det=ac.getx()*bd.gety()-ac.gety()*bd.getx();
  if(det == 0) {Stack->push<pair>(pair(infinity,infinity)); return;}
  {Stack->push<pair>(P+((p.getx()-P.getx())*bd.gety()-(p.gety()-P.gety())*bd.getx())*ac/det); return;}
}

#line 255 "runpath.in"
// Int size(path p);
void gen_runpath30(stack *Stack)
{
  path p=vm::pop<path>(Stack);
#line 256 "runpath.in"
  {Stack->push<Int>(p.size()); return;}
}

#line 260 "runpath.in"
// path &(path p, path q);
void gen_runpath31(stack *Stack)
{
  path q=vm::pop<path>(Stack);
  path p=vm::pop<path>(Stack);
#line 261 "runpath.in"
  {Stack->push<path>(camp::concat(p,q)); return;}
}

#line 265 "runpath.in"
// pair min(path p);
void gen_runpath32(stack *Stack)
{
  path p=vm::pop<path>(Stack);
#line 266 "runpath.in"
  {Stack->push<pair>(p.min()); return;}
}

#line 270 "runpath.in"
// pair max(path p);
void gen_runpath33(stack *Stack)
{
  path p=vm::pop<path>(Stack);
#line 271 "runpath.in"
  {Stack->push<pair>(p.max()); return;}
}

#line 275 "runpath.in"
// realarray* mintimes(path p);
void gen_runpath34(stack *Stack)
{
  path p=vm::pop<path>(Stack);
#line 276 "runpath.in"
  array *V=new array(2);
  pair z=p.mintimes();
  (*V)[0]=z.getx();
  (*V)[1]=z.gety();
  {Stack->push<realarray*>(V); return;}
}

#line 284 "runpath.in"
// realarray* maxtimes(path p);
void gen_runpath35(stack *Stack)
{
  path p=vm::pop<path>(Stack);
#line 285 "runpath.in"
  array *V=new array(2);
  pair z=p.maxtimes();
  (*V)[0]=z.getx();
  (*V)[1]=z.gety();
  {Stack->push<realarray*>(V); return;}
}

#line 293 "runpath.in"
// real relativedistance(real theta, real phi, real t, bool atleast);
void gen_runpath36(stack *Stack)
{
  bool atleast=vm::pop<bool>(Stack);
  real t=vm::pop<real>(Stack);
  real phi=vm::pop<real>(Stack);
  real theta=vm::pop<real>(Stack);
#line 294 "runpath.in"
  {Stack->push<real>(camp::velocity(theta,phi,tension(t,atleast))); return;}
}

#line 298 "runpath.in"
// Int windingnumber(patharray *p, pair z);
void gen_runpath37(stack *Stack)
{
  pair z=vm::pop<pair>(Stack);
  patharray * p=vm::pop<patharray *>(Stack);
#line 299 "runpath.in"
  {Stack->push<Int>(windingnumber(p,z)); return;}
}

#line 303 "runpath.in"
// bool inside(explicit patharray *g, pair z, pen fillrule=CURRENTPEN);
void gen_runpath38(stack *Stack)
{
  pen fillrule=vm::pop<pen>(Stack,CURRENTPEN);
  pair z=vm::pop<pair>(Stack);
  patharray * g=vm::pop<patharray *>(Stack);
#line 304 "runpath.in"
  {Stack->push<bool>(fillrule.inside(windingnumber(g,z))); return;}
}

#line 308 "runpath.in"
// bool inside(path g, pair z, pen fillrule=CURRENTPEN);
void gen_runpath39(stack *Stack)
{
  pen fillrule=vm::pop<pen>(Stack,CURRENTPEN);
  pair z=vm::pop<pair>(Stack);
  path g=vm::pop<path>(Stack);
#line 309 "runpath.in"
  {Stack->push<bool>(fillrule.inside(g.windingnumber(z))); return;}
}

// Determine the side of a--b that c lies on
// (negative=left, zero=on line, positive=right).
#line 315 "runpath.in"
// real side(pair a, pair b, pair c);
void gen_runpath40(stack *Stack)
{
  pair c=vm::pop<pair>(Stack);
  pair b=vm::pop<pair>(Stack);
  pair a=vm::pop<pair>(Stack);
#line 316 "runpath.in"
  {Stack->push<real>(orient2d(a,b,c)); return;}
}

// Determine the side of the counterclockwise circle through a,b,c that d
// lies on (negative=inside, 0=on circle, positive=right). 
#line 322 "runpath.in"
// real incircle(pair a, pair b, pair c, pair d);
void gen_runpath41(stack *Stack)
{
  pair d=vm::pop<pair>(Stack);
  pair c=vm::pop<pair>(Stack);
  pair b=vm::pop<pair>(Stack);
  pair a=vm::pop<pair>(Stack);
#line 323 "runpath.in"
  {Stack->push<real>(incircle(a.getx(),a.gety(),b.getx(),b.gety(),c.getx(),c.gety(),
                  d.getx(),d.gety())); return;}
}

} // namespace run

namespace trans {

void gen_runpath_venv(venv &ve)
{
#line 43 "runpath.in"
  REGISTER_BLTIN(run::nullPath,"nullPath");
#line 48 "runpath.in"
  addFunc(ve, run::gen_runpath1, primBoolean(), "==", formal(primPath(), "a", false, false), formal(primPath(), "b", false, false));
#line 53 "runpath.in"
  addFunc(ve, run::gen_runpath2, primBoolean(), "!=", formal(primPath(), "a", false, false), formal(primPath(), "b", false, false));
#line 58 "runpath.in"
  addFunc(ve, run::gen_runpath3, primPair(), "point", formal(primPath(), "p", false, false), formal(primInt(), "t", false, false));
#line 63 "runpath.in"
  addFunc(ve, run::gen_runpath4, primPair(), "point", formal(primPath(), "p", false, false), formal(primReal(), "t", false, false));
#line 68 "runpath.in"
  addFunc(ve, run::gen_runpath5, primPair(), "precontrol", formal(primPath(), "p", false, false), formal(primInt(), "t", false, false));
#line 73 "runpath.in"
  addFunc(ve, run::gen_runpath6, primPair(), "precontrol", formal(primPath(), "p", false, false), formal(primReal(), "t", false, false));
#line 78 "runpath.in"
  addFunc(ve, run::gen_runpath7, primPair(), "postcontrol", formal(primPath(), "p", false, false), formal(primInt(), "t", false, false));
#line 83 "runpath.in"
  addFunc(ve, run::gen_runpath8, primPair(), "postcontrol", formal(primPath(), "p", false, false), formal(primReal(), "t", false, false));
#line 88 "runpath.in"
  addFunc(ve, run::gen_runpath9, primPair(), "dir", formal(primPath(), "p", false, false), formal(primInt(), "t", false, false), formal(primInt(), "sign", true, false), formal(primBoolean(), "normalize", true, false));
#line 93 "runpath.in"
  addFunc(ve, run::gen_runpath10, primPair(), "dir", formal(primPath(), "p", false, false), formal(primReal(), "t", false, false), formal(primBoolean(), "normalize", true, false));
#line 98 "runpath.in"
  addFunc(ve, run::gen_runpath11, primPair(), "accel", formal(primPath(), "p", false, false), formal(primInt(), "t", false, false), formal(primInt(), "sign", true, false));
#line 103 "runpath.in"
  addFunc(ve, run::gen_runpath12, primPair(), "accel", formal(primPath(), "p", false, false), formal(primReal(), "t", false, false));
#line 108 "runpath.in"
  addFunc(ve, run::gen_runpath13, primReal(), "radius", formal(primPath(), "p", false, false), formal(primReal(), "t", false, false));
#line 120 "runpath.in"
  addFunc(ve, run::gen_runpath14, primPath(), "reverse", formal(primPath(), "p", false, false));
#line 125 "runpath.in"
  addFunc(ve, run::gen_runpath15, primPath(), "subpath", formal(primPath(), "p", false, false), formal(primInt(), "a", false, false), formal(primInt(), "b", false, false));
#line 130 "runpath.in"
  addFunc(ve, run::gen_runpath16, primPath(), "subpath", formal(primPath(), "p", false, false), formal(primReal(), "a", false, false), formal(primReal(), "b", false, false));
#line 135 "runpath.in"
  addFunc(ve, run::gen_runpath17, primPath(), "nurb", formal(primPair(), "z0", false, false), formal(primPair(), "z1", false, false), formal(primPair(), "z2", false, false), formal(primPair(), "z3", false, false), formal(primReal(), "w0", false, false), formal(primReal(), "w1", false, false), formal(primReal(), "w2", false, false), formal(primReal(), "w3", false, false), formal(primInt(), "m", false, false));
#line 141 "runpath.in"
  addFunc(ve, run::gen_runpath18, primInt(), "length", formal(primPath(), "p", false, false));
#line 146 "runpath.in"
  addFunc(ve, run::gen_runpath19, primBoolean(), "cyclic", formal(primPath(), "p", false, false));
#line 151 "runpath.in"
  addFunc(ve, run::gen_runpath20, primBoolean(), "straight", formal(primPath(), "p", false, false), formal(primInt(), "t", false, false));
#line 156 "runpath.in"
  addFunc(ve, run::gen_runpath21, primPath(), "unstraighten", formal(primPath(), "p", false, false));
#line 161 "runpath.in"
  addFunc(ve, run::gen_runpath22, primBoolean(), "piecewisestraight", formal(primPath(), "p", false, false));
#line 166 "runpath.in"
  addFunc(ve, run::gen_runpath23, primReal(), "arclength", formal(primPath(), "p", false, false));
#line 171 "runpath.in"
  addFunc(ve, run::gen_runpath24, primReal(), "arctime", formal(primPath(), "p", false, false), formal(primReal(), "dval", false, false));
#line 176 "runpath.in"
  addFunc(ve, run::gen_runpath25, primReal(), "dirtime", formal(primPath(), "p", false, false), formal(primPair(), "z", false, false));
#line 181 "runpath.in"
  addFunc(ve, run::gen_runpath26, realArray(), "intersect", formal(primPath(), "p", false, false), formal(primPath(), "q", false, false), formal(primReal(), "fuzz", true, false));
#line 198 "runpath.in"
  addFunc(ve, run::gen_runpath27, realArray2(), "intersections", formal(primPath(), "p", false, false), formal(primPath(), "q", false, false), formal(primReal(), "fuzz", true, false));
#line 229 "runpath.in"
  addFunc(ve, run::gen_runpath28, realArray(), "intersections", formal(primPath(), "p", false, false), formal(primPair(), "a", false, true), formal(primPair(), "b", false, true), formal(primReal(), "fuzz", true, false));
#line 244 "runpath.in"
  addFunc(ve, run::gen_runpath29, primPair(), "extension", formal(primPair(), "p", false, false), formal(primPair(), "q", false, false), formal(primPair(), "p", false, false), formal(primPair(), "q", false, false));
#line 255 "runpath.in"
  addFunc(ve, run::gen_runpath30, primInt(), "size", formal(primPath(), "p", false, false));
#line 260 "runpath.in"
  addFunc(ve, run::gen_runpath31, primPath(), "&", formal(primPath(), "p", false, false), formal(primPath(), "q", false, false));
#line 265 "runpath.in"
  addFunc(ve, run::gen_runpath32, primPair(), "min", formal(primPath(), "p", false, false));
#line 270 "runpath.in"
  addFunc(ve, run::gen_runpath33, primPair(), "max", formal(primPath(), "p", false, false));
#line 275 "runpath.in"
  addFunc(ve, run::gen_runpath34, realArray(), "mintimes", formal(primPath(), "p", false, false));
#line 284 "runpath.in"
  addFunc(ve, run::gen_runpath35, realArray(), "maxtimes", formal(primPath(), "p", false, false));
#line 293 "runpath.in"
  addFunc(ve, run::gen_runpath36, primReal(), "relativedistance", formal(primReal(), "theta", false, false), formal(primReal(), "phi", false, false), formal(primReal(), "t", false, false), formal(primBoolean(), "atleast", false, false));
#line 298 "runpath.in"
  addFunc(ve, run::gen_runpath37, primInt(), "windingnumber", formal(pathArray()  , "p", false, false), formal(primPair(), "z", false, false));
#line 303 "runpath.in"
  addFunc(ve, run::gen_runpath38, primBoolean(), "inside", formal(pathArray()  , "g", false, true), formal(primPair(), "z", false, false), formal(primPen(), "fillrule", true, false));
#line 308 "runpath.in"
  addFunc(ve, run::gen_runpath39, primBoolean(), "inside", formal(primPath(), "g", false, false), formal(primPair(), "z", false, false), formal(primPen(), "fillrule", true, false));
#line 313 "runpath.in"
  addFunc(ve, run::gen_runpath40, primReal(), "side", formal(primPair(), "a", false, false), formal(primPair(), "b", false, false), formal(primPair(), "c", false, false));
#line 320 "runpath.in"
  addFunc(ve, run::gen_runpath41, primReal(), "incircle", formal(primPair(), "a", false, false), formal(primPair(), "b", false, false), formal(primPair(), "c", false, false), formal(primPair(), "d", false, false));
}

} // namespace trans
