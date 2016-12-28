#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include<locale.h>
char ing[50],tr[50],aranan[50],a,temp[50],tr_kisim[50];
FILE *dosya;

void yazdirma();
bool dizileri_karsilastir(char dizi1[],char dizi2[]);
void esittire_kadar_oku();
void esittirden_sonrasini_oku();
void arama();
void listele();
char secim[1];
bool kontrol=false;

int main(){
	setlocale(LC_ALL, "Turkish");
	dosya=fopen("kelimeler.txt","a+");
	printf("1-EKLEME\n");
	printf("2-ARAMA\n");
	printf("3-LISTELEME\n");
	printf("Secim:  ");
	gets(secim);
	if(secim[0]=='1'){
		yazdirma();
		
	}
	else if(secim[0]=='2'){
			printf("aranan: ");
			gets(aranan);
		    arama();
		    fseek(dosya,0,SEEK_SET);
		    if(kontrol){
				printf("%s=%s",aranan,tr_kisim);
		  		kontrol=false;	
			}else{
				printf("aranan kelime sozlukte yok.");
			}
		system("pause");
			
			
	}else if(secim[0]=='3'){
		listele();
		system("pause");
	}else{
		printf("hatali secim");
	}
	
	fclose(dosya);
}

void listele(){
	
	while(!feof(dosya)){
		char x=getc(dosya);
		if(x!=';'){
			printf("%c",x);
		}
		
	}
	
}
void arama(){
		esittire_kadar_oku();
		esittirden_sonrasini_oku();
		if(dizileri_karsilastir(aranan,temp)){
			kontrol=true;
			
		}else if(!feof(dosya)){
			while(true){
				if(getc(dosya)=='\n'){
					break;
				}
			}
			for(int i=0;i<strlen(temp);i++){
				temp[i]=' ';
			}
			for(int i=0;i<strlen(tr_kisim);i++){
				tr_kisim[i]=' ';
			}
			arama();
		}
}
void yazdirma(){
	
	printf("ingilizce kelimeniz: ");
	gets(ing);
	printf("turkce karsiligi: ");
	gets(tr);
	fprintf(dosya,"%s=%s;\n",ing,tr);
	
}
void esittire_kadar_oku(){
	int s=0;
	while(!feof(dosya)){
		
		char okunan=getc(dosya);
		if(okunan=='='){
			break;
		}else{
			temp[s]=okunan;
			s++;
		}
	}
}
void esittirden_sonrasini_oku(){
	int say=0;
	while(!feof(dosya)){
		char okunan=getc(dosya);
		if(okunan==';'){
			break;
		}else{
			tr_kisim[say]=okunan;
			say++;
		}
	}

}
bool dizileri_karsilastir(char dizi1[],char dizi2[]){
	int say=0;
	for(int i=0;i<strlen(dizi1);i++){
		if(dizi1[i]==dizi2[i]){
			say++;
		}else{
			break;
		}
	}
	
	if(say==strlen(dizi1)){
		return true;
	}else{
		return false;
	}
}
