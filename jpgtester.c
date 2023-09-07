#include <stdio.h>
#include <string.h>

int fileTypeChecker(FILE *fp){

    // to read first n bytes of input file
    const int BYTE_SIZE = 8; // since the maximum size requires is for mp4 i.e. 8  , therefore 8 bytes we will take
    char bytes_Read[8]; // the bytes which will be read from the input file
    int number_of_Bytes = fread(bytes_Read,1,BYTE_SIZE,fp); // reading 1 Block of BYTE_SIZE = n size. from fp pointer, and storing it in bytes_Read

    if(number_of_Bytes != BYTE_SIZE){
        printf("couldn't read the first %d bytes\n",BYTE_SIZE);
        return 1;
    }

    char bytes_Required_jpeg[3] = {0xff,0xd8,0xff} ; // the bytes require to satisfy the condition of jpeg
    char bytes_Required_png[4] = {0x89,0x50,0x4e,0x47} ; //0x89504E47
    char bytes_Required_gif[3] = {0x47,0x49,0x46} ; //0x474946
    char bytes_Required_pdf[4] = {0x25,0x50,0x44,0x46} ; // 0x25504446
    char bytes_Required_zip[4] = {0x50,0x4b,0x03,0x04} ; //0x504B0304
    char bytes_Required_docx[4] = {0x50,0x4b,0x03,0x06} ; //
    char bytes_Required_mp3[2] = {0xff,0xfb} ; //0xFFFB
    char bytes_Required_mp4[8] = {0x00,0x00,0x00,0x20,0x66,0x74,0x79,0x70} ; //0x0000002066747970
    char bytes_Required_bmp[2] = {0x44,0x4d} ; //0x424D



    //jpeg
    if(memcmp(bytes_Read, bytes_Required_jpeg,3) == 0){ // comparing them , uptil byte_size = N;
        printf("Its a JPEG\n");
    }
    else if(memcmp(bytes_Read, bytes_Required_png,4) == 0)
    {
        printf("Its a PNG\n");
    }
    else if(memcmp(bytes_Read, bytes_Required_gif,3)==0){
        printf("Its a GIF\n");
    }
    else if(memcmp(bytes_Read, bytes_Required_pdf,4)==0){
        printf("Its a PDF\n");
    }
    else if(memcmp(bytes_Read, bytes_Required_zip,4)==0){
        printf("Its a zip\n");
    }
    else if(memcmp(bytes_Read, bytes_Required_docx,4)==0){
        printf("Its a docx\n");
    }
    else if(memcmp(bytes_Read, bytes_Required_mp3,2)==0){
        printf("Its a mp3\n");
    }
    else if(memcmp(bytes_Read, bytes_Required_mp4,8)==0){
        printf("Its a mp4\n");
    }
    else if(memcmp(bytes_Read, bytes_Required_bmp,2)==0){
        printf("Its a bmp\n");
    }
    else{
        printf(":( will found out soon\n");
    }
    
}

int main(int argc, char **argv){

    // checking if argc is 2, here 1-> actual command, 2-> file to pass
    if(argc != 2){
        printf("usage: %s[FILENAME]",argv[0]);
        return 1;
    }

    // storing the argument which we will use as the image file name.
    char *fileName = argv[1];

    // A pointer to file, by opening a file. Here we have used fopen(fileName,"rb") , "rb" is the read binary(flag)(not string),  to open the file
    FILE *fp = fopen(fileName,"rb");

    //checking if the fp is NULL
    if(fp == NULL){
        perror("fopen");
        printf("Unable to open the %s image file",fileName);
    }

    fileTypeChecker(fp);
    fclose(fp);


}