#include <glut/glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

static int angle1 = 0;
static int angle2 = 0;
static int angle3 = 0;
float vx = 0.0;
float vy = 0.0;
float vz = 20.0;
float sizex = 1.0;
float sizey = 1.0;
float sizez = 1.0;
float rotatex = 0;
float rotatey = 0;
float rotatez = 0;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void kure_ciz(void) { //robotun bas ve goz kismini gerceklestiren method.
	//bas
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0); //sari
	glTranslatef(0.0, 6.4, 0.0);
	glRotatef((GLfloat)angle3, 0.0, 0.0, 1.0);
	glutSolidSphere(1.5, 20, 8);
	glPopMatrix();
	//gozler
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0); //beyaz
	glTranslatef(0.5, 6.7, 0.0);
	glRotatef((GLfloat)angle3, 0.0, 0.0, 1.0);
	glutSolidSphere(0.3, 20, 8);
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0); //beyaz
	glTranslatef(-0.5, 6.7, 0.0);
	glRotatef((GLfloat)angle3, 0.0, 0.0, 1.0);
	glutSolidSphere(0.3, 20, 8);
	glPopMatrix();
}

void silindir_ciz(void) { //robotun boyun, govde, bacak ve omuz kisimlarini gerceklestiren method.
	//boyun
	glPushMatrix();
	GLUquadricObj* cylinder1 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder1, GLU_SILHOUETTE);
	glColor3f(1.0, 1.0, 1.0); //beyaz
	glTranslatef(0.0, 4.8, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glRotatef((GLfloat)angle3, 0.0, 0.0, 1.0);
	gluCylinder(cylinder1, 0.5, 0.5, 1.0, 12, 8);
	glPopMatrix();
	//govde
	glPushMatrix();
	GLUquadricObj* cylinder2 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder2, GLU_LINE);
	glColor3f(0.0, 0.0, 1.0); //mavi
	glTranslatef(0.0, 3.3, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluCylinder(cylinder2, 2.5, 2.5, 4, 12, 8);
	glPopMatrix();
	//bacaklar-dizustu
	glPushMatrix();
	GLUquadricObj* cylinder3 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder3, GLU_LINE);
	glColor3f(0.0, 1.0, 0.0); //yesil
	glTranslatef(1.0, -0.9, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluCylinder(cylinder3, 0.75, 0.75, 3, 12, 8);
	glPopMatrix();
	glPushMatrix();
	GLUquadricObj* cylinder4 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder4, GLU_LINE);
	glColor3f(0.0, 1.0, 0.0); //yesil
	glTranslatef(-1.0, -0.9, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluCylinder(cylinder4, 0.75, 0.75, 3, 12, 8);
	glPopMatrix();
	//bacaklar-dizalti
	glPushMatrix();
	GLUquadricObj* cylinder5 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder5, GLU_LINE);
	glColor3f(1.0, 1.0, 0.0); //sari
	glTranslatef(1.0, -4.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluCylinder(cylinder5, 0.75, 0.75, 3, 12, 8);
	glPopMatrix();
	glPushMatrix();
	GLUquadricObj* cylinder6 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder6, GLU_LINE);
	glColor3f(1.0, 1.0, 0.0); //sari
	glTranslatef(-1.0, -4.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluCylinder(cylinder6, 0.7, 0.7, 3, 12, 8);
	glPopMatrix();
	//omuzlar
	glPushMatrix();
	GLUquadricObj* cylinder7 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder7, GLU_SILHOUETTE);
	glColor3f(1.0, 1.0, 1.0); //beyaz
	glTranslatef(2.4, 3.0, 0.0);
	glRotatef(90.0, 1.0, 1.0, 1.0);
	gluCylinder(cylinder7, 0.3, 0.3, 0.8, 12, 8);
	glPopMatrix();
	glPushMatrix();
	GLUquadricObj* cylinder8 = gluNewQuadric();
	gluQuadricDrawStyle(cylinder8, GLU_SILHOUETTE);
	glColor3f(1.0, 1.0, 1.0); //beyaz
	glTranslatef(-3.2, 3.0, 0.0);
	glRotatef(90.0, 1.0, 1.0, 1.0);
	gluCylinder(cylinder8, 0.3, 0.3, 0.8, 12, 8);
	glPopMatrix();
}

void prizma_ciz(void) { //robotun kol kisimlarini gerceklestiren method.
	glPushMatrix();
	GLUquadricObj* prizma1 = gluNewQuadric();
	gluQuadricDrawStyle(prizma1, GLU_LINE);
	glColor3f(1.0, 0.0, 1.0); //mor
	glTranslatef(3.6, 3.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glRotatef((GLfloat)angle1, 1.0, 0.0, 0.0);
	gluCylinder(prizma1, 0.5, 0.5, 3.5, 4, 8);
	glPopMatrix();
	glPushMatrix();
	GLUquadricObj* prizma2 = gluNewQuadric();
	gluQuadricDrawStyle(prizma2, GLU_LINE);
	glColor3f(1.0, 0.0, 1.0); //mor
	glTranslatef(-3.6, 3.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glRotatef((GLfloat)angle2, 1.0, 0.0, 0.0);
	gluCylinder(prizma2, 0.5, 0.5, 3.5, 4, 8);
	glPopMatrix();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(vx, vy, vz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glScalef(sizex, sizey, sizez);
	glRotatef(rotatex, 1, 0, 0);
	glRotatef(rotatey, 0, 1, 0);
	glRotatef(rotatez, 0, 0, 1);
	kure_ciz();
	silindir_ciz();
	prizma_ciz();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1.333, 0, 100);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	//sol kol hareketini gerceklestiren case'ler
	case 'a':
		angle1 = (angle1 - 10) % 360;
		glutPostRedisplay();
		break;
	case 's':
		angle1 = (angle1 + 10) % 360;
		glutPostRedisplay();
		break;
	//sag kol hareketini gerceklestiren case'ler
	case 'q':
		angle2 = (angle2 - 10) % 360;
		glutPostRedisplay();
		break;
	case 'w':
		angle2 = (angle2 + 10) % 360;
		glutPostRedisplay();
		break;
	//robotu donduren case'ler
	case 'e':
		rotatey += 5;
		glutPostRedisplay();
		break;
	case 'r':
		rotatey -= 5;
		glutPostRedisplay();
		break;
	//robotun bas kismini donduren case'ler
	case 'd':
		angle3 = (angle3 + 10) % 360;
		glutPostRedisplay();
		break;
	case 'f':
		angle3 = (angle3 + 10) % 360;
		glutPostRedisplay();
		break;
	//kamerayi yakinlastirip uzaklastiran case'ler
	case 45: //+ tusu
		vz += 0.3;
		glutPostRedisplay();
		break;
	case 43: //- tusu
		vz -= 0.3;
		glutPostRedisplay();
		break;
	//robotu buyutup kuculten case'ler
	case 'b':
		sizex += 0.10;
		sizey += 0.10;
		sizez += 0.10;
		glutPostRedisplay();
		break;
	case 'k':
		sizex -= 0.10;
		sizey -= 0.10;
		sizez -= 0.10;
		glutPostRedisplay();
		break;
	//robotun konumunu belli eksenlerde degistiren case'ler
	case 'x':
		rotatex += 5;
		glutPostRedisplay();
		break;
	case 'z':
		rotatez += 5;
		glutPostRedisplay();
		break;
	}
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Project 2.3");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}