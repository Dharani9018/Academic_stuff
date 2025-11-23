#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[100];
int length=0;

typedef struct trinode 
{
  struct trinode *child[255];
  int EOW;
} NODE;

NODE *getnode()
{
  NODE *temp = malloc(sizeof(NODE));
  for(int i = 0;i<255;i++)
  {
    temp ->child[i] = NULL;
    temp->EOW = 0;
  }
  return temp;
}

void insert(char *input,NODE *root)
{
  NODE *cur = root;
  int index;
  for(int i = 0;input[i]!='\0';i++)
  {
    index = input[i]; //ascii value of each letter:
    if(cur->child[index]==NULL)
    {
      cur->child[index] = getnode();
    }
    cur = cur->child[index];
  }
  cur->EOW = 1;
}

void display(NODE *root)
{
  NODE *cur = root;
  for(int i = 0;i<255;i++)
  {
    if(cur->child[i]!=NULL)
    {
      str[length++] = i;
      if(cur->child[i]->EOW==1)
      {
        printf("\n");
        for(int i = 0;i<length;i++)
        {
          printf("%c",str[i]);
        }
      }
      display(cur->child[i]);
    }
  }
  length--;
}

void display_prefix(NODE *root,char *key)
{
  char str1[100];
  NODE *cur = root;
  int index;
  for(int i = 0;key[i]!='\0';i++)
  {
    index = key[i];
    if(cur->child[index]!=NULL)
    {
      str1[length++] = index;
      cur = cur->child[index];
    }
    else
    {
      printf("NO words present\n");
      return;
    }
  }
  if(cur->EOW==1)
  {
    printf("\n");
    for(int j = 0; j<length;j++)
    {
      printf("%c",str1[j]);
    } 
  }
  display(cur);
}
//WAF to search for a word in a prefix tree;
/*
void search(NODE *root,char *key)
{
  length = 0;
  char str1[100];
  NODE *cur = root;
  int index;


}*/

NODE *delete(NODE *root,char *key,int depth)
{
  if(root==NULL)
  {
    return NULL;
  }
  if(depth==strlen(key))
  {
    if(root->EOW==1)
    {
      root->EOW = 0;
    }
    if(isempty(root))
    {
      free(root);
      return NULL;
    }
    return root.
  }
  int index = key[depth];
  root->child[index] = delete(root->child[index],key,depth+1);
  if(isempty(root) && root->EOW==0)
  {
      free(root);
      return NULL;
  }
}

int main()
{
  NODE *root = getnode();
  int ch,depth=0,status;
  char input[100],prefix[100],key[100];
  while(1)
  {
    printf("\n1.Insert\n2.Display\n3.display all the words with same prefix\n4.Delete a word\n");
    scanf("%d",&ch);
    switch (ch)
    {
      case 1: printf("Enter the word: ");
        scanf("%s",input);
        insert(input,root);
        break;

      case 2:
        display(root);
        break;

      case 3:
        length = 0;
        printf("Enter the prefix: ");
        scanf("%s",prefix);
        display_prefix(root,key);
        break;

      case 4:
        printf("Enter the work to be deleted: ");
        scanf("%s",&key);
        root = delete(root,key,depth);
        length = 0;
        printf("\nUpdated trie: \n");
        display(root);
        break;
    }
  }

}
