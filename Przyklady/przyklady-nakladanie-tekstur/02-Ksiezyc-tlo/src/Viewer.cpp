#include "Viewer.hh"
#include <iostream>
#include <cmath>
#include "SceneParams.hh"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
#include <SOIL/SOIL.h>

using namespace std;

inline
double Deg2Rad(double Ang_deg)
  { return Ang_deg*M_PI/180; }


#define ANG_STEP_deg 10

static GLuint Texture4Sphere;
static GLuint Texture4Bg;








void Viewer::init()
{
  restoreStateFromFile();

  GLfloat Light1_Position[] = { 1.0, 1.0, 1.0, 0.0 };
  glLightfv(GL_LIGHT0, GL_POSITION, Light1_Position);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);


  glEnable(GL_TEXTURE_2D);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
  glGenTextures(1, &Texture4Sphere);
  glBindTexture(GL_TEXTURE_2D, Texture4Sphere);

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, 
		   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, 
                   GL_NEAREST);


   int width, height;
   unsigned char* image =
       SOIL_load_image("tekstury/Moon.png", &width, &height, 0, SOIL_LOAD_RGB);

   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                 GL_UNSIGNED_BYTE, image);

   /* Inny sposob powiazania z tekstura */
   Texture4Bg = SOIL_load_OGL_texture(
		"tekstury/space_dust.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	       );
   help();
}






/*!
 * Tworzy sferę o zadanym rozmiarze
 */
void GLSphere( double Size )
{
 glScalef( Size, Size, Size ); 

 float   x_new_z_prev, y_new_z_prev;
 float   x_new_z_new,  y_new_z_new;

 
 float   z_prev = -1, z_new;
 float   radius_prev = 0, radius_new;
 float   sn, cs;


 double  s_new;
 double  t_prev = 0, t_new;   

 for (double Elev_deg = -90+ANG_STEP_deg; Elev_deg <= 90; Elev_deg += ANG_STEP_deg) {
   z_new = sin(Deg2Rad(Elev_deg));
   radius_new = cos(Deg2Rad(Elev_deg));

   t_new =  (90+Elev_deg)/180;
   sn = 0;  cs = 1;

   
   glBegin(GL_QUAD_STRIP);
   glColor3f(   1.0,  1.0,  1.0 );

   for (double Azim_deg = 0; Azim_deg <= 360; Azim_deg += ANG_STEP_deg) {
    s_new = Azim_deg/360;
    sn = sin(Deg2Rad(Azim_deg));  cs = cos(Deg2Rad(Azim_deg));
    x_new_z_new = radius_new*cs;
    y_new_z_new = radius_new*sn;
    x_new_z_prev = radius_prev*cs;
    y_new_z_prev = radius_prev*sn;

    glTexCoord2f(s_new,t_prev);
    glNormal3f( x_new_z_prev, y_new_z_prev,  z_prev);  glVertex3f( x_new_z_prev, y_new_z_prev,  z_prev );
    glTexCoord2f(s_new,t_new);
    glNormal3f(x_new_z_new, y_new_z_new,  z_new);      glVertex3f( x_new_z_new, y_new_z_new,  z_new );     
   }
    
   glEnd();
   
  z_prev = z_new;
  radius_prev = radius_new;
  t_prev = t_new;
 }
}





 /*-----------------------------------------------------
 *  Tworzenie tła wypełnionego wygenerowaną teksturą
  */
void CreateBackground()
{
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
  glBindTexture(GL_TEXTURE_2D, Texture4Bg);

   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   
   glLoadIdentity();
   glDepthMask(GL_FALSE);

   glMatrixMode(GL_PROJECTION);
   glPushMatrix();

   glLoadIdentity();
   glOrtho(0,1,1,0,-1,1);

   glBegin(GL_QUADS);  // Tworzenie kwadratu, na którym będzie
    glTexCoord2f(0,0); // rozpięta tekstura tła.
    glVertex2f(0,0);

    glTexCoord2f(1,0);
    glVertex2f(1,0);

    glTexCoord2f(1,1);
    glVertex2f(1,1);

    glTexCoord2f(0,1);
    glVertex2f(0,1);
  glEnd();

  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
}





#define SLIDER2RAD(x) static_cast<float>(sin(M_PI*2*ScnParams.Get##x##_Light_deg()/180))


void Viewer::draw()
{
  GLfloat Light1_Position[] = { 3*SLIDER2RAD(X), 3*SLIDER2RAD(Y), 3*SLIDER2RAD(Z), 0.0 };

  glLightfv(GL_LIGHT0, GL_POSITION, Light1_Position);


  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_TEXTURE_2D);
  
  CreateBackground();

  glDepthMask(GL_TRUE);  
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // TMP 
  glBindTexture(GL_TEXTURE_2D, Texture4Sphere);  
  glTranslatef( 0.0, 0.0, -1 );
  glRotatef( ScnParams.GetAngleX_deg(), 1.0, 0.0, 0 ); // Obracanie kulu wokół osi OX
  GLSphere(0.5);
  glFlush();
  glDisable(GL_TEXTURE_2D);
}




QString Viewer::helpString() const
{
  QString text("<h2>S i m p l e V i e w e r</h2>");
  text += "Use the mouse to move the camera around the object. ";
  text += "You can respectively revolve around, zoom and translate with the three mouse buttons. ";
  text += "Left and middle buttons pressed together rotate around the camera view direction axis<br><br>";
  text += "Pressing <b>Alt</b> and one of the function keys (<b>F1</b>..<b>F12</b>) defines a camera keyFrame. ";
  text += "Simply press the function key again to restore it. Several keyFrames define a ";
  text += "camera path. Paths are saved when you quit the application and restored at next start.<br><br>";
  text += "Press <b>F</b> to display the frame rate, <b>A</b> for the world axis, ";
  text += "<b>Alt+Return</b> for full screen mode and <b>Control+S</b> to save a snapshot. ";
  text += "See the <b>Keyboard</b> tab in this window for a complete shortcut list.<br><br>";
  text += "Double clicks automates single click actions: A left button double click aligns the closer axis with the camera (if close enough). ";
  text += "A middle button double click fits the zoom of the camera and the right button re-centers the scene.<br><br>";
  text += "A left button double click while holding right button pressed defines the camera <i>Revolve Around Point</i>. ";
  text += "See the <b>Mouse</b> tab and the documentation web pages for details.<br><br>";
  text += "Press <b>Escape</b> to exit the viewer.";
  return text;
}
