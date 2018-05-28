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

float color1[15];
float color2[15];
float color3[15];

int velocidade = 50;
int passo = 1;
int olhoCamera = 40;
int rotY[15];

void Desenha_Origem()
{
	/* Define a cor Azul (BLUE) */
	glColor3f(0.0, 0.0, 1.0);
	/* Define o tamanho do ponto para 4x4 pixels */
	glPointSize(4);

	glBegin(GL_POINTS);
		glVertex3i(0, 0, 0);
	glEnd();
}

void Desenha_Eixos_Coordenados()
{
	/* Desenha Eixo +Y */
	glColor3f(1.0, 0.0, 0.0); /* RED */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(0, ALTURA/2, 0);
	glEnd();

	/* Desenha Eixo -Y */
	glColor3f(1.0, 0.8, 0.8); /* RED claro */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(0, -ALTURA/2, 0);
	glEnd();

	/* Desenha Eixo +X */
	glColor3f(0.0, 0.0, 1.0); /* BLUE */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(LARGURA/2, 0, 0);
	glEnd();

	/* Desenha Eixo -X */
	glColor3f(0.8, 0.8, 1.0); /* BLUE claro */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(-LARGURA/2, 0, 0);
	glEnd();

	/* Desenha Eixo +Z */
	glColor3f(0.0, 1.0, 0.0); /* GREEN */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(0, 0, LARGURA/2);
	glEnd();

	/* Desenha Eixo -Z */
	glColor3f(0.8, 1.0, 0.8); /* GREEN claro */
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(0, 0, -LARGURA/2);
	glEnd();

}


void ParametrosIluminacao()
{
	/* Parâmetros para a Luz GL_LIGHT0 sendo uma fonte de Luz Pontual */
	GLfloat luzAmbiente[4]={0.8, 0.8, 0.8, 1.0};
	GLfloat luzDifusa[4]={1.0, 0.0, 0.4, 1.0};
    GLfloat luzEspecular[4]={1, 1, 0.6, 1.0};
    GLfloat posicaoLuz[4]={-1.0,1.0, 1.0, 1.0};    /* Fonte de Luz Pontual */


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
    glBegin(GL_QUADS);        // Draw The Cube Using quads
         //   glColor3f(0.0f,1.0f,0.0f);    // Color Blue
            glVertex3f( 0.2f, 0.2f,-0.2f);    // Top Right Of The Quad (Top)
            glVertex3f(-0.2f, 0.2f,-0.2f);    // Top Left Of The Quad (Top)
            glVertex3f(-0.2f, 0.2f, 0.2f);    // Bottom Left Of The Quad (Top)
            glVertex3f( 0.2f, 0.2f, 0.2f);    // Bottom Right Of The Quad (Top)
         //   glColor3f(1.0f,0.5f,0.0f);    // Color Orange
            glVertex3f( 0.2f,-0.2f, 0.2f);    // Top Right Of The Quad (Bottom)
            glVertex3f(-0.2f,-0.2f, 0.2f);    // Top Left Of The Quad (Bottom)
            glVertex3f(-0.2f,-0.2f,-0.2f);    // Bottom Left Of The Quad (Bottom)
            glVertex3f( 0.2f,-0.2f,-0.2f);    // Bottom Right Of The Quad (Bottom)
        //    glColor3f(1.0f,0.0f,0.0f);    // Color Red
            glVertex3f( 0.2, 0.2, 0.2);    // Top Right Of The Quad (Front)
            glVertex3f(-0.2, 0.2, 0.2);    // Top Left Of The Quad (Front)
            glVertex3f(-0.2,-0.2, 0.2);    // Bottom Left Of The Quad (Front)
            glVertex3f( 0.2,-0.2, 0.2);    // Bottom Right Of The Quad (Front)
       //     glColor3f(1.0f,1.0f,0.0f);    // Color Yellow
            glVertex3f( 0.2f,-0.2f,-0.2f);    // Top Right Of The Quad (Back)
            glVertex3f(-0.2f,-0.2f,-0.2f);    // Top Left Of The Quad (Back)
            glVertex3f(-0.2f, 0.2f,-0.2f);    // Bottom Left Of The Quad (Back)
            glVertex3f( 0.2f, 0.2f,-0.2f);    // Bottom Right Of The Quad (Back)
        //    glColor3f(0.0f,0.0f,1.0f);    // Color Blue
            glVertex3f(-0.2f, 0.2f, 0.2f);    // Top Right Of The Quad (Left)
            glVertex3f(-0.2f, 0.2f,-0.2f);    // Top Left Of The Quad (Left)
            glVertex3f(-0.2f,-0.2f,-0.2f);    // Bottom Left Of The Quad (Left)
            glVertex3f(-0.2f,-0.2f, 0.2f);    // Bottom Right Of The Quad (Left)
        //    glColor3f(1.0f,0.0f,1.0f);    // Color Violet
            glVertex3f( 0.2f, 0.2f,-0.2f);    // Top Right Of The Quad (Right)
            glVertex3f( 0.2f, 0.2f, 0.2f);    // Top Left Of The Quad (Right)
            glVertex3f( 0.2f,-0.2f, 0.2f);    // Bottom Left Of The Quad (Right)
            glVertex3f( 0.2f,-0.2f,-0.2f);    // Bottom Right Of The Quad (Right)
    glEnd();            // End Drawing The Cube

}
/* Função callback chamada para fazer o desenho */
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
	/* Limpa a janela de visualização com a cor de fundo especificada */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    /* Especifica uma Câmera com:
     * olho = (0, 0, 30)
     * olhar = (0, 0, 0)
     * up = (0, 1, 0) */
    glLoadIdentity();
    gluLookAt(0.0, 0.0, olhoCamera,		/* eye */
    		  0.0, 0.0, -30.0,		/* look */
    		  0.0, 1.0, 0.0);		/* up */

    ParametrosIluminacao();

    /* Rotaciona os objetos para visualizar a 3 dimensão */
	glRotatef(rotationY, 1.0, 0.0, 0.0); /* Rotaciona em torno do X */
	glRotatef(rotationX, 0.0, 1.0, 0.0); /* Rotaciona em torno de Y */

	Desenha_Origem();
//	Desenha_Eixos_Coordenados();

	//glColor3f(1.0, 0.0, 0.0);
	//Desenha_Face_Superior_Cubo();
    //glutSolidCube(4);
	//glutSolidSphere(4, 50, 50);
	//glutSolidTeapot(4);
	//glutSolidTorus(1, 4, 20, 20);
    Desenha_Plano();

    glPushMatrix();
        glScalef(1.0, 6.0, 1.0);
   //    glRotated(70, 1, 0, 0);
        glTranslatef(pos_x[0], 0.2, pos_z[0]);
        glRotatef(,0, 10,0);
        glColor3d(color1[0], color2[0], color3[0]);
        Desenha_Barra(); // Barra 0
    glPopMatrix();

    glPushMatrix();
        glScalef(1.0, 4.0, 1.0);
        glTranslatef(pos_x[1], 0.2, pos_z[1]);
        glColor3d(color1[1], color2[1], color3[1]);
        Desenha_Barra(); // Barra 1
    glPopMatrix();

    glPushMatrix();

        glScalef(1.0, 1.0, 1.0);
        glTranslatef(pos_x[2], 0.2, pos_z[2]);
        glColor3d(color1[2], color2[2], color3[2]);
        Desenha_Barra(); // Barra 2
    glPopMatrix();

     glPushMatrix();

        glScalef(1.0, 7.0, 1.0);
        glTranslatef( pos_x[3], 0.2, pos_z[3]);
        glColor3d(color1[3], color2[3], color3[3]);
        Desenha_Barra(); // Barra 3
    glPopMatrix();

    glPushMatrix();

        glScalef(1.0, 3.0, 1.0);
        glTranslatef(pos_x[4], 0.2, pos_z[4]);
        glColor3d(color1[4], color2[4], color3[4]);
        Desenha_Barra(); // Barra 4
    glPopMatrix();

     glPushMatrix();

        glScalef(1.0, 10.0, 1.0);
        glTranslatef(pos_x[5], 0.2, pos_z[5]);
        glColor3d(color1[5], color2[5], color3[5]);
        Desenha_Barra(); // Barra 5
    glPopMatrix();

    glPushMatrix();

        glScalef(1.0, 5.0, 1.0);
        glTranslatef(pos_x[6], 0.2, pos_z[6]);
        glColor3d(color1[6], color2[6], color3[6]);
        Desenha_Barra(); // Barra 6
    glPopMatrix();

    glPushMatrix();

        glScalef(1.0, 10.0, 1.0);
        glTranslatef(pos_x[7], 0.2, pos_z[7]);
        glColor3d(color1[7], color2[7], color3[7]);
        Desenha_Barra(); // Barra 7
    glPopMatrix();

	glPushMatrix();
        glScaled(1, 4.0, 1.0);
        glTranslatef(pos_x[8], 0.2, pos_z[8]);
        glColor3d(color1[8], color2[8], color3[8]);
        Desenha_Barra(); // Barra 8
	glPopMatrix();

	glPushMatrix();

        glScalef(1.0, 10.0, 1.0);
        glTranslatef(pos_x[9], 0.2,pos_z[9]);
        glColor3d(color1[9], color2[9], color3[9]);
        Desenha_Barra(); // Barra 9
    glPopMatrix();

    glPushMatrix();

       glScalef(1.0, 5.0, 1.0);
       glTranslatef(pos_x[10], 0.2, pos_z[10]);
       glColor3d(color1[10], color2[10], color3[10]);
       Desenha_Barra(); // Barra 10
   glPopMatrix();

     glPushMatrix();

        glScalef(1.0, 8.0, 1.0);
        glTranslatef(pos_x[11], 0.2, pos_z[11]);
        glColor3d(color1[11], color2[11], color3[11]);
        Desenha_Barra(); // Barra 11
    glPopMatrix();

     glPushMatrix();

        glScalef(1.0, 7.0, 1.0);
        glTranslatef(pos_x[12], 0.2, pos_z[12]);
        glColor3d(color1[12], color2[12], color3[12]);
        Desenha_Barra(); // Barra 12
    glPopMatrix();

     glPushMatrix();

        glScalef(1.0, 9.0, 1.0);
        glTranslatef(pos_x[13], 0.2, pos_z[13]);
        glColor3d(color1[13], color2[13], color3[13]);
        Desenha_Barra(); // Barra 13
    glPopMatrix();

     glPushMatrix();

        glScalef(1.0, 12.0, 1.0);
        glTranslatef(pos_x[14], 0.2, pos_z[14]);
        glColor3d(color1[14], color2[14], color3[14]);
        Desenha_Barra(); // Barra 14
    glPopMatrix();

     glPushMatrix();

        glScalef(1.0, 13.0, 1.0);
        glTranslatef(pos_x[15], 0.2, pos_z[15]);
        glColor3d(color1[15], color2[15], color3[15]);
        Desenha_Barra(); // Barra 15
    glPopMatrix();

	/* Executa os comandos OpenGL */
	glFlush();
}
void Anima(int value)  /* Usada quando se usar glutTimerFunc() */
{

 if( pos_z[0]<0 && passo == 1){
    for(int i = 0; i<16; i++){
        pos_z[i] += 0.05;
        }
    if(pos_z[15] >= 0){
         passo = 2;

    }


}

    if(pos_z[0]<2 && passo == 2){
        for(int i = 0; i<8; i++){
            pos_z[i] +=0.05;
            color1[i] = 1;
            color2[i] = 0;
            color3[i] = 0;
        }

        if(pos_z[0] >= 2){
            passo = 3;
        }
    }

    if(pos_z[0]<4 && passo == 3){
        for(int i = 0; i<4; i++){
            pos_z[i] +=0.05;
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
        if(pos_z[0] >= 4){
            passo = 4;
        }
    }
    if(pos_z[0]<6 && passo == 4){
        for(int i = 0; i<2; i++){
            pos_z[i] +=0.05;
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 1;
        }

        if(pos_z[0] >= 6){
            passo = 5;
        }
    }


    if(pos_x[0]<-7.0 && passo == 5){
            pos_x[0] += 0.02;
            pos_x[1] -= 0.02;
            for(int i = 0; i<2; i++){
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
        }
        if(pos_x[0]>=-7){
            passo = 6;
            for(int i = 0; i<2; i++){
                color1[i] = 0;
                color2[i] = 1;
                color3[i] = 1;
            }
        }
    }

    if(pos_z[0]>4 && passo == 6){
        pos_z[0] -= 0.05;
        pos_z[1] -= 0.05;
        for(int i = 0; i<2; i++){
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
        if(pos_z[0]<=4){
            passo = 7;
        }
    }

    if(pos_z[2]<6 && passo == 7){
        for(int i = 2; i<4; i++){
            pos_z[i] +=0.05;
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 1;
        }
        if(pos_z[2] >= 6){
            passo = 8;
        }
    }
    if(pos_z[2]>4 && passo == 8){
        pos_z[2] -= 0.05;
        pos_z[3] -= 0.05;
        for(int i = 2; i<4; i++){
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
        if(pos_z[2]<=4){
            passo = 9;
        }
    }
    if(pos_x[1]<-6.0  && passo == 9){
            pos_x[1] += 0.02;
            pos_x[2] -= 0.02;
            for(int i = 1; i<3; i++){
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
            }
        if(pos_x[1]>=-6.0){
            passo = 10;
            for(int i = 1; i<3; i++){
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 0;
            }
        }
    }

    if(pos_x[0]<-6.0  && passo == 10){
            pos_x[0] += 0.02;
            pos_x[1] -= 0.02;
            for(int i = 0; i<2; i++){
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
            }
        if(pos_x[0]>=-6.0){
            for(int i = 0; i<2; i++){
               color1[i] = 1;
               color2[i] = 1;
               color3[i] = 0;
            }
            passo = 11;
        }
    }

    if(pos_z[0]>2.0 && passo == 11){
         for(int i = 0; i<4; i++){
            pos_z[i] -=0.05;
            color1[i] = 1;
            color2[i] = 0;
            color3[i] = 0;
        }
        if(pos_z[0]<= 2){
            passo = 12;
        }
    }
    if(pos_z[4]<4.0 && passo == 12){
         for(int i = 4; i<8; i++){
            pos_z[i] +=0.05;
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
        if(pos_z[4]>= 4){
            passo = 13;
        }
    }

    if(pos_z[4]<6.0 && passo == 13){
         pos_z[4] +=0.05;
         pos_z[5] +=0.05;
         for(int i = 4; i<6; i++){
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 1;
        }

        if(pos_z[4]>= 6){
            passo = 14;
        }
    }

    if(pos_z[4]>4.0 && passo == 14){
         pos_z[4] -=0.05;
         pos_z[5] -=0.05;
         for(int i = 4; i<6; i++){
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }

        if(pos_z[4]<=4){
            passo = 15;
        }

    }
    if(pos_z[6]<6.0 && passo == 15){
         pos_z[6] +=0.05;
         pos_z[7] +=0.05;
         for(int i = 6; i<8; i++){
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 1;
        }

        if(pos_z[6]>=6){
            passo = 16;
        }
    }

    if(pos_z[6]>4.0 && passo == 16){
         pos_z[6] -=0.05;
         pos_z[7] -=0.05;
         for(int i = 6; i<8; i++){
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }

        if(pos_z[6]<=4){
            passo = 17;
        }
    }
    if(pos_x[5]<-2.0  && passo == 17){
            pos_x[5] += 0.02;
            pos_x[6] -= 0.02;
            for(int i = 5; i<7; i++){
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
            }
        if(pos_x[5]>=-2.0){
            passo = 18;
            for(int i = 5; i<7; i++){
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 0;
            }
        }
    }
    if(pos_z[4]>2.0 && passo == 18){
         for(int i = 4; i<8; i++){
            pos_z[i] -=0.05;
            color1[i] = 1;
            color2[i] = 0;
            color3[i] = 0;
        }
        if(pos_z[4]<= 2){
            passo = 19;
        }
    }

    if(pos_x[1]<-4.0  && passo == 19){
            pos_x[1] += 0.02;
            pos_x[4] -= 0.02;
            for(int i = 1; i<5; i++){
                if(i==1 || i==4){
                    color1[i] = 1;
                    color2[i] = 1;
                    color3[i] = 1;
                }
            }
        if(pos_x[1]>=-4.0){
            passo = 20;
            for(int i = 1; i<5; i++){
                if(i==1 || i==4){
                    color1[i] = 1;
                    color2[i] = 0;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_x[0]<-4.0  && passo == 20){
            pos_x[0] += 0.02;
            pos_x[1] -= 0.02;
            for(int i = 0; i<2; i++){
                    color1[i] = 1;
                    color2[i] = 1;
                    color3[i] = 1;
            }
        if(pos_x[0]>=-4.0){
            passo = 21;
            for(int i = 0; i<2; i++){
                    color1[i] = 1;
                    color2[i] = 0;
                    color3[i] = 0;
            }
        }
    }
    if(pos_x[3]<-3.0  && passo == 21){
            pos_x[3] += 0.02;
            pos_x[6] -= 0.02;
            for(int i = 3; i<7; i++){
                if(i==3 || i==6){
                    color1[i] = 1;
                    color2[i] = 1;
                    color3[i] = 1;
                }
            }
        if(pos_x[3]>=-3.0){
            passo = 22;
            for(int i = 3; i<7; i++){
                if(i==3 || i==6){
                    color1[i] = 1;
                    color2[i] = 0;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_z[0]>0  && passo == 22){
        for(int i = 0; i<8; i++){
            pos_z[i] -=0.05;
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 0;
        }
         if(pos_z[0]<=0){
            passo = 23;
        }
    }
    if(pos_z[8]<2  && passo == 23){
        for(int i = 8; i<16; i++){
            pos_z[i] +=0.05;
            color1[i] = 1;
            color2[i] = 0;
            color3[i] = 0;
        }
         if(pos_z[8]>=2){
            passo = 24;
        }
    }

    if(pos_z[8]<4  && passo == 24){
        for(int i = 8; i<12; i++){
            pos_z[i] +=0.05;
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
         if(pos_z[8]>=4){
            passo = 25;
        }
    }
    if(pos_z[8]<6  && passo == 25){
        for(int i = 8; i<10; i++){
            pos_z[i] +=0.05;
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 1;
        }
         if(pos_z[8]>=6){
            passo = 26;
        }
    }
    if(pos_z[8]>4  && passo == 26){
        for(int i = 8; i<10; i++){
            pos_z[i] -=0.05;
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
         if(pos_z[8]<=4){
            passo = 27;
        }
    }
    if(pos_z[10]<6  && passo == 27){
        for(int i = 10; i<12; i++){
            pos_z[i] +=0.05;
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 1;
        }
         if(pos_z[10]>=6){
            passo = 28;
        }
    }
    if(pos_z[10]>4  && passo == 28){
        for(int i = 10; i<12; i++){
            pos_z[i] -=0.05;
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
         if(pos_z[10]<=4){
            passo = 29;
        }
    }
      if(pos_x[9]<2  && passo == 29){
            pos_x[9] += 0.02;
            pos_x[10] -= 0.02;
            for(int i = 9; i<11; i++){
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
            }
        if(pos_x[9]>=2){
            passo = 30;
            for(int i = 9; i<11; i++){
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 0;
            }
        }
    }
    if(pos_x[9]<3  && passo == 30){
            pos_x[9] += 0.02;
            pos_x[11] -= 0.02;
            for(int i = 9; i<12; i++){
                if(i==9 || i==11){
                    color1[i] = 1;
                    color2[i] = 1;
                    color3[i] = 1;
                }
            }
        if(pos_x[9]>=3){
            passo = 31;
            for(int i = 9; i<12; i++){
                if(i==9 || i==11){
                    color1[i] = 1;
                    color2[i] = 1;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_z[8]>2  && passo == 31){
        for(int i = 8; i<12; i++){
            pos_z[i] -=0.05;
            color1[i] = 1;
            color2[i] = 0;
            color3[i] = 0;
        }
         if(pos_z[8]<=2){
            passo = 32;
        }
    }
    if(pos_z[12]<4  && passo == 32){
        for(int i = 12; i<16; i++){
            pos_z[i] +=0.05;
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
         if(pos_z[12]>=4){
            passo = 33;
        }
    }
    if(pos_z[12]<6  && passo == 33){
        for(int i = 12; i<14; i++){
            pos_z[i] +=0.05;
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 1;
        }
         if(pos_z[12]>=6){
            passo = 34;
        }
    }
    if(pos_z[12]>4  && passo == 34){
        for(int i = 12; i<14; i++){
            pos_z[i] -=0.05;
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
         if(pos_z[12]<=4){
            passo = 35;
        }
    }
    if(pos_z[14]<6  && passo == 35){
        for(int i = 14; i<16; i++){
            pos_z[i] +=0.05;
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 1;
        }
         if(pos_z[14]>=6){
            passo = 36;
        }
    }
    if(pos_z[14]>4  && passo == 36){
        for(int i = 14; i<16; i++){
            pos_z[i] -=0.05;
            color1[i] = 1;
            color2[i] = 1;
            color3[i] = 0;
        }
         if(pos_z[14]<=4){
            passo = 37;
        }
    }
    if(pos_z[12]>2  && passo == 37){
        for(int i = 12; i<16; i++){
            pos_z[i] -=0.05;
            color1[i] = 1;
            color2[i] = 0;
            color3[i] = 0;
        }
         if(pos_z[12]<=2){
            passo = 38;
        }
    }
     if(pos_x[11]<4  && passo == 38){
            pos_x[11] += 0.02;
            pos_x[12] -= 0.02;
            for(int i = 11; i<13; i++){
                color1[i] = 1;
                color2[i] = 1;
                color3[i] = 1;
            }
        if(pos_x[11]>=4){
            passo = 39;
            for(int i = 11; i<13; i++){
                color1[i] = 1;
                color2[i] = 0;
                color3[i] = 0;
            }
        }
    }
    if(pos_x[9]<4  && passo == 39){
            pos_x[9] += 0.02;
            pos_x[11] -= 0.02;
            for(int i = 9; i<12; i++){
                if(i==9 || i==11){
                    color1[i] = 1;
                    color2[i] = 1;
                    color3[i] = 1;
                }
            }
        if(pos_x[9]>=4){
            passo = 40;
            for(int i = 9; i<12; i++){
                if(i==9 || i==11){
                    color1[i] = 1;
                    color2[i] = 0;
                    color3[i] = 0;
                }
            }
        }
    }
     if(pos_x[9]<5  && passo == 40){
            pos_x[9] += 0.02;
            pos_x[13] -= 0.02;
            for(int i = 9; i<14; i++){
                if(i==9 || i==13){
                    color1[i] = 1;
                    color2[i] = 1;
                    color3[i] = 1;
                }
            }
        if(pos_x[9]>=5){
            passo = 41;
            for(int i = 9; i<14; i++){
                if(i==9 || i==13){
                    color1[i] = 1;
                    color2[i] = 0;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_z[8]>0  && passo == 41){
        for(int i = 8; i<16; i++){
            pos_z[i] -=0.05;
            color1[i] = 0;
            color2[i] = 1;
            color3[i] = 0;
        }
         if(pos_z[8]<=0){
            passo = 42;
        }
    }
    if(pos_x[6]<0  && passo == 42){
            pos_x[6] += 0.02;
            pos_x[8] -= 0.02;
            for(int i = 6; i<9; i++){
                if(i==6 || i==8){
                    color1[i] = 1;
                    color2[i] = 1;
                    color3[i] = 1;
                }
            }
        if(pos_x[6]>=0){
            passo = 43;
            for(int i = 6; i<9; i++){
                if(i==6 || i==8){
                    color1[i] = 0;
                    color2[i] = 1;
                    color3[i] = 0;
                }
            }
        }
    }
     if(pos_x[0]<0  && passo == 43){
            pos_x[0] += 0.02;
            pos_x[6] -= 0.02;
            for(int i = 0; i<7; i++){
                if(i==0 || i==6){
                    color1[i] = 1;
                    color2[i] = 1;
                    color3[i] = 1;
                }
            }
        if(pos_x[0]>=0){
            passo = 44;
            for(int i = 0; i<7; i++){
                if(i==0 || i==6){
                    color1[i] = 0;
                    color2[i] = 1;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_x[3]<1  && passo == 44){
            pos_x[3] += 0.02;
            pos_x[10] -= 0.02;
            for(int i = 3; i<11; i++){
                if(i==3 || i==10){
                    color1[i] = 1;
                    color2[i] = 1;
                    color3[i] = 1;
                }
            }
        if(pos_x[3]>=1){
            passo = 45;
            for(int i = 3; i<11; i++){
                if(i==3 || i==10){
                    color1[i] = 0;
                    color2[i] = 1;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_x[5]<0  && passo == 45){
            pos_x[5] += 0.02;
            pos_x[0] -= 0.02;
            for(int i = 0; i<6; i++){
                if(i==0 || i==5){
                    color1[i] = 1;
                    color2[i] = 1;
                    color3[i] = 1;
                }
            }
        if(pos_x[5]>=0){
            passo = 46;
            for(int i = 0; i<6; i++){
                if(i==0 || i==5){
                    color1[i] = 0;
                    color2[i] = 1;
                    color3[i] = 0;
                }
            }
        }
    }
     if(pos_x[7]<1  && passo == 46){
            pos_x[7] += 0.02;
            pos_x[3] -= 0.02;
            for(int i = 3; i<8; i++){
                if(i==3 || i==7){
                    color1[i] = 1;
                    color2[i] = 1;
                    color3[i] = 1;
                }
            }
        if(pos_x[7]>=1){
            passo = 47;
            for(int i = 3; i<8; i++){
                if(i==3 || i==7){
                    color1[i] = 0;
                    color2[i] = 1;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_x[5]<2  && passo == 47){
            pos_x[5] += 0.02;
            pos_x[12] -= 0.02;
            for(int i = 5; i<13; i++){
                if(i==5 || i==12){
                    color1[i] = 1;
                    color2[i] = 1;
                    color3[i] = 1;
                }
            }
        if(pos_x[5]>=2){
            passo = 48;
            for(int i = 5; i<13; i++){
                if(i==5 || i==12){
                    color1[i] = 0;
                    color2[i] = 1;
                    color3[i] = 0;
                }
            }
        }
    }
      if(pos_x[7]<3  && passo == 48){
            pos_x[7] += 0.02;
            pos_x[11] -= 0.02;
            for(int i = 7; i<12; i++){
                if(i==7 || i==11){
                    color1[i] = 1;
                    color2[i] = 1;
                    color3[i] = 1;
                }
            }
        if(pos_x[7]>=3){
            passo = 49;
            for(int i = 7; i<12; i++){
                if(i==7 || i==11){
                    color1[i] = 0;
                    color2[i] = 1;
                    color3[i] = 0;
                }
            }
        }
    }
    if(pos_x[5]<4  && passo == 49){
            pos_x[5] += 0.02;
            pos_x[13] -= 0.02;
            for(int i = 5; i<14; i++){
                if(i==5 || i==13){
                    color1[i] = 1;
                    color2[i] = 1;
                    color3[i] = 1;
                }
            }
        if(pos_x[5]>=4){
            for(int i = 5; i<14; i++){
                if(i==5 || i==13){
                    color1[i] = 0;
                    color2[i] = 1;
                    color3[i] = 0;
                }
                passo=50;
            }
        }
    }

	glutPostRedisplay();
	glutTimerFunc(velocidade, Anima, 1);
}
/* Callback chamada quando o mouse é movido com
 * alguma tecla pressionada */

 static void key(unsigned char key, int x, int y)
{
    switch (key)
    {

        case 'q':
            exit(0);
            break;
        case '+': // aumentando a velocidade
            velocidade--;
            break;
        case '-': // diminuindo a velocidade
            velocidade++;
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
	/* Se o mouse é movido para a esquerda, rotationX é decrementado
	 * caso contrário, aumentado. Mesma ideia para rotationY */
	rotationX += (double)(x - last_press_x);
	rotationY += (double)(y - last_press_y);

	last_press_x = x;
	last_press_y = y;

	glutPostRedisplay();
}

/* Callback chamada quando uma tecla é pressionada ou liberada */
void Mouse_Press(int button, int state, int x, int y)
{
	if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
	{
		/* Pega a posição atua do mouse */
		last_press_x = x;
		last_press_y = y;
	}
}

void Janela(int opcao)
{
	switch(opcao){
		case 0:
			glShadeModel(GL_FLAT);		/* Modelo Flat */
		break;

		case 1:
			glShadeModel(GL_SMOOTH); 	/* Modelo Gouraud */
		break;
	}

	/* Necessário chamar toda vez que se faz uma alteração ou evento na janela
	 * Indica a funcao glutMainLoop a chamar glutDisplayFunc com as alterações */
	glutPostRedisplay();
}

void CriarMenu()
{
	/* Cria um menu cujas as opções serão gerenciadas pela funcao "Janela" */
	glutCreateMenu(Janela);

	/* Cria entradas nesse menu */
	glutAddMenuEntry("Modelo FLAT", 0);
	glutAddMenuEntry("Modelo Gouraud", 1);
	glutAddMenuEntry("Começar", 1);

	/* Indica qual o botao que acionará o menu */
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

/* Inicializa parâmetros de rendering */
void Inicializa (void)
{
    /* Define a cor de fundo da janela de visualização como branca */
    glClearColor(0.0f, 0.0f, 0.1f, 1.0f);

    /* Modo de projecao ortogonal (Default) */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-10, 10, -10, 10, -50, 50);
    gluPerspective(40.0f, ((GLfloat)LARGURA/(GLfloat)ALTURA), 1, 50.0f);

    /*************** Parâmetros de Iluminação ***************/
	/* Habilita o uso de iluminação */
        glEnable(GL_LIGHTING);
	/* Habilita a luz de número 0 */
	    glEnable(GL_LIGHT0);
	/* Habilita o depth-buffering para remoção de faces escondidas */
	    glEnable(GL_DEPTH_TEST);
	    glColorMaterial ( GL_FRONT_AND_BACK,GL_AMBIENT) ;
        glEnable(GL_COLOR_MATERIAL);
	/* Modelos de Iluminação Defaut */
	glShadeModel(GL_SMOOTH); 		/* Gouraud */
}

/* Programa Principal */
int main(int argc, char **argv)
{

    int j = -8;
     pos_x[0] = 0;
    for(int i = 0; i<16; i++){
        pos_x[i] = j;
        pos_z[i] = -4;
        color1[i] = 0;
        color2[i] = 1;
        color3[i] = 0;
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
	glutTimerFunc(100, Anima, 10);
	glutMainLoop();
}
