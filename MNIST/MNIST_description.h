#ifndef _MNIST_DESCRIPTION_H_
#define _MNIST_DESCRIPTION_H_

/*
    TODO: magic number can id files
*/

#define MNIST_TRAIN_IMAGE_MAGIC_NUMBER 
#define MNIST_TRAIN_LABLE_MAGIC_NUMBER 
#define MNIST_TEST_IMAGE_MAGIC_NUMBER 
#define MNIST_TEST_LABLE_MAGIC_NUMBER 

#define MNIST_DEFAULT_COL 28
#define MNIST_DEFAULE_ROW 28

#define MNIST_TRAIN_IMAGE_NUMBER 60000

#define FILENAME_IMG_TRAIN "train-images.idx3-ubyte"
#define FILENAME_LAB_TRAIN "train-labels.idx1-ubyte"
#define FILENAME_IMG_TEST10 "t10k-images.idx3-ubyte"
#define FILENAME_LAB_TEST10 "t10k-labels.idx1-ubyte"

#define MNIST_IMG_LENGTH 784

#endif //! _MNIST_DESCRIPTION_H_