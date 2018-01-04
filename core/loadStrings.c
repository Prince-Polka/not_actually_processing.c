/*
GLchar* loadBytes(GLchar *path){
FILE *in = fopen(path, "r");
fseek(in, 0L, SEEK_END);
int len = ftell(in);
fseek(in, 0L, SEEK_SET);
GLchar *buffer;
buffer = (GLchar*)calloc(len, sizeof(GLchar));
fread(buffer, sizeof(GLchar), len, in);
return buffer;
}*/

int cutNewline = GL_TRUE;
int linecount = 0;
int *lineLengths;
GLchar **ret;
GLchar *buffer;

GLchar **loadStrings(GLchar *path){

  /*free memory from last call to function*/

  free(buffer);
  free(ret);
  free(lineLengths);
  linecount = 0;

  /*find length of file*/

  FILE *in = fopen(path, "r");
  fseek(in,0,SEEK_END);
  int len = ftell(in);
  fseek(in,0,SEEK_SET);

  /* alllocate just enough memory for buffer*/
  buffer = malloc(len * sizeof(GLchar));

  /* alllocate more than enough memory for pointers temporarily */
  ret = malloc(len * sizeof(GLchar**));
  lineLengths = malloc(len * sizeof(int*));

  /* read file into buffer */

  fread(buffer, sizeof(GLchar), len, in);

  /* this may be dangerous but seems like there is some leeway */

  GLchar * end = &buffer[len];
  while (*end==0)end--;
  if(*end!='\n')*++end='\n';


  GLchar *i,*j;
  i = j = buffer;
  GLchar swap;
  if(cutNewline) swap = '\0'; else swap = '\n';

  for(;i<=end;i++){
    if(*i=='\n'){
      lineLengths[linecount] = i-j + !cutNewline;
      ret[linecount++] = j;
      *i=swap;
      j=i+1;
    }
  }

  /* free some unused memory */

  ret = realloc(ret,linecount * sizeof(GLchar**));
  lineLengths = realloc(lineLengths ,linecount * sizeof(int*));

  return ret;
}
