/* C�digo para exemplificar
o uso de ilumina��o no OpenGL */

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


int passo = 1;


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
	/* Par�metros para a Luz GL_LIGHT0 sendo uma fonte de Luz Pontual */
	GLfloat luzAmbiente[4]={0.0, 0.0, 1.0, 1.0};	/* cor azul */
	GLfloat luzDifusa[4]={1.0, 1.0, 1.0, 1.0};	  	/* cor branca */
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0}; 	/* cor branca - brilho */
	GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};	/* Fonte de Luz Pontual */

	/* Define os par�metros da luz de n�mero 0 (Luz Pontual) */
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	/* Ativa o uso de uma fonte de luz ambiente */
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	/* Caracter�sticas do material */
	GLfloat ka[4]={0.11, 0.06, 0.11, 1.0};		/* Reflete porcentagens da cor ambiente */
	GLfloat kd[4]={0.4, 0.4, 0.7, 1.0};		/* Reflete porcentagens da cor difusa */
	GLfloat ks[4]={1.0, 1.0, 1.0, 1.0};		/* Reflete porcentagens da cor especular */
	GLfloat shininess = 60.0;

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ka);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, kd);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ks); /* Reflet�ncia do material */
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);   /* Concentra��o do brilho */
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
/* Fun��o callback chamada para fazer o desenho */
void Desenha_Plano(void){
 glBegin(GL_QUADS);
   glColor3f(0.0f,0.0f,0.2f);    // Color Orange
        glVertex3f(30.0f, 0.0f, 30.0f);    // Top Right Of The Quad (Bottom)
        glVertex3f(-30.0f, 0.0f, 30.0f);    // Top Left Of The Quad (Bottom)
        glVertex3f(-30.0f,0.0f,-30.0f);    // Bottom Left Of The Quad (Bottom)
        glVertex3f( 30.0f,0.0f,-30.0f);    // Bottom Right Of The Quad (Bottom)
  glEnd();



}
void Desenha(void)
{
	/* Limpa a janela de visualiza��o com a cor de fundo especificada */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    /* Especifica uma C�mera com:
     * olho = (0, 0, 30)
     * olhar = (0, 0, 0)
     * up = (0, 1, 0) */
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 40.0,		/* eye */
    		  0.0, 0.0, -30.0,		/* look */
    		  0.0, 1.0, 0.0);		/* up */

    ParametrosIluminacao();

    /* Rotaciona os objetos para visualizar a 3 dimens�o */
	glRotatef(rotationY, 1.0, 0.0, 0.0); /* Rotaciona em torno do X */
	glRotatef(rotationX, 0.0, 1.0, 0.0); /* Rotaciona em torno de Y */

	Desenha_Origem();
	Desenha_Eixos_Coordenados();

	//glColor3f(1.0, 0.0, 0.0);
	//Desenha_Face_Superior_Cubo();
    //glutSolidCube(4);
	//glutSolidSphere(4, 50, 50);
	//glutSolidTeapot(4);
	//glutSolidTorus(1, 4, 20, 20);
    Desenha_Plano();

    glPushMatrix();
        glScalef(1.0, 6.0, 1.0);
        glTranslatef(pos_x[0], 0.2, pos_z[0]);
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
            color1[i] = 1;
            color2[i] = 0;
            color3[i] = 1;
        }

        if(pos_z[0] >= 6){
            passo = 5;
        }
    }


    if(pos_x[0]<-7.0 && passo == 5){
            pos_x[0] += 0.02;
            pos_x[1] -= 0.02;
        if(pos_x[0]>=-7){
            passo = 6;
        }
    }

    if(pos_z[0]>4 && passo == 6){
        pos_z[0] -= 0.05;
        pos_z[1] -= 0.05;
        if(pos_z[0]<=4){
            passo = 7;
        }
    }

    if(pos_z[2]<6 && passo == 7){
        for(int i = 2; i<4; i++){
            pos_z[i] +=0.05;
        }
        if(pos_z[2] >= 6){
            passo = 8;
        }
    }
    if(pos_z[2]>4 && passo == 8){
        pos_z[2] -= 0.05;
        pos_z[3] -= 0.05;
        if(pos_z[2]<=4){
            passo = 9;
        }
    }
    if(pos_x[1]<-6.0  && passo == 9){
            pos_x[1] += 0.02;
            pos_x[2] -= 0.02;
        if(pos_x[1]>=-6.0){
            passo = 10;
        }
    }

    if(pos_x[0]<-6.0  && passo == 10){
            pos_x[0] += 0.02;
            pos_x[1] -= 0.02;
        if(pos_x[0]>=-6.0){
            passo = 11;
        }
    }

    if(pos_z[0]>2.0 && passo == 11){
         for(int i = 0; i<4; i++){
            pos_z[i] -=0.05;
        }
        if(pos_z[0]<= 2){
            passo = 12;
        }
    }
    if(pos_z[4]<4.0 && passo == 12){
         for(int i = 4; i<8; i++){
            pos_z[i] +=0.05;
        }
        if(pos_z[4]>= 4){
            passo = 13;
        }
    }

    if(pos_z[4]<6.0 && passo == 13){
         pos_z[4] +=0.05;
         pos_z[5] +=0.05;

        if(pos_z[4]>= 6){
            passo = 14;
        }
    }

    if(pos_z[4]>4.0 && passo == 14){
         pos_z[4] -=0.05;
         pos_z[5] -=0.05;

        if(pos_z[4]<=4){
            passo = 15;
        }
    }

    if(pos_z[6]<6.0 && passo == 15){
         pos_z[6] +=0.05;
         pos_z[7] +=0.05;

        if(pos_z[6]>=6){
            passo = 16;
        }
    }

    if(pos_z[6]>4.0 && passo == 16){
         pos_z[6] -=0.05;
         pos_z[7] -=0.05;

        if(pos_z[6]<=4){
            passo = 17;
        }
    }
    if(pos_x[5]<-2.0  && passo == 17){
            pos_x[5] += 0.02;
            pos_x[6] -= 0.02;
        if(pos_x[5]>=-2.0){
            passo = 18;
        }
    }
    if(pos_z[4]>2.0 && passo == 18){
         for(int i = 4; i<8; i++){
            pos_z[i] -=0.05;
        }
        if(pos_z[4]<= 2){
            passo = 19;
        }
    }

    if(pos_x[1]<-4.0  && passo == 19){
            pos_x[1] += 0.02;
            pos_x[4] -= 0.02;
        if(pos_x[1]>=-4.0){
            passo = 20;
        }
    }
    if(pos_x[0]<-4.0  && passo == 20){
            pos_x[0] += 0.02;
            pos_x[1] -= 0.02;
        if(pos_x[0]>=-4.0){
            passo = 21;
        }
    }
    if(pos_x[3]<-3.0  && passo == 21){
            pos_x[3] += 0.02;
            pos_x[6] -= 0.02;
        if(pos_x[3]>=-3.0){
            passo = 22;
        }
    }
    if(pos_z[0]>0  && passo == 22){
        for(int i = 0; i<8; i++){
            pos_z[i] -=0.05;
        }
         if(pos_x[0]>=0){
            passo = 23;
        }
    }

	glutPostRedisplay();
	glutTimerFunc(30, Anima, 1);
}
/* Callback chamada quando o mouse � movido com
 * alguma tecla pressionada */
void Mouse_Motion(int x, int y)
{
	/* Se o mouse � movido para a esquerda, rotationX � decrementado
	 * caso contr�rio, aumentado. Mesma ideia para rotationY */
	rotationX += (double)(x - last_press_x);
	rotationY += (double)(y - last_press_y);

	last_press_x = x;
	last_press_y = y;

	glutPostRedisplay();
}

/* Callback chamada quando uma tecla � pressionada ou liberada */
void Mouse_Press(int button, int state, int x, int y)
{
	if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
	{
		/* Pega a posi��o atua do mouse */
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

	/* Necess�rio chamar toda vez que se faz uma altera��o ou evento na janela
	 * Indica a funcao glutMainLoop a chamar glutDisplayFunc com as altera��es */
	glutPostRedisplay();
}

void CriarMenu()
{
	/* Cria um menu cujas as op��es ser�o gerenciadas pela funcao "Janela" */
	glutCreateMenu(Janela);

	/* Cria entradas nesse menu */
	glutAddMenuEntry("Modelo FLAT", 0);
	glutAddMenuEntry("Modelo Gouraud", 1);

	/* Indica qual o botao que acionar� o menu */
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

/* Inicializa par�metros de rendering */
void Inicializa (void)
{
    /* Define a cor de fundo da janela de visualiza��o como branca */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    /* Modo de projecao ortogonal (Default) */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-10, 10, -10, 10, -50, 50);
    gluPerspective(40.0f, ((GLfloat)LARGURA/(GLfloat)ALTURA), 1, 50.0f);

    /*************** Par�metros de Ilumina��o ***************/
	/* Habilita o uso de ilumina��o */
      //  glEnable(GL_LIGHTING);
	/* Habilita a luz de n�mero 0 */
	 //   glEnable(GL_LIGHT0);
	/* Habilita o depth-buffering para remo��o de faces escondidas */
	    glEnable(GL_DEPTH_TEST);

	/* Modelos de Ilumina��o Defaut */
	//glShadeModel(GL_SMOOTH); 		/* Gouraud */
}

/* Programa Principal */
int main(int argc, char **argv)
{

    int j = -8;
     pos_x[0] = 0;
    for(int i = 0; i<16; i++){
        pos_x[i] = j;
        pos_z[i] = -4;
        color1[i] = 0.8;
        color2[i] = 0.8;
        color3[i] = 0.8;
        j++;
    }

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Iluminacao");
	glutDisplayFunc(Desenha);
	glutMouseFunc(Mouse_Press);
	glutMotionFunc(Mouse_Motion);
	Inicializa();
	CriarMenu();
	glutTimerFunc(100, Anima, 10);
	glutMainLoop();
}
