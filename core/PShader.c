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

glDrawArrays

gluniform + suffix

*/

/*

glGetUniformLocation     GLint glGetUniformLocation(	GLuint program,	const GLchar *name);

glCreateShader           GLuint glCreateShader(	GLenum shaderType);
glCreateProgram          GLuint glCreateProgram(	void);

glShaderSource           void glShaderSource (	GLuint shader, GLsizei count, const GLchar **string, const GLint *length);
glCompileShader          void glCompileShader(	GLuint shader);
glAttachShader           void glAttachShader (	GLuint program, GLuint shader);

glLinkProgram            void glLinkProgram(	GLuint program);
glUseProgram             void glUseProgram (	GLuint program);

glDrawArrays             void glDrawArrays(	GLenum mode,GLint first,GLsizei count);

gluniform + suffix       void

*/
#define GL_VERTEX_SHADER 0x8B31
#define GL_FRAGMENT_SHADER 0x8B30

//#define GL_COLOR_BUFFER_BIT 0x4000 works by default
//#define GL_DEPTH_BUFFER_BIT 0x100
//#define GL_TRIANGLE_STRIP 5
//(*glDrawArrays)(GLenum,GLint,GLsizei); works by default
GLint (*glGetUniformLocation)(GLuint, const GLchar*);
GLuint (*glCreateShader)(GLenum);
GLuint (*glCreateProgram)(void);

GLFWglproc
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
(*glUniformMatrix4x3fv)(GLint,GLsizei,GLboolean,const GLfloat *);

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

#define shader glUseProgram

unsigned int RENDERER;



void klistra(){

glGetUniformLocation = glfwGetProcAddress("glGetUniformLocation");
glCreateShader = glfwGetProcAddress("glCreateShader");
glCreateProgram = glfwGetProcAddress("glCreateProgram");
glShaderSource = glfwGetProcAddress("glShaderSource");
glCompileShader = glfwGetProcAddress("glCompileShader");
glAttachShader = glfwGetProcAddress("glAttachShader");
glLinkProgram = glfwGetProcAddress("glLinkProgram");
glUseProgram = glfwGetProcAddress("glUseProgram");

// glDrawArrays = glfwGetProcAddress("glDrawArrays") works by default

glUniform1f = glfwGetProcAddress("glUniform1f");
glUniform2f = glfwGetProcAddress("glUniform2f");
glUniform3f = glfwGetProcAddress("glUniform3f");
glUniform4f = glfwGetProcAddress("glUniform4f");

glUniform1i = glfwGetProcAddress("glUniform1i");
glUniform2i = glfwGetProcAddress("glUniform2i");
glUniform3i = glfwGetProcAddress("glUniform3i");
glUniform4i = glfwGetProcAddress("glUniform4i");

glUniform1ui = glfwGetProcAddress("glUniform1ui");
glUniform2ui = glfwGetProcAddress("glUniform2ui");
glUniform3ui = glfwGetProcAddress("glUniform3ui");
glUniform4ui = glfwGetProcAddress("glUniform4ui");

glUniform1fv = glfwGetProcAddress("glUniform1fv");
glUniform2fv = glfwGetProcAddress("glUniform2fv");
glUniform3fv = glfwGetProcAddress("glUniform3fv");
glUniform4fv = glfwGetProcAddress("glUniform4fv");

glUniform1iv = glfwGetProcAddress("glUniform1iv");
glUniform2iv = glfwGetProcAddress("glUniform2iv");
glUniform3iv = glfwGetProcAddress("glUniform3iv");
glUniform4iv = glfwGetProcAddress("glUniform4iv");

glUniform1uiv = glfwGetProcAddress("glUniform1uiv");
glUniform2uiv = glfwGetProcAddress("glUniform2uiv");
glUniform3uiv = glfwGetProcAddress("glUniform3uiv");
glUniform4uiv = glfwGetProcAddress("glUniform4uiv");

glUniformMatrix2fv = glfwGetProcAddress("glUniformMatrix2fv");
glUniformMatrix3fv = glfwGetProcAddress("glUniformMatrix3fv");
glUniformMatrix4fv = glfwGetProcAddress("glUniformMatrix4fv");

glUniformMatrix2x3fv = glfwGetProcAddress("glUniformMatrix2x3fv");
glUniformMatrix3x2fv = glfwGetProcAddress("glUniformMatrix3x2fv");
glUniformMatrix2x4fv = glfwGetProcAddress("glUniformMatrix2x4fv");

glUniformMatrix4x2fv = glfwGetProcAddress("glUniformMatrix4x2fv");
glUniformMatrix3x4fv = glfwGetProcAddress("glUniformMatrix3x4fv");
glUniformMatrix4x3fv = glfwGetProcAddress("glUniformMatrix4x3fv");
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
