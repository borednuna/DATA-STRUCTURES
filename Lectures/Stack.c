#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 10

struct STACK {int top; int data[10];}; 
struct STACK tumpuk;

void inisialisasi() 
{ tumpuk.top=-1; }

int isFull() 
{ return (tumpuk.top==MAX_STACK-1) ? 1 : 0; }

int isEmpty() 
{ return (tumpuk.top==-1) ? 1 : 0; }

void Push(int datanya)
{ tumpuk.data[++tumpuk.top]=datanya; }

void Pop() 
{ printf("data ter-ambil %d\n", tumpuk.data[tumpuk.top]); tumpuk.top--; }

void tampilStack()
{for (int i=tumpuk.top; i >= 0; i--) printf("Data stack ke %d adalah %d\n", i, tumpuk.data[i]);}

void masukkanData() {   
    int datanya; 
    while(!isFull()) {
        printf("Masukkan data ");
        scanf("%d", &datanya);
        Push(datanya);
    }
}

void ambilData()
{   while(!isEmpty()) Pop();}

int main() {
    inisialisasi(); 
    masukkanData(); 
    tampilStack(); 
    ambilData();
    return 0;
}