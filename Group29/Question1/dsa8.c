#include<stdio.h>
#include<stdlib.h>

#define size 100001

int flag ;

struct node
{
    int data;
    struct node *next;
};

struct node *chain[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}

void insert(int value)
{
    //create a newnode
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    //calculate hash key
    int key = value % size;

    //check if chain[key] is empty
    if(chain[key] == NULL)
        chain[key] = newNode;
    //collision
    else
    {
        //add the node at the end of chain
        struct node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void print()
{
    int i;

    for(i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main()
{
	int value;
	
    int num[100000];
    FILE* file = fopen ("integers.txt", "r");
    int i = 0;
    int j;

    fscanf (file, "%d", &j);
    while (!feof (file))
    {
      num[i] = j;

      //printf("%d\n",j);
      fscanf (file, "%d", &j);
      i++;
    }
    num[99999] = j;
    fclose (file);
    //calculate hash key
    int key = value % size;

    //init array of list to NULL
    init();
	
	int tsarr[]={231552, 234756, 596873, 648219, 726312, 981237, 988331, 1277361, 1283379};


	//inserting num to hash table
    for(i=0;i<100000;i++){
		insert(num[i]);
	}


    //printing hash table
    //print();

    
    //searching
    int a,k,hk;
   

    int b=0;
    struct node *temp ;
	for(a=0;a<9;a++)
    {	

        int flag = 0;
		for(b=0;b<100000;b++)
        {
			k=tsarr[a]-num[b];
			hk=k%size;


            if(k>=0)
            {
                for(temp=chain[hk];temp!=NULL;temp=temp->next)
                {
                    if(temp->data == k)
                    {

                        printf("1");
                        flag = 1;
                        break;
                    }
   				}
   				if(flag == 1)
                    break;
            }

    	  }
    	  if(flag == 0)
            printf("0");

	}



}
