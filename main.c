#include <stdio.h>
#include <string.h>
#include <string.h>

int count_chars(char *FileName){
	FILE* Fp=fopen(FileName,"r");
	int Res=0;
	while(!feof(Fp)){ 
		fgetc(Fp);
		Res++;		
	}
	fclose(Fp);
	return Res;
}

int count_words(char *FileName){
	FILE* Fp=fopen(FileName,"r");
	int Res=0;
	char Now;
	while(!feof(Fp)){
		Now=fgetc(Fp);	
		if( Now==',' || Now==' ' )
			Res++;
	}
	fclose(Fp);
	return Res+1;
}


int main(int argc, char *argv[]){
	if(strcmp(argv[1],"-w")==0)
		printf("统计单词数量：%d\n",count_words(argv[2]));
	else if(strcmp(argv[1],"-c")==0)
		printf("统计字符数量：%d\n",count_chars(argv[2]));
	else
		printf("输入参数有误")
	return 0;
}
