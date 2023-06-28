#ifndef shell_h
#define shell_h

typedef struct
{
char **argv;
int argc;
char **env;
}info_t;

int _env(void);
char *_getenv(const char *name);
int setenv_builtin(char **args);
int unsetenv_builtin(char **args);
#endif
