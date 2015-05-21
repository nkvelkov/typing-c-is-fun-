#ifndef MANNEQUIN_H_INCLUDED
#define MANNEQUIN_H_INCLUDED

#include "okglib.h"
#include <math.h>
#include <GL/glfw.h>

#define nL 21	// брой точки в крайниците
#define nH 50	// четен брой точки в главата
#define nJ 16	// четен брой точки в ставите

#define PI 3.141592653589793
#define EPS 0.1

#define turnForward(a)	glRotatef((a),1,0,0)
#define turnSideway(a)	glRotatef((a),0,1,0)
#define turnAround(a)	glRotatef((a),0,0,1)


// векторно произведение на вектори
OKG_POINT vmul(OKG_POINT a, OKG_POINT b, OKG_POINT p);

// пресмята декартови координати от сферични
OKG_POINT spherical( float alpha, float beta, float r );

// пресмята точка по крайник - линейна комбинация между ротационна синусоида и полусфера
OKG_POINT limbal( float alpha, float beta, float from, float to, float width, float sx1, float sx2, float sy1, float sy2, float sz );

// изчислява издутина в диапазона от min до max
double cosser( double t, double min, double max );

// прилага n издутини, всяка със свои параметри: сила, диапазон по a, диапазон по b
double smartRad( double a, double b, int n, float rads[][5] );

// дефинира връх и нормален вектор на точка от крайник
void vertex(float alpha,float beta,float from,float span,float width, float sx1, float sx2, float sy1, float sy2, float sz );
// дефинира връх и нормален вектор на точка от става
void hertex(float alpha,float beta, int m, float rads[][5], float r=1 );

// рисува крайник
void drawLimb( float from, float span, float width, float sx1, float sy1, float sx2, float sy2, float sz, bool useColor=true );

// рисува става
void drawJoint( float r );

// рисува оцветена с ленти глава
void drawHead( int n, float rads[][5] );

// рисува крак в дадена поза
void drawLeg(float angle[]);

// рисува ръка в дадена поза
void drawHand(float angle[]);

// рисува тяло в дадена поза
void drawBody(float pos[], float ori[], float scale[], float waist[], float head[], float leftHand[], float rightHand[], float leftLeg[], float rightLeg[]);

#endif // MANNEQUIN_H_INCLUDED
