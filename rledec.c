#include <stdio.h>

int main(int argc,char **argv) {

  int ch,n,i;
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

  while((n=fgetc(fin))!=EOF) {
    ch=fgetc(fin);
    if(ch==EOF) break;
    for(i=0;i<=n;i++) {
      fputc(ch,fout);
    }
  }

  fclose(fout);
  fclose(fin);

  return 0;
}
