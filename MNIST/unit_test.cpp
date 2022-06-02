#include "data_preprocess.h"
extern IMG dataset[60000];
extern unsigned char labelset[60000];
int main() {
	SetConsoleSize();
	MNIST_read();
}