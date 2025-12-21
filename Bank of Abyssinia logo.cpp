/*
Bank of Abyssinia logo - Toggleable Drop Shadow Edition
   Name ID
NATNAEL BIZUNEH ADMA/1311/24
ABREHAM DEMESSIE ADMA/1676/22
MULU ABEBE ADMA/1342/22
MERON HABTEMARIYAM ADMA/1239/22
BETHLEHEM TEKLU ADMA/1387/22
*/

#include <GL/glut.h>
#include <cmath>
#include <cstdio>  

const float PI = 3.14159265f;

bool showShadow = true; // Toggle for drop shadow (starts ON)

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 300.0, 0.0, 200.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Enable blending for soft shadow
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    float cx = 150.0f;
    float cy = 115.0f;
    float r = 52.0f;

    // === REALISTIC DROP SHADOW (toggleable) ===
    if (showShadow) {
        glColor4f(0.0f, 0.0f, 0.0f, 0.25f);  // 25% opacity black shadow

        float shadowOffsetX = 6.0f;
        float shadowOffsetY = -8.0f;

        glPushMatrix();
        glTranslatef(shadowOffsetX, shadowOffsetY, 0.0f);

        // Draw all 6 diamonds exactly as original for shadow
        glPushMatrix(); glTranslatef(cx + r, cy, 0.0f); glRotatef(90.0f,0,0,1);
        glBegin(GL_POLYGON);
            glVertex2f( 0.0f, 42.0f);
            glVertex2f( 22.0f, 0.0f);
            glVertex2f( 0.0f, -42.0f);
            glVertex2f(-22.0f, 0.0f);
        glEnd();
        glPopMatrix();

        glPushMatrix(); glTranslatef(cx + r*cosf(60*PI/180), cy + r*sinf(60*PI/180), 0.0f); glRotatef(150.0f,0,0,1);
        glBegin(GL_POLYGON);
            glVertex2f( 0.0f, 42.0f);
            glVertex2f( 22.0f, 0.0f);
            glVertex2f( 0.0f, -42.0f);
            glVertex2f(-22.0f, 0.0f);
        glEnd();
        glPopMatrix();

        glPushMatrix(); glTranslatef(cx + r*cosf(120*PI/180), cy + r*sinf(120*PI/180), 0.0f); glRotatef(210.0f,0,0,1);
        glBegin(GL_POLYGON);
            glVertex2f( 0.0f, 42.0f);
            glVertex2f( 22.0f, 0.0f);
            glVertex2f( 0.0f, -42.0f);
            glVertex2f(-22.0f, 0.0f);
        glEnd();
        glPopMatrix();

        glPushMatrix(); glTranslatef(cx - r, cy, 0.0f); glRotatef(270.0f,0,0,1);
        glBegin(GL_POLYGON);
            glVertex2f( 0.0f, 42.0f);
            glVertex2f( 22.0f, 0.0f);
            glVertex2f( 0.0f, -42.0f);
            glVertex2f(-22.0f, 0.0f);
        glEnd();
        glPopMatrix();

        glPushMatrix(); glTranslatef(cx + r*cosf(240*PI/180), cy + r*sinf(240*PI/180), 0.0f); glRotatef(330.0f,0,0,1);
        glBegin(GL_POLYGON);
            glVertex2f( 0.0f, 42.0f);
            glVertex2f( 22.0f, 0.0f);
            glVertex2f( 0.0f, -42.0f);
            glVertex2f(-22.0f, 0.0f);
        glEnd();
        glPopMatrix();

        glPushMatrix(); glTranslatef(cx + r*cosf(300*PI/180), cy + r*sinf(300*PI/180), 0.0f); glRotatef(30.0f,0,0,1);
        glBegin(GL_POLYGON);
            glVertex2f( 0.0f, 42.0f);
            glVertex2f( 22.0f, 0.0f);
            glVertex2f( 0.0f, -42.0f);
            glVertex2f(-22.0f, 0.0f);
        glEnd();
        glPopMatrix();

        glPopMatrix();
    }

    // === MAIN LOGO (exact same as your original) ===
    glColor3f(0.945f, 0.671f, 0.082f); // Official Bank of Abyssinia orange

    glPushMatrix(); glTranslatef(cx + r, cy, 0.0f); glRotatef(90.0f,0,0,1);
    glBegin(GL_POLYGON);
        glVertex2f( 0.0f, 42.0f);
        glVertex2f( 22.0f, 0.0f);
        glVertex2f( 0.0f, -42.0f);
        glVertex2f(-22.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix(); glTranslatef(cx + r*cosf(60*PI/180), cy + r*sinf(60*PI/180), 0.0f); glRotatef(150.0f,0,0,1);
    glBegin(GL_POLYGON);
        glVertex2f( 0.0f, 42.0f);
        glVertex2f( 22.0f, 0.0f);
        glVertex2f( 0.0f, -42.0f);
        glVertex2f(-22.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix(); glTranslatef(cx + r*cosf(120*PI/180), cy + r*sinf(120*PI/180), 0.0f); glRotatef(210.0f,0,0,1);
    glBegin(GL_POLYGON);
        glVertex2f( 0.0f, 42.0f);
        glVertex2f( 22.0f, 0.0f);
        glVertex2f( 0.0f, -42.0f);
        glVertex2f(-22.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix(); glTranslatef(cx - r, cy, 0.0f); glRotatef(270.0f,0,0,1);
    glBegin(GL_POLYGON);
        glVertex2f( 0.0f, 42.0f);
        glVertex2f( 22.0f, 0.0f);
        glVertex2f( 0.0f, -42.0f);
        glVertex2f(-22.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix(); glTranslatef(cx + r*cosf(240*PI/180), cy + r*sinf(240*PI/180), 0.0f); glRotatef(330.0f,0,0,1);
    glBegin(GL_POLYGON);
        glVertex2f( 0.0f, 42.0f);
        glVertex2f( 22.0f, 0.0f);
        glVertex2f( 0.0f, -42.0f);
        glVertex2f(-22.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix(); glTranslatef(cx + r*cosf(300*PI/180), cy + r*sinf(300*PI/180), 0.0f); glRotatef(30.0f,0,0,1);
    glBegin(GL_POLYGON);
        glVertex2f( 0.0f, 42.0f);
        glVertex2f( 22.0f, 0.0f);
        glVertex2f( 0.0f, -42.0f);
        glVertex2f(-22.0f, 0.0f);
    glEnd();
    glPopMatrix();

    // === TEXT ===
    glColor3f(0.0f, 0.0f, 0.0f);
    glRasterPos2f(150.0f - 78.0f + 33.0f, 12.0f);
    const char* text = "Bank of Abyssinia";
    while (*text)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text++);

    glDisable(GL_BLEND);
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 's' || key == 'S') { // Press 'S' to toggle shadow on/off
        showShadow = !showShadow;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Bank of Abyssinia - Toggle Drop Shadow with S Key");
    glutDisplayFunc(display);
     printf("  KEYBOARD:\n");
    printf("    s - Turn shadow ON\n");
    printf("    s - Turn shadow OFF\n");
    glutKeyboardFunc(keyboard); // Register keyboard callback for 'S' key
    glutMainLoop();
    
    return 0;
}