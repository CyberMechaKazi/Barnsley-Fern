//Name: Kazi Islam

#include <string.h>  // This library handling functions related to string.
#ifdef __APPLE__  // This library Check if compiling on Apple system.
#include <GLUT/glut.h> // This library is OpenGL Utility Toolkit specially for macOS.
#else
#include <GL/glut.h> // This library is OpenGL Utility Toolkit specially for Windows/Linux.
#endif

#include <stdlib.h> // Standard library header (needed for rand(), srand(), exit(), and general utilities)
/* GLUT callback Handlers */

// Declare global variables.
float x1, y1,x,y,a,b,c,d,e,f; // Variables used for fractal calculations.
int n=200000; // Number of points to draw in iterations.
int num =0;  // Random number selector for choosing transformation.

// Function to resize the window and keep aspect ratio square.
void resize(int width, int height)
{ 
    if(width<=height) // the window’s width smaller than or equal to the window’s height the do bellow.
        // If I am here means window is taller, then center the drawing vertically.
        glViewport(0,(GLsizei) (height-width)/2,(GLsizei) width,(GLsizei) width);

    else
    // If I am here means window is wider, then center the drawing horizontally
        glViewport((GLsizei) (width-height)/2 ,0 ,(GLsizei) height,(GLsizei) height);
}

// Initialization function called once at the start.
void init()
{
    x=1; // Initial x starting point.
    y=1; // Initial y starting point.
 glMatrixMode(GL_PROJECTION); // This set projection matrix.
 glLoadIdentity(); // This reset projection matrix.
 glOrtho(-2.5,2.75,10.5,0, -1.0, 1.0); // this  adjusted for suitable viewport 2D.

}

// This function display the fractal
void display(void)
{
  glClear (GL_COLOR_BUFFER_BIT);
  glColor3f(0,1,0);
    // clear display screen
    // your code here
    // Loop to generate n points 200000 iterations.
  for (int i=0; i<n; i++)
  {
      num = rand()% 100;  // here system pick random number from 0–99.
       // Choose which transformation to apply.

      if (num ==0) //if  1% chance then do things bellow.
      {
          a=0; b=0; c=0; d=0.16; e=0; f=0; // Stem transformation (1% chance): creates the thin base of the fern
      }
      else if  (num<=7) //if  7% chance then do things bellow.
        {
        a= 0.2;b =0.23;c =-0.2; d =0.22;e =0;f=1.6; // Side leaflet transformation (7% chance): creates small leaves branching off the stem
      }
      else if(num<=14) //if  14% chance then do things bellow.
      {
          a= -0.15;b =0.26;c =0.28;d =0.24;e =0;f=0.44;   // Transformation rule: creates small side leaflets of the fern
      }
      else{  // Remaining 85% chance then do things bellow.
        a= 0.85; b = -0.04; c =0.04; d =0.85; e =0; f=1.6;  // Main transformation (85% chance): draws the stem and overall leafy shape of the fern
      }

    // Apply chosen transformation from provided instruction.
        x1= a*x+ c*y+ e; // Calculate new x-coordinate using affine transformation scaling/rotation + shift.
        y1= b*x+ d*y+ f; // Calculate new y-coordinate using affine transformation scaling/rotation + shift.
    // Plot the current point
        glBegin(GL_POINTS);
        glVertex3f(x, y, 0);  // Draw point at (x,y)
        glEnd();

    // Update current coordinates for next iteration.
        x=x1;  // Update x to the new transformed x-coordinate for next iteration
        y=y1; // Update y to the new transformed y-coordinate for next iteration
  }

  // Force execution of OpenGL commands to show drawing.
  glFlush ();                           // clear buffer
}


void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :   // If ESC key is pressed. 
        case 'q':  // Or if 'q' key is pressed.
            exit(0); // Then exit the program.
            break;
    }

    glutPostRedisplay(); // Refresh display after key press
}


/* Program entry point */

int main(int argc, char *argv[])
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (600,800);                 //window screen
   glutInitWindowPosition (100, 100);            //window position
   glutCreateWindow ("Program1");                //program title
   init();
   glutDisplayFunc(display);                     //callback function for display
   glutReshapeFunc(resize);                      //callback for reshape
   glutKeyboardFunc(key);                        //callback function for keyboard
   glutMainLoop();                               //loop

    return EXIT_SUCCESS;
}
