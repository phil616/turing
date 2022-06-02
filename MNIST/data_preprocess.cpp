#include "data_preprocess.h"
#define GREY_BGC 0x08
#define WHITE_BGC 0x07

IMG dataset[60000];
unsigned char labelset[60000];
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void SetConsoleSize()
{
	// the image are 28x28, so 32x32 can fit it
	system("mode con lines=32 cols=32");
}


void ChangeConsoleColor(int colorlevle)
{
	// if the light brighter than 128, looks white
	if (colorlevle > 128) SetConsoleTextAttribute(hConsole,WHITE_BGC);
	else SetConsoleTextAttribute(hConsole,GREY_BGC);
}


void MNIST_read()
{
	FILE *TRAIN_FILE = NULL;
	FILE *TRAIN_LABEL = NULL;

	TRAIN_FILE = fopen(FILENAME_IMG_TRAIN, "rb");
	TRAIN_LABEL = fopen(FILENAME_LAB_TRAIN, "rb");

	IMG_HEAD trainImageHeadInfo;
	LAB_HEAD trainLabelHeadInfo;

	trainImageHeadInfo = get_train_image_head(TRAIN_FILE);
	trainLabelHeadInfo = get_train_label_head(TRAIN_LABEL);
	
	read_train_dataset(TRAIN_FILE);
	read_train_labelset(TRAIN_LABEL);

	testVisual(20);

	fclose(TRAIN_FILE);
	fclose(TRAIN_LABEL);

}


IMG_HEAD get_train_image_head(FILE* file)
{
	fseek(file, 0, SEEK_SET);
	IMG_HEAD buf;
	
	fread((void*)&buf.magicNum, 4, 1, file);
	fread((void*)&buf.imgNum, 4, 1, file);
	fread((void*)&buf.row,4,1,file);
	fread((void*)&buf.col,4,1,file);
	if(!isBigEndian()){
		endianConverse32((void*)&buf.magicNum);
		endianConverse32((void*)&buf.imgNum);
		endianConverse32((void*)&buf.row);
		endianConverse32((void*)&buf.col);
	}
		// add some verify
	fseek(file, 4 + 4 + 4 + 4, SEEK_SET);
	return buf;
}


LAB_HEAD get_train_label_head(FILE* file)
{
	fseek(file, 0, SEEK_SET);
	LAB_HEAD buf;
	
	fread((void*)&buf.magicNum, 4, 1, file);
	fread((void*)&buf.items, 4, 1, file);
	if(!isBigEndian()){
		endianConverse32((void*)&buf.magicNum);
		endianConverse32((void*)&buf.items);
	}
	// add some verify

	fseek(file, 4 + 4, SEEK_SET);
	return buf;
}


int isBigEndian()
{
    unsigned int c = 1;
    unsigned char *p = (unsigned char *)&c;
	if(*p != 0) return 0;
	else return 1;
}


void endianConverse32(void* ori)
{
	unsigned char * target = NULL;
	target = (unsigned char *)ori;
	unsigned char buf[4];
	for(int i = 0;i < 4;i++) buf[3-i] = target[i];
	for(int i = 0;i < 4;i++) target[i] = buf[i];
}

void read_train_dataset(FILE* file)
{
	for (int i = 0;i < MNIST_TRAIN_IMAGE_NUMBER;i++)
	{
		for (int j = 0; j < MNIST_IMG_LENGTH; j++){
			fread((void*)&dataset[i].imgMx[j],1,1,file);
		}
	}
}
void read_train_labelset(FILE* file)
{
	for (int i = 0;i < MNIST_TRAIN_IMAGE_NUMBER;i++)
	{
		fread((void*)&labelset[i],1,1,file);
	}
}

void visualConsole(IMG frame){
	int spt = 0;

	for(int row = 0; row < 28; row++)
	{
		for(int col = 0; col < 28; col++){
			printf("@");
			ChangeConsoleColor(frame.imgMx[spt++]);
		}
		printf("\n");
	}
}


void testVisual(int len){
	for(int test = 0;test < len;test++){
		system("cls");
		printf("Following number should be %d\n",labelset[test]);
		visualConsole(dataset[test]);
		Sleep(1000);
	}
}