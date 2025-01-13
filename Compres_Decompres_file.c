#include <stdio.h>
int compress(FILE *fin , FILE *fout);
int decompress(FILE *fin ,FILE *fout);

int main() {
    FILE *fp_read , *fp_dec ,*fp_com;
    int num_car;
    char choice;

    printf("compression(C) or decopression(D): ");
    scanf("%c",&choice);

    fp_read = fopen("source.txt" ,"r");
    fp_dec = fopen("compressed.txt","w");

    switch (choice) {
        case 'C' :
            if(fp_read==NULL){
                printf("error opening file\n");
                return 1;
            }
            if(fp_dec==NULL){
                printf("error opening file\n");
                return 2;
            }
            num_car = compress(fp_read , fp_com);
            fclose(fp_read);
            fclose(fp_com);
            break;
        case  'D':
            if((fp_dec = fopen("decompressed.txt","w"))==NULL){
                printf("error opening file\n");
                return 3;
            }
            if((fp_com=fopen("compressed.txt","r"))==NULL){
                printf("error opening file");
                return 4;
            }
            num_car = decompress(fp_com ,fp_dec);
            fclose(fp_dec);
            fclose(fp_com);
            break;
        default:
            printf("wrong choice\n");

    }

    if(num_car==0){
        printf("error");
    }
    else{
        printf("charecters [pprinted: %d",num_car);
    }
    return 0;
}

int compress(FILE *fin , FILE *fout){
    char ch ,ch1;
    int counter=0 , num_car =0;
    int i =0;


    ch = fgetc(fin);
    while(!feof(fin)){
        ch1 =fgetc(fin);
        if(ch==ch1 && counter <9){
            counter++;
        }
        else{
            if(counter >=2){
                fprintf(fout,"%c!%d",ch,counter);
                num_car = num_car+3;
                counter =0;
            }
            else{
                for(i=0;i<counter+1;i++){
                    fputc(ch,fout);
                    num_car++;
                }
                counter = 0;
            }
        }
        ch = ch1;
    }
    return num_car;
}
int decompress(FILE *fin ,FILE *fout){
    char ch ,ch1;
    int counter=0 , num_car=0;
    int i=0;
    ch = fgetc(fin);
    while (!feof(fin)){
        ch1 = fgetc(fin);
        if(ch1 =="!"){
            counter =fgetc(fin)-'0';
            for(i=0;i<counter+1;i++){
                fputc(ch,fout);
                num_car++;
            }
            ch =fgetc(fin);
        }
        else{
            fputc(ch,fout);
            num_car++;
            ch =ch1;
        }
    }
    return num_car;
}
