#ifndef _DATA_PREPROCESS_
#define _DATA_PREPROCESS_


#include "MNIST_description.h"
#include <stdio.h>
#include <windows.h>


struct image_head_info{
    int magicNum;
    int imgNum;
    int col;
    int row;
};
struct label_head_info{
    int magicNum;
    int items;
};

struct img_matrix{
    unsigned char imgMx[784];
};


typedef struct image_head_info IMG_HEAD;
typedef struct label_head_info LAB_HEAD;
typedef struct img_matrix IMG;


void SetConsoleSize();
void ChangeConsoleColor(int colorlevle);
void MNIST_read();

IMG_HEAD get_train_image_head(FILE* file);
LAB_HEAD get_train_label_head(FILE* file);

int isBigEndian();
void endianConverse32(void* ori);

void read_train_dataset(FILE* file);
void read_train_labelset(FILE* file);
void visualConsole(IMG frame);

void testVisual(int len);
///////////   static
/// none static data


#endif // !_DATA_PREPROCESS
