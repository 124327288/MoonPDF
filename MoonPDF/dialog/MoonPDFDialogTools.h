#pragma once

/*************************************************************************
 * ˵�����Ի��򹤾ߣ���������mupdf�ͶԻ���֮�������
 * ���ߣ�����Ȼ
 * ʱ�䣺2019-5-26 17:04
 ************************************************************************/

#include "../mupdf/pdfapp.h"

void winwarn(pdfapp_t*, char *s);
void winerror(pdfapp_t*, char *s);
void wintitle(pdfapp_t*, char *title);
void winresize(pdfapp_t*, int w, int h);
void winrepaint(pdfapp_t*);
void winrepaintsearch(pdfapp_t*);
char *winpassword(pdfapp_t*, char *filename);
char *wintextinput(pdfapp_t*, char *inittext, int retry);
int winchoiceinput(pdfapp_t*, int nopts, const char *opts[], int *nvals, const char *vals[]);
void winopenuri(pdfapp_t*, char *s);
void wincursor(pdfapp_t*, int curs);
void windocopy(pdfapp_t*);
void windrawrect(pdfapp_t*, int x0, int y0, int x1, int y1);
void windrawstring(pdfapp_t*, int x, int y, char *s);
void winclose(pdfapp_t*);
void winhelp(pdfapp_t*);
void winfullscreen(pdfapp_t*, int state);
int winsavequery(pdfapp_t*);
int winquery(pdfapp_t*, const char*);
int wingetcertpath(char *buf, int len);
int wingetsavepath(pdfapp_t*, char *buf, int len);
void winalert(pdfapp_t *, pdf_alert_event *alert);
void winprint(pdfapp_t *);
void winadvancetimer(pdfapp_t *, float duration);
void winreplacefile(char *source, char *target);
void wincopyfile(char *source, char *target);
void winreloadpage(pdfapp_t *);