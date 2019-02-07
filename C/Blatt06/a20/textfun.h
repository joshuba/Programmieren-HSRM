#ifndef TEXTFUN_H
#define TEXTFUN_H

typedef struct _listEle{
    char suchWort [25];
    char ersetzungsWort [25];
    struct _listEle *next;
    
}*listEle;


static listEle wordList = NULL;


extern void leseRegelnAusDatei(char *dateiname);
extern void schreibeRegelnInDatei(char *dateiname);

extern void addPair(const char *such, const char *ersetz);
extern void clearList(void);
extern char *find(const char *s);
extern int replaceAll(char *s);


#endif
