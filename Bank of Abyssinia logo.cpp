/*
Bank of Abyssinia logo - Toggleable Drop Shadow Edition
   Name ID
NATNAEL BIZUNEH ADMA/1311/24
ABREHAM DEMESSIE ADMA/1676/22
MULU ABEBE ADMA/1342/22
MERON HABTEMARIYAM ADMA/1239/22
BETHLEHEM TEKLU ADMA/1387/22
*/
// This block is a multi-line comment describing the program and crediting the authors

#include <GL/glut.h>                     // Includes the OpenGL Utility Toolkit header - provides window creation, input handling, and simple drawing functions
#include <cmath>                         // Includes math library for functions like cosf() and sinf() used in angle calculations
#include <cstdio>                        // Includes standard I/O library for printf() used in console output

const float PI = 3.14159265f;            // Defines a constant float value for p (pi) - used for converting degrees to radians

bool showShadow = true;                  // Global boolean flag - true = drop shadow is visible, false = hidden (toggled with 'S' key)

void display()                           // Main display callback function - GLUT calls this whenever the window needs to be redrawn
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Sets the background clear color to pure white (RGBA)
    glClear(GL_COLOR_BUFFER_BIT);        // Clears the color buffer, filling the window with the white background

    glMatrixMode(GL_PROJECTION);         // Switches to projection matrix mode (controls viewport and coordinate mapping)
    glLoadIdentity();                    // Resets the projection matrix to identity (clears previous transformations)
    gluOrtho2D(0.0, 300.0, 0.0, 200.0);  // Sets up 2D orthographic projection: logical coordinates from (0,0) bottom-left to (300,200) top-right

    glMatrixMode(GL_MODELVIEW);          // Switches back to modelview matrix mode (where we draw and transform objects)
    glLoadIdentity();                    // Resets the modelview matrix to identity

    // Enable blending for soft shadow transparency
    glEnable(GL_BLEND);                  // Turns on alpha blending for transparent/semi-transparent drawing
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Sets blending mode: source alpha controls opacity

    float cx = 150.0f;                   // X-coordinate of the star's center (half of window width 300)
    float cy = 115.0f;                   // Y-coordinate of the star's center (raised to leave space for text below)
    float r = 52.0f;                     // Radius - distance from center to the middle of each diamond arm

    // === REALISTIC DROP SHADOW (toggleable) ===
    if (showShadow) {                    // Only draw shadow if the flag is true
        glColor4f(0.0f, 0.0f, 0.0f, 0.25f); // Sets color to black with 25% opacity for soft shadow
        float shadowOffsetX = 6.0f;       // Horizontal offset for shadow (moves it right)
        float shadowOffsetY = -8.0f;      // Vertical offset for shadow (moves it down)

        glPushMatrix();                  // Saves current transformation matrix
        glTranslatef(shadowOffsetX, shadowOffsetY, 0.0f); // Applies offset to everything drawn inside this block

        // Draw all 6 diamonds exactly as the main logo but shifted for shadow effect
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

        glPopMatrix();                   // Restores matrix - ends shadow offset
    }

    // === MAIN LOGO (exact same as original) ===
    glColor3f(0.945f, 0.671f, 0.082f);    // Sets color to official Bank of Abyssinia orange

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
    glColor3f(0.0f, 0.0f, 0.0f);          // Sets text color to black
    glRasterPos2f(150.0f - 78.0f + 33.0f, 12.0f); // Sets position for text (centered with manual offset)
    const char* text = "Bank of Abyssinia"; // Pointer to the text string
    while (*text)                        // Loops through each character until null terminator
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text++); // Draws one character at a time using 24pt Times Roman font

    glDisable(GL_BLEND);                 // Disables blending after drawing (no longer needed)
    glFlush();                           // Forces all OpenGL commands to execute immediately (required for single buffering)
}

void keyboard(unsigned char key, int x, int y) // Keyboard callback function - called when a key is pressed
{
    if (key == 's' || key == 'S') {      // Checks if the pressed key is 's' or 'S'
        showShadow = !showShadow;        // Toggles the boolean value (true ? false or false ? true)
        glutPostRedisplay();             // Requests GLUT to redraw the window to reflect the change
    }
}

int main(int argc, char** argv)          // Program entry point
{
    glutInit(&argc, argv);               // Initializes GLUT with command-line arguments
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Sets display mode: single buffer + RGB color
    glutInitWindowSize(600, 400);        // Sets initial window size to 600x400 pixels
    glutCreateWindow("Bank of Abyssinia - Toggle Drop Shadow with S Key"); // Creates window with title
    glutDisplayFunc(display);            // Registers display() as the redraw function
    printf(" KEYBOARD:\n");              // Prints instructions to console
    printf(" s - Turn shadow ON\n");
    printf(" s - Turn shadow OFF\n");
    glutKeyboardFunc(keyboard);          // Registers keyboard() to handle key presses
    glutMainLoop();                      // Starts the GLUT event processing loop (program runs here forever)

    return 0;                            // Never reached - main loop runs indefinitely
}