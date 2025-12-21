/*
			Bank of Abyssinia logo

   Name 								ID
NATNAEL BIZUNEH						ADMA/1311/24
ABREHAM DEMESSIE					ADMA/1676/22
MULU ABEBE							ADMA/1342/22
MERON HABTEMARIYAM					ADMA/1239/22
BETHLEHEM TEKLU						ADMA/1387/22
*/



#include <GL/glut.h>      // Include the OpenGL Utility Toolkit (GLUT) - the official 1996 header by Mark Kilgard
#include <cmath>          // For cosf(), sinf() - we use the float versions for speed and precision

const float PI = 3.14159265f;  // Define PI as a constant float - used for angle calculations in radians

void display()  // This is the main display callback function - GLUT calls this whenever the window needs redrawing
{
    // Set the clear color to pure white (R=1.0, G=1.0, B=1.0, Alpha=1.0)
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    // Actually clear the color buffer with the white background
    glClear(GL_COLOR_BUFFER_BIT);

    // Switch to the projection matrix (controls how 3D world maps to 2D screen)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  // Reset the projection matrix to identity

    // Set up a perfect 2D orthographic view: 
    // Left=0, Right=300, Bottom=0, Top=200 ? matches our logical coordinate system
    gluOrtho2D(0.0, 300.0, 0.0, 200.0);

    // Switch back to modelview matrix (where we do all object transformations)
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();  // Reset modelview matrix - start from clean slate

    // Define the center of the star logo
    float cx = 150.0f;   // X center of the window (300/2)
    float cy = 115.0f;   // Y center raised slightly to leave room for text below
    float r  = 52.0f;    // Radius - distance from center to the center of each diamond

    // Set the drawing color to orange (#F1AB15 - Bank of Abyssinia's official color)
    glColor3f(0.945f, 0.671f, 0.082f);  // Parameters: Red=0.945, Green=0.671, Blue=0.082

    // === DIAMOND 1 - 0 degrees (points right) ===
    glPushMatrix();                                      // Save current matrix (so we don't affect other diamonds)
    glTranslatef(cx + r, cy, 0.0f);                      // Move to the right arm position
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);                  // Rotate 90� so the diamond points outward (right)
    glBegin(GL_POLYGON);                                 // Start drawing a filled polygon
        glVertex2f(  0.0f,  42.0f);                      // Top tip of diamond
        glVertex2f( 22.0f,   0.0f);                      // Right point
        glVertex2f(  0.0f, -42.0f);                      // Bottom tip
        glVertex2f(-22.0f,   0.0f);                      // Left point
    glEnd();                                             // Finish the polygon
    glPopMatrix();                                       // Restore matrix - this diamond is done

    // === DIAMOND 2 - 60 degrees ===
    glPushMatrix();
    glTranslatef(cx + r*cosf(60.0f*PI/180.0f), cy + r*sinf(60.0f*PI/180.0f), 0.0f);  // Position using polar coordinates
    glRotatef(150.0f, 0.0f, 0.0f, 1.0f);                 // Rotate so diamond points outward at 60�
    glBegin(GL_POLYGON);
        glVertex2f(  0.0f,  42.0f);
        glVertex2f( 22.0f,   0.0f);
        glVertex2f(  0.0f, -42.0f);
        glVertex2f(-22.0f,   0.0f);
    glEnd();
    glPopMatrix();

    // === DIAMOND 3 - 120 degrees ===
    glPushMatrix();
    glTranslatef(cx + r*cosf(120.0f*PI/180.0f), cy + r*sinf(120.0f*PI/180.0f), 0.0f);
    glRotatef(210.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2f(  0.0f,  42.0f);
        glVertex2f( 22.0f,   0.0f);
        glVertex2f(  0.0f, -42.0f);
        glVertex2f(-22.0f,   0.0f);
    glEnd();
    glPopMatrix();

    // === DIAMOND 4 - 180 degrees (points left) ===
    glPushMatrix();
    glTranslatef(cx - r, cy, 0.0f);                      // Simple left position
    glRotatef(270.0f, 0.0f, 0.0f, 1.0f);                 // Point straight left
    glBegin(GL_POLYGON);
        glVertex2f(  0.0f,  42.0f);
        glVertex2f( 22.0f,   0.0f);
        glVertex2f(  0.0f, -42.0f);
        glVertex2f(-22.0f,   0.0f);
    glEnd();
    glPopMatrix();

    // === DIAMOND 5 - 240 degrees ===
    glPushMatrix();
    glTranslatef(cx + r*cosf(240.0f*PI/180.0f), cy + r*sinf(240.0f*PI/180.0f), 0.0f);
    glRotatef(330.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2f(  0.0f,  42.0f);
        glVertex2f( 22.0f,   0.0f);
        glVertex2f(  0.0f, -42.0f);
        glVertex2f(-22.0f,   0.0f);
    glEnd();
    glPopMatrix();

    // === DIAMOND 6 - 300 degrees ===
    glPushMatrix();
    glTranslatef(cx + r*cosf(300.0f*PI/180.0f), cy + r*sinf(300.0f*PI/180.0f), 0.0f);
    glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2f(  0.0f,  42.0f);
        glVertex2f( 22.0f,   0.0f);
        glVertex2f(  0.0f, -42.0f);
        glVertex2f(-22.0f,   0.0f);
    glEnd();
    glPopMatrix();

    // === TEXT: "Bank of Abyssinia" ===
    glColor3f(0.0f, 0.0f, 0.0f);                         // Set color to black for text
    // Position: X = center - half text width + 33px offset (your final adjustment)
    // Y = 12.0 ? low on screen, close to bottom edge
    glRasterPos2f(150.0f - 78.0f + 33.0f, 12.0f);        
    const char* text = "Bank of Abyssinia";              // The string to display
    while (*text)                                        // Loop through each character until null terminator
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text++);  // Draw one letter at a time

    // Send all drawing commands to the screen (required when using GLUT_SINGLE buffer)
    glFlush();
}

// === MAIN FUNCTION - program starts here ===
int main(int argc, char** argv)
{
    glutInit(&argc, argv);                               // Initialize GLUT - must be first call
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);         // Use single buffer + RGB color mode (classic 1996 style)
    glutInitWindowSize(600, 400);                        // Set window size in pixels (2:1 ratio ? maps perfectly to 300�200 units)
    glutCreateWindow("Bank of Abyssinia - Pure 1996 GLUT, Final Touch");  // Create window with title
    glutDisplayFunc(display);                            // Register our display() function - GLUT will call it to draw
    glutMainLoop();                                      // Enter the infinite event processing loop - program runs forever
    return 0;                                            // Never actually reached
}