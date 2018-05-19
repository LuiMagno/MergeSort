/* Código para exemplificar
o uso de iluminação no OpenGL */

#include <GL/glut.h>

#define LARGURA  600		/* Width */
#define ALTURA   600		/* Heigth */

double rotationX = 20.0;
double rotationY = 20.0;

int last_press_x = 0;
int last_press_y = 0;
double pos_xu, vetor [16];
int pos_x = 0;
int passo = 1;
int pos_y = 0;
float pos_z = 0;
float pos_z2 = 0;
float pos_z3 = 0;
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

void Desenha_Face_Superior_Cubo()
{
	float lado_cubo = 5;
	glNormal3f(0.0, 1.0, 0.0); /* Normal da Face */
	glBegin(GL_POLYGON);
		glVertex3d(lado_cubo/2, lado_cubo, lado_cubo/2);
		glVertex3d(-lado_cubo/2, lado_cubo, lado_cubo/2);
		glVertex3d(-lado_cubo/2, lado_cubo, -lado_cubo/2);
		glVertex3d(lado_cubo/2, lado_cubo,-lado_cubo/2);
	glEnd();
}

void ParametrosIluminacao()
{
	/* Parâmetros para a Luz GL_LIGHT0 sendo uma fonte de Luz Pontual */
	GLfloat luzAmbiente[4]={0.0, 0.0, 1.0, 1.0};	/* cor azul */
	GLfloat luzDifusa[4]={1.0, 1.0, 1.0, 1.0};	  	/* cor branca */
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0}; 	/* cor branca - brilho */
	GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};	/* Fonte de Luz Pontual */

	/* Define os parâmetros da luz de número 0 (Luz Pontual) */
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	/* Ativa o uso de uma fonte de luz ambiente */
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	/* Características do material */
	GLfloat ka[4]={0.11, 0.06, 0.11, 1.0};		/* Reflete porcentagens da cor ambiente */
	GLfloat kd[4]={0.4, 0.4, 0.7, 1.0};		/* Reflete porcentagens da cor difusa */
	GLfloat ks[4]={1.0, 1.0, 1.0, 1.0};		/* Reflete porcentagens da cor especular */
	GLfloat shininess = 60.0;

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ka);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, kd);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ks); /* Refletância do material */
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);   /* Concentração do brilho */
}
void Desenha_Barra(void){
    glBegin(GL_QUADS);        // Draw The Cube Using quads
            glColor3f(0.0f,1.0f,0.0f);    // Color Blue
            glVertex3f( 0.5f, 0.5f,-0.5f);    // Top Right Of The Quad (Top)
            glVertex3f(-0.5f, 0.5f,-0.5f);    // Top Left Of The Quad (Top)
            glVertex3f(-0.5f, 0.5f, 0.5f);    // Bottom Left Of The Quad (Top)
            glVertex3f( 0.5f, 0.5f, 0.5f);    // Bottom Right Of The Quad (Top)
            glColor3f(1.0f,0.5f,0.0f);    // Color Orange
            glVertex3f( 0.5f,-0.5f, 0.5f);    // Top Right Of The Quad (Bottom)
            glVertex3f(-0.5f,-0.5f, 0.5f);    // Top Left Of The Quad (Bottom)
            glVertex3f(-0.5f,-0.5f,-0.5f);    // Bottom Left Of The Quad (Bottom)
            glVertex3f( 0.5f,-0.5f,-0.5f);    // Bottom Right Of The Quad (Bottom)
            glColor3f(1.0f,0.0f,0.0f);    // Color Red
            glVertex3f( 0.5, 0.5, 0.5);    // Top Right Of The Quad (Front)
            glVertex3f(-0.5, 0.5, 0.5);    // Top Left Of The Quad (Front)
            glVertex3f(-0.5,-0.5, 0.5);    // Bottom Left Of The Quad (Front)
            glVertex3f( 0.5,-0.5, 0.5);    // Bottom Right Of The Quad (Front)
            glColor3f(1.0f,1.0f,0.0f);    // Color Yellow
            glVertex3f( 0.5f,-0.5f,-0.5f);    // Top Right Of The Quad (Back)
            glVertex3f(-0.5f,-0.5f,-0.5f);    // Top Left Of The Quad (Back)
            glVertex3f(-0.5f, 0.5f,-0.5f);    // Bottom Left Of The Quad (Back)
            glVertex3f( 0.5f, 0.5f,-0.5f);    // Bottom Right Of The Quad (Back)
            glColor3f(0.0f,0.0f,1.0f);    // Color Blue
            glVertex3f(-0.5f, 0.5f, 0.5f);    // Top Right Of The Quad (Left)
            glVertex3f(-0.5f, 0.5f,-0.5f);    // Top Left Of The Quad (Left)
            glVertex3f(-0.5f,-0.5f,-0.5f);    // Bottom Left Of The Quad (Left)
            glVertex3f(-0.5f,-0.5f, 0.5f);    // Bottom Right Of The Quad (Left)
            glColor3f(1.0f,0.0f,1.0f);    // Color Violet
            glVertex3f( 0.5f, 0.5f,-0.5f);    // Top Right Of The Quad (Right)
            glVertex3f( 0.5f, 0.5f, 0.5f);    // Top Left Of The Quad (Right)
            glVertex3f( 0.5f,-0.5f, 0.5f);    // Bottom Left Of The Quad (Right)
            glVertex3f( 0.5f,-0.5f,-0.5f);    // Bottom Right Of The Quad (Right)
    glEnd();            // End Drawing The Cube

}
/* Função callback chamada para fazer o desenho */
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
    gluLookAt(0.0, 0.0, 40.0,		/* eye */
    		  0.0, 0.0, -30.0,		/* look */
    		  0.0, 1.0, 0.0);		/* up */

    ParametrosIluminacao();

    /* Rotaciona os objetos para visualizar a 3 dimensão */
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

	glPushMatrix();
        glTranslatef(0, 0.5, 0.0);
        Desenha_Barra(); // Barra 1
	glPopMatrix();

	glPushMatrix();
        glScalef(1.0, 6.0, 1.0);
        glTranslatef(1.5, 0.5, 0.0);
        Desenha_Barra(); // Barra 2
    glPopMatrix();

    glPushMatrix();
        glScalef(1.0, 5.0, 1.0);
        glTranslatef(3.0, 0.5, 0.0);
        Desenha_Barra(); // Barra 3
    glPopMatrix();

     glPushMatrix();
        glScalef(1.0, 8.0, 1.0);
        glTranslatef(4.5, 0.5, 0.0);
        Desenha_Barra(); // Barra 4
    glPopMatrix();

     glPushMatrix();
        glScalef(1.0, 3.0, 1.0);
        glTranslatef(6.0, 0.5, 0.0);
        Desenha_Barra(); // Barra 5
    glPopMatrix();

     glPushMatrix();
        glScalef(1.0, 2.0, 1.0);
        glTranslatef(7.5, 0.5, 0.0);
        Desenha_Barra(); // Barra 6
    glPopMatrix();

     glPushMatrix();
        glScalef(1.0, 2.0, 1.0);
        glTranslatef(9.0, 0.5, 0.0);
        Desenha_Barra(); // Barra 7
    glPopMatrix();

     glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        glTranslatef(10.5, 0.5, 0.0);
        Desenha_Barra(); // Barra 8
    glPopMatrix();
///////////////////////////////////////////////////////////////////////////////////////////////////////
    glPushMatrix();
        glScalef(1.0, 10.0, 1.0);
        glTranslatef(-1.5, 0.5, 0.0);
        Desenha_Barra(); // Barra 9
    glPopMatrix();

    glPushMatrix();
        glScalef(1.0, 5.0, 1.0);
        glTranslatef(-3.0, 0.5, 0.0);
        Desenha_Barra(); // Barra 10
    glPopMatrix();


    glPushMatrix();
    glTranslatef(pos_x, pos_y, pos_z3);
        glScalef(1.0, 10.0, 1.0);
        glTranslatef(-4.5, 0.5, 0.0);
        Desenha_Barra(); // Barra 11
    glPopMatrix();

    glPushMatrix();
        glScalef(1.0, 3.0, 1.0);
        glTranslatef(-6.0, 0.5, 0.0);
        Desenha_Barra(); // Barra 12
    glPopMatrix();

    glPushMatrix();
        glScalef(1.0, 7.0, 1.0);
        glTranslatef(-7.5, 0.5, 0.0);
        Desenha_Barra(); // Barra 13
    glPopMatrix();

    glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        glTranslatef(-9.0, 0.5, 0.0);
        Desenha_Barra(); // Barra 14
    glPopMatrix();


    glPushMatrix();
    glTranslatef(pos_x, pos_y, pos_z2);
        glScalef(1.0, 4.0, 1.0);
        glTranslatef(-10.5, 0.5, 0.0);
        Desenha_Barra(); // Barra 15
    glPopMatrix();


    glPushMatrix();
    glTranslatef(pos_x, pos_y, pos_z);
        glScalef(1.0, 6.0, 1.0);
        glTranslatef(-12.0, 0.5, 0.0);
        Desenha_Barra(); // Barra 16
    glPopMatrix();
	/* Executa os comandos OpenGL */
	glFlush();
}
void Anima(int value)  /* Usada quando se usar glutTimerFunc() */
{
   if(pos_z<5 && pos_z2<5 && pos_z3<5){
    pos_z = pos_z + 0.1;
    pos_z2 = pos_z2 + 0.1;
    pos_z3 = pos_z3 + 0.1;
}

	glutPostRedisplay();
	glutTimerFunc(20, Anima, 1);
}
/* Callback chamada quando o mouse é movido com
 * alguma tecla pressionada */
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

	/* Indica qual o botao que acionará o menu */
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

/* Inicializa parâmetros de rendering */
void Inicializa (void)
{
    /* Define a cor de fundo da janela de visualização como branca */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    /* Modo de projecao ortogonal (Default) */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-10, 10, -10, 10, -50, 50);
    gluPerspective(40.0f, ((GLfloat)LARGURA/(GLfloat)ALTURA), 1, 50.0f);

    /*************** Parâmetros de Iluminação ***************/
	/* Habilita o uso de iluminação */
      //  glEnable(GL_LIGHTING);
	/* Habilita a luz de número 0 */
	 //   glEnable(GL_LIGHT0);
	/* Habilita o depth-buffering para remoção de faces escondidas */
	    glEnable(GL_DEPTH_TEST);

	/* Modelos de Iluminação Defaut */
	//glShadeModel(GL_SMOOTH); 		/* Gouraud */
}

/* Programa Principal */
int main(int argc, char **argv)
{
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
	glutTimerFunc(100, Anima, 1);
	glutMainLoop();
}
