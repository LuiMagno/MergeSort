/* Código para exemplificar
o uso de iluminação no OpenGL */

#include <GL/glut.h>
#include <iostream>

#define LARGURA  600		/* Width */
#define ALTURA   600		/* Heigth */
using namespace std;
double rotationX = 20.0;
double rotationY = 20.0;

int last_press_x = 0;
int last_press_y = 0;
double pos_z[15];
double pos_x[15];
double pos_y[15];
int rotY[15];

float color1[15];
float color2[15];
float color3[15];

bool parar = false;
int velocidade = 50;
int passo = 1;
int olhoCamera = 40;

void ParametrosIluminacao()
{
	GLfloat luzAmbiente[4]={0.8, 0.8, 0.8, 1.0};
	GLfloat luzDifusa[4]={1.0, 0.0, 0.4, 1.0};
    GLfloat luzEspecular[4]={1, 1, 0.6, 1.0};
    GLfloat posicaoLuz[4]={-1.0,1.0, 1.0, 1.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );
    glLightfv(GL_LIGHT0, GL_POSITION, luzDifusa );

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, posicaoLuz);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzEspecular);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzDifusa);

}
void Desenha_Barra(void){
    glBegin(GL_QUADS);

            glVertex3f( 0.2f, 0.2f,-0.2f);    // Face superior
            glVertex3f(-0.2f, 0.2f,-0.2f);
            glVertex3f(-0.2f, 0.2f, 0.2f);
            glVertex3f( 0.2f, 0.2f, 0.2f);

            glVertex3f( 0.2f,-0.2f, 0.2f);    // Face inferior
            glVertex3f(-0.2f,-0.2f, 0.2f);
            glVertex3f(-0.2f,-0.2f,-0.2f);
            glVertex3f( 0.2f,-0.2f,-0.2f);

            glVertex3f( 0.2, 0.2, 0.2);    // Face frontal
            glVertex3f(-0.2, 0.2, 0.2);
            glVertex3f(-0.2,-0.2, 0.2);
            glVertex3f( 0.2,-0.2, 0.2);

            glVertex3f( 0.2f,-0.2f,-0.2f);    // Face traseira
            glVertex3f(-0.2f,-0.2f,-0.2f);
            glVertex3f(-0.2f, 0.2f,-0.2f);
            glVertex3f( 0.2f, 0.2f,-0.2f);

            glVertex3f(-0.2f, 0.2f, 0.2f);    // Face esquerda
            glVertex3f(-0.2f, 0.2f,-0.2f);
            glVertex3f(-0.2f,-0.2f,-0.2f);
            glVertex3f(-0.2f,-0.2f, 0.2f);

            glVertex3f( 0.2f, 0.2f,-0.2f);    // Face direita
            glVertex3f( 0.2f, 0.2f, 0.2f);
            glVertex3f( 0.2f,-0.2f, 0.2f);
            glVertex3f( 0.2f,-0.2f,-0.2f);
    glEnd();
}

void Desenha_Plano(void){
 glBegin(GL_QUADS);
   glColor3f(0.0f,0.0f,0.2f);    // Color Orange
        glVertex3f(30.0f, 0.0f, 30.0f);    // Top Right Of The Quad (Bottom)
        glVertex3f(-30.0f, 0.0f, 30.0f);    // Top Left Of The Quad (Bottom)
        glVertex3f(-30.0f,0.0f,-30.0f);    // Bottom Left Of The Quad (Bottom)
        glVertex3f( 30.0f,0.0f,-30.0f);    // Bottom Right Of The Quad (Bottom)
  glEnd();

  /* Desenha Eixo +X */
	glColor3f(0.0, 1.0, 0.0); /* BLUE */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(LARGURA/2, 0, 0);
	glEnd();
	/* Desenha Eixo -X */
	glColor3f(0.0, 1.0, 0.0); /* BLUE claro */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(-LARGURA/2, 0, 0);
	glEnd();
  /* Desenha Eixo +X2 */
	glColor3f(1, 0.0, 0.0); /* BLUE */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 2);
		glVertex3i(LARGURA/2, 0, 2);
	glEnd();

	/* Desenha Eixo -X2 */
	glColor3f(1, 0, 0); /* BLUE claro */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 2);
		glVertex3i(-LARGURA/2, 0, 2);
	glEnd();
	 /* Desenha Eixo +X3 */
	glColor3f(1, 1.0, 0.0); /* BLUE */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 4);
		glVertex3i(LARGURA/2, 0, 4);
	glEnd();

	/* Desenha Eixo -X3 */
	glColor3f(1, 1, 0); /* BLUE claro */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 4);
		glVertex3i(-LARGURA/2, 0, 4);
	glEnd();
	 /* Desenha Eixo +X4 */
	glColor3f(0, 1.0, 1.0); /* BLUE */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 6);
		glVertex3i(LARGURA/2, 0, 6);
	glEnd();

	/* Desenha Eixo -X4 */
	glColor3f(0, 1, 1); /* BLUE claro */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 6);
		glVertex3i(-LARGURA/2, 0, 6);
	glEnd();

}
void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    gluLookAt(0.0, 0.0, olhoCamera,
    		  0.0, 0.0, -30.0,
    		  0.0, 1.0, 0.0);

    ParametrosIluminacao();

	glRotatef(rotationY, 1.0, 0.0, 0.0);
	glRotatef(rotationX, 0.0, 1.0, 0.0);

    Desenha_Plano();
    glPushMatrix();
        glScalef(1.0, 6.0, 1.0);
        glTranslatef(pos_x[0], 0.2, pos_z[0]);
        glRotatef(rotY[0],0, 10,0);
        glColor3d(color1[0], color2[0], color3[0]);
        Desenha_Barra(); // Barra 0
    glPopMatrix();

    glPushMatrix();
        glScalef(1.0, 4.0, 1.0);
        glTranslatef(pos_x[1], 0.2, pos_z[1]);
        glRotatef(rotY[1],0, 10,0);
        glColor3d(color1[1], color2[1], color3[1]);
        Desenha_Barra(); // Barra 1
    glPopMatrix();

    glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        glTranslatef(pos_x[2], 0.2, pos_z[2]);
        glRotatef(rotY[2],0, 10,0);
        glColor3d(color1[2], color2[2], color3[2]);
        Desenha_Barra(); // Barra 2
    glPopMatrix();

    glPushMatrix();
        glScalef(1.0, 7.0, 1.0);
        glTranslatef( pos_x[3], 0.2, pos_z[3]);
        glRotatef(rotY[3],0, 10,0);
        glColor3d(color1[3], color2[3], color3[3]);
        Desenha_Barra(); // Barra 3
    glPopMatrix();

    glPushMatrix();
        glScalef(1.0, 3.0, 1.0);
        glTranslatef(pos_x[4], 0.2, pos_z[4]);
        glRotatef(rotY[4],0, 10,0);
        glColor3d(color1[4], color2[4], color3[4]);
        Desenha_Barra(); // Barra 4
    glPopMatrix();

    glPushMatrix();
        glScalef(1.0, 10.0, 1.0);
        glTranslatef(pos_x[5], 0.2, pos_z[5]);
        glRotatef(rotY[5],0, 10,0);
        glColor3d(color1[5], color2[5], color3[5]);
        Desenha_Barra(); // Barra 5
    glPopMatrix();

    glPushMatrix();
        glScalef(1.0, 5.0, 1.0);
        glTranslatef(pos_x[6], 0.2, pos_z[6]);
        glRotatef(rotY[6],0, 10,0);
        glColor3d(color1[6], color2[6], color3[6]);
        Desenha_Barra(); // Barra 6
    glPopMatrix();

    glPushMatrix();
        glScalef(1.0, 10.0, 1.0);
        glTranslatef(pos_x[7], 0.2, pos_z[7]);
        glRotatef(rotY[7],0, 10,0);
        glColor3d(color1[7], color2[7], color3[7]);
        Desenha_Barra(); // Barra 7
    glPopMatrix();

	glPushMatrix();
        glScaled(1, 4.0, 1.0);
        glTranslatef(pos_x[8], 0.2, pos_z[8]);
        glRotatef(rotY[8],0, 10,0);
        glColor3d(color1[8], color2[8], color3[8]);
        Desenha_Barra(); // Barra 8
	glPopMatrix();

	glPushMatrix();
        glScalef(1.0, 10.0, 1.0);
        glTranslatef(pos_x[9], 0.2,pos_z[9]);
        glRotatef(rotY[9],0, 10,0);
        glColor3d(color1[9], color2[9], color3[9]);
        Desenha_Barra(); // Barra 9
    glPopMatrix();

    glPushMatrix();
       glScalef(1.0, 5.0, 1.0);
       glTranslatef(pos_x[10], 0.2, pos_z[10]);
       glRotatef(rotY[10],0, 10,0);
       glColor3d(color1[10], color2[10], color3[10]);
       Desenha_Barra(); // Barra 10
    glPopMatrix();

    glPushMatrix();
        glScalef(1.0, 8.0, 1.0);
        glTranslatef(pos_x[11], 0.2, pos_z[11]);
        glRotatef(rotY[11],0, 10,0);
        glColor3d(color1[11], color2[11], color3[11]);
        Desenha_Barra(); // Barra 11
    glPopMatrix();

    glPushMatrix();
        glScalef(1.0, 7.0, 1.0);
        glTranslatef(pos_x[12], 0.2, pos_z[12]);
        glRotatef(rotY[12],0, 10,0);
        glColor3d(color1[12], color2[12], color3[12]);
        Desenha_Barra(); // Barra 12
    glPopMatrix();

    glPushMatrix();
        glScalef(1.0, 9.0, 1.0);
        glTranslatef(pos_x[13], 0.2, pos_z[13]);
        glRotatef(rotY[13],0, 10,0);
        glColor3d(color1[13], color2[13], color3[13]);
        Desenha_Barra(); // Barra 13
    glPopMatrix();

    glPushMatrix();
        glScalef(1.0, 12.0, 1.0);
        glTranslatef(pos_x[14], 0.2, pos_z[14]);
        glRotatef(rotY[14],0, 10,0);
        glColor3d(color1[14], color2[14], color3[14]);
        Desenha_Barra(); // Barra 14
    glPopMatrix();

    glPushMatrix();
        glScalef(1.0, 13.0, 1.0);
        glTranslatef(pos_x[15], 0.2, pos_z[15]);
        glRotatef(rotY[15],0, 10,0);
        glColor3d(color1[15], color2[15], color3[15]);
        Desenha_Barra(); // Barra 15
    glPopMatrix();

	glFlush();
}
void Anima(int value)
{

    if( pos_z[0]<0 && passo == 1)
    {
        for(int i = 0; i<16; i++)
        {
            pos_z[i] += 0.05;
        }
        if(pos_z[15] >= 0)
        {
            passo = 2;
        }
    }
    if(pos_z[0]<2 && passo == 2)
    {
        for(int i = 0; i<8; i++)
        {
            pos_z[i] +=0.05;
            color1[i] = 1;
            color2[i] = 0;
            color3[i] = 0;
        }
        if(pos_z[0] >= 2)
        {
            passo = 3;
        }
    }
    if(pos_z[0]<4 && passo == 3)
    {
        for(int i = 0; i<4; i++)
        {
            pos_z[i] +=0.05;
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
        if(pos_z[0] >= 4)
        {
            passo = 4;
        }
    }
    if(pos_z[0]<6 && passo == 4)
    {
        for(int i = 0; i<2; i++)
        {
            pos_z[i] +=0.05;
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 1;
        }

        if(pos_z[0] >= 6)
        {
            passo = 5;
        }
    }

    if(pos_x[0]<-7.0 && passo == 5)
    {
        pos_x[0] += 0.02;
        pos_x[1] -= 0.02;

        if(rotY[0]<10000)
        {
            rotY[0] += 20;
            rotY[1] += 20;
        }
        for(int i = 0; i<2; i++)
        {
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 1;
        }
        if(pos_x[0]>=-7)
        {
            passo = 6;
            rotY[0] = 0;
            rotY[1] = 0;
            for(int i = 0; i<2; i++)
            {
                color1[i] = 0;
                color2[i] = 1;
                color3[i] = 1;
            }
        }
    }
    if(pos_z[0]>4 && passo == 6)
    {
        pos_z[0] -= 0.05;
        pos_z[1] -= 0.05;
        for(int i = 0; i<2; i++)
        {
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
        if(pos_z[0]<=4)
        {
            passo = 7;
        }
    }
    if(pos_z[2]<6 && passo == 7)
    {
        for(int i = 2; i<4; i++)
        {
            pos_z[i] +=0.05;
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 1;
        }
        if(pos_z[2] >= 6)
        {
            passo = 8;
        }
    }
    if(pos_z[2]>4 && passo == 8)
    {
        pos_z[2] -= 0.05;
        pos_z[3] -= 0.05;
        for(int i = 2; i<4; i++)
        {
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
        if(pos_z[2]<=4)
        {
            passo = 9;
        }
    }
    if(pos_x[1]<-6.0  && passo == 9)
    {
        pos_x[1] += 0.02;
        pos_x[2] -= 0.02;
        rotY[1] += 15;
        rotY[2] += 15;
        for(int i = 1; i<3; i++)
        {
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 1;
        }
        if(pos_x[1]>=-6.0)
        {
            passo = 10;
            rotY[1] = 0;
            rotY[2] = 0;
            for(int i = 1; i<3; i++)
            {
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 0;
            }
        }
    }
    if(pos_x[0]<-6.0  && passo == 10)
    {
        pos_x[0] += 0.02;
        pos_x[1] -= 0.02;
        rotY[0] += 15;
        rotY[1] += 15;

        for(int i = 0; i<2; i++)
        {
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 1;
        }
        if(pos_x[0]>=-6.0)
        {
            passo = 11;
            rotY[0] = 0;
            rotY[1] = 0;
            for(int i = 0; i<2; i++)
            {
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 0;
            }

        }
    }
    if(pos_z[0]>2.0 && passo == 11)
    {
        for(int i = 0; i<4; i++)
        {
            pos_z[i] -=0.05;
            color1[i] = 1;
            color2[i] = 0;
            color3[i] = 0;
        }
        if(pos_z[0]<= 2)
        {
            passo = 12;
        }
    }
    if(pos_z[4]<4.0 && passo == 12)
    {
        for(int i = 4; i<8; i++)
        {
            pos_z[i] +=0.05;
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
        if(pos_z[4]>= 4)
        {
            passo = 13;
        }
    }

    if(pos_z[4]<6.0 && passo == 13)
    {
        pos_z[4] +=0.05;
        pos_z[5] +=0.05;
        for(int i = 4; i<6; i++)
        {
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 1;
        }
        if(pos_z[4]>= 6)
        {
            passo = 14;
        }
    }

    if(pos_z[4]>4.0 && passo == 14)
    {
        pos_z[4] -=0.05;
        pos_z[5] -=0.05;
        for(int i = 4; i<6; i++)
        {
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }

        if(pos_z[4]<=4)
        {
            passo = 15;
        }

    }
    if(pos_z[6]<6.0 && passo == 15)
    {
        pos_z[6] +=0.05;
        pos_z[7] +=0.05;
        for(int i = 6; i<8; i++)
        {
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 1;
        }

        if(pos_z[6]>=6)
        {
            passo = 16;
        }
    }

    if(pos_z[6]>4.0 && passo == 16)
    {
        pos_z[6] -=0.05;
        pos_z[7] -=0.05;
        for(int i = 6; i<8; i++)
        {
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }

        if(pos_z[6]<=4)
        {
            passo = 17;
        }
    }
    if(pos_x[5]<-2.0  && passo == 17)
    {
        pos_x[5] += 0.02;
        pos_x[6] -= 0.02;
        rotY[5] += 15;
        rotY[6] += 15;

        for(int i = 5; i<7; i++)
        {
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 1;
        }
        if(pos_x[5]>=-2.0)
        {
            passo = 18;
            rotY[5] = 0;
            rotY[6] = 0;
            for(int i = 5; i<7; i++)
            {
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 0;
            }
        }
    }
    if(pos_z[4]>2.0 && passo == 18)
    {
        for(int i = 4; i<8; i++)
        {
            pos_z[i] -=0.05;
            color1[i] = 1;
            color2[i] = 0;
            color3[i] = 0;
        }
        if(pos_z[4]<= 2)
        {
            passo = 19;
        }
    }

    if(pos_x[1]<-4.0  && passo == 19)
    {
        pos_x[1] += 0.02;
        pos_x[4] -= 0.02;
        rotY[1] += 15;
        rotY[4] += 15;

        for(int i = 1; i<5; i++)
        {
            if(i==1 || i==4)
            {
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
            }
        }
        if(pos_x[1]>=-4.0)
        {
            passo = 20;
            rotY[1] = 0;
            rotY[4] = 0;
            for(int i = 1; i<5; i++)
            {
                if(i==1 || i==4)
                {
                    color1[i] = 1;
                    color2[i] = 0;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_x[0]<-4.0  && passo == 20)
    {
        pos_x[0] += 0.02;
        pos_x[1] -= 0.02;
        rotY[0] += 15;
        rotY[1] += 15;

        for(int i = 0; i<2; i++)
        {
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 1;
        }
        if(pos_x[0]>=-4.0)
        {
            passo = 21;
            rotY[0] = 0;
            rotY[1] = 0;
            for(int i = 0; i<2; i++)
            {
                color1[i] = 1;
                color2[i] = 0;
                color3[i] = 0;
            }
        }
    }
    if(pos_x[3]<-3.0  && passo == 21)
    {
        pos_x[3] += 0.02;
        pos_x[6] -= 0.02;
        rotY[3] += 15;
        rotY[6] += 15;

        for(int i = 3; i<7; i++)
        {
            if(i==3 || i==6)
            {
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
            }
        }
        if(pos_x[3]>=-3.0)
        {
            passo = 22;
            rotY[3] = 0;
            rotY[6] = 0;
            for(int i = 3; i<7; i++)
            {
                if(i==3 || i==6)
                {
                    color1[i] = 1;
                    color2[i] = 0;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_z[0]>0  && passo == 22)
    {
        for(int i = 0; i<8; i++)
        {
            pos_z[i] -=0.05;
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 0;
        }
        if(pos_z[0]<=0)
        {
            passo = 23;
        }
    }
    if(pos_z[8]<2  && passo == 23)
    {
        for(int i = 8; i<16; i++)
        {
            pos_z[i] +=0.05;
            color1[i] = 1;
            color2[i] = 0;
            color3[i] = 0;
        }
        if(pos_z[8]>=2)
        {
            passo = 24;
        }
    }

    if(pos_z[8]<4  && passo == 24)
    {
        for(int i = 8; i<12; i++)
        {
            pos_z[i] +=0.05;
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
        if(pos_z[8]>=4)
        {
            passo = 25;
        }
    }
    if(pos_z[8]<6  && passo == 25)
    {
        for(int i = 8; i<10; i++)
        {
            pos_z[i] +=0.05;
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 1;
        }
        if(pos_z[8]>=6)
        {
            passo = 26;
        }
    }
    if(pos_z[8]>4  && passo == 26)
    {
        for(int i = 8; i<10; i++)
        {
            pos_z[i] -=0.05;
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
        if(pos_z[8]<=4)
        {
            passo = 27;
        }
    }
    if(pos_z[10]<6  && passo == 27)
    {
        for(int i = 10; i<12; i++)
        {
            pos_z[i] +=0.05;
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 1;
        }
        if(pos_z[10]>=6)
        {
            passo = 28;
        }
    }
    if(pos_z[10]>4  && passo == 28)
    {
        for(int i = 10; i<12; i++)
        {
            pos_z[i] -=0.05;
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
        if(pos_z[10]<=4)
        {
            passo = 29;
        }
    }
    if(pos_x[9]<2  && passo == 29)
    {
        pos_x[9] += 0.02;
        pos_x[10] -= 0.02;
        rotY[9] += 15;
        rotY[10] += 15;
        for(int i = 9; i<11; i++)
        {
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 1;
        }
        if(pos_x[9]>=2)
        {
            passo = 30;
            rotY[9] = 0;
            rotY[10] = 0;
            for(int i = 9; i<11; i++)
            {
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 0;
            }
        }
    }
    if(pos_x[9]<3  && passo == 30)
    {
        pos_x[9] += 0.02;
        pos_x[11] -= 0.02;
        rotY[9] += 15;
        rotY[11] += 15;
        for(int i = 9; i<12; i++)
        {
            if(i==9 || i==11)
            {
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
            }
        }
        if(pos_x[9]>=3)
        {
            passo = 31;
            rotY[9] = 0;
            rotY[10] = 0;
            for(int i = 9; i<12; i++)
            {
                if(i==9 || i==11)
                {
                    color1[i] = 1;
                    color2[i] = 1;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_z[8]>2  && passo == 31)
    {
        for(int i = 8; i<12; i++)
        {
            pos_z[i] -=0.05;
            color1[i] = 1;
            color2[i] = 0;
            color3[i] = 0;
        }
        if(pos_z[8]<=2)
        {
            passo = 32;
        }
    }
    if(pos_z[12]<4  && passo == 32)
    {
        for(int i = 12; i<16; i++)
        {
            pos_z[i] +=0.05;
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
        if(pos_z[12]>=4)
        {
            passo = 33;
        }
    }
    if(pos_z[12]<6  && passo == 33)
    {
        for(int i = 12; i<14; i++)
        {
            pos_z[i] +=0.05;
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 1;
        }
        if(pos_z[12]>=6)
        {
            passo = 34;
        }
    }
    if(pos_z[12]>4  && passo == 34)
    {
        for(int i = 12; i<14; i++)
        {
            pos_z[i] -=0.05;
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
        if(pos_z[12]<=4)
        {
            passo = 35;
        }
    }
    if(pos_z[14]<6  && passo == 35)
    {
        for(int i = 14; i<16; i++)
        {
            pos_z[i] +=0.05;
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 1;
        }
        if(pos_z[14]>=6)
        {
            passo = 36;
        }
    }
    if(pos_z[14]>4  && passo == 36)
    {
        for(int i = 14; i<16; i++)
        {
            pos_z[i] -=0.05;
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
        if(pos_z[14]<=4)
        {
            passo = 37;
        }
    }
    if(pos_z[12]>2  && passo == 37)
    {
        for(int i = 12; i<16; i++)
        {
            pos_z[i] -=0.05;
            color1[i] = 1;
            color2[i] = 0;
            color3[i] = 0;
        }
        if(pos_z[12]<=2)
        {
            passo = 38;
        }
    }
    if(pos_x[11]<4  && passo == 38)
    {
        pos_x[11] += 0.02;
        pos_x[12] -= 0.02;
        rotY[11] += 15;
        rotY[12] += 15;
        for(int i = 11; i<13; i++)
        {
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 1;
        }
        if(pos_x[11]>=4)
        {
            passo = 39;
            rotY[11] = 0;
            rotY[12] = 0;
            for(int i = 11; i<13; i++)
            {
                color1[i] = 1;
                color2[i] = 0;
                color3[i] = 0;
            }
        }
    }
    if(pos_x[9]<4  && passo == 39)
    {
        pos_x[9] += 0.02;
        pos_x[11] -= 0.02;
        rotY[9] += 15;
        rotY[11] += 15;
        for(int i = 9; i<12; i++)
        {
            if(i==9 || i==11)
            {
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
            }
        }
        if(pos_x[9]>=4)
        {
            passo = 40;
            rotY[9] = 0;
            rotY[11] = 0;
            for(int i = 9; i<12; i++)
            {
                if(i==9 || i==11)
                {
                    color1[i] = 1;
                    color2[i] = 0;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_x[9]<5  && passo == 40)
    {
        pos_x[9] += 0.02;
        pos_x[13] -= 0.02;
        rotY[9] += 15;
        rotY[13] += 15;
        for(int i = 9; i<14; i++)
        {
            if(i==9 || i==13)
            {
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
            }
        }
        if(pos_x[9]>=5)
        {
            passo = 41;
            rotY[9] = 0;
            rotY[13] = 0;
            for(int i = 9; i<14; i++)
            {
                if(i==9 || i==13)
                {
                    color1[i] = 1;
                    color2[i] = 0;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_z[8]>0  && passo == 41)
    {
        for(int i = 8; i<16; i++)
        {
            pos_z[i] -=0.05;
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 0;
        }
        if(pos_z[8]<=0)
        {
            passo = 42;
        }
    }
    if(pos_x[6]<0  && passo == 42)
    {
        pos_x[6] += 0.02;
        pos_x[8] -= 0.02;
        rotY[6] += 15;
        rotY[8] += 15;
        for(int i = 6; i<9; i++)
        {
            if(i==6 || i==8)
            {
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
            }
        }
        if(pos_x[6]>=0)
        {
            passo = 43;
            rotY[6] = 0;
            rotY[8] = 0;
            for(int i = 6; i<9; i++)
            {
                if(i==6 || i==8)
                {
                    color1[i] = 0;
                    color2[i] = 1;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_x[0]<0  && passo == 43)
    {
        pos_x[0] += 0.02;
        pos_x[6] -= 0.02;
        rotY[0] += 15;
        rotY[6] += 15;
        for(int i = 0; i<7; i++)
        {
            if(i==0 || i==6)
            {
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
            }
        }
        if(pos_x[0]>=0)
        {
            passo = 44;
            rotY[0] = 0;
            rotY[6] = 0;
            for(int i = 0; i<7; i++)
            {
                if(i==0 || i==6)
                {
                    color1[i] = 0;
                    color2[i] = 1;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_x[3]<1  && passo == 44)
    {
        pos_x[3] += 0.02;
        pos_x[10] -= 0.02;
        rotY[3] += 15;
        rotY[10] += 15;
        for(int i = 3; i<11; i++)
        {
            if(i==3 || i==10)
            {
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
            }
        }
        if(pos_x[3]>=1)
        {
            passo = 45;
            rotY[3] = 0;
            rotY[10] = 0;
            for(int i = 3; i<11; i++)
            {
                if(i==3 || i==10)
                {
                    color1[i] = 0;
                    color2[i] = 1;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_x[5]<0  && passo == 45)
    {
        pos_x[5] += 0.02;
        pos_x[0] -= 0.02;
        rotY[5] += 15;
        rotY[0] += 15;
        for(int i = 0; i<6; i++)
        {
            if(i==0 || i==5)
            {
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
            }
        }
        if(pos_x[5]>=0)
        {
            passo = 46;
            rotY[5] = 0;
            rotY[0] = 0;
            for(int i = 0; i<6; i++)
            {
                if(i==0 || i==5)
                {
                    color1[i] = 0;
                    color2[i] = 1;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_x[7]<1  && passo == 46)
    {
        pos_x[7] += 0.02;
        pos_x[3] -= 0.02;
        rotY[7] += 15;
        rotY[3] += 15;
        for(int i = 3; i<8; i++)
        {
            if(i==3 || i==7)
            {
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
            }
        }
        if(pos_x[7]>=1)
        {
            passo = 47;
            rotY[7] = 0;
            rotY[3] = 0;
            for(int i = 3; i<8; i++)
            {
                if(i==3 || i==7)
                {
                    color1[i] = 0;
                    color2[i] = 1;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_x[5]<2  && passo == 47)
    {
        pos_x[5] += 0.02;
        pos_x[12] -= 0.02;
        rotY[5] += 15;
        rotY[12] += 15;
        for(int i = 5; i<13; i++)
        {
            if(i==5 || i==12)
            {
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
            }
        }
        if(pos_x[5]>=2)
        {
            passo = 48;
            rotY[5] = 0;
            rotY[12] = 0;
            for(int i = 5; i<13; i++)
            {
                if(i==5 || i==12)
                {
                    color1[i] = 0;
                    color2[i] = 1;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_x[7]<3  && passo == 48)
    {
        pos_x[7] += 0.02;
        pos_x[11] -= 0.02;
        rotY[7] += 15;
        rotY[11] += 15;
        for(int i = 7; i<12; i++)
        {
            if(i==7 || i==11)
            {
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
            }
        }
        if(pos_x[7]>=3)
        {
            passo = 49;
            rotY[7] = 0;
            rotY[11] = 0;
            for(int i = 7; i<12; i++)
            {
                if(i==7 || i==11)
                {
                    color1[i] = 0;
                    color2[i] = 1;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_x[5]<4  && passo == 49)
    {
        pos_x[5] += 0.02;
        pos_x[13] -= 0.02;
        rotY[5] += 15;
        rotY[13] += 15;
        for(int i = 5; i<14; i++)
        {
            if(i==5 || i==13)
            {
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
            }
        }
        if(pos_x[5]>=4)
        {
            for(int i = 5; i<14; i++)
            {
                if(i==5 || i==13)
                {
                    color1[i] = 0;
                    color2[i] = 1;
                    color3[i] = 0;
                }
                passo=50;
            }
        }
    }

    glutPostRedisplay();
    if(parar == false)
    {
        glutTimerFunc(velocidade, Anima, 1);
    }



}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'q':
            exit(0);
            break;
        case '+': // aumentando a velocidade
            if(velocidade>10){
                velocidade -= 10;
            }else{
                velocidade--;
            }
            break;
        case '-': // diminuindo a velocidade
            if(velocidade>10){
                velocidade += 10;
            }else{
                velocidade++;
            }
            break;
        case 'a': // aumentando distância do olho
            olhoCamera++;
            break;
        case 'd': // diminuindo distância do olho
            olhoCamera--;
            break;
        glutPostRedisplay();
    }
}
void Mouse_Motion(int x, int y)
{
	rotationX += (double)(x - last_press_x);
	rotationY += (double)(y - last_press_y);
	last_press_x = x;
	last_press_y = y;
	glutPostRedisplay();
}

void Mouse_Press(int button, int state, int x, int y)
{
	if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
	{
		last_press_x = x;
		last_press_y = y;
	}
}

void Janela(int opcao)
{
	switch(opcao){
		case 0:
		    parar = false;
            glutTimerFunc(velocidade, Anima, 1);   /* Retomar */
		break;

		case 1:
            parar = true;                    /* Pausar */
		break;
	}
	glutPostRedisplay();
}

void CriarMenu()
{
	glutCreateMenu(Janela);
	glutAddMenuEntry("Retomar", 0);
	glutAddMenuEntry("Pausar", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void Inicializa (void)
{
    glClearColor(0.0f, 0.0f, 0.1f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0f, ((GLfloat)LARGURA/(GLfloat)ALTURA), 1, 50.0f);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glColorMaterial ( GL_FRONT_AND_BACK,GL_AMBIENT) ;
    glEnable(GL_COLOR_MATERIAL);

}

int main(int argc, char **argv)
{
    int j = -8;
    for(int i = 0; i<16; i++){
        pos_x[i] = j;
        pos_z[i] = -4;
        color1[i] = 0;
        color2[i] = 1;
        color3[i] = 0;
        rotY[i] = 0;
        j++;
    }
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("MergeSort");
	glutDisplayFunc(Desenha);
	glutMouseFunc(Mouse_Press);
	glutMotionFunc(Mouse_Motion);
    glutKeyboardFunc(key);
	Inicializa();
	CriarMenu();
	glutTimerFunc(1, Anima, 1000);
	glutMainLoop();
}
