#include <stdio.h>

int main(int argc,char **argv) {

  int ch1,ch2,n;
  FILE *fin,*fout;

  if(argc!=3) {
    printf("syntax: %s src dst\n",argv[0]);
    return -1;
  }

  if((fin=fopen(argv[1],"rb"))==NULL) {
    printf("error: opening file: %s\n",argv[1]);
    return -1;
  }

  if((fout=fopen(argv[2],"wb"))==NULL) {
    printf("error: opening file: %s\n",argv[2]);
    return -1;
  }

  ch1=fgetc(fin);
  while(ch1!=EOF) {
    n=0;
    while((ch2=fgetc(fin))!=EOF && ch1==ch2) {
      n++;
      if(n==255) {
        fputc(n,fout);
        fputc(ch1,fout);
        n=-1;
      }
    }
    if(n>=0) {
      fputc(n,fout);
      fputc(ch1,fout);
    }
    ch1=ch2;
  }

  fclose(fout);
  fclose(fin);

  return 0;
}
