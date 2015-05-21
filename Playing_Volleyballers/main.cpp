/// The following content is distributed under the General Purpose License (GPL).
/// Лицензът на проекта да е GPL.

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <time.h>
#include <GL/glfw.h>
#include "Mannequin.h"
#include "okglib.h"
using namespace std;

float multiplier, multiplier1;
float t = 0, X, Z;
float a, a1;
float b, b1;
bool withTextures = false;
bool dragging = false;

int xpos = 0;
int ypos = 0;
static int counter = 0, called = 0;
enum Mode{UPPASS, UPDOWNPASS, ATTACK, DOWNPASS};
Mode mode = UPPASS;
// използвам код от Mannequin в тази функция.
void drawLeftVolleyballer()
{
    {
            // второ тяло
            float position[]={10,0,0};
            float orientation[]={90,0};
            float scale[]={1,1,1,1};
            float waist[]={-10,0};
            float alpha = acos((100-10*X)/(10*sqrt((X-10)*(X-10)+(Z-7)*(Z-7)) ));
            float head[]={0,-40+2*alpha*multiplier,0};
                                //ramene lakti                  kitka
            float leftHand[]={-147,8,115, -80,-30,25, 140};
            float rightHand[]={147,8,70, 80,30,25,-140};
                        // bedra front left glezeni
            float leftLeg[]={0,-5,-7,0,60};
			float rightLeg[]={0,+5,-7,0,60};

            if(sin(100*t) > 0.0)
            {
                position[2]=-0.2*multiplier;
                waist[0]=-10-5*multiplier;

                leftHand[0]=-147+5*multiplier;// рамо
                leftHand[3]=-80-15*multiplier;// лакти
                leftHand[5]=25+40*multiplier1; // kitka
                leftHand[6]=-30-25*multiplier; // kitka
                leftLeg[0]=25*fabs(multiplier1);
                leftLeg[2]=-7-41*multiplier1;
                leftLeg[3]=-2.5*multiplier1;

                rightHand[0]=147-5*multiplier;// рамо
                rightHand[3]=80+15*multiplier;//лакти
                rightHand[5]=25+40*multiplier1;//kitka
                rightHand[6]=30+25*multiplier;//kitka
                rightLeg[0]=25*fabs(multiplier1);
                rightLeg[2]=-7-41*multiplier1;
                rightLeg[3]=-2.5*multiplier1;
			}

            drawBody (position,orientation,scale,waist,head,leftHand,rightHand,leftLeg,rightLeg);
        }
}
// използвам код от Mannequin в тази функция.
void drawRightVolleyballer()
{
        {
            // първо тяло
			float position[]={-10,0,0}; // -6*sinf(10*sinf(angle*PI/180)*PI/180)
			float orientation[]={-90,0};
			float scale[]={1,1,1,1};
			float waist[]={-10,0};
            float alpha = acos((100-10*X)/(10*sqrt((X-10)*(X-10)+(Z-7)*(Z-7)) ));
			float head[]={0,-40+2*alpha*multiplier,0};
                            //ramene lakti      kitka
            float leftHand[]={-147,8,115, -80,-30,25, 140};
            float rightHand[]={147,8,70, 80,30,25,-140};
                        // bedra front left glezeni
            float leftLeg[]={0,-5,-7,0,60};
			float rightLeg[]={0,+5,-7,0,60};

            if(sin(100*t) < 0.0)
            {
                position[2]=-0.2*multiplier;
                waist[0]=-10-5*multiplier;

                leftHand[0]=-147+5*multiplier;// рамо
                leftHand[3]=-80-15*multiplier;//лакти
                leftHand[5]=25-40*multiplier1; // kitka
                leftHand[6]=-30-25*multiplier; // kitka
                leftLeg[0]=25*fabs(multiplier1);
                leftLeg[2]=-7+41*multiplier1;
                leftLeg[3]=2.5*multiplier1;

                rightHand[0]=147-5*multiplier;// рамо
                rightHand[3]=80+15*multiplier;//лакти
                rightHand[5]=25-40*multiplier1;//kitka
                rightHand[6]=30+25*multiplier;//kitka
                rightLeg[0]=25*fabs(multiplier1);
                rightLeg[2]=-7+41*multiplier1;
                rightLeg[3]=2.5*multiplier1;
			}
            drawBody (position,orientation,scale,waist,head,leftHand,rightHand,leftLeg,rightLeg);
        }
}
// използвам код от Mannequin в тази функция.
void drawLowPassLeftVolleyballer2()
{
        {
            // щесто тяло
            float position[]={13,0,0};
            float orientation[]={90,0};
            float scale[]={1,1,1,1};
            float waist[]={-22,0};
            float head[]={0,-40,0};
                                //ramene lakti          kitka
            float leftHand[]={-163,116,15, -15,0,0,140};
            float rightHand[]={163,116,15, -15,0,0,-140};

                        // bedra front left glezeni
            float leftLeg[]={0,-5,-7,0,60};
			float rightLeg[]={0,+5,-7,0,60};

           if(sin(100*t) > 0.0)
            {
                position[2]=+0.5*multiplier1;
                waist[0]=-22-13*multiplier;

                leftHand[0]=-163+1*multiplier;// рамо

                leftHand[1]=116+35*multiplier1;// рамо
                leftHand[3]=-15-12*multiplier;// лакти
                leftHand[4]=20*multiplier;  //лакти
                leftHand[5]=15*multiplier1; // kitka
                leftHand[6]=140+43*multiplier; // kitka
                leftLeg[0]=25*fabs(multiplier1);
                leftLeg[2]=-7-41*multiplier1; // 23 - 61*
                leftLeg[3]=-20*multiplier1;

                rightHand[0]=163-1*multiplier;// рамо

                rightHand[1]=116+35*multiplier1;// рамо
                rightHand[3]=-15-12*multiplier;//лакти
                rightHand[4]=20*multiplier;//лакти
                rightHand[5]=-15*multiplier1;//kitka
                rightHand[6]=-140-43*multiplier;//kitka
                rightLeg[0]=25*fabs(multiplier1);
                rightLeg[2]=-7-41*multiplier1;
                rightLeg[3]=-20*multiplier1;
			}
            drawBody (position,orientation,scale,waist,head,leftHand,rightHand,leftLeg,rightLeg);
        }
}
// използвам код от Mannequin в тази функция.
void drawLowPassLeftVolleyballer()
{
        {
            // трето тяло
            float position[]={13,0,0};
            float orientation[]={90,0};
            float scale[]={1,1,1,1};
            float waist[]={-22,0};
            float head[]={0,-40,0};
                                //ramene lakti          kitka
            float leftHand[]={-159,116,15, -15,0,0,140};
            float rightHand[]={159,116,15, -15,0,0,-140};

                        // bedra front left glezeni
            float leftLeg[]={0,-5,-7,0,60};
			float rightLeg[]={0,+5,-7,0,60};

           if(sin(100*t) > 0.0)
            {
                position[2]=+0.5*multiplier1;
                waist[0]=-22-13*multiplier;

                leftHand[0]=-159+1*multiplier;

                leftHand[1]=116+23*multiplier1;
                leftHand[3]=-15-15*multiplier;
                leftHand[4]=20*multiplier;
                leftHand[5]=15*multiplier1; // kitka
                leftHand[6]=140+43*multiplier; // kitka
                leftLeg[0]=25*fabs(multiplier1);
                leftLeg[2]=-7-41*multiplier1;
                leftLeg[3]=-20*multiplier1;

                rightHand[0]=159-1*multiplier;

                rightHand[1]=116+23*multiplier1;
                rightHand[3]=-15-15*multiplier;
                rightHand[4]=20*multiplier;
                rightHand[5]=-15*multiplier1;//kitka
                rightHand[6]=-140-43*multiplier;//kitka
                rightLeg[0]=25*fabs(multiplier1);
                rightLeg[2]=-7-41*multiplier1;
                rightLeg[3]=-20*multiplier1;
			}
            drawBody (position,orientation,scale,waist,head,leftHand,rightHand,leftLeg,rightLeg);
        }
}
// използвам код от Mannequin в тази функция.
void drawLowPassRightVolleyballer()
{
        {
            // пето тяло
            float position[]={-13,0,0};
            float orientation[]={-90,0};
            float scale[]={1,1,1,1};
            float waist[]={-22,0};
            float head[]={0,-40,0};
                                //ramene lakti          kitka
            float leftHand[]={-159,116,15, -15,0,0,140};
            float rightHand[]={159,116,15, -15,0,0,-140};

                        // bedra front left glezeni
            float leftLeg[]={0,-5,-7,0,60};
			float rightLeg[]={0,+5,-7,0,60};

           if(sin(100*t) < 0.0)
            {
                position[2]=+0.5*multiplier1;
                waist[0]=-22-13*multiplier;

                leftHand[0]=-159+1*multiplier;

                leftHand[1]=116-15*multiplier1;
                leftHand[3]=-15+15*multiplier;
                leftHand[4]=-20*multiplier;
                leftHand[5]=-2*multiplier1; // kitka
                leftHand[6]=140-27*multiplier; // kitka
                leftLeg[0]=25*fabs(multiplier1);
                leftLeg[2]=-7+43*multiplier1; // calves
                leftLeg[3]=-20*multiplier1;

                rightHand[0]=159-1*multiplier;

                rightHand[1]=116-15*multiplier1;
                rightHand[3]=-15+15*multiplier;
                rightHand[4]=-20*multiplier;
                rightHand[5]=2*multiplier1;//kitka
                rightHand[6]=-140+27*multiplier;//kitka
                rightLeg[0]=25*fabs(multiplier1);
                rightLeg[2]=-7+43*multiplier1; // calves
                rightLeg[3]=-20*multiplier1;
			}
            drawBody (position,orientation,scale,waist,head,leftHand,rightHand,leftLeg,rightLeg);
        }
}
// използвам код от Mannequin в тази функция.
void drawAttacker()
{
        {
            // четвърто тяло
			float position[]={-13,1,0}; // -6*sinf(10*sinf(angle*PI/180)*PI/180)
			float orientation[]={-90,0};
			float scale[]={1,1,1,1};
			float waist[]={1,0};
			float head[]={0,-40,0};
                            //ramene    lakti      kitka
            float leftHand[]={170,150, 10, -15,-10, 5, 140};
            float rightHand[]={177,8,160, 30,0,-10,-140};

                        // bedra front left glezeni
            float leftLeg[]={0,-5,-8, 0,60};
			float rightLeg[]={0,+5,-2,0,60};

            if(sin(100*t) < 0.0)
            {
                position[2]=0.1*multiplier;
                waist[0]=1+13*multiplier;

                leftHand[0]=170-3*multiplier;
                leftHand[1]=150-25*multiplier;
                leftHand[2]=10+5*multiplier;
                leftHand[3]=-15-15*multiplier;
                leftHand[4]=-10-20*multiplier;
                leftHand[5]=5-10*multiplier1; // kitka // kitka
                leftLeg[0]=25*fabs(multiplier1);
                leftLeg[2]=-8+41*multiplier1;
                leftLeg[3]=-18*fabs(multiplier);//*cos(100*t);

                rightHand[0]=177-5*multiplier;
                rightHand[1]=8-42*multiplier;
                rightHand[3]=30+35*multiplier;
                rightHand[4]=+30*multiplier;

                rightLeg[0]=8*fabs(multiplier1);
                rightLeg[2]=-2+21*multiplier1;
                rightLeg[3]=-5*multiplier1;
			}
            drawBody (position,orientation,scale,waist,head,leftHand,rightHand,leftLeg,rightLeg);
        }
}// рисуване на игрището
void drawPlayGround()
{
        glColor3f(1,100/255,100/255);
        glBegin( GL_POLYGON ); // red rect
            glNormal3f(0,0,1);
            glVertex3f(-0.3,-7,-6.5);
            glVertex3f(-0.3,7,-6.5);
            glVertex3f(-14,7,-6.5);
            glVertex3f(-14,-7,-6.5);
        glEnd();
        glBegin( GL_POLYGON ); // red rect
            glNormal3f(0,0,1);
            glVertex3f(0.3,-7,-6.5);
            glVertex3f(0.3,7,-6.5);
            glVertex3f(14,7,-6.5);
            glVertex3f(14,-7,-6.5);
        glEnd();
        glColor3f(0,0.9f,1.0f);
        glBegin( GL_POLYGON ); // blue rect
            glNormal3f(0,0,1);
            glVertex3f(20,-20,-6.59);
            glVertex3f(20,20,-6.59);
            glVertex3f(-20,20,-6.59);
            glVertex3f(-20,-20,-6.59);
        glEnd();
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin( GL_POLYGON ); // white rect
            glNormal3f(0,0,1);
            glVertex3f(0.3,-7,-6.49);
            glVertex3f(0.3,7,-6.49);
            glVertex3f(-0.3,7,-6.49);
            glVertex3f(-0.3,-7,-6.49);
        glEnd();

}//рисуване на земята извън игрището
void drawOutSide()
{
    glColor3f(0.5f,0.9f,0.6f);
    glBegin( GL_POLYGON );
        glNormal3f(0,0,1);
        glVertex3f(20,100,-6.59);
        glVertex3f(20,-100,-6.59);
        glVertex3f(200,-100,-6.59);
        glVertex3f(200,100,-6.59);
    glEnd();
    glBegin( GL_POLYGON );
        glNormal3f(0,0,1);
        glVertex3f(-20,100,-6.59);
        glVertex3f(-20,-100,-6.59);
        glVertex3f(-200,-100,-6.59);
        glVertex3f(-200,100,-6.59);
    glEnd();
    glBegin( GL_POLYGON );
        glNormal3f(0,0,1);
        glVertex3f(-20,20,-6.59);
        glVertex3f(20,20,-6.59);
        glVertex3f(20,100,-6.59);
        glVertex3f(-20,100,-6.59);
    glEnd();
    glBegin( GL_POLYGON );
        glNormal3f(0,0,1);
        glVertex3f(20,-20,-6.59);
        glVertex3f(-20,-20,-6.59);
        glVertex3f(-20,-100,-6.59);
        glVertex3f(20,-100,-6.59);
    glEnd();
}//русиване на мрежата
void drawNet()
{
        glColor3f(0.87f, 0.87f, 0.87f);
        drawSmoothCylinder(0, -7.3, -6.5, 0.3, 15);// викам функция от okglib.h
        drawSmoothCylinder(0, 7.3, -6.5, 0.3, 15);// викам функция от okglib.h
        glColor3f(1.0f, 1.0f, 1.0f);
        for(int i = 0; i < 26; ++i)
        {
            glPushMatrix();
                glScalef(0.05, 0.05, 5.5);
                glTranslatef(0,-125+10*i, 0.45);
                drawUnitCylinder();// викам функция от okglib.h
            glPopMatrix();
        }
        for(int i = 0; i < 24; ++i)
        {
           if(i == 0)
            {
                glColor3f(0.48, 1.0f, 0.86);
                glPushMatrix();
                    glRotatef(-90, 0, 1, 0);
                    glScalef(3.8, 1, 1);
                    glTranslatef(2.1, -7, -5.5);
                    glRotatef(-90, 1, 0, 0);
                    glScalef(0.05, 0.05, 14);
                    glTranslatef(0,-110+5*i, 0);
                    drawUnitCylinder();// викам функция от okglib.h
                glPopMatrix();
                glColor3f(1.0f,1.0f, 1.0f);
            }else
            {
                glPushMatrix();
                    glTranslatef(0, -7, 2.7);
                    glRotatef(-90, 1, 0, 0);
                    glScalef(0.05, 0.05, 14);
                    glTranslatef(0,-110+5*i, 0);
                    drawUnitCylinder(); // викам функция от okglib.h
                glPopMatrix();
            }
        }
}
// добавяне на мъгла. Показано на упражнения.
void addFog()
{
    glEnable( GL_FOG );
    glFogi (GL_FOG_MODE, GL_EXP );
    glFogf (GL_FOG_DENSITY, 0.0021);
    glFogf( GL_FOG_START, 18);
    glFogf( GL_FOG_END, 100);
}
// Взето от упражненията. Извиква се при натискане или отпускане на миши бутон.
void GLFWCALL onMouseButton( int button, int action )
{
    if( button==GLFW_MOUSE_BUTTON_LEFT )
    {
        called++;
        dragging = action==GLFW_PRESS;
        if(GLFW_PRESS)
        {
            glfwGetMousePos( &xpos, &ypos );
            if(fabs(xpos-a)<=20 && fabs(ypos-b)<=20 && called%2==1 )
            {
                counter++;
                mode = Mode(counter%4);
            }
        }
    }
}
// Взето от упражнения
void GLFWCALL onMouseMove( int x, int y )
{
    if( dragging )
    {
        a1 = a1-(x-xpos)/150.0;
        b1 = b1+(y-ypos)/150.0;
        if( b1>+1.5 ) b1=+1.5;
        if( b1<-1.5 ) b1=-1.5;
        xpos = x;
        ypos = y;
    }
}
//Взето от примера, качен в мудъл.
void drawTexturedCube(float a)
{
    glBegin( GL_QUADS );
        glNormal3f(-a, -a, -a);
        glTexCoord2f(0, 0); // указва коя част от текстурата ще се намира в текущо дефинирания връх ...
        glVertex3f(-a, -a, -a);
        glNormal3f(-a, -a, +a);
        glTexCoord2f(0, 2); // ... текстурата е квадратче от (0,0) до (1,1), а в този пример я налагам върху ...
        glVertex3f(-a, -a, +a);
        glNormal3f(-a, +a, +a);
        glTexCoord2f(2, 2); // ... стената като казвам, че единият връх на стената съответства на точка от ...
        glVertex3f(-a, +a, +a);
        glNormal3f(-a, +a, -a);
        glTexCoord2f(2, 0); // ... тектурата (0,0), а другият -- на точка (2,2) ... т.е. текстурата ще е двойна
        glVertex3f(-a, +a, -a);

        glNormal3f(+a, -a, -a);
        glTexCoord2f(0, 0);
        glVertex3f(+a, -a, -a);
        glNormal3f(+a, -a, +a);
        glTexCoord2f(0, 2);
        glVertex3f(+a, -a, +a);
        glNormal3f(+a, +a, +a);
        glTexCoord2f(2, 2);
        glVertex3f(+a, +a, +a);
        glNormal3f(+a, +a, -a);
        glTexCoord2f(2, 0);
        glVertex3f(+a, +a, -a);

        glNormal3f(-a, -a, -a);
        glTexCoord2f(0, 0);
        glVertex3f(-a, -a, -a);
        glNormal3f(-a, -a, +a);
        glTexCoord2f(0, 2);
        glVertex3f(-a, -a, +a);
        glNormal3f(+a, -a, +a);
        glTexCoord2f(2, 2);
        glVertex3f(+a, -a, +a);
        glNormal3f(+a, -a, -a);
        glTexCoord2f(2, 0);
        glVertex3f(+a, -a, -a);

        glNormal3f(-a, +a, -a);
        glTexCoord2f(0, 0);
        glVertex3f(-a, +a, -a);
        glNormal3f(-a, +a, +a);
        glTexCoord2f(0, 2);
        glVertex3f(-a, +a, +a);
        glNormal3f(+a, +a, +a);
        glTexCoord2f(2, 2);
        glVertex3f(+a, +a, +a);
        glNormal3f(+a, +a, -a);
        glTexCoord2f(2, 0);
        glVertex3f(+a, +a, -a);

        glNormal3f(-a, -a, +a);
        glTexCoord2f(0, 0);
        glVertex3f(-a, -a, +a);
        glNormal3f(-a, +a, +a);
        glTexCoord2f(0, 2);
        glVertex3f(-a, +a, +a);
        glNormal3f(+a, +a, +a);
        glTexCoord2f(2, 2);
        glVertex3f(+a, +a, +a);
        glNormal3f(+a, -a, +a);
        glTexCoord2f(2, 0);
        glVertex3f(+a, -a, +a);

        glNormal3f(-a, -a, -a);
        glTexCoord2f(0, 0);
        glVertex3f(-a, -a, -a);
        glNormal3f(-a, +a, -a);
        glTexCoord2f(0, 2);
        glVertex3f(-a, +a, -a);
        glNormal3f(+a, +a, -a);
        glTexCoord2f(2, 2);
        glVertex3f(+a, +a, -a);
        glNormal3f(+a, -a, -a);
        glTexCoord2f(2, 0);
        glVertex3f(+a, -a, -a);
    glEnd();
}//рисуване на краката на пейката.
void drawBenchLegs(int a, int b, int c)
{
    glColor3f(0.74f,0.56f,0.56f);
    drawSmoothCylinder(a, b, c, 0.5, 7);// викам функция от okglib.h
    drawSmoothCylinder(a-9, b, c, 0.5, 7);// викам функция от okglib.h
}//рисуване на тялото на пейката
void drawBenchBoard(int a)
{
    glColor3f(0.55f,0.27f,0.07f);
    glPushMatrix();
        glTranslatef(a-4.5, -12, -2.0);
        glScalef(6.5, 1.5, 0.5);
        drawTexturedCube(1);//drawTexturedCube(0, -1, 1, 1);
                            // викам горната функция за текстура на куб
    glPopMatrix();
}
// рисуване на пейка
void drawBench(int a, int b, int c)
{
    //drawBenchBoard(a);
   // drawBenchLegs(a, b, c);
    glColor3f(0.74f,0.56f,0.56f);
    drawSmoothCylinder(a, b, c, 0.5, 7);
    drawSmoothCylinder(a-9, b, c, 0.5, 7);
    glColor3f(0.55f,0.27f,0.07f);

    glPushMatrix();
        glTranslatef(a-4.5, -10.5, -2.6);
        glScalef(11.5, 1.5, 0.5);
        drawSolidCube(0, -1, 1, 1);//drawTexturedCube(0, -1, 1, 1);
                            // викам функция от okglib.h
    glPopMatrix();
}//рисуване на предна стена без текстура
void drawWall2()
{
    glColor3f(0.47f, 0.47f, 0.47f);
    glPushMatrix();
        glTranslatef(20, -12, 0);
        glScalef(1, 16, 32);
        drawSolidCube(0, 0, 0, 1);// викам функция от okglib.h
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, 12, 0);
        glScalef(1, 16, 32);
        drawSolidCube(0, 0, 0, 1);// викам функция от okglib.h
    glPopMatrix();
    glColor3f(0.47f, 0.47f, 0.47f);
    glPushMatrix();
        glTranslatef(20, 0, 12.5);
        glScalef(1, 8, 7);
        drawSolidCube(0, 0, 0, 1);// викам функция от okglib.h
    glPopMatrix();
}//рисуване на предна стена с текстура
void drawWall2Textured()
{
    glColor3f(0.47f, 0.47f, 0.47f);
    glPushMatrix();
        glTranslatef(20, -13, 0);
        glScalef(0.5, 7, 16);
        drawTexturedCube(1);//stranichna strana // викам горната функция за текстура на куб
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, 13, 0);
        glScalef(0.5, 7, 16);
        drawTexturedCube(1);//stranichna strana // викам горната функция за текстура на куб
    glPopMatrix();
    glColor3f(0.47f, 0.47f, 0.47f);
    glPushMatrix();
        glTranslatef(20, 0, 12);//gorna strana
        glScalef(0.5, 6, 4);
        drawTexturedCube(1);// викам горната функция за текстура на куб
    glPopMatrix();
}//рисуване на лява стена с текстура
void drawWall1Textured()
{
    glColor3f(0.47f, 0.47f, 0.47f);
    glPushMatrix();
        glTranslatef(-20, 0, 0);
        glScalef(0.5, 20, 16);
        drawTexturedCube(1);// викам горната функция за текстура на куб
    glPopMatrix();
}//рисуване на задна стена с текстура
void drawWall3Textured()
{
    glColor3f(0.47f, 0.47f, 0.47f);
    glPushMatrix();
        glTranslatef(0, -20, 0);
        glScalef(20.5, 0.5, 16);
        drawTexturedCube(1);// викам горната функция за текстура на куб
    glPopMatrix();
}//рисуване на лява стена без текстура
void drawWall1()
{
    glColor3f(0.47f, 0.47f, 0.47f);
    glPushMatrix();
        glTranslatef(-20, 0, 0);
        glScalef(1, 40, 32);
        drawSolidCube(0, 0, 0, 1);// викам функция от okglib.h
    glPopMatrix();
}//рисуване на задна стена без текстура
void drawWall3()
{
    glColor3f(0.47f, 0.47f, 0.47f);
    glPushMatrix();
        glTranslatef(0, -20, 0);
        glScalef(41, 1, 32);
        drawSolidCube(0, 0, 0, 1);// викам функция от okglib.h
    glPopMatrix();
}// допълнителна стена
void drawWall4()
{
    glPushMatrix();
        glTranslatef(0, 20, 0);
        glScalef(41, 1, 32);
        drawSolidCube(0, 0, 0, 1);// викам функция от okglib.h
    glPopMatrix();
}//рисуване на врата без текстура
void drawDoor()
{
    glColor3f(0.55f,0.27f,0.07f);
    glPushMatrix();
        glTranslatef(24, 4, 1);
        glScalef(8, 0.4, 16);
        drawSolidCube(0, 0, 0, 1);// викам функция от okglib.h
    glPopMatrix();
}//рисуване на врата с текстура
void drawDoorTextured()
{
    glColor3f(0.55f,0.27f,0.07f);
    glPushMatrix();
        glTranslatef(24, 6, 0.5);
        glScalef(4, 0.25, 7.5);
        drawTexturedCube(1);// викам горната функция за текстура на куб
    glPopMatrix();
}//рисуване на щанга
void drawDumbbell()
{
    glColor3f(0.4f, 0.4f, 0.4f);
    glPushMatrix();
        glTranslatef(5, 15, -5.2);//rod
        glScalef(8, 0.2, 0.2);
        glRotatef(90, 0, 1, 0);
        drawUnitCylinder();// викам функция от okglib.h
    glPopMatrix();
    glColor3f(0.7f, 0.7f, 0.7f);
    glPushMatrix();
        glTranslatef(6, 15, -5.2); // big right
        glScalef(0.5, 1.3, 1.3);
        glRotatef(90, 0, 1, 0);
        drawUnitCylinder();// викам функция от okglib.h
    glPopMatrix();
       glPushMatrix();
        glTranslatef(11.5, 15, -5.2);// big left
        glScalef(0.5, 1.3, 1.3);
        glRotatef(90, 0, 1, 0);
        drawUnitCylinder();// викам функция от okglib.h
    glPopMatrix();
    glPushMatrix();
        glTranslatef(5.5, 15, -5.2); // small right
        glScalef(0.5, 0.9, 0.9);
        glRotatef(90, 0, 1, 0);
        drawUnitCylinder();// викам функция от okglib.h
    glPopMatrix();
    glPushMatrix();
        glTranslatef(12, 15, -5.2);//small left
        glScalef(0.5, 0.9, 0.9);
        glRotatef(90, 0, 1, 0);
        drawUnitCylinder();// викам функция от okglib.h
    glPopMatrix();
}//рисуване на стена за катерене
void drawClimbWall()
{
    for(int i = 0; i < 18; ++i) // generate strips
    {
    glPushMatrix();
        glTranslatef(-1, 1, 1+i);
        glTranslatef(-3, 12, 1);
        glRotatef(90, 0, 0, 1);
        glTranslatef(5, 15, -5.2);
        glScalef(8, 0.2, 0.2);
        glRotatef(-90, 0, 1, 0);
        drawUnitCylinder();// викам функция от okglib.h
    glPopMatrix();
    }
    glPushMatrix();
        glTranslatef(-19, 10, -6.5);
        glScalef(0.2, 0.2, 21);
        drawUnitCylinder();// викам функция от okglib.h
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-19, 18, -6.5);
        glScalef(0.2, 0.2, 21);
        drawUnitCylinder();// викам функция от okglib.h
    glPopMatrix();
}//рисуване на правоъгълник за заглавието
void drawStraightRect(float a)
{
    glPushMatrix();
        glScalef(0.4, 0.2, a);
        drawSolidCube(1,1,1,1);// викам функция от okglib.h
    glPopMatrix();
}//рисуване на правоъгълник за заглавието
void drawFloatRect(float a)
{
    glPushMatrix();
        glRotatef(90,1,0,0);
        drawStraightRect(a);
    glPopMatrix();
}//рисуване на заглавието
void drawHeading()
{
    glPushMatrix();
        glTranslatef(20, -6, 12);
        drawStraightRect(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20,-4.2,14.7);
        glRotatef(90,1,0,0);
        drawStraightRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20,-4.2,12.9);
        glRotatef(90,1,0,0);
        drawStraightRect(1);
    glPopMatrix();                  // draw S
    glPushMatrix();
        glTranslatef(20, -4.2, 12.4);
        drawStraightRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, -3.6, 12.4);
        drawStraightRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, -2.9, 13.7);
        glScalef(1, 0.8, 1);
        drawFloatRect(1);
    glPopMatrix();                  // draw p
    glPushMatrix();
        glTranslatef(20, -2.9, 12.4);
        drawStraightRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, -2.3, 12.4);
        drawStraightRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, -1.6, 13.7);
        glScalef(1, 0.8, 1);
        drawFloatRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, -1.6, 12.8);
        glScalef(1, 0.8, 1);
        drawFloatRect(1);
    glPopMatrix();                  // o
    glPushMatrix();
        glTranslatef(20, -1.6, 11);
        drawStraightRect(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, -1.0, 12.5);
        drawStraightRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, -0.3, 13.7);
        glScalef(1, 0.8, 1);
        drawFloatRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, -0.3, 12.8);
        glScalef(1, 0.8, 1);
        drawFloatRect(1);
    glPopMatrix();                  // r
    glPushMatrix();
        glTranslatef(20, 0.3, 12.5); // |
        drawStraightRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, 1, 13.7); // -
        glScalef(1, 0.8, 1);
    drawFloatRect(1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(20, 1.6, 13.7); // -
        glScalef(1, 0.8, 1);
    drawFloatRect(1);
    glPopMatrix();                 // t
        glPushMatrix();
        glTranslatef(20, 1.5, 12.5); // |
        drawStraightRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, 2.2, 12.5); // |
        drawStraightRect(1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(20, 2.8, 13.25); // -
        glScalef(1, 0.8, 1);
    drawFloatRect(1);
    glPopMatrix();                  //n
        glPushMatrix();
        glTranslatef(20, 3.0, 12.4); //|
        drawStraightRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, 3.6, 12.4);//|
        drawStraightRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, 4.3, 13.7);//-
        glScalef(1, 0.8, 1);
        drawFloatRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, 4.3, 12.8);//-
        glScalef(1, 0.8, 1);
        drawFloatRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, 4.5, 12);
        glRotatef(-45, 1, 0, 0); // a symb
        glScalef(1, 0.8, 1);
        drawFloatRect(1);
    glPopMatrix();                  // a
    glPushMatrix();
        glTranslatef(20, -3.2, 10.4);
        drawStraightRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, -2.6, 11.6);
        glScalef(1, 0.8, 1);
        drawFloatRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, -2.6, 10.7);
        glScalef(1, 0.8, 1);
        drawFloatRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, -3.2, 9.3);
        drawStraightRect(1.5);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, -2.6, 9.9);
        glScalef(1, 0.8, 1);
        drawFloatRect(1);
    glPopMatrix();          // z
    glPushMatrix();
        glTranslatef(20, -2.3, 9.5); //|
        drawStraightRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, -1.6, 9.5);//|
        drawStraightRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, -1.0, 10.8);//-
        glScalef(1, 0.8, 1);
        drawFloatRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, -1.0, 9.9);//-
        glScalef(1, 0.8, 1);
        drawFloatRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, -0.8, 9.2);
        glRotatef(-45, 1, 0, 0); // a symb
        glScalef(1, 0.8, 1);
        drawFloatRect(1);
    glPopMatrix();                  // a
    glPushMatrix();
        glTranslatef(20, 0.3, 11.5);
        glRotatef(65, 1, 0, 0); // a symb
        glScalef(1, 0.8, 1);
        drawFloatRect(1.5);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, 0.4, 9.35);
        glRotatef(-65, 1, 0, 0); // a symb
        glScalef(1, 0.8, 1);
        drawFloatRect(1.5);
    glPopMatrix();              // l
    glPushMatrix();
        glTranslatef(20, 0.9, 9.5); //|
        drawStraightRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, 1.6, 9.5);//|
        drawStraightRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, 2.3, 10.8);//-
        glScalef(1, 0.8, 1);
        drawFloatRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, 2.3, 9.9);//-
        glScalef(1, 0.8, 1);
        drawFloatRect(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(20, 2.4, 9.2);
        glRotatef(-45, 1, 0, 0); // a symb
        glScalef(1, 0.8, 1);
        drawFloatRect(1);
    glPopMatrix();           // a
}//рисуване на ракета за тенис на маса
void drawTableTennisRacket()
{
    glColor3f(1.0f, 0.2f, 0.2f);
    glPushMatrix();
        glTranslatef(8.0, -12, -1);
        glRotatef(-90, 0,1,0);
        glScalef(0.1, 0.7, 0.7);
        glRotatef(90, 0, 1, 0);
        drawUnitCylinder();// викам функция от okglib.h
    glPopMatrix();
    glColor3f(0.2f, 1.0f, 0.2f);
    glPushMatrix();
        glRotatef(90, 1, 0, 0);
        glScalef(4, 1, 1);
        drawSmoothCone(2, -0.89, 12.6, 0.1, 0.3);// викам функция от okglib.h
    glPopMatrix();
    glPushMatrix();
        glRotatef(90, 1, 0, 0);
        glScalef(4, 1, 1);
        drawSmoothCone(2, -1.0, 12.6, 0.1, 0.3);// викам функция от okglib.h
    glPopMatrix();
    glPushMatrix();
        glTranslatef(8.0, -13.3, -0.95);
        glRotatef(90, 0,0,1);
        glScalef(0.7, 0.1, 0.1);
        glRotatef(90, 0, 1, 0);
        drawUnitCylinder();// викам функция от okglib.h
    glPopMatrix();
}
void drawDancer()
{
   float mult = sin(60*t);
   float position[]={1-5,6,-3-0.2*mult*cos(160*t)};
   float orientation[]={52,0};
   float scale[]={0.9,0.9,0.9,1.1};
   float waist[]={1+15*mult,20*cosf(100*t)*mult};//10*cosf(60*t)};
   float head[]={20-5*mult,5*mult,10*cosf(100*t)*mult,};
   //float head[]={0,10,0};

   float leftHand[]={-30-10*mult,20+20*mult,30+15*mult,65+36*mult,30,0,-10};
   float rightHand[]={20+10*mult,20+20*mult,-60-15*mult,65-16*mult,10,-20,-50};
   float leftLeg[]={10,-5,-8,0,0};
   float rightLeg[]={-10,5,-2,0,0};
        leftLeg[0]=25*fabs(sin(60*t));
        leftLeg[2]=-8-41*fabs(sin(60*t));
        leftLeg[3]=-15*fabs(sin(120*t));//*cos(100*t);

        rightLeg[0]=25*fabs(sin(60*t));
        rightLeg[2]=-2-61*fabs(sin(60*t));
        rightLeg[3]=-15*sin(60*t);
   //float rightLeg[]={113.0f-0.5f*sinf(100*t+PI),-20,-95+2*sinf(100*t),-10.0f+10*sinf(100*t)};

   drawBody (position,orientation,scale,waist,head,leftHand,rightHand,leftLeg,rightLeg);
}
int main()
{
    init();

    glfwSetMouseButtonCallback( onMouseButton );
    glfwSetMousePosCallback( onMouseMove );

    glClearColor( 1,1,1,0 );
    glEnable( GL_DEPTH_TEST );
    glEnable( GL_LIGHTING );
    glEnable( GL_LIGHT0 );
    glEnable( GL_COLOR_MATERIAL );
    glEnable( GL_NORMALIZE );
	glShadeModel(GL_SMOOTH);

    glColor3f(1, 1, 1);
    float tennisRacketOffset;
    if(withTextures)
    {
        GLuint text2D, text2DWood, text2DWood2,text2DWall;
        glEnable(GL_TEXTURE_2D);

        glGenTextures(1,&text2DWood2);
        glBindTexture(GL_TEXTURE_2D,text2DWood2);
        glfwLoadTexture2D("wood.tga", GLFW_BUILD_MIPMAPS_BIT);

        glGenTextures(1,&text2DWall);
        glBindTexture(GL_TEXTURE_2D,text2DWall);
        glfwLoadTexture2D("wall.tga", GLFW_BUILD_MIPMAPS_BIT);

        glGenTextures(1,&text2DWood);
        glBindTexture(GL_TEXTURE_2D,text2DWood);
        glfwLoadTexture2D("Pattern.tga", GLFW_BUILD_MIPMAPS_BIT );

        glNewList(1, GL_COMPILE );

            glBindTexture(GL_TEXTURE_2D, text2DWood);
            drawBenchBoard(-4);
            drawBenchLegs(-4, -12.5, -9);

            drawBenchBoard(13);
            drawBenchLegs(13, -12.5, -9);
            glBindTexture(GL_TEXTURE_2D, text2DWood2);
            drawDoorTextured();
            glColor3f(0.43f, 0.47f, 0.48f);
            glBindTexture(GL_TEXTURE_2D, text2DWall);
            drawWall1Textured();
            drawWall2Textured();
            drawWall3Textured();
            glBindTexture(GL_TEXTURE_2D, text2D);
            glColor3f(1, 0.47f, 0.48f);
            drawSmoothSphere(-1.5, -12.5, -5.6, 1);
            tennisRacketOffset = -1.28;
        glEndList();
    }else
    {
        glNewList(1, GL_COMPILE );
            drawBench(-4,-12.5, -9);
            drawBench(13,-12.5, -9);
            drawWall1();
            drawWall2();
            drawWall3();
            drawDoor();
            glColor3f(1, 0.47f, 0.48f);
            drawSmoothSphere(-1.5, -12.5, -5.6, 1);// викам функция от okglib.h
            tennisRacketOffset = -1.63;
        glEndList();
    }
    glNewList(5, GL_COMPILE );
        drawPlayGround();
        drawOutSide();
        addFog();
     drawHeading();
        glPushMatrix();
            glRotatef(15, 0, 0, 1);
            drawDumbbell();
        glPopMatrix();
        glPushMatrix();
            glRotatef(-1, 0, 1, 0);
            drawClimbWall();
        glPopMatrix();

        glPushMatrix();
                glRotatef(-4, 1, 0, 0);
                glTranslatef(0,0.3,tennisRacketOffset);
                drawTableTennisRacket();
        glPopMatrix();
        glPushMatrix();
                glRotatef(90, 0,0,1);
                glRotatef(-4, 1, 0, 0);
                glTranslatef(-20,0.3,tennisRacketOffset);
                drawTableTennisRacket();
        glPopMatrix();
        glColor3f(1.0f, 1.0f, 0);
        drawSmoothSphere(10, -12, tennisRacketOffset, 0.2);// викам функция от okglib.h
        glColor3f(1.0f, 1.0f, 1.0f);
        drawSolidCube(0, 0, 0, 1);// викам функция от okglib.h
    glEndList();

    glNewList(6, GL_COMPILE );
        drawNet();
    glEndList();

    a = 318;
    b = 239; Mode mode1 = mode;
    a1 = 0, b1 = 0;

    while( running() )
    {
        glClear( GL_COLOR_BUFFER_BIT+GL_DEPTH_BUFFER_BIT );
        t=t+0.005;
        glLoadIdentity();
        gluLookAt( 30*cos(a1)*cos(b1),30*sin(a1)*cos(b1),30*sin(b1), 0,0,0, 0,0,1);

        float counterTime = 200*t, counterTime1 = 100*t;
        multiplier = sin(counterTime), multiplier1 = sin(counterTime1);
        float angle=30*sinf(25*t);
        float x=0, y=0, z=0;

        glColor3f(0,0,0);
        drawOxyz();
        glCallList(5);
        glCallList(1);

        glColor3f(0, 1, 0);

        switch(mode)
        {
            case ATTACK :
                        drawAttacker();
                        drawLowPassLeftVolleyballer2();
                        bool flag;
                        if(multiplier1 > 0.95)
                        {
                            flag = false;
                        }
                        if(multiplier1 > -0.95)
                        {
                            if(multiplier1 > 0.0 )
                            {
                                x = 10.4*multiplier1, z = 10.5-9.9*multiplier1*multiplier1;
                            }else
                            {
                                x = 10.40*multiplier1; z = 10.5-3.2*multiplier1*multiplier1;
                            }
                        }else
                        {
                            flag = true;
                        }
                        if(flag)
                        {
                             x = 10.29*sin(100*t-asin(0.01)), z = 6.5-3.2*multiplier1-2.1*multiplier1*multiplier1;//*multiplier1; // 7.6
                        }
                            break;
            case UPPASS :
                            glCallList(6);
                            drawRightVolleyballer();
                            drawLeftVolleyballer();
                            x = 8.1*multiplier1, z = 13.5-6.1*multiplier1*multiplier1;
                            break;
            case DOWNPASS :
                            glCallList(6);
                            drawLowPassLeftVolleyballer();
                            drawLowPassRightVolleyballer();
                            x = 9.9*multiplier1, z = 10.5-9.4*multiplier1*multiplier1;
                            break;
            case UPDOWNPASS :
                            glCallList(6);
                            drawLowPassLeftVolleyballer();
                            drawRightVolleyballer();

                            if(multiplier1 > 0.2 )
                            {
                                        //x = 10.4*multiplier1, z = 10.5-9.9*multiplier1*multiplier1;
                                x = 10.1*multiplier1, z = 13.5-12.1*multiplier1*multiplier1;
                            }else
                            {
                                x = 8.1*multiplier1, z = 13.5-6.1*multiplier1*multiplier1;
                                        //x = 10.40*multiplier1; z = 10.5-3.2*multiplier1*multiplier1;
                            }
                            break;
            default : cout << "Error something went wrong!";
        }

        glColor3f(0.87f, 0.23f, 1.0f);
        drawSmoothSphere(x, y, z, 0.8); // викам функция от okglib.h

        glfwSwapBuffers();
    }

    finit();
    return 0;
}
