#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int (*cmp_t)(const void *, const void *);
/*void vswap(char *p, char *q, int sz) {
  char tmp;
  for (int i = 0; i < sz; ++i) {
    tmp = *p;
    *p = *q;
    *q = tmp;
    ++p;
    ++q;
  }
}
void q2sort(void *a, int n, int sz, cmp_t cmp) {
  if (n <= 1) {
    return;
  }
  void *left = a, *right = a + (n - 2) * sz;
  void *v = a + (n - 1) * sz;
  for (;;) {
    while (cmp(v, left) > 0) {
      left += sz;
    }
    while (cmp(right, v) > 0) {
      if (right == a) {
        break;
      }
      right -= sz;
    }
    if (left >= right) {
      break;
    }
    vswap(left, right, sz);
    left += sz;
    right -= sz;
  }
  vswap(left, v, sz);
  right = left + sz;(a, (left - a)/sz + 1, sz, cmp);
  q2sort(right, (a - right)/sz + n, sz, cmp);
}*/
void selsort(void*a,int n,int sz,cmp_t cmp){
	char *buff = malloc(sz);
	for(int i=0;i<n;i++){
		for(int j=i+1; j<n;j++){
			void *pi=a+i*sz,*pj=a+j*sz;
			if(cmp(pi,pj)>0){
				memcpy(buff,pi,sz);
				memcpy(pi,pj,sz);
				memcpy(pj,buff,sz);
			}
		}
	}
	free(buff);
}
struct lop {
    char a[100];
    char stt[10];
    char name[100];
    char mssv[10];
    char diem[10];
};
struct lop hocsinh[1000000];
int cmpname(const void *ptr1, const void *ptr2){
    struct lop *x = (struct lop *)ptr1;
    struct lop *y = (struct lop *)ptr2;
    if(strcmp(x->name,y->name) != 0)
        return strcmp(x->name,y->name);
    else {
        int sttx=0;
        int stty=0;
        for(int i = 0;i < strlen(x->stt);i++)
            sttx = sttx*10 + (int)x->stt[i]-48;
        for(int i = 0;i < strlen(x->stt);i++)
            stty = stty*10 + (int)x->stt[i]-48;
        return sttx-stty;
    }
}

int cmpmssv(const void *ptr1, const void *ptr2){
    struct lop *x = (struct lop *)ptr1;
    struct lop *y = (struct lop *)ptr2;
    if(strcmp(x->mssv,y->mssv) != 0)
        return strcmp(x->mssv,y->mssv);
    else {
        int sttx=0;
        int stty=0;
        for(int i = 0;i < strlen(x->stt);i++)
            sttx = sttx*10 + (int)x->stt[i]-48;
        for(int i = 0;i < strlen(x->stt);i++)
            stty = stty*10 + (int)x->stt[i]-48;
        return sttx-stty;
    }
}

int cmpdiem(const void *ptr1, const void *ptr2){
    struct lop *x = (struct lop *)ptr1;
    struct lop *y = (struct lop *)ptr2;
    if(strcmp(x->diem,y->diem) != 0)
    {
        if(strcmp(x->diem,"10.00\n") == 0)
            return -1;
        else if(strcmp(y->diem,"10.00\n") == 0)
            return 1;
        else
            return strcmp(x->diem,y->diem)*-1;
    }
        else {
            int sttx=0;
            int stty=0;
            for(int i = 0;i < strlen(x->stt);i++)
                sttx = sttx*10 + (int)x->stt[i]-48;
            for(int i = 0;i < strlen(y->stt);i++)
                stty = stty*10 + (int)y->stt[i]-48;
            return sttx-stty;
        }
}


int main() {

    int n,k ,j,csd,cscach, ktr = 0;;
    char lenh;
    scanf("%d %c\n", &n, &lenh);
    for(int i = 0; i < n; i++) {
        fgets(hocsinh[i].a, sizeof(hocsinh[i]), stdin);
        if(hocsinh[i].a[strlen(hocsinh[i].a)-1]=='\n')
        {
            hocsinh[i].a[strlen(hocsinh[i].a)-1]='\n';
            hocsinh[i].a[strlen(hocsinh[i].a)]='\0';
        }
        k = 0;
        csd = 0;
        for(int j = 0; j < strlen(hocsinh[i].a); j++) {
            if(hocsinh[i].a[j] == '*') {
                if (k == 0)
                    strncpy(hocsinh[i].stt, hocsinh[i].a + csd, j - csd);
                else if (k == 1)
                    strncpy(hocsinh[i].name, hocsinh[i].a + cscach, j - cscach);
                else if (k == 2)
                    strncpy(hocsinh[i].mssv, hocsinh[i].a + csd, j - csd);
                k++;
                csd = j + 1;
            }
            else if(hocsinh[i].a[j] == ' ')
                cscach = j+1;
        }
        strncpy(hocsinh[i].diem, hocsinh[i].a+csd , strlen(hocsinh[i].a) - csd );
        if(strlen(hocsinh[i].diem)==4)
        {
            k = strlen(hocsinh[i].a);
            hocsinh[i].a[k-1]='0';
            hocsinh[i].a[k]='\n';

        }
    }
    if (lenh == 'n')
        selsort(hocsinh, n, sizeof(hocsinh[0]), cmpname);
    if (lenh == 'g') {
        int t = cmpdiem(&hocsinh[0],&hocsinh[1]);
        selsort(hocsinh, n, sizeof(hocsinh[0]), cmpdiem);
    }
    if (lenh == 'c')
        selsort(hocsinh, n, sizeof(hocsinh[0]), cmpmssv);
    for(int i = 0;i < n;i++)
        printf("%s", hocsinh[i].a);
    return 0;
}
