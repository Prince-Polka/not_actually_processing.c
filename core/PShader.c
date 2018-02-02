/*

This should include function pointers for GL fucntions necessary to create a shader

Should not depend on GLEW / GLAD etc

glCreateShader
glShaderSource
glCompileShader
glAttachShader

glCreateProgram
glLinkProgram
glUseProgram

glDrawArrays, works by default

gluniform + suffix

*/
#define GL_VERTEX_SHADER 0x8B31
#define GL_FRAGMENT_SHADER 0x8B30

//#define GL_COLOR_BUFFER_BIT 0x4000 works by default
//#define GL_DEPTH_BUFFER_BIT 0x100
//#define GL_TRIANGLE_STRIP 5
//(*glDrawArrays)(GLenum,GLint,GLsizei); works by default

GLint
(*glGetUniformLocation)(GLuint, const GLchar*);

GLuint
(*glCreateShader)(GLenum),
(*glCreateProgram)(void);

void
(*glShaderSource)(GLuint,GLsizei,const GLchar **, const GLint *),
(*glCompileShader)(GLuint),
(*glAttachShader)(GLuint,GLuint),
(*glLinkProgram )(GLuint),
(*glUseProgram )(GLuint),

(*glUniform1f)(GLint,GLfloat),
(*glUniform2f)(GLint,GLfloat,GLfloat),
(*glUniform3f)(GLint,GLfloat,GLfloat,GLfloat),
(*glUniform4f)(GLint,GLfloat,GLfloat,GLfloat,GLfloat),

(*glUniform1i)(GLint,GLint),
(*glUniform2i)(GLint,GLint,GLint),
(*glUniform3i)(GLint,GLint,GLint,GLint),
(*glUniform4i)(GLint,GLint,GLint,GLint,GLint),

(*glUniform1ui)(GLint,GLuint),
(*glUniform2ui)(GLint,GLuint,GLuint),
(*glUniform3ui)(GLint,GLuint,GLuint,GLuint),
(*glUniform4ui)(GLint,GLuint,GLuint,GLuint,GLuint),

(*glUniform1fv)(GLint,GLsizei,const GLfloat *),
(*glUniform2fv)(GLint,GLsizei,const GLfloat *),
(*glUniform3fv)(GLint,GLsizei,const GLfloat *),
(*glUniform4fv)(GLint,GLsizei,const GLfloat *),

(*glUniform1iv)(	GLint ,GLsizei ,const GLint *),
(*glUniform2iv)(	GLint ,GLsizei ,const GLint *),
(*glUniform3iv)(	GLint ,GLsizei ,const GLint *),
(*glUniform4iv)(	GLint ,GLsizei ,const GLint *),

(*glUniform1uiv)(	GLint ,GLsizei ,const GLuint *),
(*glUniform2uiv)(	GLint ,GLsizei ,const GLuint *),
(*glUniform3uiv)(	GLint ,GLsizei ,const GLuint *),
(*glUniform4uiv)(	GLint ,GLsizei ,const GLuint *),

(*glUniformMatrix2fv)(GLint,GLsizei,GLboolean,const GLfloat *),
(*glUniformMatrix3fv)(GLint,GLsizei,GLboolean,const GLfloat *),
(*glUniformMatrix4fv)(GLint,GLsizei,GLboolean,const GLfloat *),

(*glUniformMatrix2x3fv)(GLint,GLsizei,GLboolean,const GLfloat *),
(*glUniformMatrix3x2fv)(GLint,GLsizei,GLboolean,const GLfloat *),
(*glUniformMatrix2x4fv)(GLint,GLsizei,GLboolean,const GLfloat *),

(*glUniformMatrix4x2fv)(GLint,GLsizei,GLboolean,const GLfloat *),
(*glUniformMatrix3x4fv)(GLint,GLsizei,GLboolean,const GLfloat *),
(*glUniformMatrix4x3fv)(GLint,GLsizei,GLboolean,const GLfloat *)
;

#define FLOAT 1f
#define vec2 2f
#define vec3 3f
#define vec4 4f

#define INT 1i
#define ivec2 2i
#define ivec3 3i
#define ivec4 4i

#define gluniform(type,uniform,args...)(glUniform##type(glGetUniformLocation(RENDERER,#uniform),args))
#define uniform(t,u,a...)gluniform(t,u,a)
#define uniformv(t,u,a...)uniform(t##v,u,a)
#define uniformarray(t,u,a...)uniformv(t,u,a)

/* despite all the work ti get this macro working i consider rewriting the set uniform code some time */

#define shader glUseProgram // this name may be "dangerous"

#define KLISTRA(x)x=(void*)glfwGetProcAddress(#x);
/*
wglGetProcAddress windows specific
https://www.khronos.org/opengl/wiki/Load_OpenGL_Functions
*/

unsigned int RENDERER;

void klistra(){
KLISTRA(glGetUniformLocation)
KLISTRA(glCreateShader)
KLISTRA(glCreateProgram)
KLISTRA(glShaderSource)
KLISTRA(glCompileShader)
KLISTRA(glAttachShader)
KLISTRA(glLinkProgram)
KLISTRA(glUseProgram)

KLISTRA(glUniform1f)
KLISTRA(glUniform2f)
KLISTRA(glUniform3f)
KLISTRA(glUniform4f)

KLISTRA(glUniform1i)
KLISTRA(glUniform2i)
KLISTRA(glUniform3i)
KLISTRA(glUniform4i)

KLISTRA(glUniform1ui)
KLISTRA(glUniform2ui)
KLISTRA(glUniform3ui)
KLISTRA(glUniform4ui)

KLISTRA(glUniform1fv)
KLISTRA(glUniform2fv)
KLISTRA(glUniform3fv)
KLISTRA(glUniform4fv)

KLISTRA(glUniform1iv)
KLISTRA(glUniform2iv)
KLISTRA(glUniform3iv)
KLISTRA(glUniform4iv)

KLISTRA(glUniform1uiv)
KLISTRA(glUniform2uiv)
KLISTRA(glUniform3uiv)
KLISTRA(glUniform4uiv)

KLISTRA(glUniformMatrix2fv)
KLISTRA(glUniformMatrix3fv)
KLISTRA(glUniformMatrix4fv)
KLISTRA(glUniformMatrix2x3fv)
KLISTRA(glUniformMatrix3x2fv)
KLISTRA(glUniformMatrix2x4fv)

KLISTRA(glUniformMatrix4x2fv)
KLISTRA(glUniformMatrix3x4fv)
KLISTRA(glUniformMatrix4x3fv)

}

GLuint loadShader(char *fragFilename,char *vertFilename){
  GLchar **vert,**frag;
  cutNewline = GL_FALSE;
  GLuint vs,fs,prog;

  vert = loadStrings(vertFilename);
  vs = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vs,linecount,(const GLchar**)vert,lineLengths);
  glCompileShader(vs);

  frag = loadStrings(fragFilename);
  fs = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fs,linecount,(const GLchar**)frag,lineLengths);

  glCompileShader(fs);

  prog = glCreateProgram();

  glAttachShader(prog, fs);
  glAttachShader(prog, vs);

  glLinkProgram(prog);

  return prog;

}
